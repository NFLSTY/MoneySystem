#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

#define persenan 0.1

int n = 0;
char nasabah;
int i, pil, x, pos, a = 0;
long int no;
double setor, tarik;
bool ketemu = false;

struct Nasabah
{
    char nama[30];
    long int norek;
    double saldo;
} nas[50];

void regUser()
{
    system("cls");
lagi:
    cout << "Masukkan nomor rekening  : ";
    cin >> no;
    for (i = 0; i < n; i++)
    {
        if (no == nas[i].norek)
            ketemu = true;
        else
            ketemu = false;
    }
    if (ketemu)
    {
        cout << "Nomor rekening tersebut sudah ada, ulangi lagi" << endl;
        goto lagi;
    }
    else
    {
        cout << "masukkan nama anda       : ";
        cin >> nas[n].nama;
        cout << "Masukkan saldo awal anda : ";
        cin >> nas[n].saldo;
    }
    n = n + 1;
    nas[i].norek = no;
    return;
}

void deposit()
{
    system("clas");
    cout << "masukkan nomor rekening : ";
    cin >> no;
    for (i = 0; i < n; i++)
    {
        if (no == (nas[i].norek))
        {
            pos = i;
            ketemu = true;
            break;
        }
        else
            ketemu = false;
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
    for (i = 0; i < n; i++)
    {
        if (no == (nas[i].norek))
        {
            pos = i;
            ketemu = true;
            break;
        }
        else
            ketemu = false;
    }
    if (ketemu)
    {
        cout << "Masukkan jumlah penarikan : ";
        cin >> tarik;
        if (tarik < (nas[pos].saldo))
        {
            nas[pos].saldo = nas[pos].saldo - tarik;
            cout << endl;
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
        cout << setw(17) << nas[i].norek;
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
    for (i = 0; i < n; i++)
    {
        if (no == (nas[i].norek))
        {
            pos = i;
            ketemu = true;
            break;
        }
        else
            ketemu = false;
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
    do
    {
        system("cls");
    menu:
        cout << "==============================================" << endl;
        cout << "|             SAVING MONEY SYSTEM            |" << endl;
        cout << "|============================================|" << endl;
        cout << "|============  'MENU TRANSAKSI'  ============|" << endl;
        cout << "|1.    Pendaftaran Nasabah                   |" << endl;
        cout << "|2.    Penyetoran                            |" << endl;
        cout << "|3.    Penarikan                             |" << endl;
        cout << "|4.    Cetak Daftar Nasabah                  |" << endl;
        cout << "|5.    Cari Nasabah                          |" << endl;
        cout << "|6.    Keluar                                |" << endl;
        cout << "|============================================|" << endl;
        cout << endl
             << "Pilihan menu : ";
        int pil;
        switch (pil)
        {
        case 1:
            regUser();
            goto menu;
            break;
        case 2:
            deposit();
            goto menu;
            break;
        case 3:
            withdrawal();
            goto menu;
            break;
        case 4:
            printUser();
            goto menu;
            break;
        case 5:
            findUser();
            goto menu;
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