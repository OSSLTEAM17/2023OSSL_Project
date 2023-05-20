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
//5월 10일 달력을 출력하는 함수
int day_selector(int days); //종혁 (구현 완료) 
//5월 12-15일 달력에 있는 날짜중에서 유효한 날짜를 골라주는 함수
int data_selector(Dates *p); //종혁 (구현 완료)
//5월 12-13일 현재 입력된 날짜에 있는 데이터에서 유효한 소비내역을 골라주는 함수
int select_menu(); //은주, 종혁 (구현 완료)
//5월 10일 메뉴 선택하는 함수

int add_use(use_data* p); //종혁 (구현 완료)
//5월 11일 하나의 소비를 추가하는 함수
void read_use(use_data* p);//은주 (구현 완료)
//5월 11일 하나의 소비를 읽어오는 함수
void update_use(use_data* p); //종혁 (구현 완료)
//5월 11일 하나의 소비를 수정하는 함수
void delete_use(use_data *p); //은주 (구현 완료)
//5월 11일 하나의 소비를 삭제하는 함수

void loadData(Dates* h[]); //은주, 종혁 (구현 완료)
//5월 12-15일 텍스트 파일을 읽어오는 함수
void saveData(Dates* h[], int days); //은주, 종혁 (구현 완료)
//5월 12-15일 텍스트 파일로 저장하는 함수

void search_data(Dates* h[], int days); //은주 (구현 완료)
//5월 15-16일 데이터 안에 있는 데이터와 받아온 문자열과 매치되는 데이터 출력해주는 함수
void print_day(Dates *h, int input_day); //은주 (구현 완료)
//5월 15일 하루 전체 소비내역를 출력하는 함수
void print_month(Dates *h[], int days); //종혁 (구현 완료)
//5월 16일 한달 전체 소비내역을 출력하는 함수
int repeat_day_select(Dates* h[], int days, int* input_day); //종혁 (구현 완료)
//5월 16일 날짜를 유효한 값을 받을때까지 입력받는 함수
int get_day_sum(Dates *p); //은주 (구현 완료)
//5월 15일 하루의 전체 소비의 가격을 더한 값을 리턴해주는 함수