package adt_antrian;

//inherit
class Ngantri extends AntrianADT{
    public Ngantri(int size){
        super(size);    //konstruktor dr adt
    }
    
    @Override
    public void enqueue(int item){
        if(isFull()){
            System.out.println("Antrian penuh, gabisa ngantri :(");
        } else{
            rear = (rear + 1) % maxSize;
            qArr[rear] = item;
            currSize++;
            System.out.println("Diisi: " + item);
        }
    }
    @Override
    public int dequeue(){
        if(isEmpty()){
            System.out.println("Antrian kosong, gabisa hapus :D");
            return -1;
        } else{
            int item = qArr[front];
            front = (front + 1) % maxSize;
            currSize--;
            System.out.println("Dihapus: " + item);
            return item;
        }
    }
    @Override
    public int peek(){
        if(isEmpty()){
            System.out.println("Antrian kosong, gada yang bisa diliat 0_0");
            return -1;
        } else{
            return qArr[front];
        }
    }
}
