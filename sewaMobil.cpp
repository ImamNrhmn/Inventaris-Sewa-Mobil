#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
using namespace std;

struct Mobil {
    int id;
    string merk;
    string tipe;
    int tahun;
    bool disewa;
    Mobil* next;
};

// Fungsi untuk membuat garis menu
void garis(int n = 50) {
    for (int i = 0; i < n; ++i) cout << "=";
    cout << endl;
}

// Fungsi untuk menampilkan header menu
void headerMenu() {
    system("cls");
    garis();
    cout << setw(30) << "INVENTARIS SEWA MOBIL" << endl;
    garis();
}

int main() {
    cout << "Hello, world!" << endl;
    return 0;
}