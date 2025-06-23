#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

struct Mobil {
    int id;
    string merk;
    string tipe;
    int tahun;
    bool disewa;
    Mobil* next;
};

Mobil* head = nullptr;
int idCounter = 1;

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

void tambahMobil() {
    headerMenu();
    cout << "Tambah Data Mobil\n";
    garis();
    Mobil* baru = new Mobil;
    baru->id = idCounter++;
    cout << "Merk Mobil   : "; getline(cin >> ws, baru->merk);
    cout << "Tipe Mobil   : "; getline(cin, baru->tipe);
    cout << "Tahun        : "; cin >> baru->tahun;
    baru->disewa = false;
    baru->next = nullptr;

    if (!head) {
        head = baru;
    } else {
        Mobil* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = baru;
    }
    cout << "Data mobil berhasil ditambahkan!\n";
    system("pause");
}

int main() {
    cout << "Hello, world!" << endl;
    return 0;
}