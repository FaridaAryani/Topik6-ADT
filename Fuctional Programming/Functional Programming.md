# Contoh source code berparadigma **Functional Programming**, menggunakan bahasa **Haskell**

## Source Code: Program Menghitung Faktorial dengan Rekursi

```haskell
-- Fungsi untuk menghitung faktorial dari suatu bilangan menggunakan rekursi
factorial :: Integer -> Integer
factorial 0 = 1  -- Basis rekursi: faktorial 0 adalah 1
factorial n = n * factorial (n - 1)  -- Rekursi: n! = n * (n-1)!

-- Fungsi untuk menghitung faktorial dari setiap elemen dalam sebuah list
factorialList :: [Integer] -> [Integer]
factorialList = map factorial

-- Fungsi utama untuk menjalankan program
main :: IO ()
main = do
    -- Mencetak faktorial dari satu angka
    print (factorial 5)  -- Output: 120
    
    -- Mencetak faktorial dari beberapa angka
    print (factorialList [1, 2, 3, 4, 5])  -- Output: [1, 2, 6, 24, 120]
```

### Penjelasan Detil

1. **Tipe Data dan Fungsi Murni**

   ```haskell
   factorial :: Integer -> Integer
   ```

   - Baris ini mendefinisikan tipe fungsi `factorial`, yang mengambil satu input bertipe `Integer` dan mengembalikan nilai bertipe `Integer`.
   - Fungsi ini adalah **pure function**, artinya hasilnya hanya bergantung pada inputnya dan tidak menyebabkan efek samping (misalnya, tidak mengubah variabel global atau melakukan operasi I/O).

2. **Basis Rekursi (Base Case)**
  
   ```haskell
   factorial 0 = 1
   ```

   - Ini adalah kasus dasar dalam rekursi. Jika input `n` sama dengan `0`, maka nilai yang dikembalikan adalah `1` karena secara matematis, `0! = 1`.
   - Ini menghindari rekursi tanpa batas, karena akan ada kondisi berhenti (stop condition).

3. **Rekursi**

   ```haskell
   factorial n = n * factorial (n - 1)
   ```

   - Ini adalah bagian rekursif dari fungsi. Untuk setiap nilai `n`, fungsi akan memanggil dirinya sendiri dengan argumen `n-1` hingga mencapai kasus dasar `factorial 0`.
   - Proses ini menggambarkan **recursive function**, yang umum dalam pemrograman fungsional sebagai pengganti loop.

4. **Higher-order Function: `map`**

   ```haskell
   factorialList :: [Integer] -> [Integer]
   factorialList = map factorial
   ```

   - Fungsi `factorialList` mengambil sebuah **list** dari bilangan bertipe `Integer` dan mengembalikan list baru yang berisi hasil faktorial dari setiap elemen list.
   - Di sini kita menggunakan fungsi bawaan Haskell yaitu `map`, yang merupakan contoh **higher-order function**. `map` menerima sebuah fungsi (`factorial`) dan menerapkannya ke setiap elemen dalam list.
   - Ini adalah contoh bagaimana Haskell mendukung **first-class functions**: fungsi dapat diteruskan ke fungsi lain sebagai argumen.

5. **Fungsi `main` dan I/O**

   ```haskell
   main :: IO ()
   main = do
       print (factorial 5)
       print (factorialList [1, 2, 3, 4, 5])
   ```

   - Haskell adalah bahasa pemrograman murni, sehingga semua input/output (I/O) seperti `print` harus dinyatakan secara eksplisit. Fungsi `main` adalah titik masuk (entry point) program.
   - Fungsi `print` digunakan untuk mencetak hasil dari pemanggilan fungsi `factorial` dan `factorialList` ke layar.
   - Tipe `IO ()` menunjukkan bahwa fungsi ini melibatkan I/O dan tidak mengembalikan nilai.

### Proses Eksekusi

1. Ketika program dijalankan, `main` akan dieksekusi.
2. Pertama, program akan mencetak hasil dari `factorial 5`:
   - Untuk `factorial 5`, proses rekursi adalah sebagai berikut:
     - `factorial 5 = 5 * factorial 4`
     - `factorial 4 = 4 * factorial 3`
     - `factorial 3 = 3 * factorial 2`
     - `factorial 2 = 2 * factorial 1`
     - `factorial 1 = 1 * factorial 0`
     - `factorial 0 = 1` (basis rekursi)
     - Dengan demikian, hasil akhir dari `factorial 5` adalah `120`.
3. Kedua, program akan mencetak hasil dari `factorialList [1, 2, 3, 4, 5]`, yang menghasilkan list baru `[1, 2, 6, 24, 120]`, di mana setiap elemen merupakan hasil faktorial dari elemen pada posisi yang sama di list input.

### Intisari Konsep

- **Pure Functions**: `factorial` adalah fungsi murni karena hasilnya hanya bergantung pada input dan tidak memiliki efek samping.
- **Recursion**: Rekursi menggantikan loop imperative.
- **Higher-order Functions**: `map` adalah contoh dari fungsi tingkat tinggi yang menerima fungsi lain sebagai argumen.
- **Immutability**: Semua nilai bersifat immutable (tidak berubah) di Haskell. Sebagai contoh, list yang dihasilkan dari `map` adalah list baru tanpa mengubah list asli.

Haskell dan Functional Programming cocok digunakan untuk pemrograman yang memerlukan kejelasan, prediktabilitas, dan keamanan dari perubahan state yang tak terduga.
