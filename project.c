#include "main.h"

int main(){
    int year, month;
    year = month = 0;
    int days = calender(&year, &month);

    int  menu;
    Dates* h[31];

    for(int i = 0; i < days; i++){
        h[i] = (Dates*)malloc(sizeof(Dates));
        h[i]->count = 0;
        h[i]->real_count = 0;
        
    }


    while(1){
        menu = select_menu();
        if(menu == 0){
            break;
        }

        else if(menu == 1){
        }

        else if(menu == 2){
        read_use_all(h);
        }

        else if(menu == 3){
        }

        else if(menu == 4){
        }

        else if(menu == 5){
            
        }

        else if(menu == 6){
            
        }

        else if(menu == 7){
        }
        
        else if(menu == 8){
            
        }

        else if(menu == 9){
        }
    }


    return 0;
}

