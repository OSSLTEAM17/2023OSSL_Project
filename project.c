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
        }

        else if(menu == 2){
        
        }

        else if(menu == 3){
        }

        else if(menu == 4){// 삭제
        
        }

        else if(menu == 5){
            
        }

        else if(menu == 6){
            
        }
        else if(menu == 7){
            read_use_all(h);

        }
        else if(menu == 8){
            
        }

        else if(menu == 9){
        }
    }


    return 0;
}

