#include <iostream>
#include <math.h>

/*
 * Khai bao cac ham
*/
void int_checker();
void usc_bsc();
void karaoke_count();
void tien_dien();
void doi_tien();
void lai_suat_vay();
void vay_tien_mua_xe();
void student_sort();
void f_game();
void tinh_toan_phan_so();

/*
 * Menu cua chuong trinh
*/
int main() {
  // Tao danh sach
  std::cout<< "Menu:"<< std::endl;
  std::cout<< "1. Kiem tra so nguyen"<< std::endl;
  std::cout<< "2. Tim Uoc so chung va boi so chung cua 2 so"<< std::endl;
  std::cout<< "3. Tinh tien cho quan Karaoke"<< std::endl;
  std::cout<< "4. Tinh tien dien"<< std::endl;
  std::cout<< "5. Doi tien"<< std::endl;
  std::cout<< "6. Tinh lai suat vay ngan hang vay tra gop"<< std::endl;
  std::cout<< "7. Vay tien mua xe"<< std::endl;
  std::cout<< "8. Sap xep thong tin sinh vien"<< std::endl;
  std::cout<< "9. Xay dung game FPOLY-LOTT (2/15)"<< std::endl;
  std::cout<< "10. Tinh toan phan so"<< std::endl;
  // Chon chuc nang
  int menu_choice;
  std::cout<< "Input: "; std::cin>> menu_choice;
  std::cout<< "============================================="<< std::endl;
  switch (menu_choice) {
    case 1:
      int_checker(); break;
    case 2:
      usc_bsc(); break;
    case 3:
      karaoke_count(); break;
    case 4:
      tien_dien(); break;
    case 5:
      doi_tien(); break;
    case 6:
      lai_suat_vay(); break;
    case 7:
      vay_tien_mua_xe(); break;
    case 8:
      student_sort(); break;
    case 9:
      f_game(); break;
    case 10:
      tinh_toan_phan_so(); break;
    default:
      std::cout<< "Lua chon khong phu hop. Chuong trinh dung lai."; return -666;
  }
}

/*
 * Chuc nang cua chuong trinh
*/

// Chuc nang 1: Kiem tra so nguyen
void int_checker() {
  // Tao va nhap bien
  int x;
  std::cout<<"x = "; std::cin>>x;
  // Kiem tra neu x la so nguyen
  if(x % (int) x != 0) std::cout<<"x khong la so nguyen"<<std::endl;
  else std::cout<<"x la so nguyen"<<std::endl;
  // Kiem tra neu x la so nguyen to
  bool isNguyenTo = true;
  if (x < 2) std::cout<<"Khong the xet tinh nguyen to cua x."<<std::endl;
  else if (x > 3) {
    for (int i = 2 ; i <= x ; i++ ) {
      if (x % i == 0) {isNguyenTo = false; break;}
    }
  }
  if (isNguyenTo) std::cout<<"x la so nguyen to."<<std::endl;
  else std::cout<<"x khong la so nguyen to."<<std::endl;
  // Kiem tra neu x la so chinh phuong
  bool isChinhPhuong = false;
  for (int i = 1 ; i <= (int) sqrt(x) ; i++) {
    if (x == i * i) {isChinhPhuong = true; break;}
  }
  if (isChinhPhuong) std::cout<<"x la so chinh phuong."<<std::endl;
  else std::cout<<"x khong la so chinh phuong."<<std::endl;
}

// Chuc nang 2: Tim Uoc so chung va boi so chung cua 2 so
void usc_bsc() {
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
  } else USCLN = x;
  std::cout<<"Uoc so chung lon nhat cua 2 so: " << USCLN << std::endl;
  std::cout<<"Boi so chung lon nhat cua 2 so: " << (x * y) / USCLN << std::endl;
}

// Chuc nang 3: Chuong trinh tinh tien cho quan Karaoke
void karaoke_count() {
  // Tao va nhap bien
  short begin, end;
  std::cout<<"Goi bat dau: "; std::cin>>begin;
  std::cout<<"Goi ket thuc: "; std::cin>>end;
  // Kiem tra mot so dieu kien
  if ((begin < 12 || begin > 23) && end < 12) {
    std::cout << "Thoi gian lam viec khong phu hop." << std::endl; return;
  }
  if (begin >= 12 || end <= 23) {
    if (begin < 12) {
      std::cout << "Gio bat dau truoc thoi gian quan mo cua. Dieu chinh lai thanh 12h." << std::endl;
      begin = 12;
    }
    if (end > 23) {
      std::cout << "Gio ket thuc sau thoi gian quan mo cua. Dieu chinh lai thanh 23h." << std::endl;
      end = 23;
    }
  }
  // Khoi tao gia tri cac bien can su dung
  short working_hours = end - begin;
  long total_amount = 0;
  // Tinh toan tien luong nhan duoc
  if (working_hours <= 3) total_amount = 150000 * working_hours;
  else total_amount = 150000 * 3 + 150000 * 0.7 * (working_hours - 3);
  if (begin >= 14 && begin <= 17) total_amount *= 0.9;
  std::cout<< "Ban nhan duoc " << total_amount << " sau khi lam viec duoc " << working_hours << " tieng." << std::endl;
}

// Chuc nang 4: Tinh tien dien
void tien_dien() {
  int tieu_thu;
  std::cout<<"Luong dien tieu thu trong thang: "; std::cin>>tieu_thu;
  
  int bac = tieu_thu / 100, phan_du = tieu_thu % 100;
  long tong = 0;

  switch (bac) {
    case 4:
      if (tieu_thu >= 401) {
        tong += (tieu_thu - 400) * 2927;
        tieu_thu = 400;
      }
      tong += (tieu_thu - 300) * 2834;
      tieu_thu = 300;
    case 3:
      if (phan_du != 0) {
        tong += (tieu_thu - 300) * 2834;
        tieu_thu = 300;
      }
      tong += (tieu_thu - 200) * 2536;
      tieu_thu = 200;
    case 2:
      if (phan_du != 0) {
        tong += (tieu_thu - 200) * 2536;
        tieu_thu = 200;
      }
      tong += (tieu_thu - 100) * 2014;
      tieu_thu = 100;
    case 1:
      if (phan_du != 0) {
        tong += (tieu_thu - 100) * 2014;
        tieu_thu = 50;
      }
      tong += (tieu_thu - 50) * 1734;
      tieu_thu = 50;
    default:
      if (tieu_thu > 50 && phan_du != 0) {
        tong += (tieu_thu - 50) * 1734;
        tieu_thu = 50;
      }
      tong += tieu_thu * 1678;
  }
  std::cout<< "So tien ban can phai tra: " << tong;
}

// Chuc nang 5: Chuc nang doi tien
void doi_tien() {
}

// Chuc nang 6: Xay dung chuc nang tinh lai suat vay ngan hang vay tra gop
void lai_suat_vay() {
  double so_tien;
  std::cout<< "So tien can vay: "; std::cin>> so_tien;
  double goc_phai_tra = so_tien / 12.0, so_tien_phai_tra;

  for (int i = 1; i <= 12 ; i++) {
    so_tien_phai_tra = round(goc_phai_tra + so_tien * 0.05);
    so_tien *= 1.05;
    std::cout << "Ky han " << i << " tra: " << so_tien_phai_tra << std::endl;
    so_tien -= so_tien_phai_tra;
  }
}

// Chuc nang 7: Xay dung chuong trinh vay tien mua xe
void vay_tien_mua_xe() {
  double so_tien = 500000000;
  double phan_tram_vay;
  std::cout<< "So phan tram vay toi da: "; std::cin>> phan_tram_vay;
  if (phan_tram_vay < 0 && phan_tram_vay > 100){
  	std::cout<< "Du kien nhap khong hop le."; return;
  }	
  std::cout<< "So tien phai tra lan dau: "<< (long) (so_tien * ((100 - phan_tram_vay) / 100)) <<std::endl;
  so_tien -= so_tien * ((100 - phan_tram_vay)/100);
  
  for (int i = 0; i < 2 ; i++) {
    so_tien *= 1.072;
    double goc_phai_tra = so_tien / (12.0 * (2 - i));
	for (int j = 1; j <= 12 ; j++) {
	  std::cout << "Ky han " << (12 * i + j) << " tra: " << (long) goc_phai_tra << std::endl;
	  so_tien -= goc_phai_tra;
  	}
  }
}

// Chuc nang 8: Sap xep thong tin sinh vien
void student_sort() {
  std::string hoten; 
  float diem;
  std::cout<< "Ho ten: ";
  std::cin.ignore();
  std::getline(std::cin, hoten);
  std::cout<< "Diem: "; std::cin>> diem;

  std::cout<<hoten<<"|"<<diem;
}

// Chuc nang 9: Xay dung game FPOLY-LOTT (2/15)
void f_game() {

}

// Chuc nang 10: Xay dung chuong trinh tinh toan phan so
void tinh_toan_phan_so() {

}
