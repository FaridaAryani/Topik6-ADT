-- Membuat tabel Karyawan
CREATE TABLE tabel_karyawan OF Karyawan;

-- Membuat tabel Proyek
CREATE TABLE tabel_proyek OF Proyek;

-- Membuat tabel relasi Karyawan-Proyek
CREATE TABLE karyawan_proyek (
    id_karyawan NUMBER,
    id_proyek NUMBER,
    peran VARCHAR2(50)
);