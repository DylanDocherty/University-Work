package dylan;
import java.util.Scanner;
public class input {
    public static int GetNum() {
        int choice;
        Scanner sc = new Scanner(System.in);
        try {
            choice = sc.nextInt();//using the scanner to get the user's choice
        } catch (Exception e) {//checking if the scanned data was of the correct type
            System.out.println("Please enter a number");
            choice = GetNum();
        }
        return choice;
    }

    public static String GetStr() {
        String choice;
        Scanner sc = new Scanner(System.in);
        try {
            choice = sc.nextLine();//using the scanner to get the user's choice
        } catch (Exception e) {//checking if the scanned data was of the correct type
            System.out.println("Please enter again");
            choice = GetStr();
        }
        return choice;
    }
}