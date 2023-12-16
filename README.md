# Automatic-Control-Light-Intensity-using-Fuzzy-Logic

### Project 
- Automatic Light Intensity Control with Fuzzy Logic is an automatic regulation system that uses fuzzy logic (Tsukamoto) principles to control the brightness level or intensity of lights.
- This automation system helps in optimizing energy use by regulating light intensity according to environmental conditions. Efficient use of electricity in lighting can bring economic, environmental and comfort benefits to users.
---
### Membership Function
- MF LDR 1
- MF LDR 2
- MF Output LED

### Rule Based
- if Dark1 and Dark2 then lED Maximum
- if Dark1 and Medium2 then lED Maximum
- if Dark1 and Bright2 then lED Minimum
- if Medium1 and Dark2 then lED Maximum
- if Medium1 and Medium2 then lED Maximum
- if Medium1 and Bright2 then lED Minimum
- if Bright1 and Dark2 then lED Minimum
- if Bright1 and Medium2 then lED Minimum
- if Bright1 and Bright2 then lED Minimum

### Hardware Use
- Arduino Uno
- LDR Sensor
- LED
- LCD
- Resistor 10k
- Jumper Cables
- Breadboard
- Acrylic

### Cara Menggunakan
1. **Clone Repository:**
   ```bash
   git clone https://github.com/Azmiriyadin/webcrud.git
   ```

2. **Konfigurasi Database:**
   - Buka file `index.php`.
   - Sesuaikan parameter koneksi database pada bagian awal file dengan informasi database Anda.

3. **Jalankan Aplikasi:**
   - Buka proyek di browser dengan mengakses `http://localhost/crud`.

4. **Operasi CRUD:**
   - Tambahkan data baru: Isi formulir pada bagian "Create / Edit Data" dan klik tombol "Simpan Data".
   - Edit data: Klik tombol "Edit" pada baris data yang ingin diubah, lalu lakukan perubahan dan simpan.
   - Hapus data: Klik tombol "Delete" pada baris data yang ingin dihapus, konfirmasi penghapusan.

### Struktur Proyek
- `index.php`: File utama dengan logika PHP, formulir HTML, dan tampilan data.
- `README.md`: Dokumentasi proyek.

### Penting
- Pastikan untuk memasukkan semua informasi yang diperlukan pada formulir untuk operasi tambah dan ubah data.
- Hati-hati dengan pengaturan hak akses database dan pastikan untuk mengamankan input pengguna.

### Kontribusi
Jika Anda ingin berkontribusi pada proyek ini, silakan fork repository ini dan buat pull request dengan perubahan Anda.

### Lisensi
Proyek ini dilisensikan di bawah [lisensi MIT](LICENSE).

### Kontak
Jika Anda memiliki pertanyaan atau masukan, silakan hubungi [Azmi Riyadin] di [mzamzamiriyadin@gmail.com].

Terima kasih telah menggunakan aplikasi ini! 🚀

### gambar hasil web CRUD
![Gambar Hasil Projek](image/projek.jpg "Hasil Projek Website CRUD")
