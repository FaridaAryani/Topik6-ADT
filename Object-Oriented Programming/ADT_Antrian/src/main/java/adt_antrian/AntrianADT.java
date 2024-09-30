package adt_antrian;

abstract class AntrianADT implements Antrian{
    //enkaps
    protected int maxSize;
    protected int[] qArr;
    protected int front;
    protected int rear;
    protected int currSize;
    
    //konstruktor
    public AntrianADT(int size){
        this.maxSize = size;
        this.qArr = new int[maxSize];
        this.front = 0;
        this.rear = -1;
        this.currSize = 0;
    }
    
    @Override
    public boolean isEmpty(){
        return currSize == 0;
    }
    @Override
    public boolean isFull(){
        return currSize == maxSize;
    }
    @Override
    public void displayQueue(){
        if(isEmpty()){
            System.out.println("Antrian kosong.");
        } else{
            System.out.print("Antrian: ");
            for(int i=0; i<currSize; i++){
                System.out.print(qArr[(front + i) % maxSize] + " ");
            }
            System.out.println();
        }
    }
    
    //abstract method yihaa
    public abstract void enqueue(int item);
    public abstract int dequeue();
}
