-- Membuat view untuk menampilkan informasi karyawan dan proyek
CREATE OR REPLACE VIEW view_karyawan_proyek AS
SELECT 
    k.id_karyawan,
    k.nama AS nama_karyawan,
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

-- Stored Procedure untuk menaikkan gaji karyawan berdasarkan performa
CREATE OR REPLACE PROCEDURE naikkan_gaji_karyawan(
    p_id_karyawan IN NUMBER,
    p_persentase IN NUMBER
) AS
    v_karyawan Karyawan;
BEGIN
    SELECT VALUE(k) INTO v_karyawan
    FROM tabel_karyawan k
    WHERE k.id_karyawan = p_id_karyawan;
    
    v_karyawan.naikkan_gaji(p_persentase);
    
    UPDATE tabel_karyawan k
    SET k = v_karyawan
    WHERE k.id_karyawan = p_id_karyawan;
    
    COMMIT;
    DBMS_OUTPUT.PUT_LINE('Gaji karyawan ' || v_karyawan.nama || ' telah dinaikkan sebesar ' || p_persentase || '%');
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('Karyawan dengan ID ' || p_id_karyawan || ' tidak ditemukan.');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Terjadi kesalahan: ' || SQLERRM);
        ROLLBACK;
END;
/
