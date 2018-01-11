import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;



class myQueue {
    private static class Node{
        private int data;
        private Node next;
        private Node(int data){
            this.data = data;
        }

    }

    private int size=0;
    private Node head;
    private Node tail;

    public boolean isEmpty(){return head == null;}

    public void enqueue(int data){
        size+=1;
        Node node = new Node(data);

        if(tail != null) tail.next = node;
        tail = node;
        if (head == null) head = node;
    }

    public void dequeue(){
        if(head == null){
            return;
        }
        head = head.next;
    }
    public int peek(){
        return head.data;
    }

    public void displayQueue(){
        if(head == null){
            System.out.println("The queue is empty");
        }else {
            Node currNode = head;

            while (currNode != null) {
                System.out.println(currNode.data);
                currNode = currNode.next;
            }
        }
    }
    public int size(){
        return size;
    }
}

public class pathfinder {
    public static void main(String[] args) throws Exception {


        File myFile = new File("input.txt");//reading in from file
        Scanner input = new Scanner(myFile);
        String in = "";
        int numOfRooms,start,end;
        in = input.nextLine();//getting the first line of the file
        numOfRooms=Character.getNumericValue(in.charAt(0));
        in = input.nextLine();
        start=Character.getNumericValue(in.charAt(0));
        in = input.nextLine();
        end=Character.getNumericValue(in.charAt(0));
        int[][] matrix=new int[numOfRooms][numOfRooms];
        String expression[];
        int k=0;
        for(int i=0;i<numOfRooms;i++){
            in = input.nextLine();//gets the next line for checking
            expression=in.split(",");
            k=0;
            for(String hold : expression){
                matrix[i][k] = Character.getNumericValue(hold.charAt(0));
                k++;
            }

        }
        for(int i=0;i<numOfRooms;i++) {
            for (int j = 0; j < numOfRooms; j++) {
                System.out.print("[");
                System.out.print(matrix[i][j]);
                System.out.print("]");
                System.out.print(" ");

            }
            System.out.println("");
        }
        dikstra(numOfRooms,start,end,matrix);
        System.out.println("");
        dikstra(numOfRooms,0,6,matrix);


    }
    public static void dikstra(int size, int start,int end, int[][] arrayO) {
        myQueue queue = new myQueue();
        queue.enqueue(end);
        ArrayList al = new ArrayList();
        int i = end, prev = end;
        int[][] array = arrayO;
        for (int j = 0; j < size; j++) {
            if ((array[i][j]) != 0 && (i != j) && (prev != j)) {
                queue.enqueue(j);
                array[i][j] = 0;//dont go to these anymore
                array[j][i] = 0;//dont go to these anymore
                i = j;
                if (j == start) {
                    break;
                }
                j = -1;
            }
        }


        queue.displayQueue();


        return;
    }
}
