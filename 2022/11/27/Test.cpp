#include <stdio.h>

struct PHANSO {
    int TS;
    int MS;
};

// Chuc nang 10: Xay dung chuong trinh tinh toan phan so
int main() {
    PHANSO ps1, ps2;

    printf("Nhap Tu so cua phan so 1: ");
    scanf("%d", ps1.TS);
    do {
        printf("Nhap Mau so cua phan so 1: ");
        scanf("%d",ps1.MS);
        if(ps1.MS==0)
            printf("Nhap sai, yeu cau nhap lai mau so: ");
    } while(ps1.MS==0);

    printf("Nhap Tu so cua phan so 2: ");
    scanf("%d", ps2.TS);
    do {
        printf("Nhap Mau so cua phan so 2: ");
        scanf("%d",ps2.MS);
        if(ps2.MS==0)
            printf("Nhap sai, yeu cau nhap lai mau so: ");
    } while(ps2.MS==0);

    int Tu = ps1.TS * ps2.MS + ps1.MS * ps2.TS;
    int Mau = ps1.MS * ps2.MS;

    printf("Tong cua 2 phan so: %.2f\n", (float) Tu/Mau);


    Tu = ps1.TS * ps2.MS - ps1.MS * ps2.TS;
    Mau = ps1.MS * ps2.MS;
    printf("Hieu cua 2 phan so: %.2f\n", (float) Tu/Mau);

    Tu = ps1.TS * ps2.TS;
    Mau = ps1.MS * ps2.MS;
    printf("Tich cua 2 phan so: %.2f\n", (float)Tu/Mau);


    Tu = ps1.TS * ps2.MS;
    Mau = ps1.MS * ps2.TS;
    printf("Thuong cua 2 phan so: %.2f\n", (float)Tu/Mau);
}
