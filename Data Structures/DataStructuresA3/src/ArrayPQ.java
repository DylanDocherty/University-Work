public class ArrayPQ <T> {//Array Priority Queue Node class
    private T element;//Makes it any data type for the elements
    private int priority;

    public ArrayPQ(T element, int priority) {
        this.element = element;
        this.priority = priority;
    }
    public ArrayPQ(T element) {
        this.element = element;
        this.priority = 5;
    }

    public int P() {
        return this.priority;
    }

    public T E() {
        return this.element;
    }
}
class ArrayPriorityQueue{
    ArrayPQ[] Array;
    int i,maxSize;
    public ArrayPriorityQueue(int max){//Initializes a queue with size
        maxSize=max;
        Array = new ArrayPQ[maxSize];
        i=-1;
    }
    public <T> void enqueue(T data,int num) {
        ArrayPQ<T> item=new ArrayPQ<T>(data,num);
        if (isEmpty()){//checks if the list is empty
            i+=1;
            Array[i]=item;
        }
        else if (isFull())
            return;

        else{
            int k=0;
            while(Array[k]!=null && Array[k].P() > item.P()){
                k++;
            }
            for (int f=i; f>=k; f--){
                Array[f+1] = Array[f];
            }
            Array[k] = item;
            i++;
        }
    }
    public <T> void enqueue(T data) {
        enqueue(data,5);

    }


    public <T> void deque() {
        Array[i]=null;
        i--;
    }


    public void peek() {
        System.out.println("PEEK");
        System.out.print("Element: " + Array[i].E()+" , ");
        System.out.println(" Priority: " + Array[i].P());

    }


    public boolean isRegular() {
        if(Array[0].P()==Array[i].P()){
            return true;
        }else{
            return false;
        }
    }


    public int size() {
        return (i+1);
    }


    public boolean isEmpty() {
        if(i==-1){
            return true;
        }else{
            return false;
        }
    }


    public boolean isFull() {
        if(i==maxSize-1){//if the current size is equal to maz size
            return true;
        }else{
            return false;
        }

    }

    public void display() {
        System.out.println("First to Last");
        for(int j=i;j>=0;j--){//starts at the top goes down
            System.out.print("Element: " + Array[j].E()+" , ");
            System.out.println(" Priority: " + Array[j].P());
        }
    }
}

class test{
    public static void main(String[] args) {
        ArrayPriorityQueue john= new ArrayPriorityQueue(5);
        System.out.println("Add max");
        john.enqueue("max",1);
        System.out.println("is it full "+john.isFull());
        System.out.println("Size: "+john.size());
        System.out.println("Add john Patrick Adam Marcus");
        john.enqueue("John",2);
        john.enqueue("Patrick");
        john.enqueue("Adam");
        john.enqueue("Marcus",3);//Marcus isnt put in becuase its full
        john.display();
        System.out.println("Is it regular? "+john.isRegular());
        System.out.println("Is is full? "+john.isFull());
        System.out.println("Size: "+john.size());
        john.deque();
        john.deque();
        System.out.println("Deque Deque");
        john.display();
        john.peek();




    }
}