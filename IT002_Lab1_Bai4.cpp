#include <bits/stdc++.h>
using namespace std;

// Ham tinh sin(x) theo Taylor
double calculateSine(double x) {
    double term = x;  // Gia tri dau tien cua chuoi Taylor
    double result = term; // Tong ban dau la gia tri dau tien
    int n = 1; // Bat dau n=1

    // Lap cho den khi gia tri hang tu nho hon gia tri yeu cau
    while (fabs(term) >= 0.00001) {
        term *= -x * x / ((2 * n) * (2 * n + 1)); // Tinh gia tri hang tu tiep theo
        result += term; //Cong hang tu vao tong
        n++;
    }
    return result;
}

int main() {
    double x;

    // Nhap gia tri x
    cout << "Nhap gia tri x ";
    cin >> x;

    // Goi ham tinh sin(x)
    double sineValue = calculateSine(x);

    // In ra ket qua
    cout << "sin(" << x << ") = " << sineValue << endl;

    return 0;
}
