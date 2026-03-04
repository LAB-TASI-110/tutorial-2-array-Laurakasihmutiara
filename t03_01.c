// 12S25014 - LAURA KASIH MUTIARA

#include <stdio.h> // Diperlukan untuk fungsi input/output seperti scanf dan printf

int main() {
    int n;          // Variabel untuk menyimpan jumlah baris masukan berikutnya
    int num;        // Variabel untuk menyimpan setiap bilangan bulat yang dimasukkan
    int min_val;    // Variabel untuk menyimpan nilai terkecil dari semua angka
    int max_val;    // Variabel untuk menyimpan nilai terbesar dari semua angka
    int i;          // Variabel counter untuk loop

    int first_num_read = 0;   // Flag untuk inisialisasi min_val dan max_val dengan angka pertama

    // --- Bagian 1: Membaca dan memvalidasi nilai 'n' (Prompt interaktif dihapus) ---
    // Program akan menunggu input 'n' tanpa menampilkan prompt ke user.
    // Validasi tetap ada untuk memastikan 'n' adalah bilangan bulat positif.
    while (scanf("%d", &n) != 1 || n <= 0) {
        // Pesan error validasi juga dihapus agar tidak muncul di output autograding.
        while (getchar() != '\n'); // Membersihkan buffer input jika ada karakter yang tidak sesuai
    }

    // --- Bagian 2: Membaca 'n' baris masukan dan mencari min/max (Prompt interaktif dihapus) ---
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
    }

    // --- Bagian 3: Menampilkan hasil keluaran (Hanya hasil akhir, tanpa prompt pembuka atau rata-rata) ---
    printf("%d\n", min_val); // Menampilkan nilai terkecil
    printf("%d\n", max_val); // Menampilkan nilai terbesar

    return 0; // Menandakan program berakhir dengan sukses
}
