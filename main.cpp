#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struct untuk Komik
struct Komik {
    int id;
    string judul;
    string pengarang;
    string tanggal_dibaca;
    int chapter_terakhir;
};

// Struct untuk Manajemen Komik
struct ManajemenKomik {
    vector<Komik> daftar_komik;
    int id_counter;

    ManajemenKomik() : id_counter(1) {}

    // Function untuk menambahkan komik baru
    void tambahKomik(const string& judul, const string& pengarang, const string& tanggal_dibaca, int chapter_terakhir) {
        Komik komik;
        komik.id = id_counter++;
        komik.judul = judul;
        komik.pengarang = pengarang;
        komik.tanggal_dibaca = tanggal_dibaca;
        komik.chapter_terakhir = chapter_terakhir;
        daftar_komik.push_back(komik);
        cout << "Komik berhasil ditambahkan!\n";
    }

    // Function untuk mencari komik berdasarkan judul
    void cariKomik(const string& judul) {
        bool ditemukan = false;
        for (auto& komik : daftar_komik) {
            if (komik.judul == judul) {
                cout << "Komik ditemukan:\n";
                cout << "ID: " << komik.id << "\n";
                cout << "Judul: " << komik.judul << "\n";
                cout << "Pengarang: " << komik.pengarang << "\n";
                cout << "Tanggal Dibaca: " << komik.tanggal_dibaca << "\n";
                cout << "Chapter Terakhir: " << komik.chapter_terakhir << "\n";
                ditemukan = true;
                break;
            }
        }
        if (!ditemukan) {
            cout << "Komik tidak ditemukan.\n";
        }
    }

    // Function untuk menampilkan semua komik
    void tampilkanSemuaKomik() {
        if (daftar_komik.empty()) {
            cout << "Tidak ada komik dalam daftar.\n";
            return;
        }

        cout << "Daftar Komik yang Dibaca:\n";
        for (auto& komik : daftar_komik) {
            cout << "ID: " << komik.id << "\n";
            cout << "Judul: " << komik.judul << "\n";
            cout << "Pengarang: " << komik.pengarang << "\n";
            cout << "Tanggal Dibaca: " << komik.tanggal_dibaca << "\n";
            cout << "Chapter Terakhir: " << komik.chapter_terakhir << "\n";
            cout << "-------------------------\n";
        }
    }

    // Function untuk memperbarui chapter terakhir suatu komik
    void perbaruiChapterTerakhir(const string& judul, int chapter_terbaru) {
        bool ditemukan = false;
        for (auto& komik : daftar_komik) {
            if (komik.judul == judul) {
                komik.chapter_terakhir = chapter_terbaru;
                cout << "Chapter terakhir komik '" << judul << "' berhasil diperbarui menjadi " << chapter_terbaru << "\n";
                ditemukan = true;
                break;
            }
        }
        if (!ditemukan) {
            cout << "Komik tidak ditemukan. Chapter tidak dapat diperbarui.\n";
        }
    }
};

void tampilkanMenu() {
    cout << "Menu Manajemen Komik yang Dibaca:\n";
    cout << "1. Tambah Komik\n";
    cout << "2. Cari Komik\n";
    cout << "3. Tampilkan Semua Komik\n";
    cout << "4. Perbarui Chapter Terakhir Komik\n";
    cout << "5. Keluar\n";
    cout << "Pilih opsi: ";
}

int main() {
    ManajemenKomik manajemen_komik;
    int pilihan;
    string judul, pengarang, tanggal_dibaca;
    int chapter_terakhir, chapter_terbaru;

    while (true) {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan judul komik: ";
                cin.ignore();
                getline(cin, judul);
                cout << "Masukkan pengarang komik: ";
                getline(cin, pengarang);
                cout << "Masukkan tanggal dibaca (DD-MM-YYYY): ";
                getline(cin, tanggal_dibaca);
                cout << "Masukkan chapter terakhir yang dibaca: ";
                cin >> chapter_terakhir;
                manajemen_komik.tambahKomik(judul, pengarang, tanggal_dibaca, chapter_terakhir);
                break;
            case 2:
                cout << "Masukkan judul komik yang dicari: ";
                cin.ignore();
                getline(cin, judul);
                manajemen_komik.cariKomik(judul);
                break;
            case 3:
                manajemen_komik.tampilkanSemuaKomik();
                break;
            case 4:
                cout << "Masukkan judul komik yang ingin diperbarui chapter terakhirnya: ";
                cin.ignore();
                getline(cin, judul);
                cout << "Masukkan chapter terbaru yang dibaca: ";
                cin >> chapter_terbaru;
                manajemen_komik.perbaruiChapterTerakhir(judul, chapter_terbaru);
                break;
            case 5:
                cout << "Keluar dari program.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
                break;
        }
    }

    return 0;
}
