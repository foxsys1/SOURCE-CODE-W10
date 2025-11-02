#include <bits/stdc++.h>
using namespace std;

const int JUMLAH_SISWA = 20;

struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

void bacaData(studentType arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nama depan " << i + 1 << ": ";
        cin >> arr[i].studentFName;
        cout << "Nama belakang " << i + 1 << ": ";
        cin >> arr[i].studentLName;
        int nilai;
        do {
            cout << "Nilai (0-100): ";
            cin >> nilai;
            if (nilai < 0 || nilai > 100) cout << "Nilai tidak valid\n";
        } while (nilai < 0 || nilai > 100);
        arr[i].testScore = nilai;
    }
}

void beriGrade(studentType arr[], int n) {
    for (int i = 0; i < n; i++) {
        int t = arr[i].testScore;
        if (t >= 90) arr[i].grade = 'A';
        else if (t >= 80) arr[i].grade = 'B';
        else if (t >= 70) arr[i].grade = 'C';
        else if (t >= 60) arr[i].grade = 'D';
        else arr[i].grade = 'F';
    }
}

int cariNilaiTertinggi(studentType arr[], int n) {
    int maks = arr[0].testScore;
    for (int i = 1; i < n; i++) {
        if (arr[i].testScore > maks) maks = arr[i].testScore;
    }
    return maks;
}

void cetakNamaTertinggi(studentType arr[], int n, int tertinggi) {
    cout << "Siswa dengan nilai tertinggi (" << tertinggi << "):\n";
    for (int i = 0; i < n; i++) {
        if (arr[i].testScore == tertinggi)
            cout << arr[i].studentLName << ", " << arr[i].studentFName << endl;
    }
}

void cetakSemua(studentType arr[], int n) {
    cout << "\nNama (belakang, depan)   Nilai   Grade\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].studentLName << ", " << arr[i].studentFName
             << "   " << arr[i].testScore << "     " << arr[i].grade << endl;
    }
}

int main() {
    studentType kelas[JUMLAH_SISWA];
    bacaData(kelas, JUMLAH_SISWA);
    beriGrade(kelas, JUMLAH_SISWA);
    cetakSemua(kelas, JUMLAH_SISWA);
    int tertinggi = cariNilaiTertinggi(kelas, JUMLAH_SISWA);
    cout << "\nNilai tertinggi = " << tertinggi << endl;
    cetakNamaTertinggi(kelas, JUMLAH_SISWA, tertinggi);
    return 0;
}
