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
void read_use(use_data* p); //은주
void updata_use(use_data* p); //종혁
void delete_use(use_data *p); //은주

void load_data(); //은주, 종혁
void save_data(); //은주, 종혁

void search_data(); //은주
void print_day_sum(); //은주
void print_month_sum(); //은주, 종혁
int statistics(); //종혁

void read_use_all(Dates* p[], int days);