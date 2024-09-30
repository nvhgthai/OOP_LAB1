#include <bits/stdc++.h>
using namespace std;

// Ham tinh gia tri hash cua mot mang con
long long computeHash(const vector<long long>& arr, int start, int length, long long base) {
    long long hashValue = 0;
    for (int i = start; i < start + length; i++) {
        hashValue = hashValue * base + arr[i];
    }
    return hashValue;
}

// Ham dem so lan mang A xuat hien lien tiep trong mang B bang phuong phap hashing
vector<int> countOccurrences(const vector<long long>& A, const vector<long long>& B, long long base) {
    int n = A.size();
    int m = B.size();

    // Tinh hash cho mang A
    long long hashA = computeHash(A, 0, n, base);

    // Vector luu cac luy thua cua base de tinh hash cuon
    vector<long long> basePowers(n, 1);
    for (int i = 1; i < n; i++) {
        basePowers[i] = basePowers[i - 1] * base;
    }

    // Tinh hash cho n-1 phan tu dau tien cua B
    long long currentHashB = computeHash(B, 0, n - 1, base);

    // Vector luu cac vi tri bat dau cua su xuat hien cua A trong B
    vector<int> startIndices;

    // Su dung thuat toan hash cuon de tim kiem
    for (int i = n - 1; i < m; i++) {
        // Them phan tu tiep theo vao hash cua mang B
        currentHashB = currentHashB * base + B[i];

        // Kiem tra xem hash cua mang A co trung voi hash cua doan tuong ung trong B hay khong
        if (currentHashB == hashA) {
            startIndices.push_back(i - n + 1); // Luu vi tri bat dau
        }

        // Loai bo phan tu dau tien trong cua so ra khoi hash cua mang B
        currentHashB -= basePowers[n - 1] * B[i - n + 1];
    }

    return startIndices;
}

int main() {
    int sizeA, sizeB;

    // Nhap kich thuoc cua mang A va B
    cin >> sizeA >> sizeB;

    // Khoi tao mang A va B
    vector<long long> arrayA(sizeA), arrayB(sizeB);

    // Nhap du lieu cho mang A
    for (long long &element : arrayA) {
        cin >> element;
    }

    // Nhap du lieu cho mang B
    for (long long &element : arrayB) {
        cin >> element;
    }

    // Chon mot gia tri base lon
    long long base = 1e18;

    // Tinh so lan mang A xuat hien lien tiep trong mang B
    vector<int> occurrences = countOccurrences(arrayA, arrayB, base);

    // Xuat so luong xuat hien va cac chi so
    cout << occurrences.size() << '\n';
    for (int index : occurrences) {
        cout << index << ' ';
    }

    return 0;
}
