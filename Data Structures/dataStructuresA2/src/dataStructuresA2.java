import java.io.*;
import java.util.Scanner;
class Stacker{
    public int TOP=0,OUTTOP=0,size;
    public String[] Array,OutArray;
    public String Str;

    public void Stack(int S, String string){
        size=S;
        Str=string;
        Array=new String[S];
        OutArray=new String[S];
        return;
    }
    public void push(String pushe){
        printStack();
        TOP+=1;
        Array[TOP]=pushe;
        printStack();
    }
    public String Outpop(){
        printStack();
        String pope;
        pope=OutArray[OUTTOP];
        OutArray[OUTTOP]=null;
        OUTTOP-=1;
        printStack();
        return pope;
    }
    public void Outpush(String pushe){
        printStack();
        OUTTOP+=1;
        OutArray[OUTTOP]=pushe;
        printStack();
    }
    public String pop() {
        printStack();
        String pope;
        pope = Array[TOP];
        Array[TOP]=null;
        TOP -= 1;
        printStack();
        return pope;
    }
    public int operator(String test){
        if(test.charAt(0) == '^' || test.charAt(0)== '*' || test.charAt(0) =='/' || test.charAt(0) == '+'){
            return 1;//1 if it is a operator

        }else{
            return 0;//0 if no a operator
        }
    }
    public int precedence(String test){
        if(test=="^"){
            return 3;
        }else if(test.charAt(0) == '*' || test.charAt(0) == '/'){
            return 2;
        }else if(test.charAt(0) == '+' || test.charAt(0) == '-'){
            return 1;
        }
        return 0;
    }
    public void inToPostFix(){
        String a;
        String expression[]=Str.split( " ");

        for(String hold : expression){
            if (hold.charAt(0)=='('){
                //Outpush(hold);
                System.out.println("");
            }else if(Character.isDigit(hold.charAt(0))||(hold.length()>1 && Character.isDigit(hold.charAt(1)))){
                System.out.println("bruh2");
                Outpush(hold);
                System.out.println(hold);
            }else if(operator(hold) == 1){



                if (TOP>=1) {
                    a=pop();
                    while ((precedence(a)) >= (precedence(hold))){
                        System.out.println("bruh4");
                        push(hold);
                        push(a);

                    }

                }else{

                    push(hold);
                }
                System.out.println(hold);
                System.out.println("bruh5");

            }else{
                System.out.println("Invalid Expression");
                break;
            }


        }


    }
    public void printStack() {
        System.out.print("\n");
        for (String hold : OutArray) {
            if (hold != null){//doesnt print if its null
                System.out.print(hold);
            }
        }
        System.out.print("\n");
    }

}
public class dataStructuresA2 {
    public static void main(String[] args) throws Exception {
        File myFile = new File("testStr.txt");//reading in from file
        Scanner input = new Scanner(myFile);
        String in = "";
        Stacker steck=new Stacker();
        in = input.nextLine();//getting the first line of the file

        while(true) {
            try {
                System.out.println("The equation " + in);//these are checks for the file reading
                System.out.println(checkVal(in));
                //System.out.println(expCount(in));
                if(checkVal(in)==true){//checks if it is a valid expression
                    //steck.Stack(expCount(in),in);
                    //steck.inToPostFix();
                    //steck.printStack();
                }
                in = input.nextLine();//gets the next line for checking
            } catch (Exception NoSuchElementException){
                break;
            }
            System.out.println("\n\n");
        }

    }
    private static boolean checkVal(String input){
        int numCount=0,opCount=0,bracketOpen=0,bracketClosed=0;
        boolean valid=true;
        String expression[]=input.split(" ");//splits the strings into smaller strings split by spaces`
        for(String hold : expression){
            if(Character.isDigit(hold.charAt(0))){
                numCount+=1;
            }
            //checks if its and operator or just a negative number
            if(hold.charAt(0)=='^' || hold.charAt(0)=='+' || hold.charAt(0) == '-' || hold.charAt(0) == '*' || hold.charAt(0)=='/'){
                if(hold.charAt(0) == '-' && hold.length()>1){
                    numCount+=1;
                    opCount-=1;
                }
                opCount+=1;
            }
            //check for open and closed brackets and counts it
            if(hold.charAt(0)=='('){
                bracketOpen+=1;
            }else if(hold.charAt(0)==')'){
                bracketClosed+=1;
            }

        }
        //checks if the is 1 more number than amount of operators, and equal amount open brackets than closed brackets
        if((numCount-opCount)!=1 || bracketClosed != bracketOpen){
            valid=false;
        }

        return valid;
    }
    private static int expCount(String input){
        int i=0;
        String expression[]=input.split(" ");
        for(String hold : expression){
            i+=1;
        }
        return i;
    }


}
