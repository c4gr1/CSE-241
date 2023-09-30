/**
 * 
 * TetrisClass
 * 
 * @author c.yildiz
 * @version 1.0.0
 * @since 2022-05-01
 * 
 */

public class tetris {

    private int size;
    private char type;

    public int cursorh;
    public char moveRotation;
    public char rotation;
    public int rotationCount;
    public int moveRotationCount;
    public int middle;

    char [][] board;
    char [][] tetromino;

    public void setSize(int Size){

        size=Size;

    }
    public void setType(char Type){

        type=Type;

    }

    public int getSize(){

        return size;

    }
    public char getType(){

        return type;

    } 
    
    /** Default Constructor */
    public tetris(){

        size=10;
        type='O';

    }

    /** Constructor */
    public tetris(int Size, char Type){

        setSize(Size);
        setType(Type);

    }

    /**
     * Makes board for game
     *
     * @param Size for game size
     */

    public void makeBoard(int Size){

        board= new char [Size][Size];

        for(int i=0; i<Size; i++)
        {

            for(int j=0; j<Size; j++)
            {
                if(i==0 || i==Size-1) board[i][j]='#';
                else if(j==0 || j==Size-1) board[i][j]='#';
                else board[i][j]=' ';

            }

        }

    }

    /**
     * 
     * Adds new pieces to board
     *@param h for tetrominos height 
     *@param w for tetrominos width 
     * 
     */

    public void Add(){

        int h,w,temp1;

        temp1= cursorh;

        switch(type)
        {
            case('I'):
                        h=1;
                        w=4;
                        
                        tetromino= new char[1][4];

                        for(int i=0; i<1; i++)
                            for(int j=0; j<4; j++) tetromino[i][j]='I';

                        for(int i=0; i<h; i++)
                            for(int j=0; j<w; j++)
                                board[temp1+i][middle+j]=tetromino[i][j];

            break;

            case('O'):
                        h=2;
                        w=2;
                        
                        tetromino= new char[2][2];

                        for(int i=0; i<2; i++)
                            for(int j=0; j<2; j++) tetromino[i][j]='O';

                        for(int i=0; i<h; i++)
                            for(int j=0; j<w; j++)
                                board[temp1+i][middle+j]=tetromino[i][j];

            break;            

            case('T'):
            h=2;
            w=3;
            
            tetromino= new char[2][3];

            for(int i=0; i<2; i++)
                for(int j=0; j<3; j++){
                       
                    if((i==1 && j==0) ||(i==1 && j==2) ) tetromino[i][j]=' ';
                    else tetromino[i][j]='T';

                } 

            for(int i=0; i<h; i++)
                for(int j=0; j<w; j++)
                    board[temp1+i][middle+j]=tetromino[i][j];

            break;

            case('J'):
            h=3;
            w=2;
            
            tetromino= new char[3][2];

            for(int i=0; i<3; i++)
                for(int j=0; j<2; j++){
                       
                    if((i==0 && j==0) || (i==1 && j==0)) tetromino[i][j]=' ';
                    else tetromino[i][j]='J';

                } 

            for(int i=0; i<h; i++)
                for(int j=0; j<w; j++)
                    board[temp1+i][middle+j]=tetromino[i][j];

            break;

            case('L'):
            h=3;
            w=2;
            
            tetromino= new char[3][2];

            for(int i=0; i<3; i++)
                for(int j=0; j<2; j++){
                       
                    if((i==0 && j==1) || (i==1 && j==1)) tetromino[i][j]=' ';
                    else tetromino[i][j]='L';

                } 

            for(int i=0; i<h; i++)
                for(int j=0; j<w; j++)
                    board[temp1+i][middle+j]=tetromino[i][j];

            break;            
        
            case('S'):
            h=2;
            w=3;
            
            tetromino= new char[2][3];

            for(int i=0; i<2; i++)
                for(int j=0; j<3; j++){
                       
                    if((i==0 && j==0) ||(i==1 && j==2) ) tetromino[i][j]=' ';
                    else tetromino[i][j]='S';

                } 

            for(int i=0; i<h; i++)
                for(int j=0; j<w; j++)
                    board[temp1+i][middle+j]=tetromino[i][j];

            break; 

            case('Z'):
            h=2;
            w=3;
            
            tetromino= new char[2][3];

            for(int i=0; i<2; i++)
                for(int j=0; j<3; j++){
                       
                    if((i==0 && j==2) ||(i==1 && j==0) ) tetromino[i][j]=' ';
                    else tetromino[i][j]='Z';

                } 

            for(int i=0; i<h; i++)
                for(int j=0; j<w; j++)
                    board[temp1+i][middle+j]=tetromino[i][j];

            break;            
                   
        } // end of switch-case
     
    } //end of add

    /**
     * Resets the board
     * 
     * @param back previous location height of tetromino
     * @param width
     */

    public void resetBoard(int back,int width){

        for(int j=0; j<width; j++) board[back][middle+j]=' ';

    }

    /**
     * Checks the following space is empty or not
     * @param next following space
     * @param width of tetromino
     * @return true or false
     * 
     */

    public boolean checkBoard(int next,int width){

        if(next>=size) return false;

        else{

            for(int j=0; j<width; j++)
                if(board[next][middle+j]!=' ') return false;

        }

        return true;

    }

    /**
     * 
     * print function for game
     * 
     */

    public void Draw(){

        for(int i=0; i<size; i++)
        {    
            for(int j=0; j<size; j++)
            {
                System.out.printf("%c",board[i][j]);
            }
            
            System.out.printf("\n");
        }    
    }

  
}
