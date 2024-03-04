#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Fungsi untuk melakukan konversi dari kilometer/jam ke centimeter/detik
double km_per_jam_ke_cm_per_detik(double km_per_jam) {
    return km_per_jam * 27.7778;
}

// Fungsi untuk melakukan konversi dari kilometer/jam ke meter/detik
double km_per_jam_ke_meter_per_detik(double km_per_jam) {
    return km_per_jam * 0.277778;
}

// Fungsi untuk melakukan konversi dari kilometer/jam ke mil/jam
double km_per_jam_ke_mil_per_jam(double km_per_jam) {
    return km_per_jam * 0.621371;
}

// Fungsi untuk melakukan konversi dari centimeter/detik ke kilometer/jam
double cm_per_detik_ke_km_per_jam(double cm_per_detik) {
    return cm_per_detik * 0.036;
}

// Fungsi untuk melakukan konversi dari centimeter/detik ke meter/detik
double cm_per_detik_ke_meter_per_detik(double cm_per_detik) {
    return cm_per_detik * 0.01;
}

// Fungsi untuk melakukan konversi dari centimeter/detik ke mil/jam
double cm_per_detik_ke_mil_per_jam(double cm_per_detik) {
    return cm_per_detik * 0.0223694;
}

// Fungsi untuk melakukan konversi dari meter/detik ke kilometer/jam
double meter_per_detik_ke_km_per_jam(double meter_per_detik) {
    return meter_per_detik * 3.6;
}

// Fungsi untuk melakukan konversi dari meter/detik ke centimeter/detik
double meter_per_detik_ke_cm_per_detik(double meter_per_detik) {
    return meter_per_detik * 100;
}

// Fungsi untuk melakukan konversi dari meter/detik ke mil/jam
double meter_per_detik_ke_mil_per_jam(double meter_per_detik) {
    return meter_per_detik * 2.23694;
}

// Fungsi untuk melakukan konversi dari mil/jam ke kilometer/jam
double mil_per_jam_ke_km_per_jam(double mil_per_jam) {
    return mil_per_jam * 1.60934;
}

// Fungsi untuk melakukan konversi dari mil/jam ke centimeter/detik
double mil_per_jam_ke_cm_per_detik(double mil_per_jam) {
    return mil_per_jam * 44.704;
}

// Fungsi untuk melakukan konversi dari mil/jam ke meter/detik
double mil_per_jam_ke_meter_per_detik(double mil_per_jam) {
    return mil_per_jam * 0.44704;
}

// Fungsi untuk melakukan registrasi
void registrasi(vector<pair<string, string>>& pengguna) {
    string nama, nim;
    cout << "============================================================" << endl;
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan Nim: ";
    getline(cin, nim);
    cout << "============================================================" << endl;
    pengguna.push_back(make_pair(nama, nim));
    cout << "Akun berhasil didaftarkan." << endl;
}

// Fungsi untuk melakukan login
bool login(const vector<pair<string, string>>& pengguna) {
    string input_nama, input_nim;
    cout << "============================================================" << endl;
    cout << "Masukkan Nama: ";
    getline(cin, input_nama);
    cout << "Masukkan Nim: ";
    getline(cin, input_nim);
    cout << "============================================================" << endl;

    for (const auto& data : pengguna) {
        if (data.first == input_nama && data.second == input_nim) {
            cout << "Login berhasil" << endl;
            return true;
        }
    }

    cout << "Login gagal. Silakan coba lagi." << endl;
    return false;
}

// Fungsi untuk melakukan konversi berdasarkan input pengguna
void pilihan_konversi(int pilihan, double nilai) {
    switch (pilihan) {
        case 1:
            cout << "Centimeter/detik: " << km_per_jam_ke_cm_per_detik(nilai) << endl;
            cout << "Meter/detik: " << km_per_jam_ke_meter_per_detik(nilai) << endl;
            cout << "Mil/jam: " << km_per_jam_ke_mil_per_jam(nilai) << endl;
            break;
        case 2:
            cout << "Kilometer/jam: " << cm_per_detik_ke_km_per_jam(nilai) << endl;
            cout << "Meter/detik: " << cm_per_detik_ke_meter_per_detik(nilai) << endl;
            cout << "Mil/jam: " << cm_per_detik_ke_mil_per_jam(nilai) << endl;
            break;
        case 3:
            cout << "Kilometer/jam: " << meter_per_detik_ke_km_per_jam(nilai) << endl;
            cout << "Centimeter/detik: " << meter_per_detik_ke_cm_per_detik(nilai) << endl;
            cout << "Mil/jam: " << meter_per_detik_ke_mil_per_jam(nilai) << endl;
            break;
        case 4:
            cout << "Kilometer/jam: " << mil_per_jam_ke_km_per_jam(nilai) << endl;
            cout << "Centimeter/detik: " << mil_per_jam_ke_cm_per_detik(nilai) << endl;
            cout << "Meter/detik: " << mil_per_jam_ke_meter_per_detik(nilai) << endl;
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
    }
}

int main() {
    vector<pair<string, string>> pengguna;

    while (true) {
        cout << "Silahkan melakukan registrasi terlebih dahulu sebelum login" << endl;
        registrasi(pengguna);

        int percobaan = 0;
        while (percobaan < 3) {
            if (login(pengguna)) {
                while (true) {
                    cout << "=====================================================================" << endl;
                    cout << "1. Konversi Kilometer/jam ke (Centimeter/detik, Meter/detik, Mil/jam)" << endl;
                    cout << "2. Konversi Centimeter/detik ke (Kilometer/jam, Meter/detik, Mil/jam)" << endl;
                    cout << "3. Konversi Meter/detik ke (Kilometer/jam, centimeter/detik, Mil/jam)" << endl;
                    cout << "4. Konversi Mil/jam ke (Kilometer/jam, Centimeter/detik, Meter/detik)" << endl;
                    cout << "=====================================================================" << endl;

                    int opsi;
                    double nilai;
                    cout << "Pilih nomor konversi yang ingin Anda lakukan: ";
                    cin >> opsi;
                    cout << "Masukkan nilai yang ingin Anda konversi: ";
                    cin >> nilai;
                    pilihan_konversi(opsi, nilai);

                    char pilihan;
                    cout << "Apakah Anda ingin melakukan konversi lagi? (y/t): ";
                    cin >> pilihan;
                    cin.ignore(); // Membersihkan newline dari buffer
                    if (pilihan == 't' || pilihan == 'T') {
                        cout << "Terimakasih telah menggunakan program ini" << endl;
                        return 0;
                    } else if (pilihan != 'y' && pilihan != 'Y') {
                        break;
                    }
                }
            } else {
                percobaan++;
            }
        }
        cout << "Anda telah salah memasukkan nama dan nim lebih dari 3 kali. Program berhenti." << endl;
        break;
    }

    return 0;
}
