-- Stored Procedure untuk menambahkan karyawan ke proyek
CREATE OR REPLACE PROCEDURE tambah_karyawan_ke_proyek(
    p_id_karyawan IN NUMBER,
    p_id_proyek IN NUMBER,
    p_peran IN VARCHAR2
) AS
    v_count NUMBER;
BEGIN
    -- Cek apakah karyawan ada
    SELECT COUNT(*) INTO v_count FROM tabel_karyawan WHERE id_karyawan = p_id_karyawan;
    IF v_count = 0 THEN
        RAISE_APPLICATION_ERROR(-20001, 'Karyawan tidak ditemukan');
    END IF;
    
    -- Cek apakah proyek ada
    SELECT COUNT(*) INTO v_count FROM tabel_proyek WHERE id_proyek = p_id_proyek;
    IF v_count = 0 THEN
        RAISE_APPLICATION_ERROR(-20002, 'Proyek tidak ditemukan');
    END IF;
    
    -- Tambahkan ke tabel relasi
    INSERT INTO karyawan_proyek (id_karyawan, id_proyek, peran)
    VALUES (p_id_karyawan, p_id_proyek, p_peran);
    
    COMMIT;
    DBMS_OUTPUT.PUT_LINE('Karyawan berhasil ditambahkan ke proyek');
EXCEPTION
    WHEN DUP_VAL_ON_INDEX THEN
        DBMS_OUTPUT.PUT_LINE('Karyawan sudah terdaftar dalam proyek ini');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Terjadi kesalahan: ' || SQLERRM);
        ROLLBACK;
END;
/