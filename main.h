#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char what[100];
    int price;
    char meno[100]; 
    char type[20];
} use_data;

typedef struct{
    int count;
    int real_count;
    use_data* udata[20];
} Dates;

int calender(int* year_main, int* month_main);
int day_selector(int days);
int data_selector(Dates *p);
int select_menu();
int add_use(use_data* p);
void read_use(use_data* p);
void updata_use(use_data* p);
void delete_use(use_data *p);

