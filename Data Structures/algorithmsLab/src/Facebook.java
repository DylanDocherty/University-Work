//Dylan Docherty Assignennt 1
import java.util.Scanner;
import dylan.input;




class Link {
    public int likes,comments,size;
    public String date,author;
    public Link nextLink;
    public Link previous;
    //Link constructor
    public Link(int l, int c, int s, String d, String a) {
        this.likes=l;
        this.comments=c;
        this.size=s;
        this.date=d;
        this.author=a;
    }

    //Print Link data
    public void printLink() {
        System.out.println(author +" "+ date +" Likes:"+ likes +" Comments:"+ comments +" Characters:"+ size);
    }
}

class LinkList {
    Link head,tail;
    public int count;


    //head.nextLink = null;
    //LinkList constructor
    public LinkList() {
        head = new Link(-1,-1,-1,"","");
        head.nextLink=null;
        head.previous=null;
        count=0;

    }

    //Inserts a new Link at the first of the list
    public void insert() {
        int l,c,s;
        String d,a;
        System.out.println("How many likes?");
        l = input.GetNum();
        System.out.println("How many comments?");
        c = input.GetNum();
        System.out.println("How many characters?");
        s = input.GetNum();
        System.out.println("What is its date?");
        d = input.GetStr();
        System.out.println("Who is the author?");
        a = input.GetStr();
        Link link;
        link = new Link(l, c, s, d, a);
        Link current;
        current = head;

        while(current.nextLink != null) {
            current = current.nextLink;

        }

        link.previous = current;
        current.nextLink = link;
        count+=1;
    }
    //Prints list data
    public void printList() {
        Link currentLink = head.nextLink;
        System.out.println("List: ");
        while(currentLink != null) {
            currentLink.printLink();
            currentLink = currentLink.nextLink;
        }
        System.out.println("");
    }
    public void searchListName(String search) {
        Link currentLink = head.nextLink;
        while(currentLink != null) {
            //currentLink.printLink();
            if (currentLink.author.equals(search)){
                System.out.println(currentLink.date);
                currentLink.previous.nextLink=currentLink.nextLink;
                if (currentLink.nextLink!=null) {
                    currentLink.nextLink.previous=currentLink.previous;
                }
            }

            currentLink = currentLink.nextLink;
        }
        System.out.println("");
    }
    public void searchListDate(String search) {
        Link currentLink=head.nextLink;
        while(currentLink != null) {

            //currentLink.printLink();
            if (currentLink.date.equals(search)) {
                System.out.println(currentLink.author);
                currentLink.previous.nextLink=currentLink.nextLink;
                if (currentLink.nextLink!=null) {
                    currentLink.nextLink.previous=currentLink.previous;
                }
            }

            currentLink = currentLink.nextLink;
        }
        System.out.println("");
    }
    public void searchListSize(int search) {
        Link currentLink=head.nextLink;
        while(currentLink != null) {

            //currentLink.printLink();
            if (currentLink.size==search) {
                currentLink.printLink();
            }

            currentLink = currentLink.nextLink;
        }
        System.out.println("");
    }
    public void searchListComments(int search) {
        Link currentLink=head.nextLink;
        while(currentLink != null) {

            //currentLink.printLink();
            if (currentLink.comments==search) {
                currentLink.printLink();
            }

            currentLink = currentLink.nextLink;
        }
        System.out.println("");
    }
    public void searchListLikes(int search) {
        Link currentLink=head.nextLink;
        while(currentLink != null) {

            //currentLink.printLink();
            if (currentLink.likes==search) {
                currentLink.printLink();
            }

            currentLink = currentLink.nextLink;
        }
        System.out.println("");
    }
    public void analate(){
        head.nextLink=null;
    }

    public void sortLikes(){//bubble sort
        Link currentLink=head.nextLink;
        int hold=0;
        String h;
        for(int j=0; j<count;j++) {
            currentLink=head.nextLink;
        while(currentLink.nextLink != null) {
            if (currentLink.likes < currentLink.nextLink.likes) {
                hold = currentLink.likes;
                h = currentLink.author;
                currentLink.likes = currentLink.nextLink.likes;
                currentLink.nextLink.likes = hold;
                currentLink.author = currentLink.nextLink.author;
                currentLink.nextLink.author = h;
                hold = currentLink.comments;
                h = currentLink.date;
                currentLink.comments = currentLink.nextLink.comments;
                currentLink.nextLink.comments = hold;
                currentLink.date = currentLink.nextLink.date;
                currentLink.nextLink.date = h;
                hold = currentLink.size;
                currentLink.size = currentLink.nextLink.size;
                currentLink.nextLink.size = hold;


            }
            currentLink = currentLink.nextLink;
        }
        }
    }

    public void sortComments(){
        Link currentLink=head.nextLink;
        int hold=0;
        String h;
        for(int j=0; j<count;j++) {
            currentLink=head.nextLink;
        while(currentLink.nextLink != null) {
            if (currentLink.comments < currentLink.nextLink.comments) {
                hold = currentLink.likes;
                h = currentLink.author;
                currentLink.likes = currentLink.nextLink.likes;
                currentLink.nextLink.likes = hold;
                currentLink.author = currentLink.nextLink.author;
                currentLink.nextLink.author = h;
                hold = currentLink.comments;
                h = currentLink.date;
                currentLink.comments = currentLink.nextLink.comments;
                currentLink.nextLink.comments = hold;
                currentLink.date = currentLink.nextLink.date;
                currentLink.nextLink.date = h;
                hold = currentLink.size;
                currentLink.size = currentLink.nextLink.size;
                currentLink.nextLink.size = hold;


            }
            currentLink = currentLink.nextLink;
        }
        }
    }
    public void sortSize(){
        Link currentLink=head.nextLink;
        int hold=0;
        String h;
        for(int j=0; j<count;j++) {
            currentLink=head.nextLink;
        while(currentLink.nextLink != null) {
            if (currentLink.size < currentLink.nextLink.size) {
                hold = currentLink.likes;
                h = currentLink.author;
                currentLink.likes = currentLink.nextLink.likes;
                currentLink.nextLink.likes = hold;
                currentLink.author = currentLink.nextLink.author;
                currentLink.nextLink.author = h;
                hold = currentLink.comments;
                h = currentLink.date;
                currentLink.comments = currentLink.nextLink.comments;
                currentLink.nextLink.comments = hold;
                currentLink.date = currentLink.nextLink.date;
                currentLink.nextLink.date = h;
                hold = currentLink.size;
                currentLink.size = currentLink.nextLink.size;
                currentLink.nextLink.size = hold;


            }
            currentLink = currentLink.nextLink;
        }
        }
    }
    public void sortDate(){
        Link currentLink=head.nextLink;
        int hold=0;
        String h;
        for(int j=0; j<count;j++) {
            currentLink=head.nextLink;
        while(currentLink.nextLink != null) {
            if (currentLink.date.compareTo(currentLink.nextLink.date) < 0) {
                hold = currentLink.likes;
                h = currentLink.author;
                currentLink.likes = currentLink.nextLink.likes;
                currentLink.nextLink.likes = hold;
                currentLink.author = currentLink.nextLink.author;
                currentLink.nextLink.author = h;
                hold = currentLink.comments;
                h = currentLink.date;
                currentLink.comments = currentLink.nextLink.comments;
                currentLink.nextLink.comments = hold;
                currentLink.date = currentLink.nextLink.date;
                currentLink.nextLink.date = h;
                hold = currentLink.size;
                currentLink.size = currentLink.nextLink.size;
                currentLink.nextLink.size = hold;


            }
            currentLink = currentLink.nextLink;
        }
        }
    }
    public void sortAuthor(){
        Link currentLink=head.nextLink;
        int hold=0,counter=0;
        String h;



        for(int j=0; j<count;j++) {
            currentLink=head.nextLink;
            while (currentLink.nextLink != null) {
                if (currentLink.author.compareTo(currentLink.nextLink.author) > 0) {
                    hold = currentLink.likes;
                    h = currentLink.author;
                    currentLink.likes = currentLink.nextLink.likes;
                    currentLink.nextLink.likes = hold;
                    currentLink.author = currentLink.nextLink.author;
                    currentLink.nextLink.author = h;
                    hold = currentLink.comments;
                    h = currentLink.date;
                    currentLink.comments = currentLink.nextLink.comments;
                    currentLink.nextLink.comments = hold;
                    currentLink.date = currentLink.nextLink.date;
                    currentLink.nextLink.date = h;
                    hold = currentLink.size;
                    currentLink.size = currentLink.nextLink.size;
                    currentLink.nextLink.size = hold;


                }
                currentLink = currentLink.nextLink;
            }

        }
    }

}








public class Facebook {
    public static void main(String[] args) {
        int choice = 0;
        LinkList list = new LinkList();
        int sp=0;
        while(choice!=8) {
            choice = menu();
            //Main menu


            if (choice == 1) {//---------------------------------------------------------------------------------------
                list.printList();
            } else if (choice == 2) {//--------------------------------------------------------------------------------
                System.out.println("1.Name \n2.Date\n3.Likes\n4.Number of comments\n5.Number of characters");
                choice=input.GetNum();
                if (choice==1) {
                    System.out.println("What name?");
                    list.searchListName(input.GetStr());
                }else if(choice==2) {
                    System.out.println("What was the date?");
                    list.searchListDate(input.GetStr());
                }else if(choice==3){
                    System.out.println("How many likes?");
                    list.searchListLikes(input.GetNum());
                }else if(choice==4){
                    System.out.println("How many comments?");
                    list.searchListComments(input.GetNum());
                }else if(choice==5){
                    System.out.println("Number of characters?");
                    list.searchListSize(input.GetNum());
                }
            } else if (choice == 3) {//--------------------------------------------------------------------------------
                System.out.println("There are "+list.count+" stored posts.");
            } else if (choice == 4) {//--------------------------------------------------------------------------------
                list.insert();

                ;//this counts how many posts are stored
            } else if (choice == 5) {//--------------------------------------------------------------------------------
                System.out.println("1.Name or 2.Date?");
                choice=input.GetNum();
                if (choice==1) {
                    System.out.println("What is the name?");
                    list.searchListName(input.GetStr());
                }else if(choice==2){
                    System.out.println("What was the date?");
                    list.searchListDate(input.GetStr());

                }
                list.count-=1;

            } else if (choice == 6) {//--------------------------------------------------------------------------------
                list.analate();
                sp=0;
            } else if (choice == 7) {//--------------------------------------------------------------------------------
                System.out.println("Sort by:\n1.Likes\n2.Comments\n3.Number of Characters\n4.Date\n5.Author");
                choice=input.GetNum();
                if (choice==1) {
                    list.sortLikes();
                }else if(choice==2){
                    list.sortComments();
                }else if(choice==3){
                    list.sortSize();
                }else if(choice==4){
                    list.sortDate();
                }else if(choice==5){
                    list.sortAuthor();
                }
            } else {
                return;
            }
        }

    }

    //main menu to take in the first choice
    public static int menu() {
        int choice = 23;
        Scanner sc = new Scanner(System.in);
        //setting up the keyboard scanner
        System.out.println("1.Display stores posts.");
        System.out.println("2.Display the first post with given attribute value.");
        System.out.println("3.Display the current total number of stored posts.");
        System.out.println("4.Store the data of a new post.");
        System.out.println("5.Delete a post by one of the following options(post date or post author).");
        System.out.println("6.Delete all the stored posts.");
        System.out.println("7.Sort the posts based on one of the attributes");

        System.out.println("8.Exit");
        try {
            choice = sc.nextInt();//using the scanner to get the user's choice
        } catch (Exception e) {//checking if the scanned data was of the correct type
            System.out.println("Please enter a number");
            choice = menu();
        }
        if (choice < 9 && choice > 0) {
            return choice;
        } else {
            menu();
        }
        return 0;
    }
}


