-- Memasukkan data ke tabel Karyawan
INSERT INTO tabel_karyawan VALUES (
    Karyawan(1, 'John Doe', TO_DATE('1990-05-15', 'YYYY-MM-DD'), 'IT', 5000)
);

INSERT INTO tabel_karyawan VALUES (
    Karyawan(2, 'Jane Smith', TO_DATE('1985-09-20', 'YYYY-MM-DD'), 'HR', 5500)
);

-- Memasukkan data ke tabel Proyek
INSERT INTO tabel_proyek VALUES (
    Proyek(1, 'Website Redesign', TO_DATE('2024-01-01', 'YYYY-MM-DD'), TO_DATE('2024-03-31', 'YYYY-MM-DD'))
);

INSERT INTO tabel_proyek VALUES (
    Proyek(2, 'Mobile App Development', TO_DATE('2024-02-01', 'YYYY-MM-DD'), TO_DATE('2024-07-31', 'YYYY-MM-DD'))
);

-- Memasukkan data ke tabel relasi
INSERT INTO karyawan_proyek VALUES (1, 1, 'Developer');
INSERT INTO karyawan_proyek VALUES (1, 2, 'Team Lead');
INSERT INTO karyawan_proyek VALUES (2, 1, 'Project Manager');