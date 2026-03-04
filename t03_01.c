// 12S25014 - LAURA KASIH MUTIARA

#include <stdio.h> // Diperlukan untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Diperlukan untuk INT_MAX dan INT_MIN (opsional, bisa inisialisasi dengan nilai pertama)

int main() {
    int n;          // Variabel untuk menyimpan jumlah baris masukan berikutnya
    int num;        // Variabel untuk menyimpan setiap bilangan bulat yang dimasukkan
    int min_val;    // Variabel untuk menyimpan nilai terkecil
    int max_val;    // Variabel untuk menyimpan nilai terbesar
    int i;          // Variabel counter untuk loop

    // --- Bagian 1: Membaca dan memvalidasi nilai 'n' ---
    printf("Masukkan jumlah baris masukan berikutnya (n): ");
    // Memastikan input 'n' adalah bilangan bulat dan positif
    while (scanf("%d", &n) != 1 || n <= 0) {
        printf("Input tidak valid. n harus bilangan bulat positif. Silakan masukkan lagi: ");
        // Membersihkan buffer input jika ada karakter yang tidak sesuai
        while (getchar() != '\n'); 
    }

    // Inisialisasi min_val dan max_val dengan nilai pertama yang valid
    // Ini lebih baik daripada menginisialisasi dengan INT_MAX/INT_MIN karena menghindari masalah jika n=0 (meskipun sudah divalidasi n > 0)
    // atau jika semua angka positif/negatif.

    // --- Bagian 2: Membaca 'n' baris masukan dan mencari min/max ---
    printf("Masukkan %d bilangan bulat antara -100 dan 100:\n", n);
    for (i = 0; i < n; i++) {
        printf("Angka ke-%d: ", i + 1);
        // Memastikan input 'num' adalah bilangan bulat dan berada dalam rentang -100 hingga 100
        while (scanf("%d", &num) != 1 || num < -100 || num > 100) {
            printf("Input tidak valid. Angka harus bilangan bulat antara -100 dan 100. Silakan masukkan lagi: ");
            // Membersihkan buffer input jika ada karakter yang tidak sesuai
            while (getchar() != '\n');
        }

        // Untuk angka pertama yang valid, inisialisasi min_val dan max_val
        if (i == 0) {
            min_val = num;
            max_val = num;
        } else {
            // Membandingkan dengan min_val saat ini
            if (num < min_val) {
                min_val = num;
            }
            // Membandingkan dengan max_val saat ini
            if (num > max_val) {
                max_val = num;
            }
        }
    }

    // --- Bagian 3: Menampilkan hasil keluaran ---
    printf("\nBerikut adalah keluaran yang dihasilkan:\n");
    printf("%d\n", min_val); // Menampilkan nilai terkecil
    printf("%d\n", max_val); // Menampilkan nilai terbesar

    return 0; // Menandakan program berakhir dengan sukses
}
