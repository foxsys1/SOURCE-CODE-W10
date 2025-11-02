#include <bits/stdc++.h>
using namespace std;

const int JUMLAH_SISWA = 20;

struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

string padRight(const string &s, int w) {
    if ((int)s.size() >= w) return s;
    return s + string(w - (int)s.size(), ' ');
}

void bacaData(studentType arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Nama depan " << i+1 << ": ";
        cin >> arr[i].studentFName;
        cout << "Nama belakang " << i+1 << ": ";
        cin >> arr[i].studentLName;
        int v = -1;
        do {
            cout << "Nilai (0-100): ";
            cin >> v;
            if (v < 0 || v > 100) cout << "Nilai tidak valid\n";
        } while (v < 0 || v > 100);
        arr[i].testScore = v;
    }
}

void beriGrade(studentType arr[], int n) {
    for (int i = 0; i < n; ++i) {
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
    for (int i = 1; i < n; ++i) if (arr[i].testScore > maks) maks = arr[i].testScore;
    return maks;
}

void cetakNamaTertinggi(studentType arr[], int n, int tertinggi) {
    cout << "Siswa dengan nilai " << tertinggi << ":\n";
    for (int i = 0; i < n; ++i)
        if (arr[i].testScore == tertinggi)
            cout << arr[i].studentLName << ", " << arr[i].studentFName << '\n';
}

void cetakSemua(studentType arr[], int n) {
    cout << "Nama (belakang, depan)         Nilai  Grade\n";
    for (int i = 0; i < n; ++i) {
        string nama = arr[i].studentLName + ", " + arr[i].studentFName;
        cout << padRight(nama, 30) << arr[i].testScore << "     " << arr[i].grade << '\n';
    }
}

int main() {
    studentType kelas[JUMLAH_SISWA];
    bacaData(kelas, JUMLAH_SISWA);
    beriGrade(kelas, JUMLAH_SISWA);
    cetakSemua(kelas, JUMLAH_SISWA);
    int tertinggi = cariNilaiTertinggi(kelas, JUMLAH_SISWA);
    cout << "\nNilai tertinggi = " << tertinggi << '\n';
    cetakNamaTertinggi(kelas, JUMLAH_SISWA, tertinggi);
    return 0;
}
