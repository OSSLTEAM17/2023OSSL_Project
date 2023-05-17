#include "main.h"

int main(){
    int year, month;
    year = month = 0;
    Dates* h[31];

    int input_day, menu, yn, num;
    
    printf("파일을 읽어오시겠습니까? (예: 1, 아니요: 0) ");
    scanf("%d", &yn);

    if(yn == 1){
        printf("읽어오실 데이터의 년도와 월에 대한 정보를 입력해주세요. ");
        scanf("%d %d", &year, &month);
    }

    int days = calender(&year, &month);
    for(int i = 0; i < days; i++){
        h[i] = (Dates*)malloc(sizeof(Dates));
        h[i]->count = 0;
        h[i]->real_count = 0;
    }
    
    if(yn == 1){
        loadData(h);
    }

    while(1){
        menu = select_menu();
        if(menu == 0){
            break;
        }

        else if(menu == 1){
            input_day = day_selector(days);
            while(1){
                if(h[input_day - 1]->count > 19){
                    printf("하루 저장할 수 있는 가계데이터를 초과하였습니다.\n");
                    break;
                }
                else{
                h[input_day - 1]->udata[h[input_day - 1]->count] = (use_data*)malloc(sizeof(use_data));
                h[input_day - 1]->count+= add_use(h[input_day - 1]->udata[h[input_day - 1]->count]);
                h[input_day - 1]->real_count++;
                
                printf("%d일에 데이터를 더 추가하시겠나요? (예: 1, 아니요: 0) ", input_day);
                scanf("%d", &yn);
                if(yn == 0) break;
                }
            }
        }

        else if(menu == 2){

            yn = repeat_day_select(h, days, &input_day);    
            
            if(yn == 0){

            }
            else{
                num = data_selector(h[input_day - 1]);
                if(num == 0) printf("취소되었습니다.\n");
                else{
                    printf("\n****************************\n");
                    read_use(h[input_day - 1]->udata[num - 1]);
                }
            }
        }

        else if(menu == 3){
            yn = repeat_day_select(h, days, &input_day);    
            
            if(yn == 0){

            }
            else{
                num = data_selector(h[input_day - 1]);
                if(num == 0) printf("취소되었습니다.\n");
                else{
                    printf("\n****************************\n");
                    update_use(h[input_day - 1]->udata[num - 1]);
                }
            }
        }
        
        else if(menu == 4){
            yn = repeat_day_select(h, days, &input_day);    
            
            if(yn == 0){

            }
            else{
                num = data_selector(h[input_day - 1]);
                if(num == 0) printf("취소되었습니다.\n");
                else{
                    delete_use(h[input_day - 1]->udata[num - 1]);
                    h[input_day - 1]->udata[num - 1] = NULL;
                    h[input_day - 1]->real_count--;
                }
            }
        }

        else if(menu == 5){
            saveData(h, days);
            printf("파일이 저장되었습니다.\n");
        }

        else if(menu == 6){
            search_data(h, days);
        }
        
        else if(menu == 7){
            yn = repeat_day_select(h, days, &input_day);
            if(yn == 0){

            }
            else{
                print_day(h[input_day - 1], input_day);
            }
        }

        else if(menu == 8){
            print_month(h, days);
        }

        else if(menu == 9){
            calender(&year, &month);
        }
 
    }


    return 0;
}

