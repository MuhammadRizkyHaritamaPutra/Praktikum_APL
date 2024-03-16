#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Struktur untuk menyimpan data pengguna
struct Pengguna {
    string nama;
    string nim;
};

// Struktur untuk menyimpan data obat
struct Obat {
    string nama;
    string jenis;
    int stok;
};

// Fungsi untuk menampilkan menu pengguna
void tampilkanMenuobat() {
    cout << "\n=== M E N U ===" << endl;
    cout << "1. Tambah Obat" << endl;
    cout << "2. Lihat Daftar Obat" << endl;
    cout << "3. Update Nama dan Stok Obat" << endl;
    cout << "4. Hapus Obat" << endl;
    cout << "5. Keluar" << endl;
}

// Fungsi untuk melakukan registrasi pengguna baru
void registrasiPengguna(vector<Pengguna>& pengguna) {
    Pengguna user;
    cout << "Masukkan Nama: ";
    getline(cin, user.nama);
    cout << "Masukkan NIM: ";
    getline(cin, user.nim);
    pengguna.push_back(user);
    cout << "Registrasi berhasil." << endl;
}

// Fungsi untuk melakukan login
bool loginPengguna(const vector<Pengguna>& pengguna) {
    string nama, nim;
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim);

    for (const auto& user : pengguna) {
        if (user.nama == nama && user.nim == nim) {
            cout << "Login berhasil." << endl;
            return true;
        }
    }

    cout << "Login gagal. Nama atau NIM salah." << endl;
    return false;

}

// Fungsi untuk memvalidasi login pengguna
void cekLogin(vector<Pengguna>& pengguna) {
    if (pengguna.empty()) {
        cout << "Belum ada pengguna terdaftar. Silakan registrasi terlebih dahulu." << endl;
    } else {
        int percobaan = 0;
        while (percobaan < 3) {
            string nama, nim;
            cout << "Masukkan Nama: ";
            getline(cin, nama);
            cout << "Masukkan NIM: ";
            getline(cin, nim);

            for (const auto& user : pengguna) {
                if (user.nama == nama && user.nim == nim) {
                    cout << "Login berhasil." << endl;
                    return;
                }
            }

            percobaan++;
            if (percobaan < 3)
                cout << "Login gagal. Anda memiliki " << 3 - percobaan << " percobaan lagi." << endl;
        }
        cout << "Anda telah salah login sebanyak 3 kali. Program berhenti." << endl;
        exit(1);
    }
}


// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "\n=== M E N U ===" << endl;
    cout << "1. Registrasi" << endl;
    cout << "2. Login" << endl;
    cout << "3. Keluar" << endl;
}

// Fungsi untuk menambahkan obat baru
void tambahObat(Obat daftarObat[], int& jumlahObat, const int MAX_OBAT) {
    if (jumlahObat < MAX_OBAT) {
        cout << "Masukkan nama obat: ";
        cin.ignore();
        getline(cin, daftarObat[jumlahObat].nama);
        cout << "Masukkan jenis obat: ";
        getline(cin, daftarObat[jumlahObat].jenis);
        cout << "Masukkan stok obat: ";
        cin >> daftarObat[jumlahObat].stok;
        jumlahObat++; // Tambah jumlah obat dalam daftar
    } else {
        cout << "Daftar obat penuh!" << endl;
    }
}

// Fungsi untuk menampilkan daftar obat ke samping
void lihatDaftarObat(const Obat daftarObat[], const int jumlahObat) {
    if (jumlahObat > 0) {
        cout << "=== DAFTAR OBAT ===" << endl;
        cout << "ID\tNama\tJenis\tStok" << endl;
        for (int i = 0; i < jumlahObat; i++) {
            cout << i + 1 << "\t";
            cout << daftarObat[i].nama << "\t";
            cout << daftarObat[i].jenis << "\t";
            cout << daftarObat[i].stok << endl;
        }
    } else {
        cout << "Daftar obat kosong!" << endl;
    }
}

// Fungsi untuk mengupdate nama dan stok obat berdasarkan indeks
void updateNamaDanStokObat(Obat daftarObat[], const int jumlahObat) {
    if (jumlahObat > 0) {
        int indeks;
        cout << "Masukkan nomor obat yang ingin diupdate: ";
        cin >> indeks;
        if (indeks >= 1 && indeks <= jumlahObat) {
            cout << "Masukkan nama baru: ";
            cin.ignore();
            getline(cin, daftarObat[indeks - 1].nama);
            cout << "Masukkan stok baru: ";
            cin >> daftarObat[indeks - 1].stok;
            cout << "Informasi obat berhasil diperbarui." << endl;
        } else {
            cout << "Nomor obat tidak valid!" << endl;
        }
    } else {
        cout << "Daftar obat kosong!" << endl;
    }
}

// Fungsi untuk menghapus obat berdasarkan indeks
void hapusObat(Obat daftarObat[], int& jumlahObat) {
    if (jumlahObat > 0) {
        int indeks;
        cout << "Masukkan nomor obat yang ingin dihapus: ";
        cin >> indeks;
        if (indeks >= 1 && indeks <= jumlahObat) {
            for (int i = indeks - 1; i < jumlahObat - 1; i++) {
                daftarObat[i] = daftarObat[i + 1];
            }
            jumlahObat--; // Kurangi jumlah obat dalam daftar
            cout << "Obat berhasil dihapus." << endl;
        } else {
            cout << "Nomor obat tidak valid!" << endl;
        }
    } else {
        cout << "Daftar obat kosong!" << endl;
    }
}

int main() {
    const int MAX_OBAT = 100;
    Obat daftarObat[MAX_OBAT];
    int jumlahObat = 0;

    vector<Pengguna> pengguna;

    while (true) {
        tampilkanMenu();
        int pilihan;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                registrasiPengguna(pengguna);
                break;
            case 2:
                cekLogin(pengguna); // Memanggil fungsi cekLogin
                while (true) {
                    tampilkanMenuobat();
                    int pilihan;
                    cout << "Pilihan: ";
                    cin >> pilihan;

                    switch (pilihan) {
                        case 1:
                            tambahObat(daftarObat, jumlahObat, MAX_OBAT);
                            break;
                        case 2:
                            lihatDaftarObat(daftarObat, jumlahObat);
                            break;
                        case 3:
                            lihatDaftarObat(daftarObat, jumlahObat);
                            updateNamaDanStokObat(daftarObat, jumlahObat);
                            break;
                        case 4:
                            lihatDaftarObat(daftarObat, jumlahObat);
                            hapusObat(daftarObat, jumlahObat);
                            break;
                        case 5:
                            cout << "Keluar dari program,Terima kasih telah menggunakan program kami." << endl;
                            return 0;
                        default:
                            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                            break;
                    }
                }
                break;
            case 3:
                cout << "Keluar dari program,Terima kasih telah menggunakan program kami." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    }

    return 0;
}
