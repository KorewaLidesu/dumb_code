// Li
// 2023 - 06 - 02

// Prevent conflict with other implementations
#ifndef LI_QUANLYKHACHSAN
#define LI_QUANLYKHACHSAN

#include <exception>
#include "ArrayList.h"
#include "HoaDon.h"
#include "ThuePhong.h"

class QuanLyKhachSan
{
    private:
        int N = 10;
        ArrayList<ThuePhong> danhSachThue;
    public:
        QuanLyKhachSan();
        void listPhongThue();
        void themPhongThue(ThuePhong&);
        int tongTatCa();
        HoaDon taoHoaDon();
        HoaDon taoHoaDon(ThuePhong*);
        HoaDon taoHoaDon(int, DateAndTime&, ThuePhong*, bool);
};

// Constructor
QuanLyKhachSan::QuanLyKhachSan() : danhSachThue(ArrayList<ThuePhong>(N))
{
}

void QuanLyKhachSan::themPhongThue(ThuePhong& thuePhong)
{
    danhSachThue.add(thuePhong);
}

int QuanLyKhachSan::tongTatCa()
{
    int tongTien = 0;
    for (int i = 0 ; i < danhSachThue.getSize() ; i++)
        tongTien += danhSachThue.get(i) -> tongTienPhong();
    return tongTien;
}

void QuanLyKhachSan::listPhongThue()
{
    for (int i = 0 ; i < danhSachThue.getSize() ; i++)
    {
        std::cout << i << ". So phong #" << danhSachThue.get(i) -> getMaPhong() << std::endl;
    }
}

HoaDon QuanLyKhachSan::taoHoaDon()
{
    listPhongThue();
    std::cout << "Chon phong muon tao hoa don";
    int i; std::cin >> i;
    if (i < 0 || i > danhSachThue.getSize())
        throw std::out_of_range("");
    return taoHoaDon(danhSachThue.get(i));
}

HoaDon QuanLyKhachSan::taoHoaDon(ThuePhong* phong)
{
    std::cout << "Tao hoa don moi cho phong #" << phong -> getMaPhong() << ":" << std::endl;
    std::cout << "- Ma hoa don:";
    int maHD; std::cin >> maHD;
    std::cout << "- Ngay tao hoa don:";
    DateAndTime ngayHD; std::cin >> ngayHD;
    std::cout << "- Loai hoa don (Mac dinh: 1)" << std::endl
        << "1. Theo ngay" << std::endl
        // << "2. Theo gio" << std::endl // Uncomment if required
        << "Chon: "
        ;
    int loaiHD; std::cin >> loaiHD;
    return taoHoaDon(maHD, ngayHD, phong, loaiHD == 2 ? false : true);
}

HoaDon QuanLyKhachSan::taoHoaDon(int maHD, DateAndTime& ngayHD, ThuePhong* phong, bool loaiHD)
{
    return HoaDon(maHD, ngayHD, phong, loaiHD);
}

#endif