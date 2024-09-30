#include <bits/stdc++.h>
using namespace std;

// Cau truc luu ngay
struct Date {
    int day, month, year;

    Date(int d = 1, int m = 1, int y = 1) : day(d), month(m), year(y) {
        if (!isValid()) {
            throw invalid_argument("Ngay khong hop le");
        }
    }

    bool isLeapYear() const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    bool isValid() const {
        if (month < 1 || month > 12 || day < 1 || year < 1) return false;
        if (month == 2) return (isLeapYear() ? day <= 29 : day <= 28);
        if (month == 4 || month == 6 || month == 9 || month == 11) return day <= 30;
        return day <= 31;
    }

    bool operator<(const Date& other) const {
        return (year < other.year) || (year == other.year && (month < other.month || (month == other.month && day < other.day)));
    }

    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }
};

// Cau truc luu gio
struct Time {
    int hour, minute;

    Time(int h = 0, int m = 0) : hour(h), minute(m) {
        if (!isValid()) {
            throw invalid_argument("Gio khong hop le");
        }
    }

    bool isValid() const {
        return (hour >= 0 && hour < 24) && (minute >= 0 && minute < 60);
    }

    bool operator<(const Time& other) const {
        return (hour < other.hour) || (hour == other.hour && minute < other.minute);
    }
};

// Cau truc luu chuyen bay
struct Flight {
    string code;
    Date departureDate;
    Time departureTime;
    string departurePlace;
    string arrivalPlace;

    Flight(const string& c, const Date& d, const Time& t, const string& dep, const string& arr)
        : code(c), departureDate(d), departureTime(t), departurePlace(dep), arrivalPlace(arr) {}
};

// Ham hien thi danh sach chuyen bay
void displayFlights(const vector<Flight>& flights) {
    for (const auto& flight : flights) {
        cout << "Ma: " << flight.code;
        cout << ", Ngay: " << flight.departureDate.day << "/" << flight.departureDate.month << "/" << flight.departureDate.year;
        cout << ", Gio: " << flight.departureTime.hour << "h " << flight.departureTime.minute << "m";
        cout << ", Noi di: " << flight.departurePlace;
        cout << ", Noi den: " << flight.arrivalPlace << '\n';
    }
}

// Ham dem so chuyen bay tu noi di den noi den
int countFlights(const vector<Flight>& flights, const string& from, const string& to) {
    int count = 0;
    for (const auto& flight : flights) {
        if (flight.departurePlace == from && flight.arrivalPlace == to) {
            count++;
        }
    }
    return count;
}

// Ham tim cac chuyen bay tu mot noi di cu the
vector<Flight> findFlights(const vector<Flight>& flights, const string& place) {
    vector<Flight> result;
    for (const auto& flight : flights) {
        if (flight.departurePlace == place) {
            result.push_back(flight);
        }
    }
    return result;
}

int main() {
    vector<Flight> flightList;
    int flightCount;

    // Nhap so luong chuyen bay
    cout << "Nhap so luong chuyen bay: ";
    cin >> flightCount;
    cin.ignore(); // Loai bo ky tu xuong dong con lai sau khi nhap so luong chuyen bay

    // Nhap thong tin cac chuyen bay
    for (int i = 0; i < flightCount; ++i) {
        string code, departurePlace, arrivalPlace;
        int day, month, year, hour, minute;

        cout << "Nhap ma chuyen bay: ";
        getline(cin, code);

        cout << "Nhap ngay khoi hanh (ngay thang nam): ";
        cin >> day >> month >> year;

        cout << "Nhap gio khoi hanh (gio phut): ";
        cin >> hour >> minute;
        cin.ignore(); // Loai bo ky tu xuong dong

        cout << "Nhap noi khoi hanh: ";
        getline(cin, departurePlace);

        cout << "Nhap noi den: ";
        getline(cin, arrivalPlace);

        try {
            Flight flight(code, Date(day, month, year), Time(hour, minute), departurePlace, arrivalPlace);
            flightList.push_back(flight);
        } catch (const invalid_argument& e) {
            cout << e.what() << '\n';
            --i; // Giam i de nhap lai chuyen bay
        }
    }

    // Hien thi danh sach chuyen bay
    cout << "Danh sach chuyen bay:\n";
    displayFlights(flightList);

    // Tim kiem chuyen bay theo noi khoi hanh
    string searchPlace;
    cout << "Nhap noi khoi hanh de tim: ";
    getline(cin, searchPlace);
    vector<Flight> foundFlights = findFlights(flightList, searchPlace);

    // Hien thi ket qua tim kiem
    displayFlights(foundFlights);

    // Dem so chuyen bay tu noi di den noi den
    string fromPlace, toPlace;
    cout << "Nhap noi khoi hanh: ";
    getline(cin, fromPlace);
    cout << "Nhap noi den: ";
    getline(cin, toPlace);
    int numberOfFlights = countFlights(flightList, fromPlace, toPlace);

    // Hien thi so luong chuyen bay
    cout << "So luong chuyen bay tu " << fromPlace << " den " << toPlace << ": " << numberOfFlights << '\n';

    return 0;
}
