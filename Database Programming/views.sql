-- Membuat view untuk menampilkan informasi karyawan dan proyek
CREATE OR REPLACE VIEW view_karyawan_proyek AS
SELECT 
    k.id_karyawan,
    k.nama AS nama_karyawan,
    k.hitung_usia() AS usia,
    k.departemen,
    p.id_proyek,
    p.nama_proyek,
    kp.peran,
    p.tanggal_mulai,
    p.tanggal_selesai,
    p.hitung_durasi() AS durasi_proyek
FROM 
    tabel_karyawan k
    JOIN karyawan_proyek kp ON k.id_karyawan = kp.id_karyawan
    JOIN tabel_proyek p ON kp.id_proyek = p.id_proyek;