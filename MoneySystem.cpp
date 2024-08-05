#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
using namespace std;

#define persenan 0.1

int n = 0;
char nasabah;
int i, x, pos, a = 0;
long int no;
double setor, tarik;
bool ketemu = false;

time_t t = time(0);
tm *now = localtime(&t);
const char *dayNames[] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
int dayOfWeek = now->tm_wday;

struct Nasabah
{
    char nama[30];
    long int norek;
    double saldo;
} nas[50];

void regUser()
{
    system("cls");
    ketemu = false; 
lagi:
    cout << "Masukkan nomor rekening  : ";
    cin >> no;
    for (i = 0; i < n; i++)
    {
        if (no == nas[i].norek)
        {
            ketemu = true;
            break;
        }
    }
    if (ketemu)
    {
        cout << "Nomor rekening tersebut sudah ada, ulangi lagi" << endl;
        goto lagi;
    }
    else
    {
        cout << "Masukkan nama anda       : ";
        cin >> nas[n].nama;
        cout << "Masukkan saldo awal anda : ";
        cin >> nas[n].saldo;
    }
    nas[n].norek = no;
    n = n + 1;
    return;
}

void deposit()
{
    system("cls");
    cout << "Masukkan nomor rekening : ";
    cin >> no;
    ketemu = false;
    for (i = 0; i < n; i++)
    {
        if (no == (nas[i].norek))
        {
            pos = i;
            ketemu = true;
            break;
        }
    }
    if (ketemu)
    {
        cout << "Masukkan jumlah setoran : ";
        cin >> setor;
        nas[pos].saldo = nas[pos].saldo + setor;
        cout << endl;
    }
    else
        cout << "Nomor rekening tidak ditemukan!" << endl;
    return;
}

void withdrawal()
{
    system("cls");
    cout << "Masukkan nomor rekening : ";
    cin >> no;
    ketemu = false;
    for (i = 0; i < n; i++)
    {
        if (no == (nas[i].norek))
        {
            pos = i;
            ketemu = true;
            break;
        }
    }
    if (ketemu)
    {
        cout << "Masukkan jumlah penarikan : ";
        cin >> tarik;
        if (tarik < (nas[pos].saldo))
        {
            nas[pos].saldo = nas[pos].saldo - tarik;
            cout << endl;

            cout << "=========================================" << endl;
            cout << "              BUKTI PENARIKAN            " << endl;
            cout << "=========================================" << endl;
            cout << "Hari      : " << dayNames[dayOfWeek] << "" << endl;
            cout << "Tanggal   : " << __DATE__ << "" << endl;
            cout << "Waktu     : " << __TIME__ << "" << endl;
            cout << "=========================================" << endl;
            cout << "No Rekening      : " << nas[pos].norek << endl;
            cout << "Nama Nasabah     : " << nas[pos].nama << endl;
            cout << "Jumlah Penarikan : " << tarik << endl;
            cout << "=========================================" << endl;
        }
        else
            cout << "Maaf saldo anda tidak mencukupi" << endl;
    }
    else
        cout << "Nomor rekening tidak ditemukan" << endl;
    return;
}

void printUser()
{
    system("cls");
    cout << "|====|================|================|================|" << endl;
    cout << "|NO  |  NO REKENING   |     NAMA       |  TOTAL SALDO   |" << endl;
    cout << "|====|================|================|================|" << endl;
    for (i = 0; i < n; i++)
    {
        cout << setw(4) << i + 1;
        cout << setw(14) << nas[i].norek;
        cout << setw(14) << nas[i].nama;
        cout << setw(14) << ((nas[i].saldo) + (nas[i].saldo * 0.1)) << endl;
    }
    cout << endl
         << endl;
    cout << "|====|================|================|================|" << endl;
    cout << "jumlah total saldo diatas telah ditambah bunga 10%" << endl;
    return;
}

void findUser()
{
    system("cls");
    cout << "Masukkan nomor rekening yang akan dicari : ";
    cin >> no;
    cout << endl;
    ketemu = false; 
    for (i = 0; i < n; i++)
    {
        if (no == (nas[i].norek))
        {
            pos = i;
            ketemu = true;
            break;
        }
    }
    if (ketemu)
    {
        cout << "Nomor rekening            : " << nas[pos].norek << endl;
        cout << "Nama nasabah              : " << nas[pos].nama << endl;
        cout << "Saldo                     : " << nas[pos].saldo << endl;
        cout << "Total saldo setelah bunga : " << ((nas[i].saldo) + (nas[i].saldo * persenan)) << endl;
    }
    else
        cout << "Nomor rekening tidak ditemukan!" << endl;
    return;
}

void mainMenu()
{
    int pil;
    do
    {
        cout << "===================================" << endl;
        cout << "|           MONEY SYSTEM          |" << endl;
        cout << "|=================================|" << endl;
        cout << "|1.    Pendaftaran Nasabah        |" << endl;
        cout << "|2.    Penyetoran                 |" << endl;
        cout << "|3.    Penarikan                  |" << endl;
        cout << "|4.    Cetak Daftar Nasabah       |" << endl;
        cout << "|5.    Cari Nasabah               |" << endl;
        cout << "|6.    Keluar                     |" << endl;
        cout << "|=================================|" << endl;
        cout << "\nPilihan menu : ";
        cin >> pil;
        switch (pil)
        {
        case 1:
            regUser();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdrawal();
            break;
        case 4:
            printUser();
            break;
        case 5:
            findUser();
            break;
        case 6:
            cout << "Terimakasih telah bertransaksi disini..." << endl;
            break;
        default:
            cout << "Pilihan tidak valid, silahkan coba lagi" << endl;
            break;
        }
    } while (pil != 6);
}

int main()
{
    mainMenu();
    return 0;
}
