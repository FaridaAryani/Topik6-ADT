-- MEMBERSIHKAN DATABASE
-- Menghapus stored procedures
DROP PROCEDURE naikkan_gaji_karyawan;
DROP PROCEDURE tambah_karyawan_ke_proyek;

-- Menghapus view
DROP VIEW view_karyawan_proyek;

-- Menghapus tabel relasi
DROP TABLE karyawan_proyek;

-- Menghapus tabel objek
DROP TABLE tabel_karyawan;
DROP TABLE tabel_proyek;

-- Menghapus tipe objek
DROP TYPE Karyawan FORCE;
DROP TYPE Proyek FORCE;