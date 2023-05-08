#include <iostream>
#include <math.h>

// Function template
// Chuc nang : Description
// void func_name() {
// }

// Chuc nang 1: Kiem tra so nguyen
void int_checker() {
    // Tao va nhap bien
    int x;
    std::cout<<"x = "; std::cin>>x;
    
    // Kiem tra neu x la so nguyen
    if(x % (int) x != 0) std::cout<<"x khong la so nguyen";
    else std::cout<<"x la so nguyen";

    // Kiem tra neu x la so nguyen to
    bool isNguyenTo = true;
    if (x < 2) {
        printf("Khong the xet tinh nguyen to cua x.\n"); 
        return;
    }
    if (x > 3) {
        for (int i = 2 ; i <= x ; i++ ) {
            if (x % i == 0) { isNguyenTo = false; break; }
        }
    }

    if (isNguyenTo) std::cout<<"x la so nguyen to.\n";
    else std::cout<<"x khong la so nguyen to.\n";

    // Kiem tra neu x la so chinh phuong
    bool isChinhPhuong = false;
    for (int i = 1 ; i <= (int) sqrt(x) ; i++) {
        if (x == i * i) {isChinhPhuong = true; break;}
    }

    if (isChinhPhuong) std::cout<<"x la so chinh phuong.\n";
    else std::cout<<"x khong la so chinh phuong.\n";
}

// Chuc nang 2: Tim Uoc so chung va boi so chung cua 2 so
void function2() {
    // Tao va nhap bien
    int x, y, USCLN;
    std::cout<<"x = "; std::cin>>x;
    std::cout<<"y = "; std::cin>>y;

    // Tim USCLN cua 2 so
    if (x != y) {
        int tmp1 = x, tmp2 = y, holder;
        while (tmp2 != 0) {
            holder = tmp1;
            tmp1 = tmp2;
            tmp2 = holder % tmp2;
        }
        USCLN = tmp1;
    } else {USCLN = x;}
    std::cout<<"Uoc so chung lon nhat cua 2 so: " << USCLN << std::endl;

    // Tim BSCNN cua 2 so
    std::cout<<"Boi so chung lon nhat cua 2 so: " << (x * y) / USCLN;
}

// Chuc nang 3: Chuong trinh tinh tien cho quan Karaoke
void karaoke_count() {
    // Tao va nhap bien
    short begin, end, working_hours;
    std::cout<<"Goi bat dau: "; std::cin>>begin;
    std::cout<<"Goi ket thuc: "; std::cin>>end;


    // Kiem tra mot so dieu kien 
    if ((begin < 12 || begin > 23) && end < 12) {
        std::cout<<"Thoi gian lam viec khong phu hop.\n";
        return;
    }

    if (begin >= 12 || end <= 23) {
        if (begin < 12) {
            std::cout<<"Gio bat dau truoc thoi gian quan mo cua. Dieu chinh lai thanh 12h.\n";
            begin = 12;
        }
        if (end > 23) {
            std::cout<<"Gio ket thuc sau thoi gian quan mo cua. Dieu chinh lai thanh 23h.\n";
            end = 23;
        }
    }

    // Khoi tao gia tri cac bien can su dung
    working_hours = end - begin;

    long salary = 150000;
    long total_amount = 0;

    // Tinh toan tien luong nhan duoc
    if (working_hours <= 3) total_amount = salary * working_hours;
    else total_amount = salary * 3 + salary * 0.7 * (working_hours - 3);

    if (begin >= 14 && begin <= 17) total_amount *= 0.9;

    std::cout<< "Ban nhan duoc " << total_amount << " sau khi lam viec duoc " << working_hours << " tieng.\n";
    return;
    
}

// Init menu
int main() {
    //  Khoi tao bien chon menu
    int menu_choice;

    // Tao giao dien cho menu
    std::cout<< "Menu:\n";
    std::cout<< "1. Kiem tra so nguyen\n";
    std::cout<< "2. Tim Uoc so chung va boi so chung cua 2 so\n";
    std::cout<< "3. Chuong trinh tinh tien cho quan Karaoke\n";

    // Chon chuc nang
    std::cout<< "Input: "; std::cin>> menu_choice;

    switch (menu_choice)
    {
    case 1:
        int_checker(); break;
    case 2:
        function2(); break;
    case 3:
        karaoke_count(); break;
    // case <function>:
    //     (); break;
    default:
        std::cout<< "Lua chon khong phu hop. Chuong trinh dung lai."; break;
    }
}
