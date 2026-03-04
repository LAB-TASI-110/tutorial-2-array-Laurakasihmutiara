// 12S25014 - LAURA KASIH MUTIARA

#include <stdio.h> // Diperlukan untuk fungsi input/output seperti printf dan scanf
// #include <limits.h> // Diperlukan untuk INT_MAX dan INT_MIN (opsional, inisialisasi dengan nilai pertama lebih robust)
// #include <float.h>  // Diperlukan untuk FLT_MAX atau FLT_MIN (opsional, inisialisasi dengan nilai pertama lebih robust)

int main() {
    int n;          // Variabel untuk menyimpan jumlah baris masukan berikutnya
    int num;        // Variabel untuk menyimpan setiap bilangan bulat yang dimasukkan
    int prev_num;   // Variabel untuk menyimpan angka sebelumnya, diperlukan untuk rata-rata pasangan
    int min_val;    // Variabel untuk menyimpan nilai terkecil dari semua angka
    int max_val;    // Variabel untuk menyimpan nilai terbesar dari semua angka
    float min_avg;  // Variabel untuk menyimpan nilai rata-rata terendah dari pasangan berturut-turut
    float max_avg;  // VARIABEL BARU: Untuk menyimpan nilai rata-rata tertinggi dari pasangan berturut-turut
    int i;          // Variabel counter untuk loop

    int first_num_read = 0;   // Flag untuk inisialisasi min_val dan max_val dengan angka pertama
    int first_pair_read = 0;  // Flag untuk inisialisasi min_avg dan max_avg dengan rata-rata pasangan pertama

    // --- Bagian 1: Membaca dan memvalidasi nilai 'n' ---
    printf("Masukkan jumlah baris masukan berikutnya (n): ");
    // Memastikan input 'n' adalah bilangan bulat dan positif
    while (scanf("%d", &n) != 1 || n <= 0) {
        printf("Input tidak valid. n harus bilangan bulat positif. Silakan masukkan lagi: ");
        // Membersihkan buffer input jika ada karakter yang tidak sesuai
        while (getchar() != '\n'); 
    }

    // --- Bagian 2: Membaca 'n' baris masukan dan mencari min/max serta rata-rata terendah/tertinggi ---
    printf("Masukkan %d bilangan bulat antara -100 dan 100:\n", n);
    for (i = 0; i < n; i++) {
        printf("Angka ke-%d: ", i + 1);
        int current_input_val; // Variabel sementara untuk input yang belum divalidasi
        // Memastikan input adalah bilangan bulat dan berada dalam rentang -100 hingga 100
        while (scanf("%d", &current_input_val) != 1 || current_input_val < -100 || current_input_val > 100) {
            printf("Input tidak valid. Angka harus bilangan bulat antara -100 dan 100. Silakan masukkan lagi: ");
            // Membersihkan buffer input jika ada karakter yang tidak sesuai
            while (getchar() != '\n');
        }
        num = current_input_val; // Gunakan angka yang sudah divalidasi

        // Inisialisasi min_val dan max_val dengan angka pertama yang valid
        if (!first_num_read) {
            min_val = num;
            max_val = num;
            first_num_read = 1;
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

        // Hitung rata-rata terendah dan tertinggi dari dua nilai berturut-turut
        // Ini hanya bisa dilakukan jika sudah ada setidaknya dua angka (mulai dari i=1)
        if (i >= 1) { 
            // Hitung rata-rata dari angka sebelumnya (prev_num) dan angka saat ini (num)
            float current_avg = (float)(prev_num + num) / 2.0;

            // Inisialisasi min_avg dan max_avg dengan rata-rata pasangan pertama yang ditemukan
            if (!first_pair_read) {
                min_avg = current_avg;
                max_avg = current_avg; // Inisialisasi max_avg juga dengan rata-rata pasangan pertama
                first_pair_read = 1;
            } else {
                // Bandingkan dengan min_avg yang sudah ada
                if (current_avg < min_avg) {
                    min_avg = current_avg;
                }
                // Bandingkan dengan max_avg yang sudah ada
                if (current_avg > max_avg) { // Logic baru untuk max_avg
                    max_avg = current_avg;
                }
            }
        }
        
        // Simpan angka saat ini sebagai 'prev_num' untuk iterasi berikutnya
        prev_num = num;
    }

    // --- Bagian 3: Menampilkan hasil keluaran ---
    printf("\nBerikut adalah keluaran yang dihasilkan:\n");
    printf("%d\n", min_val); // Menampilkan nilai terkecil
    printf("%d\n", max_val); // Menampilkan nilai terbesar

    // Menampilkan rata-rata terendah dan tertinggi hanya jika ada setidaknya satu pasangan angka (yaitu, n >= 2)
    if (n >= 2) {
        printf("%.2f\n", min_avg); // Menampilkan nilai rata-rata terendah dengan 2 digit presisi
        printf("%.2f\n", max_avg); // Menampilkan nilai rata-rata tertinggi dengan 2 digit presisi
    }

    return 0; // Menandakan program berakhir dengan sukses
}
