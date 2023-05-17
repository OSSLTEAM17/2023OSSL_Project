#include "main.h"

int main(){
    int year, month;
    year = month = 0;
    Dates* h[31];

    int input_day, menu, yn, num;
    
    printf("������ �о���ðڽ��ϱ�? (��: 1, �ƴϿ�: 0) ");
    scanf("%d", &yn);

    if(yn == 1){
        printf("�о���� �������� �⵵�� ���� ���� ������ �Է����ּ���. ");
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
                    printf("�Ϸ� ������ �� �ִ� ���赥���͸� �ʰ��Ͽ����ϴ�.\n");
                    break;
                }
                else{
                h[input_day - 1]->udata[h[input_day - 1]->count] = (use_data*)malloc(sizeof(use_data));
                h[input_day - 1]->count+= add_use(h[input_day - 1]->udata[h[input_day - 1]->count]);
                h[input_day - 1]->real_count++;
                
                printf("%d�Ͽ� �����͸� �� �߰��Ͻðڳ���? (��: 1, �ƴϿ�: 0) ", input_day);
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
                if(num == 0) printf("��ҵǾ����ϴ�.\n");
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
                if(num == 0) printf("��ҵǾ����ϴ�.\n");
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
                if(num == 0) printf("��ҵǾ����ϴ�.\n");
                else{
                    delete_use(h[input_day - 1]->udata[num - 1]);
                    h[input_day - 1]->udata[num - 1] = NULL;
                    h[input_day - 1]->real_count--;
                }
            }
        }

        else if(menu == 5){
            saveData(h, days);
            printf("������ ����Ǿ����ϴ�.\n");
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

