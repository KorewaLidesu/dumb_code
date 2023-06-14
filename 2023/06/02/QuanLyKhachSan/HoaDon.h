// Li
// 2023 - 06 - 02

// Prevent conflict with other implementations
#ifndef LI_HOADON
#define LI_HOADON

#include <exception>
#include "QuanLyKhachSan.h"
#include "DateAndTime.h"
#include "ThuePhong.h"

class HoaDon
{
    friend std::ostream& operator<<(std::ostream&, HoaDon);

    private:
        int maHoaDon;
        DateAndTime ngayHoaDon;
        std::string tenKhachHang;
        int maPhong;
        int donGia;
        bool loaiHoaDon; // F = tinh theo gio, T = tinh theo ngay
        ThuePhong* phongThanhToan;
    public:
        // Constructor & Deconstructor
        HoaDon(int, DateAndTime&, ThuePhong*, bool);
        ~HoaDon();

        // Methods
        int thanhToan() const;
        void sanityCheck(bool) const;

        // Getter
        int getMaHD() const;
        DateAndTime getNgayHD() const;
        std::string getTenKH() const;
        int getMaPhong() const;
        int getDonGia() const;
        bool getLoaiHoaDon() const;
        std::string getLoaiHDinString() const;
};

HoaDon::HoaDon(int maHD, DateAndTime& ngayHD, ThuePhong* phong, bool loaiHD)
{
    maHoaDon = maHD;
    ngayHoaDon = ngayHD;
    phongThanhToan = phong;
    loaiHoaDon = loaiHD;
}

HoaDon::~HoaDon()
{
    delete phongThanhToan;
}

int HoaDon::thanhToan() const
{
    sanityCheck(false);
    return phongThanhToan -> tongTienPhong();
}

void HoaDon::sanityCheck(bool secondCheck) const
{
    std::cout << "test" << std::endl;
    if (phongThanhToan == nullptr)
    {
        throw std::runtime_error("Chua thiet lap phong can thanh toan");
    }
    std::cout << "test" << std::endl;
    if (secondCheck && phongThanhToan -> getKhachThue() == nullptr)
    {
        throw std::runtime_error("Khong co khach hang nao thue phong nay!");
    }
    std::cout << "test" << std::endl;
}

int HoaDon::getMaHD() const
{
    return maHoaDon;
}

DateAndTime HoaDon::getNgayHD() const
{
    return ngayHoaDon;
}

std::string HoaDon::getTenKH() const
{
    sanityCheck(true);
    return phongThanhToan -> getKhachThue() -> getHoTen();
}

int HoaDon::getMaPhong() const
{
    sanityCheck(false);
    return phongThanhToan -> getMaPhong();
}

int HoaDon::getDonGia() const
{
    sanityCheck(false);
    return phongThanhToan -> getGiaPhong();
}

bool HoaDon::getLoaiHoaDon() const
{
    return loaiHoaDon;
}

std::string HoaDon::getLoaiHDinString() const
{
    return loaiHoaDon ? "ngay" : "gio" ;
}

std::ostream& operator<<(std::ostream& outStream, HoaDon hoaDon)
{
    std::cout << "Hoa don so #" << hoaDon.maHoaDon << ":" << std::endl
        << "- Ngay tao hoa don: " << hoaDon.ngayHoaDon
        << "- Ten khach hang: " << hoaDon.getTenKH() << std::endl
        << "- Ma phong: " << hoaDon.getMaPhong() << std::endl
        << "- Don gia: " << hoaDon.getDonGia() << std::endl
        << "- Loai hoa don: " << hoaDon.getLoaiHDinString() << std::endl
        << "- Thoi gian: " << hoaDon.phongThanhToan -> getThoiGian() << " ngay" << std::endl
        << "=> So tien can thanh toan: " << hoaDon.phongThanhToan -> tongTienPhong() << std::endl;
    return outStream;
}

#endif