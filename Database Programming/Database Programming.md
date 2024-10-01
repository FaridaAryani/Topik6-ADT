# Dokumentasi Proyek ADT Oracle SQL

## Struktur File

Proyek ini terdiri dari beberapa file SQL yang terorganisir untuk mengelola data karyawan dan proyek menggunakan Abstract Data Type (ADT) di Oracle SQL.

### 1. types.sql

File ini berisi definisi tipe objek yang digunakan dalam proyek.

- **Karyawan**: Tipe objek untuk merepresentasikan data karyawan.
  - Atribut: id_karyawan, nama, tanggal_lahir, departemen, gaji
  - Metode: hitung_usia(), naikkan_gaji()

- **Proyek**: Tipe objek untuk merepresentasikan data proyek.
  - Atribut: id_proyek, nama_proyek, tanggal_mulai, tanggal_selesai
  - Metode: hitung_durasi()

### 2. tables.sql

File ini berisi perintah untuk membuat tabel-tabel yang digunakan dalam proyek.

- **tabel_karyawan**: Tabel untuk menyimpan data karyawan.
- **tabel_proyek**: Tabel untuk menyimpan data proyek.
- **karyawan_proyek**: Tabel relasi antara karyawan dan proyek.

### 3. data.sql

File ini berisi perintah INSERT untuk memasukkan data awal ke dalam tabel-tabel.

- Memasukkan data ke tabel_karyawan
- Memasukkan data ke tabel_proyek
- Memasukkan data ke karyawan_proyek

### 4. views.sql

File ini berisi definisi view yang digunakan dalam proyek.

- **view_karyawan_proyek**: View yang menampilkan informasi gabungan dari karyawan dan proyek.

### 5. procedures.sql

File ini berisi stored procedures yang digunakan dalam proyek.

- **naikkan_gaji_karyawan**: Prosedur untuk menaikkan gaji karyawan.
- **tambah_karyawan_ke_proyek**: Prosedur untuk menambahkan karyawan ke proyek.

### 6. main.sql

File utama yang menjalankan semua script lainnya dan memberikan contoh penggunaan.

## Cara Penggunaan

1. Pastikan semua file berada dalam satu direktori.
2. Hubungkan ke database Oracle Anda.
3. Jalankan file main.sql untuk mengeksekusi seluruh proyek.
4. Jalankan file clear.sql untuk drop semua tabel.
