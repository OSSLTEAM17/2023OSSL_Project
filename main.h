#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char what[100];
    int price;
    char memo[100]; 
} use_data;

typedef struct{
    int count;
    int real_count;
    use_data* udata[20];
} Dates;

int calender(int* year_main, int* month_main); //종혁 (구현 완료) 
//5월 10일
int day_selector(int days); //종혁 (구현 완료) 
//5월 12-15일
int data_selector(Dates *p); //종혁 (구현 완료)
//5월 12-13일
int select_menu(); //은주, 종혁 (구현 완료)
//5월 10일

int add_use(use_data* p); //종혁 (구현 완료)
//5월 11일
void read_use(use_data* p);//은주 (구현 완료)
//5월 11일
void update_use(use_data* p); //종혁 (구현 완료)
//5월 11일
void delete_use(use_data *p); //은주 (구현 완료)
//5월 11일

void loadData(Dates* h[]); //은주, 종혁 (구현 완료)
//5월 12-15일
void saveData(Dates* h[], int days); //은주, 종혁 (구현 완료)
//5월 12-15일

void search_data(Dates* h[], int days); //은주 (구현 완료)
//5월 15-16일
void print_day(Dates *h, int input_day); //은주 (구현 완료)
//5월 15일
void print_month(Dates *h[], int days); //종혁 (구현 완료)
//5월 16일
int repeat_day_select(Dates* h[], int days, int* input_day); //종혁 (구현 완료)
//5월 16일
int get_day_sum(Dates *p); //은주 (구현 완료)
//5월 15일