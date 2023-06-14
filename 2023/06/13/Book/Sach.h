// Li
// 2023 - 06 - 12

// Prevent conflict with other implementations
#ifndef LI_BOOK_SACH
#define LI_BOOK_SACH

#include <string>
#include <iostream>

class Sach {
    friend std::ostream& operator<<(std::ostream&, Sach&);
    friend std::istream& operator>>(std::istream&, Sach&);

    private:
        int ID;
        std::string tenSach;
        std::string tacGia;
        int namXuatBan;
        std::string nhaXuatBan;
    public:
        Sach(int = 0, std::string  = "Placeholder", std::string  = "", int = 0, std::string  = "");

        int getID();
        std::string getTenSach();
        std::string getTacGia();
        int getNamXuatBan();
        std::string getNhaXuatBan();

        void setID(int);
        void setTenSach(std::string);
        void setTacGia(std::string);
        void setNamXuatBan(int);
        void setNhaXuatBan(std::string);

        void Nhap();

        void Xuat();
};

Sach::Sach(int ID, std::string tenSach, std::string tenTacGia, int namXuatBan, std::string tenNhaXuatBan)
    : ID(ID), tenSach(tenSach), tacGia(tenTacGia), namXuatBan(namXuatBan), nhaXuatBan(tenNhaXuatBan) {
    // implementation
}

int Sach::getID() {
    return ID;
}

std::string Sach::getTenSach() {
    return tenSach;
}

std::string Sach::getTacGia() {
    return tacGia;
}

int Sach::getNamXuatBan() {
    return namXuatBan;
}

std::string Sach::getNhaXuatBan() {
    return nhaXuatBan;
}

void Sach::setID(int ID) {
    this -> ID = ID;
}

void Sach::setTenSach(std::string tenSach) {
    this -> tenSach = tenSach;
}

void Sach::setTacGia(std::string tenTacGia) {
    this -> tacGia = tenTacGia;
}

void Sach::setNamXuatBan(int namXuatBan) {
    this -> namXuatBan = namXuatBan;
}

void Sach::setNhaXuatBan(std::string tenNhaXuatBan) {
    this -> nhaXuatBan = tenNhaXuatBan;
}

void Sach::Nhap() {
    std::cout << std::endl; // Create space for easy reading (can use symbol but seems like it doesn't look that good)
    std::cout << "Nhap ID: "; std::cin >> ID;
    std::cin.ignore(); // Remove \n residue
    std::cout << "Nhap ten sach: "; std::getline(std::cin, tenSach);
    std::cout << "Nhap ten tac gia: "; std::getline(std::cin, tacGia);
    std::cout << "Nhap nam xuat ban: "; std::cin >> namXuatBan;
    std::cin.ignore(); // Remove \n residue
    std::cout << "Nhap ten nha xuat ban: "; std::getline(std::cin, nhaXuatBan);
}

void Sach::Xuat() {
    std::cout << std::endl // Create space for easy reading (can use symbol but seems like it doesn't look that good)
        << "ID: " << ID << std::endl
        << "Ten sach: " << tenSach << std::endl
        << "Tac gia: " << tacGia << std::endl
        << "Nam xuat ban: " << namXuatBan << std::endl
        << "Nha xuat ban: " << nhaXuatBan << std::endl;
}

std::ostream& operator<<(std::ostream& outStream, Sach& sach) {
    sach.Xuat();
    return outStream;
}

std::istream& operator>>(std::istream& inStream, Sach& sach) {
    sach.Nhap();
    return inStream;
}

#endif