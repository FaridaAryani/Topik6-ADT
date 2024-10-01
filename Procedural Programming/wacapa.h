typedef struct{
    char *Nama[100];
    int score;
}Player;

Player Player1, Player2;

typedef struct{
    char AngkaAwal[8][8];
    int Dimensi;
    int sisakotak;
}papan;

typedef struct{
    int Baris, Kolom;
    char pembatas;
}Kotak;

	papan Board;
    Kotak Input;
// Header Modul

void TampilMenu();
/*Prosedur untuk menampilkan main menu awal. Berisi opsi :
1. mulai game
2. intruksi
3. highscore
4. quit
I.S: Judul program belum tampil di layar
F.S: Judul program tampil di layar
*/

void input(int *input);
/*Prosedur untuk menginput integer yang akan dikembalikan ke dalam parameter formal
bernama input (dapat digunakan untuk semua input variabel bertipe integer)
I.S: Variabel bertipe integer belum memiliki value
F.S: Variabel bertipe integer sudah terinput value
*/

void CetakLoading();
/*Prosedur untuk menampilkan loading Bar yang digunakan ketika user memilih 1/2/3
I.S : Loading Bar belum tampil di layar
F.S : Loading Bar sudah tampil di layar 
*/

void gotoxy(int x, int y);
/*Prosedur untuk memidahkan kursor ke letak x,y terkait di layar konsol Parameter input nilai x dan y
      Sumber referensi : https://www.geeksforgeeks.org/how-to-use-gotoxy-in-codeblocks/ */


void CetakNama(Player *Player1, Player *Player2);
/*Prosedur untuk memampilkan kata-kata perintah agar user 1 dan 2 menginput nama
lalu memanggil modul untuk menginput nama user 1 dan 2
I.S: Perintah masukkan nama belum muncul di layar
F.S: Perintah masukkan nama dan penginputan nama sudah tersedia
*/

void CetakDimensi(); 
/*Prosedur untuk menampilkan opsi dimensi yang akan dipilih
1. dimensi 3x3
2. dimensi 5x5
3. dimensi 7x7 
I.S: Menu dimensi papan belum muncul di layar
F.S: Menu dimensi papan muncul di layar
*/

void CetakIntruksi();
/*Prosedur berisi intruksi permainan tic tac toe untuk dimensi 3x3, 5x5, dan 7x7
I.S: Instruksi belum muncul dilayar
F.S: Instruksi muncul di layar
*/

void CetakQuit();
/*Prosedur berisi kata-kata untuk bermain kembali kepada player
*/

void InputNama(char *Nama[100]);
/*Prosedur untuk menerima input nama dari user berupa satu string yang akan 
masuk ke dalam variabel *Nama
I.S: Nama user belum ada
F.S: Nama user sudah terinput
*/

void CetakPapan(char AngkaAwal[8][8], int Dimensi, char *Nama1, int score1, char *Nama2, int score2);
/*Prosedur untuk menampilkan papan tic tac toe dimensi 3x3,5x5, dan 7x7 dengan memasukkan 
sebuah angka ke dalam variabel dimensi. 
jika 1 : menampilkan papan 3x3
jika 2 : menampilkan papan 5x5
jika 3 : menampilkan papan 7x7
I.S: Papan belum muncul
F.S: Papan sudah muncul
*/

void CetakSisa(int *sisakotak);
/*Prosedur untuk menampilkan sisakotak yang masih dapat diisi user dengan passing
variabel sisakotak
I.S: Sisakotak belum muncul
F.S: Sisakotak sudah muncul
*/

void Inputkotak(Kotak *Put);
/*Prosedur untuk menerima nilai baris dan kolom yang diinput oleh user yang 
akan masuk ke dalam variabel baris (integer), pemabatas (char) dan kolom (integer)
yang terdapat dalam struct Kotak
I.S: Input untuk baris, pembatas dan kolom belum tersedia
F.S: Input untuk baris, pembatas dan kolom belum tersedia
*/       

void CekValid();
/*Prosedur untuk  menampilkan Invalid move
I.S: Kata Invalid belum muncul
F.S: Kata Invalid sudah muncul
*/

int KondisiWin(char AngkaAwal[8][8], int Dimensi);
/*Function untuk mengecek kondisi win 3x3, 5x5 dan 7x7 lalu mengembalikan nilai 1 atau 2 
berdasarkan kondisi yang sudah ditentukan berdasarkan dimensinya masing-masing 
jika mengembalikan nilai 1: menang untuk user 1
jika mengembalikan nilai 2: menang untuk user 2
*/

void Cetakmenang(Player Pemain);
/*Prosedur untuk menampilkan kondisi menang untuk player ketika variabel Win bernilai != 0
jika 1 : menampilkan kondisi menang untuk player 1
jika 2 : menampilkan kondisi menang untuk player 2
I.S: Kondisi menang belum muncul
F.S: Kondisi menang sudah muncul
*/

void CetakDraw();
/*Prosedur untuk menampilkan kondisi draw ketika giliran sudah habis dan
 variabel Win masih tetap bernilai = 0
 I.S: Kondisi draw belum muncul
 F.S: Kondisi draw sudah muncul
*/

void HapusKotak(char AngkaAwal[8][8]);
/*Prosedur yang berfungsi untuk mengisi kotak dengan 'spasi' agar variabel dalam papan
kembali kosong
I.S: Variabel dalam papan berisi char game sebelumnya
F.S: Variabel dalam papan kembali kosong 
*/

int CetakMainLagi();
/*Function untuk menampilkan pertanyaan akan bermain lagi atau kembali ke main menu,
di dalam function memanggil modul input dengan passing variabel aftergame dan
mengembalikan nilai variabel aftergame yaitu 1 atau 2
jika 1: bermain lagi dengan nama user 1 dan 2 yang sama dan memilih kembali dimensi
jika 2: kembali ke main menu
*/

void SusunHighScore();
/*Untuk menambahkan nama dan skor dari player 1 dan 2 pada file binary yang telah disediakan
I.S: File kosong
F.S: File berisi nama dan skor dari player 1 dan 2
*/

int JumlahBarisFile();
void PapanSkor();
/*Menampilkan Papan Skor
*/
void tampilkanHighscore();
/*Menampilkan High skor
*/
void InputHighScore(Player Pemain);
/*Untuk menampung skor pemain
*/

//void Selisih();
