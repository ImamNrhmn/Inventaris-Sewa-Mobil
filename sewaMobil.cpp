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

// Fungsi untuk menampilkan semua mobil
void tampilMobil(bool tampilSemua = true, bool status = false) {
    headerMenu();
    if (tampilSemua)
        cout << "Daftar Semua Mobil\n";
    else
        cout << (status ? "Daftar Mobil Disewa\n" : "Daftar Mobil Tersedia\n");
    garis();
    cout << left << setw(5) << "ID" << setw(15) << "Merk" << setw(15) << "Tipe" << setw(8) << "Tahun" << setw(12) << "Status" << endl;
    garis();
    Mobil* temp = head;
    bool ada = false;
    while (temp) {
        if (tampilSemua || temp->disewa == status) {
            cout << left << setw(5) << temp->id
                 << setw(15) << temp->merk
                 << setw(15) << temp->tipe
                 << setw(8) << temp->tahun
                 << setw(12) << (temp->disewa ? "Disewa" : "Tersedia") << endl;
            ada = true;
        }
        temp = temp->next;
    }
    if (!ada) cout << "Tidak ada data mobil.\n";
    garis();
    system("pause");
}

// Fungsi untuk menandai mobil sebagai disewa/dikembalikan
void updateStatusMobil() {
    headerMenu();
    cout << "Tandai Mobil Disewa/Dikembalikan\n";
    garis();
    tampilMobil();
    cout << "Masukkan ID mobil: ";
    int id; cin >> id;
    Mobil* temp = head;
    while (temp && temp->id != id) temp = temp->next;
    if (!temp) {
        cout << "Mobil tidak ditemukan!\n";
    } else {
        cout << "Status saat ini: " << (temp->disewa ? "Disewa" : "Tersedia") << endl;
        cout << "Ubah status menjadi (1: Disewa, 0: Tersedia): ";
        int st; cin >> st;
        temp->disewa = (st == 1);
        cout << "Status berhasil diubah!\n";
    }
    system("pause");
}

// Fungsi untuk mencari mobil berdasarkan merk
void cariMobil() {
    headerMenu();
    cout << "Cari Mobil Berdasarkan Merk\n";
    garis();
    cout << "Masukkan merk mobil: ";
    string merkCari;
    getline(cin >> ws, merkCari);
    Mobil* temp = head;
    bool ada = false;
    garis();
    cout << left << setw(5) << "ID" << setw(15) << "Merk" << setw(15) << "Tipe" << setw(8) << "Tahun" << setw(12) << "Status" << endl;
    garis();
    while (temp) {
        if (temp->merk.find(merkCari) != string::npos) {
            cout << left << setw(5) << temp->id
                 << setw(15) << temp->merk
                 << setw(15) << temp->tipe
                 << setw(8) << temp->tahun
                 << setw(12) << (temp->disewa ? "Disewa" : "Tersedia") << endl;
            ada = true;
        }
        temp = temp->next;
    }
    if (!ada) cout << "Mobil dengan merk tersebut tidak ditemukan.\n";
    garis();
    system("pause");
}

int main() {
    cout << "Hello, world!" << endl;
    return 0;
}