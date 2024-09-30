#include <bits/stdc++.h>
using namespace std;

// Cau truc 1 ngay
struct Date {
    int day;
    int month;
    int year;
};

// Ham kiem tra nam nhuan
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Ham tra ve so thang trong 1 nam
int daysInMonth(int month, int year) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29; // Thang 2 nam nhuan
    }
    return days[month];
}

// Ham tim ngay tiep theo
Date nextDay(Date current) {
    current.day++;
    if (current.day > daysInMonth(current.month, current.year)) {
        current.day = 1;
        current.month++;
        if (current.month > 12) {
            current.month = 1;
            current.year++;
        }
    }
    return current;
}

// Ham tim ngay phia truoc
Date previousDay(Date current) {
    current.day--;
    if (current.day == 0) {
        current.month--;
        if (current.month == 0) {
            current.month = 12;
            current.year--;
        }
        current.day = daysInMonth(current.month, current.year);
    }
    return current;
}

// Ham tinh so thu tu cua ngay
int dayOfYear(Date date) {
    int dayOfYearCount = date.day;
    for (int i = 1; i < date.month; i++) {
        dayOfYearCount += daysInMonth(i, date.year);
    }
    return dayOfYearCount;
}

int main() {
    Date date;
    cout << "Nhap ngay thang nam: ";
    cin >> date.day >> date.month >> date.year;

    Date followingDate = nextDay(date);
    Date previousDate = previousDay(date);
    int dayOrder = dayOfYear(date);

    cout << "Ngay tiep theo: " << followingDate.day << "/" << followingDate.month << "/" << followingDate.year << endl;
    cout << "Ngay truoc do: " << previousDate.day << "/" << previousDate.month << "/" << previousDate.year << endl;
    cout << "Ngay thu " << dayOrder << " trong nam" << endl;

    return 0;
}
