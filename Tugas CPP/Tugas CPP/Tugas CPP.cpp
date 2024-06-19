#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <algorithm>

using namespace std;

// Function to validate integer input
int getValidIntInput() {
    string input;
    bool isValid = false;
    while (!isValid) {
        cin >> input;
        isValid = true;
        for (char c : input) {
            if (!isdigit(c)) {
                isValid = false;
                break;
            }
        }
        if (!isValid) {
            cout << "Input tidak valid. Masukkan angka: ";
        }
    }
    return stoi(input);
}

// Function to read and validate NIM input
string readNIM() {
    string input;
    while (true) {
        cin >> input;
        if (input.length() == 12 && all_of(input.begin(), input.end(), ::isdigit)) {
            return input;
        }
        else {
            cout << "NIM tidak valid. Masukkan NIM dengan 12 digit angka: ";
        }
    }
}

// Function to display the main menu
void displayMenu() {
    cout << "\n========== Menu Utama ==========" << endl;
    cout << "1. Kalkulator Sederhana" << endl;
    cout << "2. Menghitung Luas" << endl;
    cout << "3. Menghitung Nilai\n" << endl;
    cout << "Pilih menu (1-3): ";
}

// Function penjumlahan
int tambah() {
    int a, b, hasil;

    cout << "\n-----Operasi Penjumlahan-----\n" << endl;
    cout << "Angka Pertama: ";
    a = getValidIntInput();
    cout << "Angka Kedua: ";
    b = getValidIntInput();
    hasil = a + b;
    cout << "\nHasilnya\nPenjumlahan: " << a << " + " << b << " = " << hasil << endl;
    return 0;
}

// Function pengurangan
int kurang() {
    int a, b, hasil;

    cout << "\n-----Operasi Pengurangan-----\n" << endl;
    cout << "Angka Pertama: ";
    a = getValidIntInput();
    cout << "Angka Kedua: ";
    b = getValidIntInput();
    hasil = a - b;
    cout << "\nHasilnya\nPengurangan: " << a << " - " << b << " = " << hasil << endl;
    return 0;
}

// Function perkalian
int kali() {
    int a, b, hasil;

    cout << "\n-----Operasi Perkalian-----\n" << endl;
    cout << "Angka Pertama: ";
    a = getValidIntInput();
    cout << "Angka Kedua: ";
    b = getValidIntInput();
    hasil = a * b;
    cout << "\nHasilnya\nPerkalian: " << a << " * " << b << " = " << hasil << endl;
    return 0;
}

// Function pembagian
int bagi() {
    float a, b, hasil;

    cout << "\n-----Operasi Pembagian-----\n" << endl;
    cout << "Angka Pertama: ";
    a = getValidIntInput();
    cout << "Angka Kedua: ";
    b = getValidIntInput();

    if (b != 0) {
        hasil = a / b;
        cout << "\nHasilnya\nPembagian: " << a << " / " << b << " = " << hasil << endl;
    }
    else {
        cout << "\nPembagian dengan nol tidak diperbolehkan." << endl;
    }

    return 0;
}

// Function tampilan
void tampilan() {
    int pilih;

    cout << "\n========== Kalkulator Sederhana ==========" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "3. Perkalian" << endl;
    cout << "4. Pembagian\n" << endl;
    cout << "Pilih Operasi Matematika (1-4): ";

    while (true) {
        pilih = getValidIntInput();

        switch (pilih) {
        case 1:
            tambah();
            return; // Keluar dari fungsi setelah selesai operasi
        case 2:
            kurang();
            return;
        case 3:
            kali();
            return;
        case 4:
            bagi();
            return;
        default:
            cout << "\nNomor Yang Anda Masukan Tidak Masuk Dalam Menu!" << endl;
            cout << "Pilih Nomor Yang Sesuai Dengan Menu!\n" << endl;
            cout << "Pilih Operasi Matematika (1-4): ";
            continue; // Mengulang loop untuk meminta input yang valid
        }
    }
}


// Function to calculate area
void menghitungLuas() {
    int pilihan;
    const double PI = 3.14159265358979323846;

    cout << "\n========== Menghitung Luas ==========" << endl;
    cout << "1. Luas Lingkaran" << endl;
    cout << "2. Luas Persegi\n" << endl;
    cout << "Pilih jenis perhitungan (1-2): ";

    while (true) {
        pilihan = getValidIntInput();

        switch (pilihan) {
        case 1: {
            int radius;
            cout << "\n-----Menghitung Jari-jari Lingkaran-----\n" << endl;
            cout << "Masukkan jari-jari lingkaran: ";
            radius = getValidIntInput();
            cout << "\nHasilnya\nLuas Lingkaran: " << fixed << setprecision(1) << PI * radius * radius << endl;
            return; // Keluar dari fungsi setelah selesai operasi
        }
        case 2: {
            int subPilihan;
            cout << "Menghitung Luas Persegi" << endl;
            cout << "1. Persegi/Kotak" << endl;
            cout << "2. Persegi Panjang\n" << endl;
            cout << "Pilih jenis perhitungan (1-2): ";
            subPilihan = getValidIntInput();

            switch (subPilihan) {
            case 1: {
                int sisi;
                cout << "\n-----Masukan Sisi Persegi-----\n" << endl;
                cout << "Masukkan panjang sisi persegi: ";
                sisi = getValidIntInput();
                cout << "\nHasilnya\nLuas Persegi: " << fixed << setprecision(1) << sisi * sisi << endl;
                return; // Keluar dari fungsi setelah selesai operasi
            }
            case 2: {
                int panjang, lebar;
                cout << "\n-----Masukan Sisi Persegi Panjang-----\n" << endl;
                cout << "Masukkan panjang persegi panjang: ";
                panjang = getValidIntInput();
                cout << "Masukkan lebar persegi panjang: ";
                lebar = getValidIntInput();
                cout << "\nHasilnya\nLuas Persegi Panjang: " << fixed << setprecision(1) << panjang * lebar << endl;
                return; // Keluar dari fungsi setelah selesai operasi
            }
            default:
                cout << "\nNomor Yang Anda Masukan Tidak Masuk Dalam Menu!" << endl;
                cout << "Pilih Nomor Yang Sesuai Dengan Menu!\n" << endl;
                cout << "Pilih jenis perhitungan (1-2): ";
                continue; // Mengulang loop untuk meminta input yang valid
            }
            break;
        }
        default:
            cout << "\nNomor Yang Anda Masukan Tidak Masuk Dalam Menu!" << endl;
            cout << "Pilih Nomor Yang Sesuai Dengan Menu!\n" << endl;
            cout << "Pilih jenis perhitungan (1-2): ";
            continue; // Mengulang loop untuk meminta input yang valid
        }
    }
}


// Function to calculate grade and final score
void menghitungNilai() {
    double kehadiran, tugas, uts, uas, hasil;
    int sks, max_kehadiran;
    string nama, nim;
    cout << "\n========== Menghitung Nilai Mahasiswa ==========" << endl;
    cout << "Masukkan Nama Mahasiswa: ";
    cin >> ws; // clear leading whitespace
    getline(cin, nama);

    cout << "Masukkan NIM Mahasiswa (12 digit angka): ";
    nim = readNIM();

    while (true) {
        cout << "Masukkan jumlah SKS (2 atau 3): ";
        sks = getValidIntInput();
        if (sks == 2 || sks == 3) {
            break;
        }
        else {
            cout << "Jumlah SKS tidak valid, silakan masukkan 2 atau 3." << endl;
        }
    }

    max_kehadiran = (sks == 3) ? 21 : 14;

    cout << "Masukkan Kehadiran 0-" << max_kehadiran << ": ";
    kehadiran = getValidIntInput();
    while (kehadiran < 0 || kehadiran > max_kehadiran) {
        cout << "Kehadiran tidak valid. Masukkan Kehadiran 0-" << max_kehadiran << ": ";
        kehadiran = getValidIntInput();
    }
    double phadir = (kehadiran / max_kehadiran) * 10.0;
    cout << "Kehadiran: " << fixed << setprecision(1) << phadir << " %" << endl;

    cout << "Masukkan Nilai Tugas 0-100: ";
    tugas = getValidIntInput();
    while (tugas < 0 || tugas > 100) {
        cout << "Nilai Tugas tidak valid. Masukkan Nilai Tugas 0-100: ";
        tugas = getValidIntInput();
    }

    cout << "Masukkan Nilai UTS 0-100: ";
    uts = getValidIntInput();
    while (uts < 0 || uts > 100) {
        cout << "Nilai UTS tidak valid. Masukkan Nilai UTS 0-100: ";
        uts = getValidIntInput();
    }

    cout << "Masukkan Nilai UAS 0-100: ";
    uas = getValidIntInput();
    while (uas < 0 || uas > 100) {
        cout << "Nilai UAS tidak valid. Masukkan Nilai UAS 0-100: ";
        uas = getValidIntInput();
    }

    hasil = (phadir * 0.1) + (tugas * 0.2) + (uts * 0.3) + (uas * 0.4);
    cout << "\n========== Hasil Nilai ==========" << endl;
    cout << "Nama Mahasiswa : " << nama << endl;
    cout << "NIM            : " << nim << endl;
    cout << "Nilai Akhir    : " << fixed << setprecision(1) << hasil << endl;
    cout << "Grade          : ";
    if (hasil >= 85)
        cout << "A" << endl;
    else if (hasil >= 70)
        cout << "B" << endl;
    else if (hasil >= 55)
        cout << "C" << endl;
    else if (hasil >= 40)
        cout << "D" << endl;
    else
        cout << "E" << endl;
}

int main() {
    cout << "Nama         : Suryadi " << endl;
    cout << "NIM          : 231091950050 " << endl;
    cout << "Mata Kuliah  : Algoritma Pemrograman " << endl;
    cout << "Tugas        : C++ " << endl;
    cout << " \n ";

    while (true) {
        int select;
        char op;

        displayMenu();
        select = getValidIntInput();

        switch (select) {
        case 1:
            tampilan();
            break;
        case 2:
            menghitungLuas();
            break;
        case 3:
            menghitungNilai();
            break;
        default:
            cout << "Pilihan tidak valid, silakan ulangi." << endl;
            // Loop until a valid selection is made
            while (true) {
                displayMenu();
                select = getValidIntInput();
                switch (select) {
                case 1:
                    tampilan();
                    break;
                case 2:
                    menghitungLuas();
                    break;
                case 3:
                    menghitungNilai();
                    break;
                default:
                    cout << "Pilihan tidak valid, silakan ulangi." << endl;
                    continue;
                }
                break;
            }
        }

        cout << "\nApakah anda ingin lanjut? (y/n): ";
        cin >> op;
        if (op == 'n') {
            break;
        }
        else if (op != 'y') {
            cout << "Pilihan tidak valid, silakan ulangi." << endl;
        }
    }

    return 0;
}
