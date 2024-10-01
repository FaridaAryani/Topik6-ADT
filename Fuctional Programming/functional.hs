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
