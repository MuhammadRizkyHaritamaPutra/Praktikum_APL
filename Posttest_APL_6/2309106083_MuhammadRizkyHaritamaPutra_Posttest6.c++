#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <conio.h>
using namespace std;

struct Pengguna {
    string nama;
    string nim;
};

struct Obat {
    string nama;
    string jenis;
    int stok;
};

void tampilkanMenu() {
    cout << "\n=== M E N U ===" << endl;
    cout << "1. Registrasi" << endl;
    cout << "2. Login" << endl;
    cout << "3. Keluar" << endl;
}

bool registrasiPengguna(vector<Pengguna>& pengguna) {
    Pengguna user;
    cout << "Masukkan Nama: ";
    getline(cin, user.nama);
    cout << "Masukkan NIM: ";
    getline(cin, user.nim);
    pengguna.push_back(user);
    cout << "Registrasi berhasil." << endl;
    cout << "Tekan enter untuk melanjutkan...";
    getch();
    system("cls");
    return true; 
}

bool cekLogin(const vector<Pengguna>& pengguna) {
    if (pengguna.empty()) {
        cout << "Belum ada pengguna terdaftar. Silakan registrasi terlebih dahulu." << endl;
        return false;
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
                    cout << "Tekan enter untuk melanjutkan...";
                    getch();
                    system("cls");
                    return true;
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

void tampilkanMenuobat() {
    cout << "\n=== M E N U ===" << endl;
    cout << "1. Tambah Obat" << endl;
    cout << "2. Lihat Daftar Obat" << endl;
    cout << "3. Update Nama dan Stok Obat" << endl;
    cout << "4. Hapus Obat" << endl;
    cout << "5. Mengurutkan Nama obat secara Ascending" << endl;
    cout << "6. Mengurutkan stok obat secara Descending" << endl;
    cout << "7. Mengurutkan stok obat secara Ascending" << endl;
    cout << "8. Cari nama obat secara Ascending" << endl;
    cout << "9. Cari jenis obat secara Descending" << endl;
    cout << "10. Keluar" << endl;
}

void tambahObat(Obat *daftarObat, int& jumlahObat, const int MAX_OBAT) {
    bool validInput = false;
    while (!validInput) {
        try {
            if (jumlahObat < MAX_OBAT) {
                cout << "Masukkan nama obat: ";
                cin.ignore();
                getline(cin, (daftarObat + jumlahObat)->nama);
                cout << "Masukkan jenis obat: ";
                getline(cin, (daftarObat + jumlahObat)->jenis);
                cout << "Masukkan stok obat: ";
                cin >> (daftarObat + jumlahObat)->stok;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                system("cls");
                if (cin.fail()) {
                    cin.clear(); 
                    throw "Input stok obat tidak valid. Masukkan bilangan bulat.";
                }
                jumlahObat++;
                validInput = true; 
            } else {
                throw "Daftar obat penuh!";
            }
        } catch (const char* errorMsg) {
            cerr << "Terjadi kesalahan: " << errorMsg << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    }
}

void lihatDaftarObat(const Obat *daftarObat, const int jumlahObat) {
    if (jumlahObat > 0) {
        cout << "=== DAFTAR OBAT ===" << endl;
        cout << "ID\tNama\tJenis\tStok" << endl;
        for (int i = 0; i < jumlahObat; i++) {
            cout << i + 1 << "\t";
            cout << (daftarObat + i)->nama << "\t";
            cout << (daftarObat + i)->jenis << "\t";
            cout << (daftarObat + i)->stok << endl;
        }
    } else {
        cout << "Daftar obat kosong!" << endl;
    }
}

void updateNamaDanStokObat(Obat *daftarObat, const int jumlahObat) {
    try {
        if (jumlahObat > 0) {
            int indeks;
            cout << "Masukkan nomor obat yang ingin diupdate: ";
            cin >> indeks;
            if (cin.fail() || indeks < 1 || indeks > jumlahObat) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system("cls");
                lihatDaftarObat(daftarObat, jumlahObat);
                throw "Nomor obat tidak valid!";
            }
            cout << "Masukkan nama baru: ";
            cin.ignore();
            getline(cin, (daftarObat + indeks - 1)->nama);
            cout << "Masukkan stok baru: ";
            cin >> (daftarObat + indeks - 1)->stok;
            if (cin.fail()) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system("cls");
                throw "Input stok obat tidak valid. Masukkan bilangan bulat.";
            }
            cout << "Informasi obat berhasil diperbarui." << endl;
        } else {
            throw "Daftar obat kosong!";
        }
    } catch (const char* errorMsg) {
        cerr << "Terjadi kesalahan: " << errorMsg << endl;
        if (jumlahObat == 0)
            return;
        updateNamaDanStokObat(daftarObat, jumlahObat); 
    }
}

void hapusObat(Obat *daftarObat, int& jumlahObat) {
    bool obatDitambahkan = (jumlahObat > 0); 
    try {
        if (jumlahObat > 0) {
            int indeks;
            cout << "Masukkan nomor obat yang ingin dihapus: ";
            cin >> indeks;
            if (cin.fail() || indeks < 1 || indeks > jumlahObat) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                system("cls");
                lihatDaftarObat(daftarObat, jumlahObat);
                throw "Nomor obat tidak valid!";
            }
            for (int i = indeks - 1; i < jumlahObat - 1; i++) {
                *(daftarObat + i) = *(daftarObat + i + 1);
            }
            jumlahObat--; 
            cout << "Obat berhasil dihapus." << endl;
        } else {
            throw "Daftar obat kosong!";
        }
    } catch (const char* errorMsg) {
        cerr << "Terjadi kesalahan: " << errorMsg << endl;
        if (!obatDitambahkan) {
            return;
        }
        hapusObat(daftarObat, jumlahObat); 
    }
}

void selectionSortHuruf(Obat arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].nama < arr[min_idx].nama) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
}

void bubbleSortAngka(Obat arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].stok < arr[j + 1].stok) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSortAngka(Obat arr[], int n) {
    for (int i = 1; i < n; i++) {
        Obat key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].stok > key.stok) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int binarySearchAscending(const Obat arr[], int l, int r, const string& x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid].nama == x) {
            return mid;
        }
        if (arr[mid].nama < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int binarySearchDescending(const Obat arr[], int l, int r, const string& x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid].jenis == x) {
            return mid;
        }
        if (arr[mid].jenis > x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
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
        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            cout << "Input tidak valid. Silakan masukkan nomor pilihan." << endl;
            continue;
        }
        cin.ignore(); 
        system("cls");

        switch (pilihan) {
            case 1:
                registrasiPengguna(pengguna);
                break;
            case 2:
                if (cekLogin(pengguna)) {
                    system("cls");
                    while (true) {
                        tampilkanMenuobat();
                        int pilihanObat;
                        cout << "Pilihan: ";
                        if (!(cin >> pilihanObat)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            system("cls");
                            cout << "Input tidak valid. Silakan masukkan nomor pilihan." << endl;
                            continue;
                        }

                        switch (pilihanObat) {
                            case 1:
                                system("cls");
                                tambahObat(daftarObat, jumlahObat, MAX_OBAT);
                                break;
                            case 2:
                                system("cls");
                                lihatDaftarObat(daftarObat, jumlahObat);
                                break;
                            case 3:
                                system("cls");
                                lihatDaftarObat(daftarObat, jumlahObat);
                                updateNamaDanStokObat(daftarObat, jumlahObat);
                                break;
                            case 4:
                                system("cls");
                                lihatDaftarObat(daftarObat, jumlahObat);
                                hapusObat(daftarObat, jumlahObat);
                                break;
                            case 5:
                                selectionSortHuruf(daftarObat, jumlahObat);
                                system("cls");
                                cout << "Daftar obat diurutkan secara ascending berdasarkan nama." << endl;
                                lihatDaftarObat(daftarObat, jumlahObat);
                                break;
                            case 6:
                                bubbleSortAngka(daftarObat, jumlahObat);
                                system("cls");
                                cout << "Daftar obat diurutkan secara descending berdasarkan stok." << endl;
                                lihatDaftarObat(daftarObat, jumlahObat);
                                break;
                            case 7:
                                insertionSortAngka(daftarObat, jumlahObat);
                                system("cls");
                                cout << "Daftar obat diurutkan secara ascending berdasarkan stok." << endl;
                                lihatDaftarObat(daftarObat, jumlahObat);
                                break;
                            case 8: {
                                string namaObat;
                                cout << "Masukkan nama obat yang ingin dicari: ";
                                cin.ignore();
                                getline(cin, namaObat);
                                int idx = binarySearchAscending(daftarObat, 0, jumlahObat - 1, namaObat);
                                if (idx != -1) {
                                    cout << "Obat ditemukan pada indeks " << idx + 1 << endl;
                                    cout << "=== DAFTAR OBAT ===" << endl;
                                    cout << "ID\tNama\tJenis\tStok" << endl;
                                    cout << idx + 1 << "\t";
                                    cout << daftarObat[idx].nama << "\t";
                                    cout << daftarObat[idx].jenis << "\t";
                                    cout << daftarObat[idx].stok << endl;
                                } else {
                                    cout << "Obat tidak ditemukan." << endl;
                                }
                                break;
                            }
                            case 9: {
                                string jenisObat;
                                cout << "Masukkan jenis obat yang ingin dicari: ";
                                cin.ignore();
                                getline(cin, jenisObat);
                                int idx = binarySearchDescending(daftarObat, 0, jumlahObat - 1, jenisObat);
                                if (idx != -1) {
                                    cout << "Obat ditemukan pada indeks " << idx + 1 << endl;
                                    cout << "=== DAFTAR OBAT ===" << endl;
                                    cout << "ID\tNama\tJenis\tStok" << endl;
                                    cout << idx + 1 << "\t";
                                    cout << daftarObat[idx].nama << "\t";
                                    cout << daftarObat[idx].jenis << "\t";
                                    cout << daftarObat[idx].stok << endl;
                                } else {
                                    cout << "Obat tidak ditemukan." << endl;
                                }
                                break;
                            }
                            case 10:
                                cout << "Keluar dari program,Terima kasih telah menggunakan program kami." << endl;
                                return 0;
                            default:
                                system("cls");
                                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                                break;
                        }
                    }
                }
                break;
            case 3:
                cout << "Keluar dari program,Terima kasih telah menggunakan program kami." << endl;
                return 0;
            default:
                system("cls");
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    }

    return 0;
}
