#include <iostream>
#include <String>

using namespace std;

int main() {
    string ketqua;
    unsigned int a, b, c;
    cout<<"Nhap do dai 3 canh a b c: ";
    cin>>a>>b>>c;
    if ( a + b > c && a + c > b && b + c > a) {
        if ( a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
            if (a == b || a == c || b == c) ketqua = "Day la 3 canh cua tam giac vuong can.";
            else ketqua = "Day la 3 canh cua tam giac vuong.";
        } 
        else if (a == b && a == c && b == c) ketqua = "Day la 3 canh cua tam giac deu.";
        else if (a == b ^ a == c ^ b == c) ketqua = "Day la 3 canh cua tam giac can.";
        else ketqua = "Day la 3 canh cua mot tam giac.";
    } else ketqua = "Day khong phai la 3 canh cua mot tam giac.";
    cout<<ketqua;
}