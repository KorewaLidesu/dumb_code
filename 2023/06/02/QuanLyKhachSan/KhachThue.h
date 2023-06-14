// Li
// 2023 - 06 - 02

// Prevent conflict with other implementations
#ifndef LI_KHACHTHUE
#define LI_KHACHTHUE

// Include necessary lib
#include <string>
#include <iostream>
#include <exception>

class KhachThue
{
    friend std::istream& operator>>(std::istream&, KhachThue&);
    friend std::ostream& operator<<(std::ostream&, KhachThue);

    private:
        std::string hoTen;
        int tuoi;
        int soCMND;

    public:
        // Constructor
        KhachThue(std::string = "", int = 0, int = 0);

        // Methods
        void kiemTra();

        // Getter
        std::string getHoTen();
        int getTuoi();
        int getSoCMND();
};

KhachThue::KhachThue(std::string hoTen, int tuoi, int soCMND)
    : hoTen(hoTen), tuoi(tuoi), soCMND(soCMND)
{
    kiemTra();
}

std::string KhachThue::getHoTen()
{
    return hoTen;
}

int KhachThue::getTuoi()
{
    return tuoi;
}

int KhachThue::getSoCMND()
{
    return soCMND;
}

void KhachThue::kiemTra() // Kiem tra neu du lieu dau vao khong dung voi yeu cau
{
    std::string error;
    if (tuoi < 0) error += "Tuoi duoc nhap khong dung voi yeu cau";
    if (soCMND < 0) error += "\nSo CMND duoc nhap khong dung voi yeu cau";
    if (!error.empty()) throw std::runtime_error(error);
}

std::istream& operator>>(std::istream& inStream, KhachThue& khachThue)
{
    std::cout << "- Nhap thong tin khach hang: " << std::endl;
    std::cout << "+ Ho va ten: "; std::getline(std::cin, khachThue.hoTen);
    std::cout << "+ Tuoi: "; inStream >> khachThue.tuoi;
    std::cout << "+ So CMND: "; inStream >> khachThue.soCMND;
    khachThue.kiemTra();
    return inStream;
}

std::ostream& operator<<(std::ostream& outStream, KhachThue khachThue)
{
    outStream << "- Thong tin khach hang:" << std::endl
        << "+ Ho va ten: " << khachThue.hoTen << std::endl
        << "+ Tuoi (YC: >0): " << khachThue.tuoi << std::endl
        << "+ So CMND (YC: >0): " << khachThue.soCMND << std::endl;
    return outStream;
}

#endif