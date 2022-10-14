/* Contoh Program ke : 1 */
/* Program : struktur data statis mahasiswa */
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#define nmax 5 // banyak data yang dapat ditampung
using namespace std;

int n = 0; // variable n sebagai banyak data yang telah tersimpan
struct data
{ // struktur data mahasiswa yg akan diinput

    int nim;
    char nama[20];
    char kom;
};
struct data maba[nmax]; // deklarasi variabel bertipe struct
void tambah_data();     // prototype fungsi void
void hapus_data();
void tampilkan_data();
void update_data();
main()
{
    system("cls");
    int pil;
menu:
    cout << " \t\t MENU \n";
    cout << "1. tambah data\n";
    cout << "2. hapus data \n";
    cout << "3. tampilkan data \n";
    cout << "4. update data \n";
    cout << "5. keluar \n";
    cout << "\nPilih menu (1/2/3/4) ? ";
    cin >> pil;
    if (pil == 1)
        tambah_data();
    else if (pil == 2)
        hapus_data();
    else if (pil == 3)
        tampilkan_data();
    else if (pil == 4)
        update_data();
    else if (pil == 5)
        exit(1); // atau bisa pakai return(0)
    else
    {
        cout << "pilihan tak tersedia...!!!\n";
    }
    goto menu;
    getch();
}

void tambah_data()
{
    system("cls");
    if (n < nmax)
    {
        cout << "nama : ";
        cin >> maba[n].nama;
        cout << "NIM : ";
        cin >> maba[n].nim;
        cout << "Kom : ";
        cin >> maba[n].kom;
        n++;
    }
    else
        cout << "\n data telah melebihi...!!!\n maksimal data = " << nmax;
}
void hapus_data()
{
    system("cls");
    int x;
    cout << "pilih data yang akan dihapus (1 s.d. 5) : ";
    cin >> x;
    if (x < n && x > 0)
    {
        for (int i = x; i < n; i++)
        {
            strcpy(maba[i - 1].nama, maba[x].nama);
            maba[i - 1].nim = maba[x].nim;
            maba[i - 1].kom = maba[x].kom;
        }
        n--;
    }
    else if (x == n)
        n--;
    else
        cout << "\n data yang ingin dihapus tidak ada...!!!\n";
}
void tampilkan_data()
{
    system("cls");
    if (n == 0)
        cout << "Tidak ada data yang disimpan...!!!\n";
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Data ke-" << i + 1 << " : ";
            cout << "\nNama : " << maba[i].nama;
            cout << "\nNIM : " << maba[i].nim;
            cout << "\nKom : " << maba[i].kom;
            cout << endl;
        }
    }
}

void update_data(){
    int index, nomor;
    system("cls");

    cout << "Index data yang akan diubah : "; 
    cin >> index;

    if ((index <= n) and (index >= 1)) {
        cout << endl << endl;
        cout << "Data Mahasiswa ke - " << index << endl;
        cout << "1. Nama : " << maba[index - 1].nama << endl;
        cout << "2. NIM  : " << maba[index - 1].nim << endl;
        cout << "3. Kom  : " << maba[index - 1].kom << endl;
        cout << "Pilih nomor yang akan Anda ubah : "; 
        cin >> nomor;

        if (nomor == 1){
            cout << "Masukkan update nama   : "; 
            cin >> maba[index - 1].nama;
        } else if (nomor == 2) {
            cout << "Masukkan update NIM    : ";
            cin >> maba[index - 1].nim;
        } else if (nomor == 3) {
            cout << "Masukkan update KOM    : ";
            cin >> maba[index - 1].kom;
        }

        cout << "Update Data Mahasiswa ke-" << index << endl;
        cout << "\nNama : " << maba[index - 1].nama;
        cout << "\nNIM : " << maba[index - 1].nim;
        cout << "\nKom : " << maba[index - 1].kom;
        cout << endl;
    } else {
        cout << "Index Anda diluar jangkauan" << endl;
    }
}