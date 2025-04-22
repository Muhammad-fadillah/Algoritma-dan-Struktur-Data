#include<iostream>
#include <string>
using namespace std;

struct InputData {
    string huruf, kata, angka;
};

int main(){
    InputData dataPengguna;
    cout << "Masukkan sebuah huruf = ";
    cin >> dataPengguna.huruf;
    cout << "Masukkan sebuah kata = ";
    cin >> dataPengguna.kata;
    cout << "Masukkan Angka = ";
    cin >> dataPengguna.angka;

    cout << "Huruf yang Anda masukkan adalah " << dataPengguna.huruf << endl;
    cout << "Kata yang Anda masukkan adalah " << dataPengguna.kata << endl;
    cout << "Angka yang Anda masukkan adalah " << dataPengguna.angka << endl;

    return 0;
}
