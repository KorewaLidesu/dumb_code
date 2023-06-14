#include "QuanLyKhachSan.h"

int initMenu();

int main()
{
    QuanLyKhachSan khachSan;

    ThuePhong phong;
    std::cin >> phong;

    khachSan.themPhongThue(phong);

    std::cout << khachSan.tongTatCa() << std::endl;

    HoaDon hoaDon = khachSan.taoHoaDon();

    // Buoc in danh sach
    khachSan.listPhongThue();

    HoaDon hoaDon();

    std::cout << hoaDon;
}

int initMenu()
{
    std::cout << "He thong quan ly khach san";
}