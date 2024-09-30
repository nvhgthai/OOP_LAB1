#include <bits/stdc++.h>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;
public:
    // Constructor mac dinh
    Fraction() : numerator(0), denominator(1) {}

    // Constructor co tham so
    Fraction(int n, int d) : numerator(n), denominator(d) {}

    // Ham nhap phan so
    void input() {
        cin >> numerator >> denominator;
    }

    // Ham kt phan so co hop le khong
    bool KT() const {
        return denominator != 0;
    }

    // Ham rut gon phan so
    void reduce() {
        int gcd = __gcd(numerator, denominator);
        if (numerator * denominator < 0) gcd = -gcd;
        numerator /= gcd;
        denominator /= gcd;
    }

    // Ham xuat ra man hinh
    void display() const {
        cout << numerator << "/" << denominator << endl;
    }

    // Ham tinh tong
    Fraction add(const Fraction& other) const {
        int newNumerator = numerator * other.denominator + denominator * other.numerator;
        int newDenominator = denominator * other.denominator;
        Fraction result(newNumerator, newDenominator);
        result.reduce();
        return result;
    }

    // Ham tinh hieu
    Fraction subtract(const Fraction& other) const {
        int newNumerator = numerator * other.denominator - denominator * other.numerator;
        int newDenominator = denominator * other.denominator;
        Fraction result(newNumerator, newDenominator);
        result.reduce();
        return result;
    }

    // Ham tinh tich
    Fraction multiply(const Fraction& other) const {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        Fraction result(newNumerator, newDenominator);
        result.reduce();
        return result;
    }

    // Ham tinh thuong
    Fraction divide(const Fraction& other) const {
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        Fraction result(newNumerator, newDenominator);
        result.reduce();
        return result;
    }
};

int main() {
    Fraction fraction1, fraction2;

    //Nhap phan so thu nhat
    cout << "Nhap phan so thu nhat: ";
    do {
        fraction1.input();
        if (!fraction1.KT()) {
            cout << "Phan so khong hop le, thu lai ";
        }
    } while (!fraction1.KT());

    //Nhap phan so thu 2
    cout << "Nhap phan so thu hai: ";
    do {
        fraction2.input();
        if (!fraction2.KT()) {
            cout << "Phan so khong hop le, thu lai ";
        }
    } while (!fraction2.KT());

    // Thuc hien phep toan
    Fraction sum = fraction1.add(fraction2);
    Fraction difference = fraction1.subtract(fraction2);
    Fraction product = fraction1.multiply(fraction2);
    Fraction quotient = fraction1.divide(fraction2);

    // Xuat ket qua
    cout << "Tong cua 2 phan so: ";
    sum.display();

    cout << "Hieu cua 2 phan so: ";
    difference.display();

    cout << "Tich cua 2 phan so: ";
    product.display();

    cout << "Thuong cua 2 phan so: ";
    quotient.display();

    return 0;
}
