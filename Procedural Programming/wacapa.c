#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "wacapa.h"
#include <stdlib.h>


/*
	Kelompok : wacapa
	Anggota : Carissa Amanda Crisanty Lesmana (231524003)
			  Farida Ariyani (23152405)
			  Fitri Salwa (231524009)
	GAME TICTACTOE
*/


void menu(){
	int counter, Giliran, batas, Win;
    int AwalGame, AfterGame;
    time_t waktu, waktusesudah;

	Win= 0; 
	AwalGame=00;
    Player1.score=0;
    Player2.score=0;
    
	
    while(AwalGame==00){ 
    	HapusKotak(Board.AngkaAwal);
        TampilMenu();
        input(&AwalGame);
        system("cls");
        CetakLoading();
        system("cls");
        switch (AwalGame){
            case 1: CetakNama(&Player1,&Player2);
                	while(AwalGame==1){
	                    CetakDimensi();
	                    input(&Board.Dimensi);
                        system("cls");
	                    while(Board.Dimensi>3 || Board.Dimensi<1){
	                    	CetakDimensi();
	                    	input(&Board.Dimensi);
	                    	system("cls");
						}
	                    switch(Board.Dimensi){
	                    	case 1 : batas=9;break;
	                    	case 2 : batas=25;break;
	                    	case 3 : batas=49;break;
						}
	                    system("cls"); 
                        CetakPapan(Board.AngkaAwal,Board.Dimensi,Player1.Nama,Player1.score,Player2.Nama,Player2.score);
                        Board.sisakotak=batas;
                        CetakSisa(&Board.sisakotak);
                        for(Giliran=1; Giliran<batas && (Win==0 && Board.sisakotak>1) ; Giliran++){
                            Win=0;                                      //Win=0, untuk kondisi awal, jika tidak berubah maka draw
                            if(Giliran%2==1){
                                printf(" %s Turn",Player1.Nama);
                                counter=0;                              //Counter untuk menghentikan while
                                while(counter==0){
//                                	Selisih();
                                    printf("\n Input Kotak [Baris],[Kolom]: ");
                                    InputKotak(&Input);
//                                    Selisih();
                                    waktu= time(NULL);
                                    waktusesudah= time(NULL);
                                    if(waktusesudah - waktu>=10){
                                        printf("\nWaktu Habis!!!\n\n");
                                        batas=batas+1;
                                        counter=1;
                                    }
                                    else if(Input.Baris>sqrt(batas) || Input.Baris<1 || Input.Kolom>sqrt(batas) || Input.Kolom<1 || Input.pembatas!=','){
                                        CekValid();
                                    }
                                    else if((Board.AngkaAwal[Input.Baris][Input.Kolom]=='X') || Board.AngkaAwal[Input.Baris][Input.Kolom]=='O'){
                                            CekValid();                           //Jika menginput kotak yang sudah di isi
                                    }
                                    else{
                                        system("cls");
                                        counter=1;
                                        Board.AngkaAwal[Input.Baris][Input.Kolom]='X';                                  //Proses mengisi board dengan simbol 
                                        CetakPapan(Board.AngkaAwal,Board.Dimensi,Player1.Nama,Player1.score,Player2.Nama,Player2.score);
                                        Board.sisakotak--;
                                        CetakSisa(&Board.sisakotak);   
                                    }
                                }
                                Win=KondisiWin(Board.AngkaAwal,Board.Dimensi);
                                if(Win==1){
                                CetakMenang(Player1.Nama);
                                Player1.score= Player1.score + 1;
                                }
                            }
                            else{   
                                printf(" %s Turn",Player2.Nama);
                                counter=0;
                                while(counter==0){
//                                	Selisih();
                                    printf("\n Input Kotak [Baris],[Kolom]: ");
                                    InputKotak(&Input);
//                                    Selisih();
                                    waktu= time(NULL);
                                    waktusesudah= time(NULL);
                                    if(waktusesudah - waktu>=10){
                                        printf("\nWaktu Habis!!!\n\n");
                                        batas=batas+1;
                                        counter=1;
                                    }
                                    else if(Input.Baris>sqrt(batas) || Input.Baris<1 || Input.Kolom>sqrt(batas) || Input.Kolom<1 || Input.pembatas!=','){
                                        CekValid();
                                    }
                                    else if((Board.AngkaAwal[Input.Baris][Input.Kolom]=='X') || Board.AngkaAwal[Input.Baris][Input.Kolom]=='O'){
                                        CekValid();                           //Jika menginput kotak yang sudah di isi
                                    }
                                    else{
                                        system("cls");
                                        counter=1;
                                        Board.AngkaAwal[Input.Baris][Input.Kolom]='O';                                  //Proses mengisi board dengan simbol 
                                        CetakPapan(Board.AngkaAwal,Board.Dimensi,Player1.Nama,Player1.score,Player2.Nama,Player2.score);                                               
                                        Board.sisakotak--;
                                        CetakSisa(&Board.sisakotak);   
                                    }
                                }
                                Win=KondisiWin(Board.AngkaAwal,Board.Dimensi);
                                if(Win==2){
                                    CetakMenang(Player2.Nama);
                                    Player2.score= Player2.score + 1;
                                }
                            }
                            if(Win != 0){               //Jika variabel win berubah, maka loop akan lgsg berhenti, break
                                break;
                            }
                        } 
                            if(Win==0){
                                CetakDraw();      //Jika variabel win tetap 0 seperti diawal, maka akan terjadi draw
                            }
                            HapusKotak(Board.AngkaAwal);
                            counter=0;
                            InputHighScore(Player1);
                    		InputHighScore(Player2);
                            while(counter==0){
                                AfterGame=CetakMainLagi();
                                if(AfterGame>2){
                                	system("cls");
                                    CekValid();
                                }
                    			
                                if(AfterGame==1){
                                	system("cls");
                                    AwalGame=1;
                                    counter=1;
                                    Win=0;
                                }
                                else if(AfterGame==2){
                                	system("cls");
                                    AwalGame=00;
                                    counter=1;
                                    Win=0;
                                }
                            }
                            
                    }break;
                                    
            case 2: 
                    CetakIntruksi();
                    input(&AwalGame);
                    system("cls");
                    break;

            case 3:
            		mainHightScore();
                    input(&AwalGame);
                    system("cls");
                    break;

            case 4: 
                    CetakQuit();
                    return 0;
                    break;

            default: 
                    AwalGame=00;
                    break;
        }
    }
    return 0;
}               

//BodyModul

void TampilMenu(){
	system("color F1");
   	printf("\n\n");
    printf("\t\t\t\t   _______ _        _______           _______ \n");
    printf("\t\t\t\t  |__   __(_)      |__   __|         |__   __|\n");
    printf("\t\t\t\t     | |   _  ___     | | __ _  ___     | | ___   ___ \n");
    printf("\t\t\t\t     | |  | |/ _ \\    | |/ _` |/ _ \\    | |/ _ \\ / _ \\\n");
    printf("\t\t\t\t     | |  | | (_      | | (_| |  |__    | | (_) |  __/\n");
    printf("\t\t\t\t     |_|  |_|\\___/    |_|\\___ |\\___/    |_|\\___/ \\___|\n");
    printf("\t\t\t\t                            |_/                     \n");
    printf("\t\t\t\t	========================================================   \n\n");
    printf(" \t\t\t\t\t\t   +--------------------+\n");
    printf(" \t\t\t\t\t\t   |        Menu        |\n");
    printf(" \t\t\t\t\t\t   |--------------------|\n");
    printf(" \t\t\t\t\t\t   |1. Mulai            |\n");
    printf(" \t\t\t\t\t\t   |2. Aturan           |\n");
    printf(" \t\t\t\t\t\t   |3. Leaderboard      |\n");
    printf(" \t\t\t\t\t\t   |4. Keluar game      |\n");
    printf(" \t\t\t\t\t\t   +--------------------+\n\n");
    printf("  Apa yang ingin kamu lakuin? (masukan nomor) : ");
}

void input(int *input){ 
	scanf("%d", &*input);
}

void CetakLoading(){
	system("color 0D");
    int i,j;
    char AKI,Ver,BKI,Hor,BKA,AKA;
    // Kode ASCII untuk membentuk kotak loading
    AKI = 201;  //Atas Kiri
    Ver = 186;  //Vertikal
    BKI = 200;   //Bawah Kiri
    Hor = 205;  //Horizontal
    BKA = 188;  //Bawah Kanan
    AKA = 187;  //Atas Kanan
    for ( i = 1; i < 5; i++)
    {
        for ( j = 1; j < 35; j++)
        {
            if (i == 1 && j == 1)
            {
                gotoxy(38,6);
                printf("%c",AKI);
            }
            if (i == 1 && j == 34)
            {
                gotoxy(71,6);
                printf("%c",AKA);
            }
            if (i == 3 && j == 1)
            {
                gotoxy(38,8);
                printf("%c",BKI);
            }
            if (i == 3 && j == 34)
            {
                gotoxy(71,8);
                printf("%c",BKA);
            }
            if (i == 1 || i == 3)
            {
                if (j > 1 && j < 34)
                {
                    printf("%c",Hor);
                }
            }
            if (j == 1 || j == 34)
            {
                if (i == 2 && j == 34)
                {
                    gotoxy(71,7);
                    printf("%c",Ver);
                }
                if (i == 2 && j == 1)
                {
                    gotoxy(38,7);
                    printf("%c",Ver);
                }
                
            }
            
        }
        
    }
    
    gotoxy(49,5);
    printf("Tunggu Sebentar....\n");
    gotoxy(40,7);
    for ( i = 0; i < 30; i++)      //30 teh mau ada brp kotaknya
    {
        printf("%c",145);       // kode ascii simbol
        Sleep(40);
    }
    gotoxy(49,5);
    printf("KLIK ENTER YA!! ");
    getche();       //hrs enter dl biar ke next
}

void gotoxy(int x, int y)   //buat memanipulasi tampilan di layar monitor 
{                           //jdi nnti tulisan bisa di tengah langsung berdasarkan koordinatnya tanpa pke printf banyak
    COORD K;
    K.X = x;
    K.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),K);
}

void CetakNama(Player *Player1, Player *Player2){
	printf("\n \t\t\tMasukkan Nama Pemain: \n");
    printf("\t\t\t--------------------\n");
    
    InputNama(Player1->Nama);
 //   InputNama(Player2->Nama);
    
//    printf(" Player 1 (X): ", Player1->Nama);
//    printf(" Player 2 (O): ", Player2->Nama);
}

void CetakDimensi(){
    printf("\nPilih Dimensi Board Yang Akan Anda Mainkan: \n");
    printf("\n\t\t=======================");
    printf("\n\t\t||\t       \t     ||");
    printf("\n\t\t||\t1. 3x3 \t     ||");
    printf("\n\t\t||\t2. 5x5 \t     ||");
    printf("\n\t\t||\t3. 7x7 \t     ||\n");
    printf("\t\t||\t             ||\n");
    printf("\t\t=======================\n");
    printf("\nMasukkan Angka (1/2/3): ");
}

void CetakIntruksi(){
    char simbol[5]={4,4};
    printf("\n\t\t\t\t\t\t%c\tIntruksi\t%c\n", simbol[0], simbol[1]);
 	printf("\t\t\t\t\t=========================================\n\n");
	printf("\t==========================================================================================================\n");
	printf("\t||                                                                                                      ||\n");
    printf("\t|| 1. Player memilih opsi 1 untuk memulai permainan.\t\t\t\t\t\t\t||\n");
	printf("\t|| 2. Player akan diminta mengisi nama.\t\t\t\t\t\t\t\t\t||\n");
    printf("\t|| 3. Player akan diminta memilih dimensi board yang akan dimainkan.\t\t\t\t\t||\n");
	printf("\t|| 4. Player akan diminta menginput baris dan kolom, sesuai dengan kotak yang ingin di isi \t\t||\n");
	printf("\t|| 5. Player akan diberi waktu selama 10 detik untuk mengisi kotak.\t\t\t\t\t||\n");
	printf("\t|| 6. Player tidak bisa mengisi kotak yang sudah terisi sebelumnya, jika terisi maka akan invalid.   \t||\n");
    printf("\t|| 7. Player tidak bisa menginput baris/kolom diluar jangkauan board yang dipilih,    \t\t\t||\n");
    printf("\t||     jika dipilih maka akan invalid.    \t\t\t\t\t\t\t\t||\n");
	printf("\t|| 8. Player dinyatakan menang jika bisa membuat garis pertama secara horizontal,vertikal, \t\t||\n");
    printf("\t||     ataupun diagonal dari 3,4, atau 5 bidaknya (sesuai dimensi yang dipilih).   \t\t\t||\n");
	printf("\t|| 9. Permainan dinyatakan draw jika board sudah terisi penuh dan keduanya tidak membuat \t\t||\n");
    printf("\t||     3,4, atau 5 bidaknya (sesuai dimensi yang dipilih).   \t\t\t\t\t\t||\n");
	printf("\t|| 10. Player dinyatakan kalah jika lawan yang pertama membuat garis dari ketiga bidaknya.         \t||\n");
    printf("\t|| 11. Jika game sudah selesai, player akan diberikan pilihan untuk kembali main atau tidak.    \t||\n");
	printf("\t||                                                                                                      ||\n");
	printf("\t||======================================================================================================||\n\n");
	printf("\n\n\t Kembali(00) : ");	
}

void CetakQuit(){
    printf("\n\t\t\t\t   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _  \n");
    printf("\t\t\t\t  / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ \n");
    printf("\t\t\t\t ( n | a | n | t | i |   | m | a | i | n |   | l | a | g | i |   | n | a | n | t | i |   | m | a | i | n )\n");
    printf("\t\t\t\t  \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \n");
    printf("\t\t\t\t                                                                                                        \n");
}

void InputNama(char *Nama[100]){
	do {
        printf(" Masukkan Nama Player 1: ");
        scanf(" %[^\n]", Player1.Nama);
        if (invalid(Player1.Nama)) {
            printf("Nama tidak boleh mengandung angka! Silakan coba lagi.\n");
        }
    } while (invalid(Player1.Nama));

    do {
        printf(" Masukkan Nama Player 2: ");
        scanf(" %[^\n]", Player2.Nama);
        if (invalid(Player2.Nama)) {
            printf("Nama tidak boleh mengandung angka! Silakan coba lagi.\n");
        }
    } while (invalid(Player2.Nama));

	}

void CetakPapan(char AngkaAwal[8][8], int Dimensi, char *Nama1, int score1, char *Nama2, int score2){
	system("color D0");
    if(Dimensi==1){
    	
    printf("\n\t\t1\t\t2\t\t3\t\t\t\t\t\t Score\n\n");
	printf("\t-------------------------------------------------\t\t\t\t\t %s: %d\n",Nama1,score1);
    printf("\t|\t\t|\t\t|\t\t|\t\t\t\t\t %s: %d\n",Nama2,score2);
    
    
    
    
    printf(" 1\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[1][1],AngkaAwal[1][2],AngkaAwal[1][3]);
    printf("\t|\t\t|\t\t|\t\t|\n");
    printf("\t|---------------+---------------+---------------|\n");
    printf("\t|\t\t|\t\t|\t\t|\n");
    printf(" 2\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[2][1],AngkaAwal[2][2],AngkaAwal[2][3]);
    printf("\t|\t\t|\t\t|\t\t|\n");
    printf("\t|---------------+---------------+---------------|\n");
    printf("\t|\t\t|\t\t|\t\t|\n");
    printf(" 3\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[3][1],AngkaAwal[3][2],AngkaAwal[3][3]); 
	printf("\t|\t\t|\t\t|\t\t|\n");
	printf("\t-------------------------------------------------\n\n");
    }
    else if(Dimensi==2){
    printf("\n\t\t1\t\t2\t\t3\t\t4\t\t5\t\t\t Score\n\n");
    printf("\t---------------------------------------------------------------------------------\t\t %s: %d\n",Nama1,score1);
    printf("\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t %s: %d\n",Nama2,score2);
    printf(" 1\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[1][1],AngkaAwal[1][2],AngkaAwal[1][3],AngkaAwal[1][4],AngkaAwal[1][5]);
    printf("\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf("\t|---------------+---------------+---------------+---------------+---------------|\n");
    printf("\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf(" 2\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[2][1],AngkaAwal[2][2],AngkaAwal[2][3],AngkaAwal[2][4],AngkaAwal[2][5]);
    printf("\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf("\t|---------------+---------------+---------------+---------------+---------------|\n");
    printf("\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf(" 3\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[3][1],AngkaAwal[3][2],AngkaAwal[3][3],AngkaAwal[3][4],AngkaAwal[3][5]);
    printf("\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf("\t|---------------+---------------+---------------+---------------+---------------|\n");
    printf("\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
	printf(" 4\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[4][1],AngkaAwal[4][2],AngkaAwal[4][3],AngkaAwal[4][4],AngkaAwal[4][5]);
	printf("\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
	printf("\t|---------------+---------------+---------------+---------------+---------------|\n");
	printf("\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
	printf(" 5\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[5][1],AngkaAwal[5][2],AngkaAwal[5][3],AngkaAwal[5][4],AngkaAwal[5][5]);
	printf("\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
	printf("\t---------------------------------------------------------------------------------\n\n");
    }
    else if(Dimensi==3){
    printf("\n   \t1\t\t2\t\t3\t\t4\t\t5\t\t6\t\t7\t\t Score\n\n");
    printf("   --------------------------------------------------------------------------------------------------------------\t %s: %d\n",Nama1,score1);
    printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t %s: %d\n",Nama2,score2);
    printf(" 1 |\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[1][1],AngkaAwal[1][2],AngkaAwal[1][3],AngkaAwal[1][4], AngkaAwal[1][5],AngkaAwal[1][6], AngkaAwal[1][7]);
	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf("   |------------+---------------+---------------+---------------+---------------+---------------+---------------|\n");
	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf(" 2 |\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[2][1],AngkaAwal[2][2],AngkaAwal[2][3],AngkaAwal[2][4], AngkaAwal[2][5], AngkaAwal[2][6], AngkaAwal[2][7]);
  	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf("   |------------+---------------+---------------+---------------+---------------+---------------+---------------|\n");
    printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf(" 3 |\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[3][1],AngkaAwal[3][2],AngkaAwal[3][3],AngkaAwal[3][4], AngkaAwal[3][5],AngkaAwal[3][6], AngkaAwal[3][7]);
	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf("   |------------+---------------+---------------+---------------+---------------+---------------+---------------|\n");
	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf(" 4 |\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[4][1],AngkaAwal[4][2],AngkaAwal[4][3],AngkaAwal[4][4], AngkaAwal[4][5], AngkaAwal[4][6], AngkaAwal[4][7]);
  	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf("   |------------+---------------+---------------+---------------+---------------+---------------+---------------|\n");
 	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf(" 5 |\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[5][1],AngkaAwal[5][2],AngkaAwal[5][3],AngkaAwal[5][4], AngkaAwal[5][5],AngkaAwal[5][6], AngkaAwal[5][7]);
	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf("   |------------+---------------+---------------+---------------+---------------+---------------+---------------|\n");
	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");	
    printf(" 6 |\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[6][1],AngkaAwal[6][2],AngkaAwal[6][3],AngkaAwal[6][4], AngkaAwal[6][5], AngkaAwal[6][6], AngkaAwal[6][7]);
  	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
    printf("   |------------+---------------+---------------+---------------+---------------+---------------+---------------|\n");
	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
	printf(" 7 |\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\t%c\t|\n",AngkaAwal[7][1],AngkaAwal[7][2],AngkaAwal[7][3],AngkaAwal[7][4], AngkaAwal[7][5], AngkaAwal[7][6], AngkaAwal[7][7]);
	printf("   |\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n");
	printf("   --------------------------------------------------------------------------------------------------------------\n\n");
    }
}

void CetakSisa(int *sisakotak){
	printf(" Sisa Kotak : %d\n\n", *sisakotak);
}

void InputKotak(Kotak *Put){
    
    scanf("%d%c%d",&Put->Baris,&Put->pembatas,&Put->Kolom);
}

void CekValid(){
        printf(" Invalid Move!!!\n");
}

int KondisiWin(char AngkaAwal[8][8], int Dimensi)
{
    if(Dimensi == 1)        //kondisi menang 3x3
    {
        if(AngkaAwal[1][1]=='X' && AngkaAwal[1][2]=='X' && AngkaAwal[1][3] == 'X'){                  //Kondisi Menang untuk Player 1
            return 1;
        } 
        else if(AngkaAwal[2][1]=='X' && AngkaAwal[2][2]=='X' && AngkaAwal[2][3] == 'X'){
             return 1;
        }
        else if(AngkaAwal[3][1]== 'X' && AngkaAwal[3][2]=='X' && AngkaAwal[3][3] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][1]=='X' && AngkaAwal[2][1]== 'X' && AngkaAwal[3][1] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][2]=='X' && AngkaAwal[2][2]== 'X' && AngkaAwal[3][2] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][3]=='X' && AngkaAwal[2][3]=='X' && AngkaAwal[3][3] == 'X'){
             return 1;
         }
        else if(AngkaAwal[1][1]=='X' && AngkaAwal[2][2]=='X' && AngkaAwal[3][3] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][3]=='X' && AngkaAwal[2][2]=='X' && AngkaAwal[3][1] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][1]=='O' && AngkaAwal[1][2]=='O' && AngkaAwal[1][3] == 'O'){                  //Kondisi Menang untuk Player 2
             return 2;
        } 
        else if(AngkaAwal[2][1]=='O' && AngkaAwal[2][2]=='O' && AngkaAwal[2][3] == 'O'){
             return 2;
        }
        else if(AngkaAwal[3][1]== 'O' && AngkaAwal[3][2]=='O' && AngkaAwal[3][3] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][1]=='O' && AngkaAwal[2][1]== 'O' && AngkaAwal[3][1] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][2]=='O' && AngkaAwal[2][2]== 'O' && AngkaAwal[3][2] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][3]=='O' && AngkaAwal[2][3]=='O' && AngkaAwal[3][3] == 'O'){
             return 2;
         }
        else if(AngkaAwal[1][1]=='O' && AngkaAwal[2][2]=='O' && AngkaAwal[3][3] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][3]=='O' && AngkaAwal[2][2]=='O' && AngkaAwal[3][1] == 'O'){
            return 2;
        }
        else{
            return 0;
        }
    }
    else if(Dimensi == 2)   //kondisi win 5x5
    {
        if(AngkaAwal[1][1]=='X' && AngkaAwal[1][2]=='X' && AngkaAwal[1][3] == 'X' && AngkaAwal[1][4] == 'X'){                  //Kondisi Menang untuk Player 1
            return 1;
        } 
        else if(AngkaAwal[1][5]=='X' && AngkaAwal[1][2]=='X' && AngkaAwal[1][3] == 'X' && AngkaAwal[1][4] == 'X'){                  
            return 1;
        } 
        else if(AngkaAwal[2][1]=='X' && AngkaAwal[2][2]=='X' && AngkaAwal[2][3] == 'X' && AngkaAwal[2][4] == 'X' ){
             return 1;
        }
        else if(AngkaAwal[2][2]=='X' && AngkaAwal[2][3] == 'X' && AngkaAwal[2][4] && AngkaAwal[2][5] == 'X'){
             return 1;
        }
        else if(AngkaAwal[3][1]== 'X' && AngkaAwal[3][2]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[3][4] == 'X'){
             return 1;
        }
        else if(AngkaAwal[3][2]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[3][4] == 'X' && AngkaAwal[3][5] == 'X'){
             return 1;
        }
        else if(AngkaAwal[4][1]== 'X' && AngkaAwal[4][2]=='X' && AngkaAwal[4][3] == 'X' && AngkaAwal[4][4] == 'X'){
             return 1;
        }
        else if(AngkaAwal[4][2]=='X' && AngkaAwal[4][3] == 'X' && AngkaAwal[4][4] == 'X' && AngkaAwal[4][5] == 'X'){
             return 1;
        }
         else if(AngkaAwal[5][1]== 'X' && AngkaAwal[5][2]=='X' && AngkaAwal[5][3] == 'X' && AngkaAwal[5][4] == 'X' ){
             return 1;
        }
        else if(AngkaAwal[5][2]=='X' && AngkaAwal[5][3] == 'X' && AngkaAwal[5][4] == 'X' && AngkaAwal[5][5] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][1]=='X' && AngkaAwal[2][1]== 'X' && AngkaAwal[3][1] == 'X' && AngkaAwal[4][1] == 'X'){	//6
             return 1;
        }
        else if(AngkaAwal[2][1]== 'X' && AngkaAwal[3][1] == 'X' && AngkaAwal[4][1] == 'X' && AngkaAwal[5][1] == 'X'){	//6
             return 1;
        }
        else if(AngkaAwal[1][2]=='X' && AngkaAwal[2][2]== 'X' && AngkaAwal[3][2] == 'X' && AngkaAwal[4][2] == 'X'){
             return 1;
        }
        else if(AngkaAwal[2][2]== 'X' && AngkaAwal[3][2] == 'X' && AngkaAwal[4][2] == 'X' && AngkaAwal[5][2] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][3]=='X' && AngkaAwal[2][3]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[4][3] == 'X'){
             return 1;
        }
        else if(AngkaAwal[2][3]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[4][3] == 'X' && AngkaAwal[5][3] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][4]=='X' && AngkaAwal[2][4]=='X' && AngkaAwal[3][4] == 'X' && AngkaAwal[4][4] == 'X'){
             return 1;
        }
        else if(AngkaAwal[2][4]=='X' && AngkaAwal[3][4] == 'X' && AngkaAwal[4][4] == 'X' && AngkaAwal[5][4] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][5]=='X' && AngkaAwal[2][5]=='X' && AngkaAwal[3][5] == 'X' && AngkaAwal[4][5] == 'X'){
             return 1;
        }
        else if(AngkaAwal[2][5]=='X' && AngkaAwal[3][5] == 'X' && AngkaAwal[4][5] == 'X' && AngkaAwal[5][5] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][1]=='X' && AngkaAwal[2][2]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[4][4] == 'X'){
             return 1;
        }
        else if(AngkaAwal[2][2]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[4][4] == 'X' && AngkaAwal[5][5] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][5]=='X' && AngkaAwal[2][4]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[4][2] == 'X'){
             return 1;
        }
        else if(AngkaAwal[2][4]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[4][2] == 'X' && AngkaAwal[5][1] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][2]=='X' && AngkaAwal[2][3] == 'X' && AngkaAwal[3][4] == 'X' && AngkaAwal[4][5] == 'X'){
             return 1;
        }
        else if(AngkaAwal[2][1]=='X' && AngkaAwal[3][2] == 'X' && AngkaAwal[4][3] == 'X' && AngkaAwal[5][4] == 'X'){
             return 1;
        }
        else if(AngkaAwal[1][4]=='X' && AngkaAwal[2][3] == 'X' && AngkaAwal[3][2] == 'X' && AngkaAwal[4][1] == 'X'){
             return 1;
        }
        else if(AngkaAwal[2][5]=='X' && AngkaAwal[3][4] == 'X' && AngkaAwal[4][3] == 'X' && AngkaAwal[5][2] == 'X'){
             return 1;
        }   
        else if(AngkaAwal[1][1]=='O' && AngkaAwal[1][2]=='O' && AngkaAwal[1][3] == 'O' && AngkaAwal[1][4] == 'O'){      //kondisi menang player2            
            return 2;
        } 
        else if(AngkaAwal[1][5]=='O' && AngkaAwal[1][2]=='O' && AngkaAwal[1][3] == 'O' && AngkaAwal[1][4] == 'O'){                  
            return 2;
        } 
        else if(AngkaAwal[2][1]=='O' && AngkaAwal[2][2]=='O' && AngkaAwal[2][3] == 'O' && AngkaAwal[2][4] == 'O' ){
             return 2;
        }
        else if(AngkaAwal[2][2]=='O' && AngkaAwal[2][3] == 'O' && AngkaAwal[2][4] && AngkaAwal[2][5] == 'O'){
             return 2;
        }
        else if(AngkaAwal[3][1]== 'O' && AngkaAwal[3][2]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[3][4] == 'O'){
             return 2;
        }
        else if(AngkaAwal[3][2]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[3][4] == 'O' && AngkaAwal[3][5] == 'O'){
             return 2;
        }
        else if(AngkaAwal[4][1]== 'O' && AngkaAwal[4][2]=='O' && AngkaAwal[4][3] == 'O' && AngkaAwal[4][4] == 'O'){
             return 2;
        }
        else if(AngkaAwal[4][2]=='O' && AngkaAwal[4][3] == 'O' && AngkaAwal[4][4] == 'O' && AngkaAwal[4][5] == 'O'){
             return 2;
        }
         else if(AngkaAwal[5][1]== 'O' && AngkaAwal[5][2]=='O' && AngkaAwal[5][3] == 'O' && AngkaAwal[5][4] == 'O' ){
             return 2;
        }
        else if(AngkaAwal[5][2]=='O' && AngkaAwal[5][3] == 'O' && AngkaAwal[5][4] == 'O' && AngkaAwal[5][5] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][1]=='O' && AngkaAwal[2][1]== 'O' && AngkaAwal[3][1] == 'O' && AngkaAwal[4][1] == 'O'){	
             return 2;
        }
        else if(AngkaAwal[2][1]== 'O' && AngkaAwal[3][1] == 'O' && AngkaAwal[4][1] == 'O' && AngkaAwal[5][1] == 'O'){	
             return 2;
        }
        else if(AngkaAwal[1][2]=='O' && AngkaAwal[2][2]== 'O' && AngkaAwal[3][2] == 'O' && AngkaAwal[4][2] == 'O'){
             return 2;
        }
        else if(AngkaAwal[2][2]== 'O' && AngkaAwal[3][2] == 'O' && AngkaAwal[4][2] == 'O' && AngkaAwal[5][2] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][3]=='O' && AngkaAwal[2][3]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[4][3] == 'O'){
             return 2;
        }
        else if(AngkaAwal[2][3]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[4][3] == 'O' && AngkaAwal[5][3] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][4]=='O' && AngkaAwal[2][4]=='O' && AngkaAwal[3][4] == 'O' && AngkaAwal[4][4] == 'O'){
             return 2;
        }
        else if(AngkaAwal[2][4]=='O' && AngkaAwal[3][4] == 'O' && AngkaAwal[4][4] == 'O' && AngkaAwal[5][4] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][5]=='O' && AngkaAwal[2][5]=='O' && AngkaAwal[3][5] == 'O' && AngkaAwal[4][5] == 'O'){
             return 2;
        }
        else if(AngkaAwal[2][5]=='O' && AngkaAwal[3][5] == 'O' && AngkaAwal[4][5] == 'O' && AngkaAwal[5][5] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][1]=='O' && AngkaAwal[2][2]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[4][4] == 'O'){
             return 2;
        }
        else if(AngkaAwal[2][2]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[4][4] == 'O' && AngkaAwal[5][5] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][5]=='O' && AngkaAwal[2][4]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[4][2] == 'O'){
             return 2;
        }
        else if(AngkaAwal[2][4]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[4][2] == 'O' && AngkaAwal[5][1] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][2]=='O' && AngkaAwal[2][3] == 'O' && AngkaAwal[3][4] == 'O' && AngkaAwal[4][5] == 'O'){
             return 2;
        }
        else if(AngkaAwal[2][1]=='O' && AngkaAwal[3][2] == 'O' && AngkaAwal[4][3] == 'O' && AngkaAwal[5][4] == 'O'){
             return 2;
        }
        else if(AngkaAwal[1][4]=='O' && AngkaAwal[2][3] == 'O' && AngkaAwal[3][2] == 'O' && AngkaAwal[4][1] == 'O'){
             return 2;
        }
        else if(AngkaAwal[2][5]=='O' && AngkaAwal[3][4] == 'O' && AngkaAwal[4][3] == 'O' && AngkaAwal[5][2] == 'O'){
             return 2;
        }
        else {
            return 0;
        }
    }
    else if(Dimensi == 3)   //kondisi win 7x7
    {
        if(AngkaAwal[1][1]=='X' && AngkaAwal[1][2]=='X' && AngkaAwal[1][3] == 'X' && AngkaAwal[1][4]== 'X' && AngkaAwal[1][5]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        } 
	
	else if(AngkaAwal[1][2]=='X' && AngkaAwal[1][3]=='X' && AngkaAwal[1][4] == 'X' && AngkaAwal[1][5]== 'X' && AngkaAwal[1][6]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        } 
        
    else if(AngkaAwal[1][3]=='X' && AngkaAwal[1][4]=='X' && AngkaAwal[1][5] == 'X' && AngkaAwal[1][6]== 'X' && AngkaAwal[1][7]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
	
	else if(AngkaAwal[2][1]=='X' && AngkaAwal[2][2]=='X' && AngkaAwal[2][3] == 'X' && AngkaAwal[2][4]== 'X' && AngkaAwal[2][5]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
	
	else if(AngkaAwal[2][2]=='X' && AngkaAwal[2][3]=='X' && AngkaAwal[2][4] == 'X' && AngkaAwal[2][5]== 'X' && AngkaAwal[2][6]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[2][3]=='X' && AngkaAwal[2][4]=='X' && AngkaAwal[2][5] == 'X' && AngkaAwal[2][6]== 'X' && AngkaAwal[2][7]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[3][1]=='X' && AngkaAwal[3][2]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[3][4]== 'X' && AngkaAwal[3][5]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
	
	else if(AngkaAwal[3][2]=='X' && AngkaAwal[3][3]=='X' && AngkaAwal[3][4] == 'X' && AngkaAwal[3][5]== 'X' && AngkaAwal[3][6]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[3][3]=='X' && AngkaAwal[3][4]=='X' && AngkaAwal[3][5] == 'X' && AngkaAwal[3][6]== 'X' && AngkaAwal[3][7]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[4][1]=='X' && AngkaAwal[4][2]=='X' && AngkaAwal[4][3] == 'X' && AngkaAwal[4][4]== 'X' && AngkaAwal[4][5]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
	
	else if(AngkaAwal[4][2]=='X' && AngkaAwal[4][3]=='X' && AngkaAwal[4][4] == 'X' && AngkaAwal[4][5]== 'X' && AngkaAwal[4][6]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[4][3]=='X' && AngkaAwal[4][4]=='X' && AngkaAwal[4][5] == 'X' && AngkaAwal[4][6]== 'X' && AngkaAwal[4][7]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[5][1]=='X' && AngkaAwal[5][2]=='X' && AngkaAwal[5][3] == 'X' && AngkaAwal[5][4]== 'X' && AngkaAwal[5][5]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
	
	else if(AngkaAwal[5][2]=='X' && AngkaAwal[5][3]=='X' && AngkaAwal[5][4] == 'X' && AngkaAwal[5][5]== 'X' && AngkaAwal[5][6]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[5][3]=='X' && AngkaAwal[5][4]=='X' && AngkaAwal[5][5] == 'X' && AngkaAwal[5][6]== 'X' && AngkaAwal[5][7]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[6][1]=='X' && AngkaAwal[6][2]=='X' && AngkaAwal[6][3] == 'X' && AngkaAwal[6][4]== 'X' && AngkaAwal[6][5]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
	
	else if(AngkaAwal[6][2]=='X' && AngkaAwal[6][3]=='X' && AngkaAwal[6][4] == 'X' && AngkaAwal[6][5]== 'X' && AngkaAwal[6][6]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[6][3]=='X' && AngkaAwal[6][4]=='X' && AngkaAwal[6][5] == 'X' && AngkaAwal[6][6]== 'X' && AngkaAwal[6][7]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[7][1]=='X' && AngkaAwal[7][2]=='X' && AngkaAwal[7][3] == 'X' && AngkaAwal[7][4]== 'X' && AngkaAwal[7][5]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
	
	else if(AngkaAwal[7][2]=='X' && AngkaAwal[7][3]=='X' && AngkaAwal[7][4] == 'X' && AngkaAwal[7][5]== 'X' && AngkaAwal[7][6]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[7][3]=='X' && AngkaAwal[7][4]=='X' && AngkaAwal[7][5] == 'X' && AngkaAwal[7][6]== 'X' && AngkaAwal[7][7]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[1][1]=='X' && AngkaAwal[2][1]=='X' && AngkaAwal[3][1] == 'X' && AngkaAwal[4][1]== 'X' && AngkaAwal[5][1]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }

    else if(AngkaAwal[2][1]=='X' && AngkaAwal[3][1]=='X' && AngkaAwal[4][1] == 'X' && AngkaAwal[5][1]== 'X' && AngkaAwal[6][1]== 'X'){                  //Kondisi Menang untuk Player 1
    	return 1;
        }
        
    else if(AngkaAwal[3][1]=='X' && AngkaAwal[4][1]=='X' && AngkaAwal[5][1] == 'X' && AngkaAwal[6][1]== 'X' && AngkaAwal[7][1]== 'X'){                  
    	return 1;
        }
        
    else if(AngkaAwal[1][2]=='X' && AngkaAwal[2][2]=='X' && AngkaAwal[3][2] == 'X' && AngkaAwal[4][2]== 'X' && AngkaAwal[5][2]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[2][2]=='X' && AngkaAwal[3][2]=='X' && AngkaAwal[4][2] == 'X' && AngkaAwal[5][2]== 'X' && AngkaAwal[6][2]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[3][2]=='X' && AngkaAwal[4][2]=='X' && AngkaAwal[5][2] == 'X' && AngkaAwal[6][2]== 'X' && AngkaAwal[7][2]== 'X'){                  
    	return 1;
        }
        
    else if(AngkaAwal[1][3]=='X' && AngkaAwal[2][3]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[4][3]== 'X' && AngkaAwal[5][3]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[2][3]=='X' && AngkaAwal[3][3]=='X' && AngkaAwal[4][3] == 'X' && AngkaAwal[5][3]== 'X' && AngkaAwal[6][3]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[3][3]=='X' && AngkaAwal[4][3]=='X' && AngkaAwal[5][3] == 'X' && AngkaAwal[6][3]== 'X' && AngkaAwal[7][3]== 'X'){                  
    	return 1;
        }
        
    else if(AngkaAwal[1][4]=='X' && AngkaAwal[2][4]=='X' && AngkaAwal[3][4] == 'X' && AngkaAwal[4][4]== 'X' && AngkaAwal[5][4]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[2][4]=='X' && AngkaAwal[3][4]=='X' && AngkaAwal[4][4] == 'X' && AngkaAwal[5][4]== 'X' && AngkaAwal[6][4]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[3][4]=='X' && AngkaAwal[4][4]=='X' && AngkaAwal[5][4] == 'X' && AngkaAwal[6][4]== 'X' && AngkaAwal[7][4]== 'X'){                  
    	return 1;
        }
        
    else if(AngkaAwal[1][5]=='X' && AngkaAwal[2][5]=='X' && AngkaAwal[3][5] == 'X' && AngkaAwal[4][5]== 'X' && AngkaAwal[5][5]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[2][5]=='X' && AngkaAwal[3][5]=='X' && AngkaAwal[4][5] == 'X' && AngkaAwal[5][5]== 'X' && AngkaAwal[6][5]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[3][5]=='X' && AngkaAwal[4][5]=='X' && AngkaAwal[5][5] == 'X' && AngkaAwal[6][5]== 'X' && AngkaAwal[7][5]== 'X'){                  
    	return 1;
        }
        
    else if(AngkaAwal[1][6]=='X' && AngkaAwal[2][6]=='X' && AngkaAwal[3][6] == 'X' && AngkaAwal[4][6]== 'X' && AngkaAwal[5][6]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[2][6]=='X' && AngkaAwal[3][6]=='X' && AngkaAwal[4][6] == 'X' && AngkaAwal[5][6]== 'X' && AngkaAwal[6][6]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[3][6]=='X' && AngkaAwal[4][6]=='X' && AngkaAwal[5][6] == 'X' && AngkaAwal[6][6]== 'X' && AngkaAwal[7][6]== 'X'){                  
    	return 1;
        }
        
    else if(AngkaAwal[1][7]=='X' && AngkaAwal[2][7]=='X' && AngkaAwal[3][7] == 'X' && AngkaAwal[4][7]== 'X' && AngkaAwal[5][7]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[2][7]=='X' && AngkaAwal[3][7]=='X' && AngkaAwal[4][7] == 'X' && AngkaAwal[5][7]== 'X' && AngkaAwal[6][7]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[3][7]=='X' && AngkaAwal[4][7]=='X' && AngkaAwal[5][7] == 'X' && AngkaAwal[6][7]== 'X' && AngkaAwal[7][7]== 'X'){                  
    	return 1;
        }
    
    else if(AngkaAwal[1][5]=='X' && AngkaAwal[2][4]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[4][2]== 'X' && AngkaAwal[5][1]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[1][6]=='X' && AngkaAwal[2][5]=='X' && AngkaAwal[3][4] == 'X' && AngkaAwal[4][3]== 'X' && AngkaAwal[5][2]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[2][5]=='X' && AngkaAwal[3][4]=='X' && AngkaAwal[4][3] == 'X' && AngkaAwal[5][2]== 'X' && AngkaAwal[6][1]== 'X'){                  
    	return 1;
    	}
    	
    else if(AngkaAwal[1][7]=='X' && AngkaAwal[2][6]=='X' && AngkaAwal[3][5] == 'X' && AngkaAwal[4][4]== 'X' && AngkaAwal[5][3]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[2][6]=='X' && AngkaAwal[3][5]=='X' && AngkaAwal[4][4] == 'X' && AngkaAwal[5][3]== 'X' && AngkaAwal[6][2]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[3][5]=='X' && AngkaAwal[4][4]=='X' && AngkaAwal[5][3] == 'X' && AngkaAwal[6][2]== 'X' && AngkaAwal[7][1]== 'X'){                  
    	return 1;
    	}
    	
    else if(AngkaAwal[2][7]=='X' && AngkaAwal[3][6]=='X' && AngkaAwal[4][5] == 'X' && AngkaAwal[5][4]== 'X' && AngkaAwal[6][3]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[3][6]=='X' && AngkaAwal[4][5]=='X' && AngkaAwal[5][4] == 'X' && AngkaAwal[6][3]== 'X' && AngkaAwal[7][2]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[3][7]=='X' && AngkaAwal[4][6]=='X' && AngkaAwal[5][5] == 'X' && AngkaAwal[6][4]== 'X' && AngkaAwal[7][3]== 'X'){                  
    	return 1;
    	}
    	
    else if(AngkaAwal[1][3]=='X' && AngkaAwal[2][4]=='X' && AngkaAwal[3][5] == 'X' && AngkaAwal[4][6]== 'X' && AngkaAwal[5][7]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[1][2]=='X' && AngkaAwal[2][3]=='X' && AngkaAwal[3][4] == 'X' && AngkaAwal[4][5]== 'X' && AngkaAwal[5][6]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[2][3]=='X' && AngkaAwal[3][4]=='X' && AngkaAwal[4][5] == 'X' && AngkaAwal[5][6]== 'X' && AngkaAwal[6][7]== 'X'){                  
    	return 1;
    	}
    	
    else if(AngkaAwal[1][1]=='X' && AngkaAwal[2][2]=='X' && AngkaAwal[3][3] == 'X' && AngkaAwal[4][4]== 'X' && AngkaAwal[5][5]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[2][2]=='X' && AngkaAwal[3][3]=='X' && AngkaAwal[4][4] == 'X' && AngkaAwal[5][5]== 'X' && AngkaAwal[6][6]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[3][3]=='X' && AngkaAwal[4][4]=='X' && AngkaAwal[5][5] == 'X' && AngkaAwal[6][6]== 'X' && AngkaAwal[7][7]== 'X'){                  
    	return 1;
    	}
    	
    else if(AngkaAwal[2][1]=='X' && AngkaAwal[3][2]=='X' && AngkaAwal[4][3] == 'X' && AngkaAwal[5][4]== 'X' && AngkaAwal[6][5]== 'X'){                  
    	return 1;
        }

    else if(AngkaAwal[3][2]=='X' && AngkaAwal[4][3]=='X' && AngkaAwal[5][4] == 'X' && AngkaAwal[6][5]== 'X' && AngkaAwal[7][6]== 'X'){                  
    	return 1;
        }
        
    else if(AngkaAwal[3][1]=='X' && AngkaAwal[4][2]=='X' && AngkaAwal[5][3] == 'X' && AngkaAwal[6][4]== 'X' && AngkaAwal[7][5]== 'X'){                  
    	return 1;
    	}
    else if(AngkaAwal[1][1]=='O' && AngkaAwal[1][2]=='O' && AngkaAwal[1][3] == 'O' && AngkaAwal[1][4]== 'O' && AngkaAwal[1][5]== 'O'){    //Menang O              //Kondisi Menang untuk Player 1
    	return 2;
        } 
	
	else if(AngkaAwal[1][2]=='O' && AngkaAwal[1][3]=='O' && AngkaAwal[1][4] == 'O' && AngkaAwal[1][5]== 'O' && AngkaAwal[1][6]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        } 
        
    else if(AngkaAwal[1][3]=='O' && AngkaAwal[1][4]=='O' && AngkaAwal[1][5] == 'O' && AngkaAwal[1][6]== 'O' && AngkaAwal[1][7]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
	
	else if(AngkaAwal[2][1]=='O' && AngkaAwal[2][2]=='O' && AngkaAwal[2][3] == 'O' && AngkaAwal[2][4]== 'O' && AngkaAwal[2][5]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
	
	else if(AngkaAwal[2][2]=='O' && AngkaAwal[2][3]=='O' && AngkaAwal[2][4] == 'O' && AngkaAwal[2][5]== 'O' && AngkaAwal[2][6]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[2][3]=='O' && AngkaAwal[2][4]=='O' && AngkaAwal[2][5] == 'O' && AngkaAwal[2][6]== 'O' && AngkaAwal[2][7]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[3][1]=='O' && AngkaAwal[3][2]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[3][4]== 'O' && AngkaAwal[3][5]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
	
	else if(AngkaAwal[3][2]=='O' && AngkaAwal[3][3]=='O' && AngkaAwal[3][4] == 'O' && AngkaAwal[3][5]== 'O' && AngkaAwal[3][6]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[3][3]=='O' && AngkaAwal[3][4]=='O' && AngkaAwal[3][5] == 'O' && AngkaAwal[3][6]== 'O' && AngkaAwal[3][7]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[4][1]=='O' && AngkaAwal[4][2]=='O' && AngkaAwal[4][3] == 'O' && AngkaAwal[4][4]== 'O' && AngkaAwal[4][5]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
	
	else if(AngkaAwal[4][2]=='O' && AngkaAwal[4][3]=='O' && AngkaAwal[4][4] == 'O' && AngkaAwal[4][5]== 'O' && AngkaAwal[4][6]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[4][3]=='O' && AngkaAwal[4][4]=='O' && AngkaAwal[4][5] == 'O' && AngkaAwal[4][6]== 'O' && AngkaAwal[4][7]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[5][1]=='O' && AngkaAwal[5][2]=='O' && AngkaAwal[5][3] == 'O' && AngkaAwal[5][4]== 'O' && AngkaAwal[5][5]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
	
	else if(AngkaAwal[5][2]=='O' && AngkaAwal[5][3]=='O' && AngkaAwal[5][4] == 'O' && AngkaAwal[5][5]== 'O' && AngkaAwal[5][6]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[5][3]=='O' && AngkaAwal[5][4]=='O' && AngkaAwal[5][5] == 'O' && AngkaAwal[5][6]== 'O' && AngkaAwal[5][7]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[6][1]=='O' && AngkaAwal[6][2]=='O' && AngkaAwal[6][3] == 'O' && AngkaAwal[6][4]== 'O' && AngkaAwal[6][5]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
	
	else if(AngkaAwal[6][2]=='O' && AngkaAwal[6][3]=='O' && AngkaAwal[6][4] == 'O' && AngkaAwal[6][5]== 'O' && AngkaAwal[6][6]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[6][3]=='O' && AngkaAwal[6][4]=='O' && AngkaAwal[6][5] == 'O' && AngkaAwal[6][6]== 'O' && AngkaAwal[6][7]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[7][1]=='O' && AngkaAwal[7][2]=='O' && AngkaAwal[7][3] == 'O' && AngkaAwal[7][4]== 'O' && AngkaAwal[7][5]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
	
	else if(AngkaAwal[7][2]=='O' && AngkaAwal[7][3]=='O' && AngkaAwal[7][4] == 'O' && AngkaAwal[7][5]== 'O' && AngkaAwal[7][6]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[7][3]=='O' && AngkaAwal[7][4]=='O' && AngkaAwal[7][5] == 'O' && AngkaAwal[7][6]== 'O' && AngkaAwal[7][7]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[1][1]=='O' && AngkaAwal[2][1]=='O' && AngkaAwal[3][1] == 'O' && AngkaAwal[4][1]== 'O' && AngkaAwal[5][1]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }

    else if(AngkaAwal[2][1]=='O' && AngkaAwal[3][1]=='O' && AngkaAwal[4][1] == 'O' && AngkaAwal[5][1]== 'O' && AngkaAwal[6][1]== 'O'){                  //Kondisi Menang untuk Player 1
    	return 2;
        }
        
    else if(AngkaAwal[3][1]=='O' && AngkaAwal[4][1]=='O' && AngkaAwal[5][1] == 'O' && AngkaAwal[6][1]== 'O' && AngkaAwal[7][1]== 'O'){                  
    	return 2;
        }
        
    else if(AngkaAwal[1][2]=='O' && AngkaAwal[2][2]=='O' && AngkaAwal[3][2] == 'O' && AngkaAwal[4][2]== 'O' && AngkaAwal[5][2]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[2][2]=='O' && AngkaAwal[3][2]=='O' && AngkaAwal[4][2] == 'O' && AngkaAwal[5][2]== 'O' && AngkaAwal[6][2]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[3][2]=='O' && AngkaAwal[4][2]=='O' && AngkaAwal[5][2] == 'O' && AngkaAwal[6][2]== 'O' && AngkaAwal[7][2]== 'O'){                  
    	return 2;
        }
        
    else if(AngkaAwal[1][3]=='O' && AngkaAwal[2][3]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[4][3]== 'O' && AngkaAwal[5][3]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[2][3]=='O' && AngkaAwal[3][3]=='O' && AngkaAwal[4][3] == 'O' && AngkaAwal[5][3]== 'O' && AngkaAwal[6][3]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[3][3]=='O' && AngkaAwal[4][3]=='O' && AngkaAwal[5][3] == 'O' && AngkaAwal[6][3]== 'O' && AngkaAwal[7][3]== 'O'){                  
    	return 2;
        }
        
    else if(AngkaAwal[1][4]=='O' && AngkaAwal[2][4]=='O' && AngkaAwal[3][4] == 'O' && AngkaAwal[4][4]== 'O' && AngkaAwal[5][4]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[2][4]=='O' && AngkaAwal[3][4]=='O' && AngkaAwal[4][4] == 'O' && AngkaAwal[5][4]== 'O' && AngkaAwal[6][4]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[3][4]=='O' && AngkaAwal[4][4]=='O' && AngkaAwal[5][4] == 'O' && AngkaAwal[6][4]== 'O' && AngkaAwal[7][4]== 'O'){                  
    	return 2;
        }
        
    else if(AngkaAwal[1][5]=='O' && AngkaAwal[2][5]=='O' && AngkaAwal[3][5] == 'O' && AngkaAwal[4][5]== 'O' && AngkaAwal[5][5]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[2][5]=='O' && AngkaAwal[3][5]=='O' && AngkaAwal[4][5] == 'O' && AngkaAwal[5][5]== 'O' && AngkaAwal[6][5]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[3][5]=='O' && AngkaAwal[4][5]=='O' && AngkaAwal[5][5] == 'O' && AngkaAwal[6][5]== 'O' && AngkaAwal[7][5]== 'O'){                  
    	return 2;
        }
        
    else if(AngkaAwal[1][6]=='O' && AngkaAwal[2][6]=='O' && AngkaAwal[3][6] == 'O' && AngkaAwal[4][6]== 'O' && AngkaAwal[5][6]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[2][6]=='O' && AngkaAwal[3][6]=='O' && AngkaAwal[4][6] == 'O' && AngkaAwal[5][6]== 'O' && AngkaAwal[6][6]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[3][6]=='O' && AngkaAwal[4][6]=='O' && AngkaAwal[5][6] == 'O' && AngkaAwal[6][6]== 'O' && AngkaAwal[7][6]== 'O'){                  
    	return 2;
        }
        
    else if(AngkaAwal[1][7]=='O' && AngkaAwal[2][7]=='O' && AngkaAwal[3][7] == 'O' && AngkaAwal[4][7]== 'O' && AngkaAwal[5][7]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[2][7]=='O' && AngkaAwal[3][7]=='O' && AngkaAwal[4][7] == 'O' && AngkaAwal[5][7]== 'O' && AngkaAwal[6][7]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[3][7]=='O' && AngkaAwal[4][7]=='O' && AngkaAwal[5][7] == 'O' && AngkaAwal[6][7]== 'O' && AngkaAwal[7][7]== 'O'){                  
    	return 2;
        }
    
    else if(AngkaAwal[1][5]=='O' && AngkaAwal[2][4]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[4][2]== 'O' && AngkaAwal[5][1]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[1][6]=='O' && AngkaAwal[2][5]=='O' && AngkaAwal[3][4] == 'O' && AngkaAwal[4][3]== 'O' && AngkaAwal[5][2]== 'O'){                  
    	return 2;   
        }

    else if(AngkaAwal[2][5]=='O' && AngkaAwal[3][4]=='O' && AngkaAwal[4][3] == 'O' && AngkaAwal[5][2]== 'O' && AngkaAwal[6][1]== 'O'){                  
    	return 2;
    	}
    	
    else if(AngkaAwal[1][7]=='O' && AngkaAwal[2][6]=='O' && AngkaAwal[3][5] == 'O' && AngkaAwal[4][4]== 'O' && AngkaAwal[5][3]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[2][6]=='O' && AngkaAwal[3][5]=='O' && AngkaAwal[4][4] == 'O' && AngkaAwal[5][3]== 'O' && AngkaAwal[6][2]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[3][5]=='O' && AngkaAwal[4][4]=='O' && AngkaAwal[5][3] == 'O' && AngkaAwal[6][2]== 'O' && AngkaAwal[7][1]== 'O'){                  
    	return 2;
    	}
    	
    else if(AngkaAwal[2][7]=='O' && AngkaAwal[3][6]=='O' && AngkaAwal[4][5] == 'O' && AngkaAwal[5][4]== 'O' && AngkaAwal[6][3]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[3][6]=='O' && AngkaAwal[4][5]=='O' && AngkaAwal[5][4] == 'O' && AngkaAwal[6][3]== 'O' && AngkaAwal[7][2]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[3][7]=='O' && AngkaAwal[4][6]=='O' && AngkaAwal[5][5] == 'O' && AngkaAwal[6][4]== 'O' && AngkaAwal[7][3]== 'O'){                  
    	return 2;
    	}
    	
    else if(AngkaAwal[1][3]=='O' && AngkaAwal[2][4]=='O' && AngkaAwal[3][5] == 'O' && AngkaAwal[4][6]== 'O' && AngkaAwal[5][7]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[1][2]=='O' && AngkaAwal[2][3]=='O' && AngkaAwal[3][4] == 'O' && AngkaAwal[4][5]== 'O' && AngkaAwal[5][6]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[2][3]=='O' && AngkaAwal[3][4]=='O' && AngkaAwal[4][5] == 'O' && AngkaAwal[5][6]== 'O' && AngkaAwal[6][7]== 'O'){                  
    	return 2;
    	}
    	
    else if(AngkaAwal[1][1]=='O' && AngkaAwal[2][2]=='O' && AngkaAwal[3][3] == 'O' && AngkaAwal[4][4]== 'O' && AngkaAwal[5][5]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[2][2]=='O' && AngkaAwal[3][3]=='O' && AngkaAwal[4][4] == 'O' && AngkaAwal[5][5]== 'O' && AngkaAwal[6][6]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[3][3]=='O' && AngkaAwal[4][4]=='O' && AngkaAwal[5][5] == 'O' && AngkaAwal[6][6]== 'O' && AngkaAwal[7][7]== 'O'){                  
    	return 2;
    	}
    	
    else if(AngkaAwal[2][1]=='O' && AngkaAwal[3][2]=='O' && AngkaAwal[4][3] == 'O' && AngkaAwal[5][4]== 'O' && AngkaAwal[6][5]== 'O'){                  
    	return 2;
        }

    else if(AngkaAwal[3][2]=='O' && AngkaAwal[4][3]=='O' && AngkaAwal[5][4] == 'O' && AngkaAwal[6][5]== 'O' && AngkaAwal[7][6]== 'O'){                  
    	return 2;
        }
        
    else if(AngkaAwal[3][1]=='O' && AngkaAwal[4][2]=='O' && AngkaAwal[5][3] == 'O' && AngkaAwal[6][4]== 'O' && AngkaAwal[7][5]== 'O'){                  
    	return 2;
    	}
    else {
        return 0;
        }
    }
}

void CetakMenang(Player Pemain){
    printf("\t\t\t\t>> %s Win <<", Pemain);
}

void CetakDraw(){   
	printf("\t\t\t\t>> Draw <<");
}

void HapusKotak(char AngkaAwal[8][8]){
    int i,j;
    for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			AngkaAwal[i][j]=' ';
		}
	}
}

int CetakMainLagi(){
    int AfterGame;

    printf("\n\n Main Lagi yes(1)/no(2)?\n Masukkan Angka : ");
    input(&AfterGame);
    return AfterGame;
}


void InputHighScore(Player Pemain){  	//membaca dan menamah data
	FILE *file4;
	
	file4= fopen("Score.txt", "a+");
	
	if(file4==NULL)
	{
		exit(1);
	}
	fprintf(file4, "%s %d\n", Pemain.Nama, Pemain.score);
	fclose(file4);
}

// Procedure untuk membaca dan menampilkan skor dari file
void tampilkanSkor() {
	system("color 0C");
	
    FILE *file = fopen("Score.txt", "r");
    if (file == NULL) {
        printf("File 'score.txt' tidak ditemukan.\n");
        return;
    }

    printf("Daftar Skor:\n");
    printf("--------------\n");

    Player pemain;
    while (fscanf(file, "%s %d", pemain.Nama, &pemain.score) != EOF) {
        printf("%s: %d\n", pemain.Nama, pemain.score);
    }

    fclose(file);
}

void tampilkanHighscore() { //menampilkan skor tertinggi
	int temp;
    FILE *file = fopen("Score.txt", "r");
    if (file == NULL) {
        printf("File 'Score.txt' tidak ditemukan.\n");
        return;
    }

    Player pemain[100];
    int jumlahPemain = 0;

    // Membaca data pemain dari file
    while (fscanf(file, "%s %d", pemain[jumlahPemain].Nama, &(pemain[jumlahPemain].score)) != EOF) {
        jumlahPemain++;
    }

    //fclose(file);

    // Mengurutkan pemain berdasarkan skor dari yang tertinggi ke terendah
    int i=0;
    while (i < jumlahPemain-1){
    	int j=0;
    	while(j < jumlahPemain - i - 1){
    		 if (pemain[j].score < pemain[j + 1].score) {
                // Menukar posisi jika skor lebih tinggi
                Player temp = pemain[j];
                pemain[j] = pemain[j + 1];
                pemain[j + 1] = temp;
            }
    		j++;
		}
    	i++;
	}
    

    // Menampilkan highscore setelah diurutkan
    printf("Highscore:\n");
    printf("-----------\n");
	
	
	while(i < jumlahPemain){
		printf("%s %d\n", pemain[i].Nama, pemain[i].score);
		i++;
	}
	fclose(file);
}

void updateSkor(const char *namaPemain, int skorTambahan) {
    FILE *file;
    Player Pemain;
    int ditemukan = 0;

    // Buka file untuk membaca nilai saat ini
    file = fopen("Score.txt", "r");
    if (file == NULL) {
        printf("Error membuka file skor.txt\n");
        exit(EXIT_FAILURE);
    }

    // Baca data pemain dari file dan cek jika nama sudah ada
    while (fscanf(file, "%s %d\n", Pemain.Nama, &Pemain.score) != EOF) {
        if (strcmp(Pemain.Nama, namaPemain) == 0) {
            // Nama ditemukan, tambahkan skor
            Pemain.score += skorTambahan;
            ditemukan = 1;
        }
    }

    fclose(file);

    // Buka file untuk menulis kembali data pemain
    file = fopen("Score.txt", "a+");
    if (file == NULL) {
        printf("Error membuka file skor.txt\n");
        exit(EXIT_FAILURE);
    }

    // Jika nama tidak ditemukan, tambahkan sebagai pemain baru
    if (!ditemukan) {
        fprintf(file, "%s %d\n", namaPemain, skorTambahan);
    } else {
        // Kembalikan posisi file ke awal
        rewind(file);

        // Tulis kembali data pemain ke file
        while (fscanf(file, "%s %d\n", Pemain.Nama, &Pemain.score) != EOF) {
            fprintf(file, "%s %d\n", Pemain.Nama, Pemain.score);
        }
    }

    fclose(file);
}

int mainHightScore() {
    int pilihan;
    Player pemain;
    do {
        printf("\nMenu:\n");
        printf("1. Tampilkan Skor\n");
        printf("2. Tampilkan Skor Terakhir\n");
        printf("3. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tampilkanSkor();
                break;
                system("cls");
            case 2:
               tampilkanHighscore();
                break;
            case 3:
            	system("cls");
            	menu();
            	break;
            default:
            	
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 3);

    return 0;
}

//void Selisih(){
//	int selisih;
//		for(selisih = 10; selisih >= 1;){
//		printf("%d", selisih);
//		selisih--;
//		sleep(1);
//		}
//	return 0;
//}

int invalid(const char *Nama){
	while(*Nama){
		if ((*Nama >= '0' && *Nama <= '9') || !isalpha(*Nama)) {
            return 1; // Mengandung angka
    }
    Nama++;
	}
    return 0; // Tidak mengandung angka
}

int isDigit(char c) {
    return c >= '0' && c <= '9';
}
