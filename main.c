#include <stdio.h>
#include <stdlib.h>

char nama[50][20];
int harga[50];
int jumlah[50];
int totalBarang = 0;

void tambahBarang() {
    puts("\n>> Tambah Barang");
    printf("Nama Barang: ");
    scanf("%s", nama[totalBarang]);
    printf("Harga Barang: Rp");
    scanf("%d", &harga[totalBarang]);
    printf("Jumlah: ");
    scanf("%d", &jumlah[totalBarang]);
    totalBarang++;
    puts("");
}

void lihatBelanja() {
    puts("\n>> Daftar Belanja");
    puts("-----------------------------");
    printf("No\tNama\tHarga\tJumlah\n");
    puts("-----------------------------");
    for (int i = 0; i < totalBarang; i++) {
        printf("%d\t%s\t%d\t%d\n",i+1, nama[i], harga[i], jumlah[i]);
    }
    puts("");
}

void hitungTotal() {
    int totalHarga = 0;

    puts("\n>> Hitung Total Belanja");
    for (int i = 0; i < totalBarang; i++) {
        totalHarga += harga[i] * jumlah[i];
    }
    printf("Total harga = Rp%d\n", totalHarga);

    if (totalHarga > 100000) {
        float diskon = totalHarga * 0.1;
        int bayar = totalHarga - diskon;
        printf("Diskon\t\t= 10%%\n");
        printf("Bayar\t\t= Rp%d\n", bayar);
    } else {
        printf("Diskon\t\t= 0%%\n");
        printf("Bayar\t\t= Rp%d\n", totalHarga);
    }
    puts("");
}

void menu() {
    puts("1. Tambah Barang");
    puts("2. Lihat Daftar Belanja");
    puts("3. Hitung Total");
    puts("4. Keluar");
}

int main() {
    int pilih_menu;

    do {
        puts("========================");
        puts("APLIKASI KASIR SEDERHANA");
        puts("========================");
        menu();
        puts("=========================");

        printf("Pilih menu: ");
        scanf("%d", &pilih_menu);

        switch (pilih_menu) {
            case 1:
                tambahBarang();
                break;
            case 2:
                lihatBelanja();
                break;
            case 3:
                hitungTotal();
                break;
            case 4:
                puts("Terima kasih, program selesai");
                exit(0);
            default:
                puts("Masukan Pilihan Yang Benar!\n");
        }
    } while (1);
}