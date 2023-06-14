#include<algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AnPham {
protected:
    long maAnPham;
    string tenNhaXB;
    int soLuong;
public:
    AnPham(long maAnPham = 0, string tenNhaXB = "a", int soLuong = 0) {
        this->maAnPham = maAnPham;
        this->tenNhaXB = tenNhaXB;
        this->soLuong = soLuong;
    }
    long getMaAnPham() {
        return maAnPham;
    }
    string getTenNhaXB() {
        return tenNhaXB;
    }
    int getSoLuong() {
        return soLuong;
    }
    virtual void Xuat() {
        cout << "Ma An Pham: " << maAnPham << endl;
        cout << "Ten Nha XB: " << tenNhaXB << endl;
        cout << "So Luong: " << soLuong << endl;
    }
    virtual void Nhap() {
        cout << "Ma An Pham: ";
        cin >> maAnPham;
        cout << "Ten Nha XB: ";
        cin >> tenNhaXB;
        cout << "So Luong: ";
        cin >> soLuong;
    }
};

class Sach : public AnPham {
private:
    string tenTacGia;
    int soTrang;
public:
    Sach(long maAnPham = 0, string tenNhaXB = "a", int soLuong = 0, string tenTacGia = "b",
        int soTrang = 0) : AnPham(maAnPham, tenNhaXB, soLuong) {
        this->tenTacGia = tenTacGia;
        this->soTrang = soTrang;
    }
    string getTenTacGia() {
        return tenTacGia;
    }
    int getSoTrang() {
        return soTrang;
    }
    void Nhap() {
        AnPham::Nhap();
        cout << "Ten Tac Gia: ";
        cin >> tenTacGia;
        cout << "So Trang: ";
        cin >> soTrang;
    }
    void Xuat() {
        AnPham::Xuat();
        cout << "Ten Tac Gia: " << tenTacGia << endl;
        cout << "So Trang: " << soTrang << endl;
    }
};

class TapChi : public AnPham {
private:
    long soPhatHanh;
    int thangPhatHanh;
public:
    TapChi(long maAnPham = 0, string tenNhaXB = "a", int soLuong = 0, long soPhatHanh = 0,
        int thangPhatHanh = 0) : AnPham(maAnPham, tenNhaXB, soLuong) {
        this->soPhatHanh = soPhatHanh;
        this->thangPhatHanh = thangPhatHanh;
    }
    long getSoPhatHanh() {
        return soPhatHanh;
    }
    int getThangPhatHanh() {
        return thangPhatHanh;
    }
    void Nhap() {
        AnPham::Nhap();
        cout << "So Phat Hanh: ";
        cin >> soPhatHanh;
        cout << "Thang Phat Hanh: ";
        cin >> thangPhatHanh;
    }
    void Xuat() {
        AnPham::Xuat();
        cout << "So Phat Hanh: " << soPhatHanh << endl;
        cout << "Thang Phat Hanh: " << thangPhatHanh << endl;
    }
};

class Bao : public AnPham {
private:
    string tieuDe;
    int ngayPhatHanh;
public:
    Bao(long maAnPham = 0, string tenNhaXB = "a", int soLuong = 0, string tieuDe = "b",
        int ngayPhatHanh = 0) : AnPham(maAnPham, tenNhaXB, soLuong) {
        this->tieuDe = tieuDe;
        this->ngayPhatHanh = ngayPhatHanh;
    }
    string getTieuDe() {
        return tieuDe;
    }
    int getNgayPhatHanh() {
        return ngayPhatHanh;
    }
    void Nhap() {
        AnPham::Nhap();
        cout << "Tieu De: ";
cin >> tieuDe;
        cout << "Ngay Phat Hanh: ";
        cin >> ngayPhatHanh;
    }
    void Xuat() {
        AnPham::Xuat();
        cout << "Tieu De: " << tieuDe << endl;
        cout << "Ngay Phat Hanh: " << ngayPhatHanh << endl;
    }
};

class QuanLyAnPham {
private:
    vector<AnPham*> ds;
public:
    void Menu() {
        int luachon;
        do {
            cout << "1. Them An Pham" << endl;
            cout << "2. Xoa An Pham" << endl;
            cout << "3. Xem An Pham" << endl;
            cout << "4. sua an pham" << endl;
            cout << "5. Thoat" << endl;
            cout << "Moi ban chon: ";
            cin >> luachon;
            switch (luachon)
            {
            case 1:
            {
                int loaiAnPham;
                cout << "Nhap loai an pham (1: Sach, 2: Tap Chi, 3: Bao): ";
                cin >> loaiAnPham;
                AnPham* ap;
                switch (loaiAnPham)
                {
                case 1:
                    ap = new Sach();
                    break;
                case 2:
                    ap = new TapChi();
                    break;
                case 3:
                    ap = new Bao();
                    break;
                default:
                    cout << "Loai an pham khong hop le" << endl;
                    continue;
                }
                ap->Nhap();
                ds.push_back(ap);
                break;
            }
            case 2:
            {
                long maAnPham;
                cout << "Nhap ma an pham can xoa: ";
                cin >> maAnPham;
                bool found = false;
                for (int i = 0; i < ds.size(); i++) {
                    if (ds[i]->getMaAnPham() == maAnPham) {
                        found = true;
                        ds.erase(ds.begin() + i);
                        i--;
                    }
                }
                if (!found) {
                    cout << "Khong tim thay an pham co ma " << maAnPham << endl;
                }
                break;
            }
            case 3:
            {
                for (int i = 0; i < ds.size(); i++) {
                    ds[i]->Xuat();
                    cout << endl;
                }
                break;
            }
            case 4:
            {
                long maAnPham;
                cout << "Nhap ma an pham can sua: ";
                cin >> maAnPham;
                bool found = false;
                for (int i = 0; i < ds.size(); i++) {
                    if (ds[i]->getMaAnPham() == maAnPham) {
                        found = true;
                        ds[i]->Nhap();
                        break;
                    }
                }
            }
                case 5:
           cout << "Tam biet!" << endl;
          break;
              default:
          cout << "Lua chon khong hop le" << endl;
          break;
        }
         } while (luachon != 5);
        }
   };
   int main() {
QuanLyAnPham q;
    q.Menu();
    return 0;
}