// Li
// 2023 - 06 - 02

// Prevent conflict with other implementations
#ifndef LI_THUEPHONG
#define LI_THUEPHONG

#include "KhachThue.h"
#include <iostream>

class ThuePhong {
    friend std::istream& operator>>(std::istream&, ThuePhong&);
    friend std::ostream& operator<<(std::ostream&, ThuePhong);

    private:
        KhachThue* khachThue;
        int maPhong;
        char loaiPhong; // A, B, C
        int thoiGian; // Tinh theo ngay

    public:
        // Constructor & Deconstructor
        ThuePhong(){}
        ThuePhong(KhachThue*, int, char, int);
        ~ThuePhong();

        // Methods
        void nhapThongTin(ThuePhong& thuePhong);
        void themKhachThue(ThuePhong& thuePhong);
        int tongTienPhong() const;

        // Getter
        KhachThue* getKhachThue() const;
        int getMaPhong() const;
        char getLoaiPhong() const;
        int getThoiGian() const;
        int getGiaPhong() const;

        // Setter
        void setKhachThue(KhachThue*);
        void setMaPhong(int);
        void setLoaiPhong(char&);
        void setThoiGian(int);
};

ThuePhong::ThuePhong(KhachThue* khachThue, int maPhong, char loaiPhong, int thoiGian)
    : khachThue(khachThue), maPhong(maPhong), loaiPhong(loaiPhong), thoiGian(thoiGian) {
    // Constructor khoi tao
}

// Deconstructor
ThuePhong::~ThuePhong() {
    delete khachThue;
}

KhachThue* ThuePhong::getKhachThue() const {
    return khachThue;
}

int ThuePhong::getMaPhong() const {
    return maPhong;
} 

char ThuePhong::getLoaiPhong() const {
    return loaiPhong;
}

int ThuePhong::getThoiGian() const {
    return thoiGian;
}

int ThuePhong::getGiaPhong() const {
    switch (loaiPhong) {
    case 'a':
        return 500;
    case 'b':
        return 300;
    default:
        return 100;
    }
}

void ThuePhong::setKhachThue(KhachThue* khachThue) {
    this -> khachThue = khachThue;
}
void ThuePhong::setMaPhong(int maPhong) {
    this -> maPhong = maPhong;
} 
void ThuePhong::setLoaiPhong(char& loaiPhong) { 
    if ((loaiPhong >= 'A') && (loaiPhong <= 'Z')) loaiPhong += 32;
    if (loaiPhong < 'a' || loaiPhong > 'z') {
        std::cout << "Loai phong da chon khong ton tai.";
        return;
    }
    this -> loaiPhong = loaiPhong;
}

void ThuePhong::setThoiGian(int thoiGian) {
    this -> thoiGian = thoiGian;
}

int ThuePhong::tongTienPhong() const {
    return getGiaPhong() * getThoiGian();
}

void ThuePhong::nhapThongTin(ThuePhong& thuePhong) {
    std::cout << "Nhap thong tin phong thue:" << std::endl;
    char loaiPhong; 
    while (loaiPhong < 'a' || loaiPhong > 'c') {
        std::cout << "- Chon loai phong (A, B, C): ";
        std::cin >> loaiPhong;
        thuePhong.setLoaiPhong(loaiPhong);
    }
    std::cout << "- So phong: "; std::cin >> thuePhong.maPhong;
    std::cout << "- Thoi gian: "; std::cin >> thuePhong.thoiGian;
    std::cout << "- Them thong tin khach hang? (Y/N)";
    char confirm;
    do {
        std::cin >> confirm;
        if (std::cin.fail() || confirm != 'Y' || confirm != 'N') {
            std::cin.clear();
            std::cout << "Nhap gia tri khong dung yeu cau. Vui long nhap lai.";
        }
        if (confirm == 'Y') {
            
        }

    } while (confirm != 'Y' || confirm != 'N')
}

void ThuePhong::themKhachThue(ThuePhong& thuePhong) {
    
}

std::istream& operator>>(std::istream& inStream, ThuePhong& thuePhong) {
    thuePhong.nhapThongTin(thuePhong);
    return inStream;
}

std::ostream& operator<<(std::ostream& outStream, ThuePhong thuePhong) {
    std::cout << "Ma khach " << thuePhong.maPhong << ":" << std::endl
        << thuePhong.khachThue << std::endl
        << "- Loai phong: " << thuePhong.loaiPhong << std::endl
        << "- Thoi gian: " << thuePhong.thoiGian << " ngay" << std::endl;
    return outStream;
}

#endif