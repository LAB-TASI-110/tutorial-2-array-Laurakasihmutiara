// 12S25014 - LAURA KASIH MUTIARA

#include <stdio.h> // Diperlukan untuk fungsi input/output seperti scanf dan printf

int main() {
    int n;          // Variabel untuk menyimpan jumlah baris masukan berikutnya
    int num;        // Variabel untuk menyimpan setiap bilangan bulat yang dimasukkan
    int prev_num;   // Variabel untuk menyimpan angka sebelumnya, diperlukan untuk rata-rata pasangan
    int min_val;    // Variabel untuk menyimpan nilai terkecil dari semua angka
    int max_val;    // Variabel untuk menyimpan nilai terbesar dari semua angka
    float min_avg;  // Variabel untuk menyimpan nilai rata-rata terendah dari pasangan berturut-turut
    int i;          // Variabel counter untuk loop

    int first_num_read = 0;   // Flag untuk inisialisasi min_val dan max_val dengan angka pertama
    int first_pair_read = 0;  // Flag untuk inisialisasi min_avg dengan rata-rata pasangan pertama

    // --- Bagian 1: Membaca dan memvalidasi nilai 'n' (Prompt interaktif dihapus) ---
    // Program akan menunggu input 'n' tanpa menampilkan prompt ke user.
    // Validasi tetap ada untuk memastikan 'n' adalah bilangan bulat positif.
    while (scanf("%d", &n) != 1 || n <= 0) {
        // Pesan error validasi juga dihapus agar tidak muncul di output autograding.
        while (getchar() != '\n'); // Membersihkan buffer input jika ada karakter yang tidak sesuai
    }

    // --- Bagian 2: Membaca 'n' baris masukan dan mencari min/max serta rata-rata terendah (Prompt interaktif dihapus) ---
    for (i = 0; i < n; i++) {
        int current_input_val; // Variabel sementara untuk input yang belum divalidasi
        // Program akan menunggu input angka tanpa menampilkan prompt ke user.
        // Validasi tetap ada untuk memastikan angka dalam rentang yang ditentukan.
        while (scanf("%d", &current_input_val) != 1 || current_input_val < -100 || current_input_val > 100) {
            // Pesan error validasi juga dihapus.
            while (getchar() != '\n'); // Membersihkan buffer input jika ada karakter yang tidak sesuai
        }
        num = current_input_val; // Gunakan angka yang sudah divalidasi

        // Logika pencarian nilai terkecil dan terbesar
        if (!first_num_read) {
            min_val = num;
            max_val = num;
            first_num_read = 1;
        } else {
            if (num < min_val) {
                min_val = num;
            }
            if (num > max_val) {
                max_val = num;
            }
        }

        // Logika pencarian rata-rata terendah dari dua nilai berturut-turut
        // Ini hanya bisa dilakukan jika sudah ada setidaknya dua angka (mulai dari i=1)
        if (i >= 1) { 
            float current_avg = (float)(prev_num + num) / 2.0;

            if (!first_pair_read) {
                min_avg = current_avg;
                first_pair_read = 1;
            } else {
                if (current_avg < min_avg) {
                    min_avg = current_avg;
                }
            }
        }
        
        // Simpan angka saat ini sebagai 'prev_num' untuk iterasi berikutnya
        prev_num = num;
    }

    // --- Bagian 3: Menampilkan hasil keluaran (Hanya hasil akhir, tanpa prompt pembuka atau rata-rata tertinggi) ---
    printf("%d\n", min_val); // Menampilkan nilai terkecil
    printf("%d\n", max_val); // Menampilkan nilai terbesar

    // Menampilkan rata-rata terendah hanya jika ada setidaknya satu pasangan angka (yaitu, n >= 2)
    if (n >= 2) {
        printf("%.2f\n", min_avg); // Menampilkan nilai rata-rata terendah dengan 2 digit presisi
    }

    return 0; // Menandakan program berakhir dengan sukses
}
