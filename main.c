#include "main.h"


int add_use(use_data* p){
    int yn;
    printf("??? ?????? ????????: ");
    getchar();
    fgets(p->what, 100, stdin);
    p->what[strlen(p->what) - 1] = '\0';

    printf("????? ?????? ????????: ");
    scanf("%d", &(p->price));

    printf("????? ?????? ???? ??? ?????????? (??: 1, ????: 0) ");
    scanf("%d", &yn);

    if(yn == 1){
        printf("??? ????????. ");
        getchar();
        fgets(p->memo, 100, stdin);
        p->memo[strlen(p->memo) - 1] = '\0';
    }
    else{
        strcpy(p->memo, "????");
    }

    return 1;
}

void read_use(use_data* p){
    printf("\t???: %-20s\n\t????: %-10d\n\t???: %-s\n", p->what, p->price, p->memo);
    
}

void update_use(use_data* p){
    int yn;
    printf("?????? ??? ?????? ????????: ");
    getchar();
    fgets(p->what, 100, stdin);
    p->what[strlen(p->what) - 1] = '\0';

    printf("?????? ????? ?????? ????????: ");
    scanf("%d", &(p->price));

    printf("?????? ????? ?????? ???? ??? ?????????? (??: 1, ????: 0) ");
    scanf("%d", &yn);

    if(yn == 1){
        printf("??? ????????. ");
        getchar();
        fgets(p->memo, 100, stdin);
        p->memo[strlen(p->memo) - 1] = '\0';
    }
    else{
        strcpy(p->memo, "????");
    }
}

void delete_use(use_data *p){
    printf("%s ", p->what);
    free(p);
    p = NULL;

    printf("?? ???? ????????? ????????????.\n");
}

int day_selector(int days){
    int day;
    while(1){
        printf("????? ????????: ");
        scanf("%d", &day);

        if(day > days || day < 1){
            printf("??????? ???? ???????. ??? ????????.\n");
        }
        else break;
    }
    return day;
}

int data_selector(Dates *p){
    int num;
    int temp[20] = {0,};
    for(int i = 0; i < p->count; i++){
        if(p->udata[i] == NULL) continue;
        printf("%d ", i + 1);
        printf("%s\n", p->udata[i]->what);
        temp[i]++;
    }

    int yn;
    while(1){
        printf("????? ???????????? (???: 0): ");
        scanf("%d", &num);
        if(num == 0 || temp[num - 1] == 1) break;
        printf("??????? ???? ???????. ???????????. ");
    }

    return num;
}

int select_menu(){
    int num;
    
    printf("\n****************************\n");
    printf("1. ??? ???\n");
    printf("2. ??? ???\n");
    printf("3. ??? ????\n");
    printf("4. ??? ????\n");
    printf("5. ?????? ???? \n");
    printf("6. ??? ???\n");
    printf("7. ??? ??? ??? ???\n");
    printf("8. ??? ??? ??? ???\n");
    printf("9. ??? ???\n");
    printf("0. ????\n");
    printf("?????? ????? ????????: ");


    scanf("%d", &num);
    return num;
}

void loadData(Dates* h[]){
    
    
    char temp[200];
    char temp_strings[3][100];
    int nums[2];
    int count = 0;
    int j;
    int current_day;
    int d_count = 0;
    
    FILE* file;
    if((file = fopen("data.txt", "rt")) == NULL){
        printf("=> ???? ??????? ????.\n");
    }
    else{
        while(1){
            if(fgets(temp, 220, file) == NULL) break;

            if(strlen(temp) < 3){
                current_day = atoi(temp);
                d_count = 0;
            }
            else{
                count = 0;

                for(j = 0; j < strlen(temp); j++){
                    if(temp[j] == ','){
                        nums[count] = j;
                        count++;
                    }
                }

                h[current_day - 1]->udata[d_count] = (use_data*)malloc(sizeof(use_data));

                strncpy(temp_strings[0], temp, nums[0]);
                temp_strings[0][nums[0]] = '\0';
                strcpy(h[current_day - 1]->udata[d_count]->what, temp_strings[0]);

                strncpy(temp_strings[1], temp + nums[0] + 1, nums[1] - nums[0]);
                temp_strings[1][nums[1] - nums[0] - 1] = '\0';
                h[current_day - 1]->udata[d_count]->price = atoi(temp_strings[1]);

                strncpy(temp_strings[2], temp + nums[1] + 1, strlen(temp) - nums[1]);
                temp_strings[2][strlen(temp) - nums[1] - 2] = '\0';
                strcpy(h[current_day - 1]->udata[d_count]->memo, temp_strings[2]);

                d_count++;
                h[current_day - 1]->count++;
                h[current_day - 1]->real_count++;
            }
        }

        fclose(file);
    }

}

void saveData(Dates* h[], int days){
    FILE* file;
    file = fopen("data.txt", "wt");


    for(int i = 0; i < days; i++){
        if(h[i]->real_count > 0){
            fprintf(file, "%d\n", i + 1);

            for(int j = 0; j < h[i]->count; j++){
                if(h[i]->udata[j] == NULL) continue;
                fprintf(file, "%s,%d,%s\n", h[i]->udata[j]->what, h[i]->udata[j]->price, h[i]->udata[j]->memo);
            }
        }

    }

    fclose(file);
}

int calender(int* year_main, int* month_main){
    int days, blanks;
    int leap_year;
    int i;

    if(*year_main == 0 || *month_main == 0){
        while(1){
            printf("???? ???? ????????: ");
            scanf("%d %d", year_main, month_main);

            if(*month_main < 1 || *month_main > 12){
                printf("??????? ???? ??????. ??? ????????.\n");
            }
            else if(*year_main < 1900){
                printf("??????? ???? ??????. ??? ????????.\n");
            }
            else{
                break;
            }
        }
    }

    int year = *year_main;
    int month = *month_main;
    //???? ???? ??? ????
    blanks = 1;
    days = 0;

    for(i = year - 1; i >= 1900; i--){

        if(i % 400 == 0){
            leap_year = 1;
        }
        else if (i % 100 == 0)
        {
            leap_year = 0;
        }
        else if (i % 4 == 0)
        {
            leap_year = 1;
        }
        else
        {
            leap_year = 0;
        }

        // ??????? ???? ???? ??????? 2?? ?????? ???? 1?? ??????
        if (leap_year == 0)
        {
            blanks++;
        }
        else
        {
            blanks = blanks + 2;
        }

        if (blanks > 6)
        {
            blanks = blanks % 7;
        }
    }

    // ??? ???? ???? ????
    if (year % 400 == 0)
    {
        leap_year = 1;
    }
    else if (year % 100 == 0)
    {
        leap_year = 0;
    }
    else if (year % 4 == 0)
    {
        leap_year = 1;
    }
    else
    {
        leap_year = 0;
    }

    // ???? ???? ???? ????? ????
    for (i = 0; i < month; i++)
    {
        if (i == 0)
            days = 0;

        else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            days = 31;

        else if (i == 2)
        {
            if (leap_year == 0)
                days = 28;
            else
                days = 29;
        }

        else
            days = 30;

        blanks = blanks + days;
        blanks = blanks % 7;
    }

    // ???? ???? ??? ??
    // ????? ????? ??????? ???? ?????
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        days = 31;

    else if (month == 2)
    {
        if (leap_year == 1)
            days = 29;
        else if (leap_year == 0)
            days = 28;
    }
    else
        days = 30;

    // ??? ??? ????
    printf("Sun    Mon    Tue    Wed    Thu    Fri    Sat\n");

    for (int i = 0; i < blanks; i++){
        printf("       ");
    }
    for (int i = 1; i <= days; i++)
    {
        if (((blanks - 1) + i) % 7 == 0)
        {
            printf("\n");
        }
        printf(" %-6d", i);
    }
    // ??? ??? ??

    printf("\n");
    return days;
}

void print_day(Dates *h, int input_day){
    printf("\n****************************\n");
    printf("%d???? ????\n\n", input_day);
    int n_count = 0;
    for(int i = 0 ; i < h->count ; i++){
        if(h->udata[i] == NULL) continue;

        printf("%d.\n", n_count + 1);
        n_count++;
        read_use(h->udata[i]);
        
    }

    int sum = get_day_sum(h);
    printf("\n%d??? ?? ??????? %d??????.\n", input_day, sum);
}

void print_month(Dates *h[], int days){
    int sum = 0;
    for(int i = 0; i < days; i++){
        if(h[i]->real_count == 0) continue;

        if(i != 0) printf("****************************\n");
        printf("%d??\n", i + 1);

        for(int j = 0; j < h[i]->count; j++){
            if(h[i]->udata[j] == NULL) continue;
            printf("\n");
            printf("%d???? %d?? ??????:\n", i + 1, j + 1);
            read_use(h[i]->udata[j]);
        }
        sum+= get_day_sum(h[i]);

    }

    printf("\n?? ??????? %d??????.\n", sum);
}

int repeat_day_select(Dates* h[], int days, int* input_day){
    int yn;
    while(1){
        *input_day = day_selector(days);
        if(h[*input_day - 1]->real_count == 0){
            printf("%d????? ?????? ???????. ????????????? (??: 1, ????: 0) ", *input_day);
            scanf("%d", &yn);
            if(yn == 0) break;
            
        }
        else{
            yn = 1;
            break;
        }
    }
    return yn;
}

void search_data(Dates* h[], int days){
    int scnt = 0;
    char search[100]; //????? ????? 
    printf("????? ????? ??????????: ");
    getchar();
    fgets(search, 100, stdin);
    search[strlen(search)-1] = '\0';

    for (int i = 0; i < days; i++){
        if (h[i]->real_count == 0) continue;
        for(int j = 0; j < h[i]->count; j++){
            if(h[i]->udata[j] == NULL) continue;
            if(strstr(h[i]->udata[j]->what, search)){
                printf("****************************\n");
                printf("%d???? %d?? ??????:\n", i + 1, j + 1);
                read_use(h[i]->udata[j]);
                scnt++;
            }
        }
    }
    if (scnt == 0) printf("=> ??? ????? ??? ?????? ????! ");

}

int get_day_sum(Dates *p){

    int sum = 0;
    if(p->real_count == 0){  // ?????? ???? ?? 
        return sum;
    }
    else{
        
        for(int i = 0; i < p->count; i++){ //?????? ????? ??? ?????? 1?? ?????? 
            if(p->udata[i] == NULL) continue;
            sum+= p->udata[i]->price;
        } 
    }

    return sum;
}
