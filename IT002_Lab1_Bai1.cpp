#include <bits/stdc++.h>
using namespace std;

class Fraction {
private:
    int numerator, denominator;
public:
    // Cau truc voi gia tri mac đinh
    Fraction() {
        numerator = 0;
        denominator = 1;
    }

    // Cau truc voi tham so
    Fraction(int n, int d) {
        numerator = n;
        denominator = d;
    }

    // Ham nhap phan sa
    void input() {
        cin >> numerator >> denominator;
    }

    // Ham kiem tra mau co = 0 khong
    bool KT() {
        return denominator != 0;
    }

    // Ham rut gon phan so
    void Shorted() {
        int gcd = __gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    // In ra man hinh phan so da duoc rut gon
    void output() {
        cout << "Phan so da rut gon la: " << numerator << "/" << denominator << endl;
    }
};

int main() {
    Fraction fraction;

    cout << "Nhap vao mot phan so: ";
    while(true) {
        fraction.input();
        if(fraction.KT()) {
            break;
        }
        cout << "Nhap lai mau so, mau so khong the bang 0";
    }

    fraction.Shorted();
    fraction.output();
    return 0;
}
