package adt_antrian;
import java.util.Scanner;

public class Antri_yok {
    public static void main(String[] args) {
        Scanner isi = new Scanner(System.in);
        
        System.out.print("Jumlah maksimal Antrian: ");
        int max = isi.nextInt();
        
        //polimorfisme
        Antrian antri = new Ngantri(max);
        
        //menuuuuuuu
        int pilihdong;
        do{
            System.out.println("\n[ MENU ]");
            System.out.println("| 1. Isi Antrian (Enqueue)");
            System.out.println("| 2. Hapus Antrian (Dequeue)");
            System.out.println("| 3. Tampilkan Antrian (Queue)");
            System.out.println("| 4. Lihat elemen terdepan (Peek)");
            System.out.println("| 5. Udah? Ya Keluar");
            System.out.println("----------------------");
            System.out.println("Yang mana? ");
            pilihdong = isi.nextInt();
            
            switch(pilihdong){
                case 1:
                    System.out.println("----------------------");
                    System.out.print("Masukkan angka: ");
                    int bil = isi.nextInt();
                    antri.enqueue(bil);
                    break;
                case 2:
                    System.out.println("----------------------");
                    antri.dequeue();
                    break;
                case 3:
                    System.out.println("----------------------");
                    antri.displayQueue();
                    break;
                case 4:
                    System.out.println("----------------------");
                    System.out.println("Elemen terdepan: " + antri.peek());
                    break;
                case 5:
                    System.out.println("Baibaii :3");
                    break;
                default:
                    System.out.println("Ga valid, yang bener milihnya >:(");
            }
        } while(pilihdong != 5);
        
        isi.close();
    }
}

/*
    //polimorfisme
    Antrian antri = new Ngantri(7);

    //isi
    antri.enqueue(1);
    antri.enqueue(8);
    antri.enqueue(0);
    antri.enqueue(4);
    antri.enqueue(2);
    antri.enqueue(5);
    antri.enqueue(10);

    //tampil
    antri.displayQueue();

    //hapus
    antri.dequeue();
    antri.dequeue();

    //tampil after dihapus
    antri.displayQueue();

    //isi lagi eak
    antri.enqueue(19);
    antri.displayQueue();

    //ngintip elemen depan
    System.out.println("Elemen terdepan: " + antri.peek());

    //cek penuh
    antri.enqueue(22);
    antri.enqueue(12);  //melebihi

    //cek kosong
    antri.dequeue();
    antri.dequeue();
    antri.dequeue();
    antri.dequeue();
    antri.dequeue();
    antri.dequeue();
    antri.dequeue();
    antri.dequeue();    //melebihi
*/