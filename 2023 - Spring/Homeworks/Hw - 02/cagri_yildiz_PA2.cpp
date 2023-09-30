
//  190-104-26-30 CAGRI YILDIZ PROGRAMMING ASSIGNMENT 2 

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;


//  IMAGE EDITOR CLASS WHICH INCLUDES THE INFORMATIONS ABOUT IMAGE'S RGB COEFFICIENTS,IMAGE'S PIXELS AND IT'S MAX VALUE WITH FILE FORMAT INFO.
class ImageEditor{
public:

    ImageEditor();  //  DEFAULT CONSTRUCTOR FOR IMAGE EDITOR CLASS

    ImageEditor(int x,int y,int z); // ANOTHER CONSTRUCTOR FOR ASSIGN THE 1 TO RGB COEFFICIENT

    void getPixel() const;    //  FUNCTION THAT PRINTS THE VECTOR WHICH INCLUDES IMAGES PIXEL 

    int getRow() const {return row;}   //  FUNCTION THAT RETURNS THE NUMBER OF ROWS IN THE PPM FILE

    int getColumn() const {return column;} //  FUNCTION THAT RETURNS THE NUMBER OF COLUMNS IN THE PPM FILE

    int getMax() const {return maxValue;}  //   FUNCTION THAT RETURNS THE NUMBER OF MAX VALUE IN THE PPM FILE

    void setRed(float red){r=red;}  //  SETS USER INPUT TO RED COEFFICIENTS

    void setGreen(float green){g=green;}    //  SETS USER INPUT TO GREEN COEFFICIENTS

    void setBlue(float blue){b=blue;}   //  SETS USER INPUT TO BLUE COEFFICIENTS

    float getRed() const {return r;}   //  PRINTS THE RGB VALUES

    float getGreen() const {return g;} //  PRINTS THE RGB VALUES

    float getBlue() const {return b;}  //  PRINTS THE RGB VALUES

    string getType() const {return type;}  //  PRINTS THE FILE TYPE LIKE 'P3'

    void saveFile(string name);    //   FUNCTION THAT SAVES THE IMAGE FILE

    void openFile(string name); //  FUNCTION THAT OPENS THE IMAGE FILE

private:

    float r,g,b;    //  VARIABLES FOR RGB VALUES
    string type;    //  VARIABLE FOR FILE TYPE  IN THE PPM FILE
    int row,column,maxValue;    //  VARIABLES FOR INFORMATION ABOUT PPM FILE
    vector<vector<int>> image;  //  VECTOR FOR SAVING THE PIXELS IN THE PPM FILE

};

//  DEFAULT CONSTRUCTOR
ImageEditor::ImageEditor():r(1),g(1),b(1)
{}

//  INITIALIZATION CONSTRUCTOR
ImageEditor::ImageEditor(int x,int y,int z):r(x),g(y),b(z)
{}

//  FUNCTION THAT PRINTS THE PIXELS IN THE VECTOR
void ImageEditor::getPixel() const {

    for(int i=0;i<image.size();i++){
        for(int j=0;j<image[i].size();j++)  cout << image[i][j] << " ";

        cout << endl;
    }

}

//  FUNCTION THAT OPENS THE PPM FILE CHECKS IT THEN TAKES INFORMATION FROM PPM FILE
void ImageEditor::openFile(string name){

    ifstream inputStream(name);

    //  IF THERE IS NO FILE AT THAT PATH
    if(!inputStream){

        cout << "File Can Not Found !\n";

    }

    //  TAKING THE INFORMATIONS FROM PPM FILE
        inputStream >> type;
        inputStream >> column;
        inputStream >> row;
        inputStream >> maxValue;

    //  IF  FILE TYPE IS NOT P3 IT MEANS WRONG FILE TYPE HAS OPENED
        if(type != "P3" || maxValue != 255){

            cout << "Invalid PPM file format\n" ;

        }
    
    //  FOR LOOP FOR TAKING THE PIXELS FROM PPM FILE TO SAVE IMAGE VECTOR 
        for(int i=0;i<column;++i){
           
		    vector<int> v2;           
           
            for(int j=0;j<row*3;++j) {  
                    
                int c;
                inputStream >> c;
                v2.push_back(c);
            
            }

            image.push_back(v2);

        }

        //  CLOSING THE FILE
        inputStream.close();
}

//  FUNCTION THAT SAVES THE CHANGED FILE 
void ImageEditor::saveFile(string name){

    //  OPENING THE FILE 
    ofstream outStream(name);   

    //  SAVING THE FILE INFORMATION FROM IMAGE-EDITOR CLASS
    outStream << type << endl;

    outStream << column << " " << row << endl;

    outStream << maxValue << endl;

    //  CHANGING THE PIXELS WHICH EFFECTED BY RGB COEFFICENTS
    for(int i=0;i<image.size();i++){
        for(int j=0;j<image[i].size();j=j+3){

            image[i][j]=((image[i][j]*r)+(image[i][j+1]*g)+(image[i][j+2]*b));

            if(image[i][j]>255) image[i][j]=255;    //  IF PIXEL HIGHER THAN 255 IT MEANS IT IS SATURATED IT HAVE TO BE 255

            image[i][j+1]=image[i][j];
            image[i][j+2]=image[i][j];

        }
    }
    
    //  FOR LOOP FOR SAVING THE NEW PIXELS TO FILE
    for(int i=0;i<image.size();i++){
        for(int j=0;j<image[i].size();j++){

            outStream << image[i][j] << " " ; 
        
        }

        outStream << endl;

    }     

    //  CLOSING THE FILE
    outStream.close();

}

int main(){

    //  CONDITIONS FOR SET THE PRECISION '2' LIKE 2.119 -> 2.20
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    int mainMenuChoice; //  VARIABLE THAT HOLDS THE MAIN MENU USER SELECTION
    int subMenuChoice;  //  VARIABLE THAT HOLDS THE SUB-MENU USER SELECTION
    int subSubMenuChoice;   //  VARIABLE THAT HOLDS THE SUB-SUB-MENU USER SELECTION

    float red,green,blue;   //  VARIABLES FOR RGB COEFFICIENTS  

    string fileName;    //  VARIABLE FOR FILE NAME

    ImageEditor image1; //  OBJECT FOR THE IMAGE

    //  DO-WHILE LOOP FOR MAIN MENU
    do
    {

        cout << "MAIN MENU" << endl;
        cout << "0 - Exit" << endl;
        cout << "1 - Open An Image(D)" << endl;
        cout << "2 - Save Image Data(D)" << endl;
        cout << "3 - Scripts(D)" << endl;

        cin >> mainMenuChoice;     

        //  SWITCH-CASE FOR SUB-MENU OPERATIONS
        switch (mainMenuChoice)
        {

        case 1:

            //  DO-WHILE LOOP FOR PRINTING THE CURRENT SITUATION IN THE MENU
            do{

                cout << "OPEN AN IMAGE MENU" << endl;
                cout << "0 - UP" << endl;
                cout << "1 - Enter The Name Of The Image File" << endl;

                cin >> subMenuChoice;

                if(subMenuChoice==1){
                   
                    cin >> fileName;

                    image1.openFile(fileName);

                }

            }while(subMenuChoice!=0);

            break;   

        case 2:

        //  DO-WHILE LOOP FOR PRINTING THE CURRENT SITUATION IN THE MENU
        do{

            cout << "SAVE IMAGE DATA MENU" << endl;
            cout << "0 - UP" << endl;
            cout << "1 - Enter A File Name" << endl;

            cin >> subMenuChoice;

            if(subMenuChoice==1){

                cin >> fileName;

                image1.saveFile(fileName);

            }

        }while(subMenuChoice!=0);
            
            break;

        case 3:

            //  DO-WHILE LOOP FOR PRINTING THE CURRENT SITUATION IN THE MENU
            do
            {

            cout << "SCRIPTS MENU" << endl;
            cout << "0 - UP" << endl;
            cout << "1 - Convert To Grayscale(D)" << endl;

            cin >> subMenuChoice;

                if(subMenuChoice==1){
                    
                    //  DO-WHILE LOOP FOR PRINTING THE CURRENT SITUATION IN THE MENU
                    do{
                        
                        cout << "CONVERT TO GRAYSCALE MENU" << endl;
                        cout << "0 - UP" << endl;
                        cout << "1 - Enter Coefficients For RED GREEN And BLUE Channels." << endl;
                        
                        cin >> subSubMenuChoice; 

                        if(subSubMenuChoice==1){

                            do{

                                cin >> red >> green >> blue ;

                                //  INVALID COEFFICIENTS CONDITIONS
                                if(red<0 || red>=1 || green<0 || green>=1 || blue<0 || blue >=1)   cout << "Invalid Coefficients Try Again" << endl;
                        
                            }while(red<0 || red>=1 || green<0 || green>=1 || blue<0 || blue >=1);
                                
                            //  SETTING RGB COEFFICIENTS FOR OBJECT
                            image1.setRed(red);
                            image1.setGreen(green); 
                            image1.setBlue(blue);
                        
                        }

                    }while(subSubMenuChoice !=0 );

                }

            }while(subMenuChoice != 0);    
            
            break;                
        
        default:

            if(mainMenuChoice!=0) cout << "Invalid Request" << endl;    //  IF USER ENTERS DIFFERENT NUMBER FOR MENU
            
            break;
        }

    } while(mainMenuChoice!=0);
     
    return 0;

}