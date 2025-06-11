#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int random(int bil) {
    return rand() % bil;
}

void randomize() {
    srand(time(NULL));
}

void clrscr() {
    system("cls");
}

void sequential_searching() {
    clrscr();
    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save;
    randomize();
    printf("Generating 100 numbers . . .\n");
    for (int i = 0; i < 100; i++) {
        data[i] = random(100) + 1;
        printf("%d ", data[i]);
    }
    printf("\nDone.\n");

    for (int i = 0; i < 100; i++) {
        if (data[i] == cari) {
            counter++;
            flag = 1;
            save = i;
        }
    }

    if (flag == 1) {
        printf("Data ada, sebanyak %d!\n", counter);
        printf("pada indeks ke-%d", save);
    } else {
        printf("Data tidak ada\n");
    }
}

void binary_searching() {
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout << "Masukan jumlah data? ";
    cin >> n;
    int angka[n];
    for (int i = 0; i < n; i++) {
        cout << "Angka ke - [" << i << "]: ";
        cin >> angka[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (angka[j] > angka[j + 1]) {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }
    cout << "================================================================\n";
    cout << "Data yang telah diurutkan adalah:\n";
    for (int i = 0; i < n; i++) {
        cout << angka[i] << " ";
    }
    cout << "\n================================================================\n";
    cout << "Masukan angka yang dicari: ";
    cin >> key;

    kiri = 0;
    kanan = n - 1;
    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah]) {
            ketemu = true;
            break;
        } else if (key < angka[tengah]) {
            kanan = tengah - 1;
        } else {
            kiri = tengah + 1;
        }
    }
    if (ketemu) {
        cout << "Angka ditemukan ";
    } else {
        cout << "Angka tidak ditemukan";
    }
}

void explain_difference() {
    clrscr();
    cout << "=== Perbedaan Sequential Searching dan Binary Searching ===\n\n";

    cout << "1. Sequential Searching (Pencarian Berurutan):\n";
    cout << "- Dilakukan dengan memeriksa setiap elemen satu per satu dari awal sampai akhir.\n";
    cout << "- Tidak memerlukan data yang terurut.\n\n";

    cout << "   Kelebihan:\n";
    cout << "   - Mudah diimplementasikan.\n";
    cout << "   - Bisa digunakan untuk semua jenis data dan struktur data linier.\n";
    cout << "   - Tidak perlu proses pengurutan terlebih dahulu.\n\n";

    cout << "   Kekurangan:\n";
    cout << "   - Tidak efisien untuk jumlah data yang besar.\n";
    cout << "   - Waktu pencarian bisa lama karena harus mengecek satu per satu (kompleksitas O(n)).\n\n";

    cout << "2. Binary Searching (Pencarian Biner):\n";
    cout << "- Dilakukan dengan membagi data menjadi dua bagian dan membandingkan nilai tengah.\n";
    cout << "- Hanya bisa digunakan jika data sudah dalam keadaan terurut.\n\n";

    cout << "   Kelebihan:\n";
    cout << "   - Lebih cepat dan efisien, terutama untuk jumlah data yang besar.\n";
    cout << "   - Kompleksitas waktu lebih baik yaitu O(log n).\n\n";

    cout << "   Kekurangan:\n";
    cout << "   - Hanya berlaku untuk data yang sudah diurutkan.\n";
    cout << "   - Sedikit lebih kompleks dalam implementasi dibanding sequential search.\n\n";

    cout << "Kesimpulan:\n";
    cout << "- Gunakan Sequential Search jika data tidak terurut atau ukurannya kecil.\n";
    cout << "- Gunakan Binary Search jika data sudah terurut dan jumlahnya besar.\n";

    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}

int main() {
    int choice;
    do {
        cout << "\nPilih menu\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching\n";
        cout << "4. Exit\n";
        cout << "Pilih : ";
        cin >> choice;

        switch (choice) {
            case 1:
                sequential_searching();
                break;
            case 2:
                binary_searching();
                break;
            case 3:
                explain_difference();
                break;
            case 4:
                cout << "Exit...\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 4);

    return 0;
}