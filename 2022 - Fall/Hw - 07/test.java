import java.util.Scanner;
import java.util.Random;
import java.lang.Thread;

public class test {
    public static void main(String args[]){
    
        tetris game = new tetris();
        Scanner input = new Scanner(System.in);
        Random rand = new Random();

        int size;
        char type;
        int width=0;
        int height=0;
        char letters[]={'I','O','T','J','L','S','Z'};
        
        do{
            System.out.println("Enter board size :");
            size= input.nextInt();
        }while(size<6);

        game.setSize(size);

        game.makeBoard(game.getSize());

        do{

            game.cursorh=1;

            System.out.printf("what type :");

            type=input.next().charAt(0);

            if(type=='o' || type=='O' || type=='i' || type=='I' || type=='t' || type=='T' || type=='r' || type=='R'
            || type=='l' || type=='L' || type=='j' || type=='J' || type=='s' || type=='S' || type=='z' || type=='Z')
            {

                if(type=='i') type='I';
                else if(type=='o') type='O';
                else if(type=='t') type='T';
                else if(type=='l') type='L';
                else if(type=='j') type='J';
                else if(type=='s') type='S';
                else if(type=='z') type='Z';

                int d=rand.nextInt(7);

                if(type=='R' || type == 'r') {type=letters[d];}

                game.setType(type);

                if(type=='I') width=4;
                else if(type=='O') width=2;
                else if(type=='T') width=3;
                else if(type=='L') width=2;
                else if(type=='J') width=2;
                else if(type=='S') width=3;
                else if(type=='Z') width=3;

                if(type=='I') height=1;
                else if(type=='O') height=2;
                else if(type=='T') height=2;
                else if(type=='L') height=3;
                else if(type=='J') height=3;
                else if(type=='S') height=2;
                else if(type=='Z') height=2; 
                
                game.middle=size/2-width/2;

                    for(int i=1; i<size; i++){

                        if(i==1)
                        {

                        System.out.printf("enter rotation(L-R) and count\n");

                        game.rotation = input.next().charAt(0);
                        game.rotationCount = input.nextInt();


                        System.out.printf("enter tetromino rotation(L-R) and count\n");

                        game.moveRotation = input.next().charAt(0);
                        game.moveRotationCount = input.nextInt();

                        if(game.rotation=='R' || game.rotation=='r')
                        game.middle=game.middle+game.rotationCount;

                        if(game.rotation=='L' || game.rotation=='l')
                        game.middle=game.middle-
                        game.rotationCount;

                        }

                        while(game.checkBoard(i, width)==true)
                        {

                            game.Add();
                            if(i!=1) game.resetBoard(i-height,width);
                            game.Draw();
                            game.cursorh++;
                            wait(500);
                            System.out.printf("\033[3;1H");
                            System.out.printf("\033[2J");

                        }                       
                    }
            }

            else if (type=='q' || type=='Q') {System.out.printf("Game over !! \n");}
    
            else{ System.out.printf("Invalid Tetromino \n");}

        }while(type!='q' && type!='Q');

        input.close();

    }    // end of main

    public static void wait(int ms)
    {
        try{

            Thread.sleep(ms);
            
        }

        catch(InterruptedException ex)
        {
            Thread.currentThread().interrupt();
        }
    }   
    
}

