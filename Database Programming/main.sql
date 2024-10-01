-- File utama untuk menjalankan semua script

-- Menjalankan script pembuatan tipe
@types.sql

-- Menjalankan script pembuatan tabel
@tables.sql

-- Menjalankan script insersi data
@data.sql

-- Menjalankan script pembuatan view
@views.sql

-- Menjalankan script pembuatan stored procedures
@procedures.sql

-- Contoh penggunaan
EXEC naikkan_gaji_karyawan(1, 10);
EXEC tambah_karyawan_ke_proyek(2, 2, 'Designer');

-- Menampilkan data menggunakan view
SELECT * FROM view_karyawan_proyek;