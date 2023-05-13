#include "main.h"

int add_use(use_data* p){
    int yn;
    printf("소비 내용을 입력하세요: ");
    getchar();
    fgets(p->what, 100, stdin);
    p->what[strlen(p->what) - 1] = '\0';
    printf("소비의 가격을 입력하세요: ");
    scanf("%d", &(p->price));

    printf("소비의 추가하고 싶은 메모가 있으신가요? (예: 1, 아니요: 0) ");
    scanf("%d", &yn);

    if(yn == 1){
        printf("메모를 입력하세요. ");
        getchar();
        fgets(p->memo, 100, stdin);
        p->memo[strlen(p->memo) - 1] = '\0';
    }
    else{
        strcpy(p->memo, "없음");
    }

    return 1;
}

void read_use(use_data* p){
 
 printf("\t소비: %-20s\n\t가격: %-10d\n\t메모: %-s\n", p->what, p->price, p->memo);

}

void updata_use(use_data* p){
    int yn;
    printf("수정된 소비 내용을 입력하세요: ");
    getchar();
    fgets(p->what, 100, stdin);
    p->what[strlen(p->what) - 1] = '\0';

    printf("수정된 소비의 가격을 입력하세요: ");
    scanf("%d", &(p->price));

    printf("수정된 소비의 추가하고 싶은 메모가 있으신가요? (예: 1, 아니요: 0) ");
    scanf("%d", &yn);

    if(yn == 1){
        printf("메모를 입력하세요. ");
        getchar();
        fgets(p->memo, 100, stdin);
        p->memo[strlen(p->memo) - 1] = '\0';
    }
    else{
        strcpy(p->memo, "없음");
    }
}

void delete_use(use_data *p){ //
  printf("%s ", p->what);
    free(p);
    p = NULL;
    printf("에 대한 데이터가 삭제되었습니다.\n");
}

int data_selector(Dates *p){
    int num;
    for(int i = 0; i < p->count; i++){
        if(p->udata[i] == NULL) continue;
        printf("%d ", i + 1);
        printf("%s\n", p->udata[i]->what);
    }

    printf("번호를 선택하여주세요 (취소: 0): ");
    scanf("%d", &num);

    return num - 1;
}

void read_use_all(Dates *p){
    int n_count = 0;
    printf("===========================\n");
    printf("번호| 지출내역 | 지출비용 | 메모 \n");
    if(p->count==0) printf(" =>해당 날짜에는 소비 내역이 없습니다.\n");
    else{
    for(int i = 0; i < p->count; i++){
        if(p->udata[i] == NULL) continue;
        printf("%d| %s %d원| 메모: %s\n", n_count + 1, p->udata[i]->what,p->udata[i]->price,p->udata[i]->memo);
        n_count++;
    }
    printf("===========================\n");
    }
}

int select_menu(){
    int num;
    
    printf("\n****************************\n");
    printf("1. 소비 추가\n");
    printf("2. 소비 출력\n");
    printf("3. 소비 수정\n");
    printf("4. 소비 삭제\n");
    printf("5. 데이터 저장 \n");
    printf("6. 소비 검색\n");
    printf("7. 하루 전체 소비 출력\n");
    printf("8. 한달 전체 소비 출력\n");
    printf("9. 달력 출력\n");
    printf("0. 종료\n");
    printf("사용하실 메뉴를 입력하세요: ");


    scanf("%d", &num);
    return num;
}

int calender(int* year_main, int* month_main){
    int days, blanks;
    int leap_year;
    int i;

    if(*year_main == 0 || *month_main == 0){
        while(1){
            printf("년도와 월을 입력하세요: ");
            scanf("%d %d", year_main, month_main);

            if(*month_main < 1 || *month_main > 12){
                printf("유효하지 않은 월입니다. 다시 입력하세요.\n");
            }
            else if(*year_main < 1900){
                printf("유효하지 않은 년도입니다. 다시 입력하세요.\n");
            }
            else{
                break;
            }
        }
    }

    int year = *year_main;
    int month = *month_main;
    //요일 시작 계산 시작
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

        // 윤년이면 전년도 시작 요일보다 2개 앞으로 아니면 1개 앞으로
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

    // 입력 년도의 윤년 조건
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

    // 달의 시작 요일 구하는 조건
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

    // 요일 시작 계산 끝
    // 달력의 끝날짜 조건문을 통해 구하기
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

    // 달력 출력 시작
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
    // 달력 출력 끝

    printf("\n");
    return days;
}


 