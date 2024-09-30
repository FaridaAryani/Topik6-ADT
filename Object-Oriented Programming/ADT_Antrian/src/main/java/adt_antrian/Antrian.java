package adt_antrian;

interface Antrian {
    void enqueue(int item); //tambah elemen
    int dequeue();          //hapus elemen (dari terdepan/paling awal)
    int peek();             //liat elemen terdepan
    boolean isEmpty();      //cek kosong ga
    boolean isFull();       //cek penuh ga
    void displayQueue();    //tampilkan
}
