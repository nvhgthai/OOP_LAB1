#include <bits/stdc++.h>
using namespace std;

class Fraction {
private:
    int numerator, denominator;  // Khai bao tu so va mau so

public:
    // Constructor mac dinh
    Fraction() {
        numerator = 0;
        denominator = 1;
    }

    // Constructor co tham so
    Fraction(int n, int d) {
        numerator = n;
        denominator = d;
    }

    // Ham nhap gia tri phan so
    void input(){
        cout << "Nhap tu so va mau so ";
        cin >> numerator >> denominator;
    }

    // Ham kiem tra mau so
    bool KT() {
        return denominator != 0;
    }



    // Ham tra ve gia tri so thuc cua phan so
    double value() const {
        return static_cast<double>(numerator) / denominator;
    }

    // So sanh 2 phan so
    bool Sosanh(const Fraction& other) const {
        return value() > other.value();
    }

    // Ham in ra phan so
    void print() const {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Fraction fraction1, fraction2;

    // Nhap 2 phan so
    cout << "Nhap phan so dau tien: " << endl;
    fraction1.input();
    while (!fraction1.KT()) {
        cout << "Phan so khong hop le. Thu lai" << endl;
        fraction1.input();
    }

    cout << "Nhap phan so thu 2 " << endl;
    fraction2.input();
    while (!fraction2.KT()) {
        cout << "Phan so khong hop le. Thu lai." << endl;
        fraction2.input();
    }

    // So sanh
    cout << "Phan so lon hon la ";
    if (fraction1.Sosanh(fraction2)) {
        fraction1.print();
    } else {
        fraction2.print();
    }

    return 0;
}
