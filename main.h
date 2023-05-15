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

int calender(int* year_main, int* month_main); //종혁
int day_selector(int days); //종혁
int data_selector(Dates *p); //종혁
int select_menu(); //은주, 종혁

int add_use(use_data* p); //종혁 
void read_use(Dates *p[], int days);//은주
void updata_use(use_data* p); //종혁
void delete_use(Dates* p[], int days); //은주

void load_data(); //은주, 종혁
void save_data(); //은주, 종혁

void search_data(); //은주
void print_day_sum(Dates* p[], int days); //은주, Dates* p, int days 파라미터로 추가 
void print_month_sum(); //은주, 종혁
int statistics(); //종혁

void read_use_all(Dates* p); // 선택한 날짜의 하루 지출 내역을 읽어오는 함수 (메뉴 7번)
void read_use_one(use_data* p); //은주, read_use 함수에서 나온 use 내용 중 선택한 use 하나만 출력
