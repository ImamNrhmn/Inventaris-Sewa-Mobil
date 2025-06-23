#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

struct Mobil {
    int id;
    string merk;
    string tipe;
    int tahun;
    bool disewa;
    Mobil* next;
};

int main() {
    cout << "Hello, world!" << endl;
    return 0;
}