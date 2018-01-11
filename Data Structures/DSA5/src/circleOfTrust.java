import java.util.ArrayList;

class myQueue {
    private static class Node{
        private String data;
        private Node next;
        private Node(String data){
            this.data = data;
        }

    }

    private int size=0;
    private Node head;
    private Node tail;

    public boolean isEmpty(){return head == null;}

    public void enqueue(String data){
        size+=1;
        Node node = new Node(data);

        if(tail != null) tail.next = node;
        tail = node;
        if (head == null) head = node;
        if(size>10){
            this.dequeue();
        }
    }

    public void dequeue(){
        if(head == null){
            return;
        }
        size-=1;
        head = head.next;
    }
    public String peek(){
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
class circle{
    //up to 10 users at a time
    //users can post messages to the circle
    //users in the same circle can see 10 most recent messages
    //if the owner leaves the next member is the new leader
    //if all users leaves circle auto deletes
    ArrayList<String> users= new ArrayList<>();//arraylist can be accessed like an array but dynamic like a list
    myQueue Queue=new myQueue();//a queue for the messages
    public void circle(String user){
        users.add(user);//this make a list of all the users
    }
    public void posting(String userID,String Msg){//didnt use circle parameter
        //becuase each object of circle of trust with be its own id
        String hold;
        hold=userID.concat(": ");
        hold=hold.concat(Msg);
        Queue.enqueue(hold);
    }
    public void getMessages(){
        Queue.displayQueue();
    }
    public void join(String userID){
        users.add(userID);
    }
    public void leave(String userID){
        if(users.contains(userID)){//checks if userID is in the circle
            users.remove(userID);//takes it out if it is in the circle
        }
    }
    public boolean isIn(String userID){
        if(users.contains(userID)){
            return true;
        }else{
            return false;
        }
    }


}
public class circleOfTrust{
    ArrayList<circle> circleList=new ArrayList<>();//this creates a Arraylist^ of circles, where their index is their id
    ArrayList<String> userCircleList=new ArrayList<>();
    public static void main(String[] args) {



    }
    public void newCircle(String user) {
        if (userCircleList.contains(user)) {
            return;
        }else{
            circle hold=new circle();
            hold.circle(user);
            userCircleList.add(user);
            circleList.add(hold);
        }

    }
    public void posting(String userID,String Msg,circle circleID){
        if(circleID.isIn(userID)){
            circleID.posting(userID,Msg);
        }

    }
    public void getMessages(String userID){//circleID not needed since it must get the first ten of all the users circles
        for(circle hold: circleList){
            if(hold.isIn(userID)){
                hold.getMessages();
            }
        }
    }
    public void join(String userID,circle circleID){
        circleID.join(userID);
    }
    public void leave(String userID,circle circleID){
        circleID.leave(userID);
    }
}