#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

#define max 5

struct Stack {
    int atas;
    int data[max];
} Tumpuk;

int kosong() {
    if (Tumpuk.atas == -1)
        return 1;
    else
        return 0;
}

int penuh() {
    if (Tumpuk.atas == max - 1)
        return 1;
    else
        return 0;
}

void input(int data) {
    if (kosong() == 1) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack\n";
    } else if (penuh() == 0) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack\n";
    } else {
        cout << "Tumpukan Penuh\n";
    }
}

void hapus() {
    if (kosong() == 0) {
        cout << "Data Teratas Sudah Terambil\n";
        Tumpuk.atas--;
    } else {
        cout << "Data Kosong\n";
    }
}

void tampil() {
    if (kosong() == 0) {
        for (int i = Tumpuk.atas; i >= 0; i--) {
            cout << "Tumpukan Ke " << i << " = " << Tumpuk.data[i] << endl;
        }
    } else {
        cout << "Tumpukan Kosong\n";
    }
}

void bersih() {
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong!\n";
}

int main() {
    char PILIHAN[10];
    int PIL;
    int data;

    Tumpuk.atas = -1;

    do {
        cout << "=====" << endl;
        cout << "STACK" << endl;
        cout << "=====" << endl;
        cout << "1. PUSH (Input)" << endl;
        cout << "2. POP (Hapus)" << endl;
        cout << "3. CETAK STACK" << endl;
        cout << "4. BERSIH" << endl;
        cout << "5. QUIT" << endl;
        cout << "PILIHAN: ";
        cin >> PILIHAN;
        PIL = atoi(PILIHAN);

        switch (PIL) {
            case 1:
                cout << "Masukkan Data: ";
                cin >> data;
                input(data);
                break;
            case 2:
                hapus();
                break;
            case 3:
                tampil();
                break;
            case 4:
                bersih();
                break;
            default:
                cout << "TERIMA KASIH\n";
                break;
        }

        cout << "Press any key to continue...\n";
        getch();
        system("cls");

    } while (PIL < 5);

    return 0;
}