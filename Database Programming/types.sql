-- Membuat tipe objek Karyawan
CREATE OR REPLACE TYPE Karyawan AS OBJECT (
    id_karyawan NUMBER,
    nama VARCHAR2(100),
    tanggal_lahir DATE,
    departemen VARCHAR2(50),
    gaji NUMBER,
    
    MEMBER FUNCTION hitung_usia RETURN NUMBER,
    MEMBER PROCEDURE naikkan_gaji(persentase NUMBER)
);
/

-- Implementasi metode Karyawan
CREATE OR REPLACE TYPE BODY Karyawan AS
    MEMBER FUNCTION hitung_usia RETURN NUMBER IS
    BEGIN
        RETURN TRUNC(MONTHS_BETWEEN(SYSDATE, tanggal_lahir) / 12);
    END hitung_usia;
    
    MEMBER PROCEDURE naikkan_gaji(persentase NUMBER) IS
    BEGIN
        SELF.gaji := SELF.gaji * (1 + persentase/100);
    END naikkan_gaji;
END;
/

-- Membuat tipe objek Proyek
CREATE OR REPLACE TYPE Proyek AS OBJECT (
    id_proyek NUMBER,
    nama_proyek VARCHAR2(100),
    tanggal_mulai DATE,
    tanggal_selesai DATE,
    
    MEMBER FUNCTION hitung_durasi RETURN NUMBER
);
/

-- Implementasi metode Proyek
CREATE OR REPLACE TYPE BODY Proyek AS
    MEMBER FUNCTION hitung_durasi RETURN NUMBER IS
    BEGIN
        RETURN tanggal_selesai - tanggal_mulai;
    END hitung_durasi;
END;
/