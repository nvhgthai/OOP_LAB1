#include <bits/stdc++.h>
using namespace std;

struct Student {
    string fullName;  // Ten hoc sinh
    float mathScore;  // Diem Toan
    float litScore;   // Diem Van
    float engScore;   // Diem Anh
    double avgScore;  // Diem trung binh

    // Ham kiem tra tinh hop le cua ten hoc sinh
    bool isValidName(const string &name) {
        if (name.length() > 50) return false;

        bool isNewWord = true; // Danh dau vi tri bat dau cua tu moi

        for (char c : name) {
            if (isspace(c)) {
                if (isNewWord) return false; // Tranh truong hop co hai khoang trang lien tiep
                isNewWord = true; // Bat dau tu moi sau dau cach
            } else {
                if (!isalpha(c)) return false; // Kiem tra ky tu khong phai chu cai
                if (isNewWord) {
                    if (!isupper(c)) return false; // Chu cai dau phai viet hoa
                    isNewWord = false; // Danh dau da vuot qua chu dau
                } else {
                    if (!islower(c)) return false; // Cac chu con lai phai viet thuong
                }
            }
        }
        return true;
    }

    // Ham kiem tra diem co hop le khong
    bool isValidScore(float score) {
        return (score >= 0.0 && score <= 10.0);
    }

    // Nhap thong tin hoc sinh
    void input() {
        cout << "Nhap ten khong qua 50 ky tu, chu cai dau viet hoa va chi chua chu cai tieng Anh:\n";
        getline(cin, this->fullName);
        while (!isValidName(this->fullName)) {
            cout << "Ten khong hop le. Vui long nhap lai:\n";
            getline(cin, this->fullName);
        }

        cout << "Nhap diem Toan: ";
        cin >> this->mathScore;
        while (!isValidScore(this->mathScore)) {
            cout << "Diem khong hop le. Vui long nhap lai:\n";
            cin >> this->mathScore;
        }

        cout << "Nhap diem Van: ";
        cin >> this->litScore;
        while (!isValidScore(this->litScore)) {
            cout << "Diem khong hop le. Vui long nhap lai:\n";
            cin >> this->litScore;
        }

        cout << "Nhap diem Anh: ";
        cin >> this->engScore;
        while (!isValidScore(this->engScore)) {
            cout << "Diem khong hop le. Vui long nhap lai:\n";
            cin >> this->engScore;
        }
    }

    // Ham xep loai dua tren diem trung binh
    string rank(double avg) {
        if (avg >= 9.0) return "Xuat Sac";
        if (avg >= 8.0) return "Gioi";
        if (avg >= 6.5) return "Kha";
        if (avg >= 5.0) return "Trung Binh";
        return "Yeu";
    }

    // Xuat thong tin hoc sinh
    void display() {
        cout << this->fullName << ", " << this->mathScore << ", " << this->litScore << ", " << this->engScore << '\n';
        this->avgScore = (this->mathScore * 2.0 + this->litScore + this->engScore) / 4.0; // Tinh diem trung binh
        cout << "Diem trung binh: " << fixed << setprecision(3) << this->avgScore << '\n';
        cout << "Xep loai: " << rank(this->avgScore) << '\n';
    }
};

vector<Student> students(3); // Danh sach hoc sinh
Student highestAvgStudent;   // Hoc sinh co diem trung binh cao nhat

int main() {
    // Nhap thong tin hoc sinh
    for (auto &student : students) {
        student.input();
        cin.ignore(); // Bo qua ky tu xuong dong
    }

    cout << "Bang thong tin hoc sinh:\n";
    for (auto student : students) {
        student.display();
        if (student.avgScore > highestAvgStudent.avgScore) {
            highestAvgStudent = student; // Cap nhat hoc sinh co diem cao nhat
        }
    }

    cout << "Hoc sinh co diem trung binh cao nhat:\n";
    cout << highestAvgStudent.fullName << ' ' << highestAvgStudent.avgScore << '\n';

    // Tra cuu thong tin hoc sinh theo ten
    cin.ignore();
    cout << "Nhap ten de tra cuu:\n";
    string searchName;
    getline(cin, searchName);
    while (!students[0].isValidName(searchName)) {
        cout << "Ten khong hop le. Vui long nhap lai:\n";
        getline(cin, searchName);
    }

    cout << "Ket qua tra cuu:\n";
    for (auto student : students) {
        if (student.fullName == searchName) {
            student.display();
        }
    }
    cout << '\n';

    // Tim diem Toan thap nhat
    float minMathScore = 10;
    for (auto student : students) {
        minMathScore = min(minMathScore, student.mathScore);
    }

    cout << "Diem Toan thap nhat la: " << minMathScore << '\n';
    cout << "Hoc sinh co diem Toan thap nhat:\n";
    for (auto student : students) {
        if (student.mathScore == minMathScore) {
            cout << student.fullName << '\n';
        }
    }

    return 0;
}
