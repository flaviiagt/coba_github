#include <iostream>
#include <iomanip>
using namespace std;

struct lagu
{
    int jumlah;
    string judul;
    string penyanyi;
    string genre;
    string tahun;
};

int searching(lagu daftarlagu[], int jumlahlagu, string carijudul);
void quickSort(lagu daftarlagu[], int jumlahlagu, int low, int high);
void carilagu();

const int MAX_LAGU = 100;
lagu daftarlagu[MAX_LAGU];
int jumlahlagu = 0;

void tambahlagu()
{
    int jumlahinput;
    lagu lagu1;
    cin.ignore();
    cout << "Masukkan jumlah lagu yang ingin diinput: ";
    cin >> jumlahinput;
    
    for (int i = 0; i < jumlahinput; i++)
    {
        cout << "\nMasukkan Judul Lagu: ";
        cin.ignore();
        getline(cin, daftarlagu[jumlahlagu].judul);

        cout << "Masukkan Penyanyi: ";
        getline(cin, daftarlagu[jumlahlagu].penyanyi);

        cout << "Masukkan Genre Lagu: ";
        cin >> daftarlagu[jumlahlagu].genre;

        cout << "Masukkan Tahun Lagu: ";
        cin >> daftarlagu[jumlahlagu].tahun;
        cout << "\nLagu \"" << daftarlagu[jumlahlagu].judul << "\" oleh " << daftarlagu[jumlahlagu].penyanyi << " berhasil ditambahkan!" << endl;
        jumlahlagu++;
    }
    quickSort(daftarlagu, jumlahlagu, 0, jumlahlagu - 1);
}

void quickSort(lagu daftarlagu[], int jumlahlagu, int low, int high)
{
    if (low >= high)
        return;
    int awal = low, akhir = high;
    lagu pivot = daftarlagu[(awal + akhir) / 2];
    do
    {
        while (daftarlagu[awal].judul < pivot.judul)
        {
            awal++;
        }
        while (daftarlagu[akhir].judul > pivot.judul)
        {
            akhir--;
        }
        if (awal <= akhir)
        {
            swap(daftarlagu[awal], daftarlagu[akhir]);
            awal++;
            akhir--;
        }
    } while (awal <= akhir);

    if (low < akhir)
        quickSort(daftarlagu, jumlahlagu, low, akhir);
    if (awal < high)
        quickSort(daftarlagu, jumlahlagu, awal, high);
}

void tampillagu()
{
    if (jumlahlagu == 0)
    {
        cout << "Daftar lagu kosong!\n";
        return;
    }

    cout << "\n===== Daftar Lagu =====\n";
    for (int i = 0; i < jumlahlagu; i++)
    {
        cout << "Lagu ke-" << i + 1 << ":\n";
        cout << "Judul   : " << daftarlagu[i].judul << endl;
        cout << "Penyanyi: " << daftarlagu[i].penyanyi << endl;
        cout << "Genre   : " << daftarlagu[i].genre << endl;
        cout << "Tahun   : " << daftarlagu[i].tahun << endl;
        cout << "-----------------------\n";
    }
}


void carilagu()
{
    string carijudul;
    cout << "Masukkan judul lagu yang ingin dicari: ";
    cin.ignore();
    getline(cin, carijudul);
    searching(daftarlagu, jumlahlagu, carijudul);
}

int searching(lagu daftarlagu[], int jumlahlagu, string carijudul)
{
    for (int i = 0; i < jumlahlagu; i++)
    {
        if (daftarlagu[i].judul == carijudul)
        {
            cout << "Lagu ditemukan!\n" << endl;
            cout << "Judul   : " << daftarlagu[i].judul << endl;
            cout << "Penyanyi: " << daftarlagu[i].penyanyi << endl;
            cout << "Genre   : " << daftarlagu[i].genre << endl;
            cout << "Tahun   : " << daftarlagu[i].tahun << endl;
            return i;
        }
    }
    cout << "Lagu tidak ditemukan" << endl;
    return -1;
}

void menu()
{
    int pilih;
    int jawab;
    cout << "Playlist Lagu" << endl;
    cout << setfill('=') << setw(20) << "=" << endl;
    cout << setfill(' ');

    cout << "1. Tambah Lagu" << endl;
    cout << "2. Cari Lagu" << endl;
    cout << "3. Keluar" << endl;

    cout << "Pilih Menu: ";
    cin >> pilih;
    switch (pilih)
    {
    case 1:
        tambahlagu();
        tampillagu();
        break;
    case 2:
        carilagu();
        break;
    case 3:
        cout << "Terima kasih sudah menggunakan aplikasi ini!";
        exit (0);
        break;
    default:
        cout << "Menu tidak tersedia";
    }
}

int main()
{
    char jawab;
    do {
        menu();
        cout << "Apakah anda ingin kembali ke menu? (y/n): ";
        cin >> jawab;
        } while (jawab == 'y' || jawab == 'Y');
    
        cout << "Terima kasih sudah menggunakan aplikasi ini!"; 
    return 0;
}