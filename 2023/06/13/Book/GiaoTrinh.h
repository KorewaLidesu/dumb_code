// Li
// 2023 - 06 - 12

// Prevent conflict with other implementations
#ifndef LI_BOOK_GIAOTRINH
#define LI_BOOK_GIAOTRINH

#include "Sach.h"

class GiaoTrinh : public Sach {
    friend std::ostream& operator<<(std::ostream&, GiaoTrinh&);
    friend std::istream& operator>>(std::istream&, GiaoTrinh&);

    private:
        std::string chuyenNganh;
    public:
        // No param required
        GiaoTrinh(std::string = "");
        // Param required
        GiaoTrinh(int, std::string, std::string, int, std::string, std::string);

        std::string getChuyenNganh();
        void setChuyenNganh(std::string);

        void Nhap();

        void Xuat();
};

GiaoTrinh::GiaoTrinh(std::string tenChuyenNganh) : Sach(), chuyenNganh(tenChuyenNganh) {
    // implementation
}

GiaoTrinh::GiaoTrinh(int ID, std::string tenSach, std::string tenTacGia, int namXuatBan, std::string tenNhaXuatBan, std::string tenChuyenNganh)
    : Sach(ID, tenSach, tenTacGia, namXuatBan, tenNhaXuatBan), chuyenNganh(tenChuyenNganh) {
    // implementation
}

std::string GiaoTrinh::getChuyenNganh() {
    return chuyenNganh;
}

void GiaoTrinh::setChuyenNganh(std::string tenChuyenNganh) {
    this -> chuyenNganh = tenChuyenNganh;
}

void GiaoTrinh::Nhap() {
    Sach::Nhap();
    std::cout << "Nhap ten nha xuat ban: "; std::getline(std::cin, chuyenNganh);
}

void GiaoTrinh::Xuat() {
    Sach::Xuat();
    std::cout << "Chuyen nganh: " << chuyenNganh << std::endl;
}

std::ostream& operator<<(std::ostream& outStream, GiaoTrinh& giaoTrinh) {
    giaoTrinh.Xuat();
    return outStream;
}

std::istream& operator>>(std::istream& inStream, GiaoTrinh& giaoTrinh) {
    giaoTrinh.Nhap();
    return inStream;
}

#endif