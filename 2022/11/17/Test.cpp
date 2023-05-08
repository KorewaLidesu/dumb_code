#include "iostream"
#include "stdio.h"
#include "math.h"
using namespace std;
void cacsotunhienchiahetcho2();
void xacdinhsonguyento();
void sochinhphuong();
void thoat();
int main(){
    int chucnang;
    //B1
    do {
        cout<<"1. cacsotunhienchiahetcho2"<<endl;
        cout<<"2. xacdinhsonguyento"<<endl;
        cout<<"3. sochinhphuong"<<endl;
        cout<<"4. thoat"<<endl;
        cout<<"Hay chon chuc nang"<<endl;
        cin >> chucnang; //nhap tu ban phim
        if (chucnang >=1 && chucnang <=4) break;
    } while(true);

    switch (chucnang) {
        case 1:
            cacsotunhienchiahetcho2();
            break;
        case 2:
            xacdinhsonguyento();
            break;
        case 3:
            sochinhphuong();
            break;
        case 4:
            thoat();
            break;
        default:
            break;
    }


}
void cacsotunhienchiahetcho2()
{int min,max;
int sum,avg;

printf("nhap min va max");
scanf("%d%d", &min, &max);

int i = min;
while (i <= max){
printf("%d", i);
i ++; // i = i + 1
}

}
void xacdinhsonguyento()
{int num;
    printf("vui long nhap x: ");
    scanf("%d", &num);
    int y = 0;
    for (int i = 2; i <= sqrt(num) ; i++) {
        if(i * i == num){
            y = 1;
            break;
        }
    }
    if (y == 1){
        printf("\n%d la so chinh phuong", num);
    } else{
        printf("\n%d khong phai la so chinh phuong", num);
    }

}
void sochinhphuong()
{int x;
    printf("vui long nhap x: ");
    scanf("%d", &x);
    int y = 0;
    for (int i = 2; i <= sqrt(x) ; i++) {
        if(i * i == x){
            y = 1;
            break;
        }
    }
    if (y == 1){
        printf("\n%d la so chinh phuong", x);
    } else{
        printf("\n%d khong phai la so chinh phuong", x);
    }

}

