#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

//  A CLASS FOR HOLDING PPM IMAGE INFORMATIONS
class ppmImage{
public:

    ppmImage(); // DEFAULT CONSTRUCTOR

    ppmImage(string filename);  //  A CONSTUCTOR WHICH TAKES A PPM FILE NAME AS ARGUMENT AND CREATES OBJECT FORM FILE

    ppmImage(int column,int row);   // A CONSTRUCTOR THAT CREATES AN OBJECT USING THE GIVEN DIMENSIONS

    void setRow(int row){this->row=row;}    // SETTER FOR ROW

    void setColumn(int column){this->column=column;}    // SETTER FOR COLUMN

    void setGetMax(int max){this->maxValue=max;}    // SETTER FOR MAX VALUE

    void setType(string type){this->type=type;} //  SETTER VALUE FOR PPM FILE FORMAT

    int getRow() const {return row;}   //  FUNCTION THAT RETURNS THE NUMBER OF ROWS IN THE PPM FILE

    int getColumn() const {return column;} //  FUNCTION THAT RETURNS THE NUMBER OF COLUMNS IN THE PPM FILE

    int getMax() const {return maxValue;}  //   FUNCTION THAT RETURNS THE NUMBER OF MAX VALUE IN THE PPM FILE

    string getType() const {return type;}  //  PRINTS THE FILE TYPE LIKE 'P3'

    void getPixel() const;    //  FUNCTION THAT PRINTS THE VECTOR WHICH INCLUDES IMAGES PIXEL
    
    void saveFile(string name) const;    //   FUNCTION THAT SAVES THE IMAGE FILE

    void openFile(string name); //  FUNCTION THAT OPENS THE IMAGE FILE

    int isVectorEmpty() const;  // CHECKS THE VECTOR SITUTATION WHETHER IS EMPTY OR NOT

    void swapPixel(int column,int row,int value);   // CHANGES THE PIXEL AT THE GIVEN LOCATION TO GIVEN VALUE

    friend ostream& operator <<(ostream& os,const ppmImage &o); // COUT OVERLOADING

    friend ppmImage operator+(const ppmImage& o1,const ppmImage& o2);   // OVERLOADING FOR ADDITION

    friend ppmImage operator-(const ppmImage& o1,const ppmImage& o2);   // OVERLOADING FOR SUBSTRUCTION

    const int& operator()(int column,int row,int index) const; // FUNCTION OVERLOADING FOR RETURNING THE PIXEL AT THE REQUESTED COORDINATES

private:

    int row;    // HOLDS ROW INFORMATION OF FILE
    int column; // HOLDS COLUMN INFORMATION OF FILE
    int maxValue;   // HOLDS THE MAX VALUE OF FILE 
    string type;    // HOLDS THE TYPE OF FILE
    vector<vector<int>> image;  // HOLDS THE PIXELS OF FILE

};

//  DEFAULT CONSTRUCTOR
ppmImage::ppmImage(){

    row=0;
    column=0;
    maxValue=0;
    type="";
    image={};

}

//CONSTRUCTOR THAT TAKES FILE AS A ARGUMENT
ppmImage::ppmImage(string filename){

    ifstream inputStream(filename);

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

//CONSTRUCTOR THAT CREATES OBJECT ACCONDING TO GIVEN DIMENSIONS
ppmImage::ppmImage(int column,int row){

    if(row<=0 || column<=0){ 
        cout << " Wrong dimensions !";
        exit(1); 
    }

    this->row=row;
    this->column=column;
    maxValue=255;
    type="P3";

    // CREATING A VECTOR WITH GIVEN DIMENSIONS . PIXEL'S VALUES ARE INITIALLY WHITE(255)
    
    for(int i=0;i<column;++i){
           
		vector<int> v2;           
           
        for(int j=0;j<row*3;++j) {  
                    
                int c;
                c=255;  
                v2.push_back(c);
            
        }

            image.push_back(v2);

        }

}

//  FUNCTION THAT PRINTS THE PIXELS IN THE VECTOR
void ppmImage::getPixel() const {

    for(int i=0;i<image.size();i++){
        for(int j=0;j<image[i].size();j++)  cout << image[i][j] << " ";

        cout << endl;
    }

}

//  FUNCTION THAT OPENS THE PPM FILE CHECKS IT THEN TAKES INFORMATION FROM PPM FILE
void ppmImage::openFile(string name){

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
void ppmImage::saveFile(string name) const{

    //  OPENING THE FILE 
    ofstream outStream(name);   

    //  SAVING THE FILE INFORMATION FROM IMAGE-EDITOR CLASS
    outStream << type << endl;

    outStream << column << " " << row << endl;

    outStream << maxValue << endl;
 
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

//  FUNCTION THAT CHECKS THE VECTOR WHETHER IS EMPTY OR NOT IF IT IS EMPTY RETURNS 1 ELSE 0
int ppmImage::isVectorEmpty() const {

    if(image.empty()) return 1;
    else return 0;

}

//  FUNCTION THAT CHANGES THE INDIVIDUAL PIXEL AT GIVEN POSITIONS
void ppmImage::swapPixel(int column,int row,int value){

    image[column][row]=value;

}

//  FUNCTION THAT OVERLOADS THE COUT
ostream& operator << (ostream& os,const ppmImage& o){

    os << o.column << " " << o.row << " " << o.maxValue << " " << o.type << endl ;

    return os;

}
//  FUNCTION THAT ADDS THE 2 PPMIMAGE'S OBJECT
ppmImage operator +(const ppmImage& o1,const ppmImage& o2){

    ppmImage o3 ;   // VARIABLE FOR HOLDING THE ADDITION OF 2 OBJECT

    //  CHECKING THE DIMENSIONS OF GIVEN OBJECTS IF THEY HAVE NOT SAME DIMENSIONS FUNCTION RETURN EMPTY OBJECT
    if(o1.column==o2.column && o1.row==o2.row){

        o3.column=o1.column;
        o3.row=o1.row;
        o3.maxValue=o1.maxValue;
        o3.type=o1.type;
  
        o3.image.resize(o3.column); //  o3 HAS INITIALLY EMPTY VECTOR WE RESIZE IT 

        for(int i=0;i<o3.column;i++) o3.image[i].resize(o3.row*3); 

        for(int i=0;i<o1.column;i++){
            for(int j=0;j<o1.row*3;j++){

                o3.image[i][j]=o1.image[i][j]+o2.image[i][j];

                if(o3.image[i][j]>=o3.maxValue) o3.image[i][j]=255; // IF ADDITION OF 2 OBJECTS BIGGER THAN 255 IT MEANS SATURATED

            }
        }
            
        return o3;

    }

    else return o3;

}

//  FUNCTION THAT SUBSTRACT THE 2 PPMIMAGE'S OBJECT
ppmImage operator-(const ppmImage& o1,const ppmImage& o2){

    ppmImage o3 ;

    //  CHECKING THE DIMENSIONS OF OBJECTS  IF THEY HAVE NOT SAME DIMENSIONS FUNCTION RETURNS EMPTY OBJECT
    if(o1.column==o2.column && o1.row==o2.row){

        o3.column=o1.column;
        o3.row=o1.row;
        o3.maxValue=o1.maxValue;
        o3.type=o1.type;
  
        o3.image.resize(o3.column);

        for(int i=0;i<o3.column;i++) o3.image[i].resize(o3.row*3); 

        for(int i=0;i<o1.column;i++){
            for(int j=0;j<o1.row*3;j++){

                o3.image[i][j]=o1.image[i][j]-o2.image[i][j];

                if(o3.image[i][j]<0) o3.image[i][j]=0;  // PIXELS CAN NOT BE LESS THAN 0

            }
        }
            
        return o3;

    }

    else return o3;    

}

//  FUNCTION THAT RETURNS THE ONE OF THE RGB VALUES OF REQUESTED PIXEL'S 
const int& ppmImage::operator()(int column,int row,int index) const {
    
    //  CHECKING THE DIMENSIONS
    if(row < this->row && column < this->column){

        if(index==1) return image[column][3*row];
        else if(index==2) return image[column][3*row+1];
        else if(index==3) return image[column][3*row+2]; 
        else{
            //  IF USER ENTERS INVALID INDEX
            cout<< "invalid color index " ;
            return image[0][0];
        }

    }  

    else{

        cout << "invalid column or row index " ; 
        return image[0][0];
    }
}

//  FUNCTION THAT TESTS THE OVERLOADING + FUNCTION THAN SAVES THE PIXELS TO GIVEN FILE
int test_addition(const string filename_image1,const string filename_image2,const string filename_image3){

    ppmImage o1(filename_image1);
    ppmImage o2(filename_image2);
    ppmImage o3 = o1+o2;

    o3.saveFile(filename_image3);

    if(o3.isVectorEmpty()) return 0;    //  IF OBJECTS HAVE NOT SAME SIZE FUNCTION RETURNS 0 

    else return 1;

}

// //  FUNCTION THAT TESTS THE OVERLOADING - FUNCTION THAN SAVES THE PIXELS TO GIVEN FILE
int test_substraction(const string filename_image1,const string filename_image2,const string filename_image3){

    ppmImage o1(filename_image1);
    ppmImage o2(filename_image2);
    ppmImage o3 = o1-o2;

    o3.saveFile(filename_image3);

    if(o3.isVectorEmpty()) return 0;    //  //  IF OBJECTS HAVE NOT SAME SIZE FUNCTION RETURNS 0 

    else return 1;

}

// returns 1 if the operation is successful. otherwise, returns 0.
// reads ppm data from file named as source_ppm_file_name. stores data in destination_object
int read_ppm(const string source_ppm_file_name, ppmImage& destination_object){

    destination_object.openFile(source_ppm_file_name);
    return 1;

}

// returns 1 if the operation is successful. otherwise, returns 0.
// writes ppm data from source_object to the file named destination_ppm_file_name.
int write_ppm(const string destination_ppm_file_name, const ppmImage& source_object){

    source_object.saveFile(destination_ppm_file_name);
    return 1;
}

// returns 1 if the operation is successful. otherwise, returns 0.
// reads images from filename_image1 and prints it to stdout
int test_print(const string filename_image1){

    ppmImage o1(filename_image1);
    
    cout << o1;

    return 1;

}

//  if swap_choice is 1: swaps red and green
//  if swap_choice is 2: swaps red and blue
//  if swap_choice is 3: swaps green and blue
//  if swap_choice is not 1, 2 or 3: no swaps (this does not mean that the operation is not
//  successful. the function should return 1 in this case if everything is normal)
//  returns 1 if the operation is successful. otherwise, returns 0.
int swap_channels(ppmImage& image_object_to_be_modified, int swap_choice){

    if(swap_choice==1){

        for(int i=0;i<image_object_to_be_modified.getColumn();i++)
            for(int j=0;j<image_object_to_be_modified.getRow();j++){

                //  HOLDING THE VALUES BEFORE SWAPPING    
                int temp_r =  image_object_to_be_modified(i,j,2);   
                int temp_g =  image_object_to_be_modified(i,j,1);
                int temp_b =  image_object_to_be_modified(i,j,3);
 
                image_object_to_be_modified.swapPixel(i,3*j,temp_r);
                image_object_to_be_modified.swapPixel(i,3*j+1,temp_g);
                image_object_to_be_modified.swapPixel(i,3*j+2,temp_b);
            }

            return 1;   

    }

    else if(swap_choice==2){

        for(int i=0;i<image_object_to_be_modified.getColumn();i++)
            for(int j=0;j<image_object_to_be_modified.getRow();j++){

                //  HOLDING THE VALUES BEFORE SWAPPING 
                int temp_r =  image_object_to_be_modified(i,j,3);
                int temp_g =  image_object_to_be_modified(i,j,2);
                int temp_b =  image_object_to_be_modified(i,j,1);

                image_object_to_be_modified.swapPixel(i,3*j,temp_r);
                image_object_to_be_modified.swapPixel(i,3*j+1,temp_g);
                image_object_to_be_modified.swapPixel(i,3*j+2,temp_b);
            }   

        return 1; 

    }

    else if(swap_choice==3){

        for(int i=0;i<image_object_to_be_modified.getColumn();i++)
            for(int j=0;j<image_object_to_be_modified.getRow();j++){

                //  HOLDING THE VALUES BEFORE SWAPPING 
                int temp_r =  image_object_to_be_modified(i,j,1);
                int temp_g =  image_object_to_be_modified(i,j,3);
                int temp_b =  image_object_to_be_modified(i,j,2);

                image_object_to_be_modified.swapPixel(i,3*j,temp_r);
                image_object_to_be_modified.swapPixel(i,3*j+1,temp_g);
                image_object_to_be_modified.swapPixel(i,3*j+2,temp_b);
            }

            return 1;    

    }

    else return 1;

}

//  creates and returns a copy of a new ppmImage object which stores only one color at each
//  pixel. This simply takes the source and copies only one color information and stores it in
//  a new object. The other color channels are simply going to be zeros.
//  if color_choice is 1: red channel is preserved
//  if color_choice is 2: green channel is preserved
//  if color_choice is 3: blue channel is preserved
ppmImage single_color(const ppmImage& source, int color_choice){

    int column=source.getColumn();
    int row=source.getRow();

    ppmImage temp(column,row);

    temp.setColumn(source.getColumn());
    temp.setRow(source.getRow());
    temp.setGetMax(source.getMax());
    temp.setType(source.getType());

    for(int i=0;i<temp.getColumn();i++)
        for(int j=0;j<temp.getRow();j++){

            if(color_choice==1){

                temp.swapPixel(i,3*j,source(i,j,1));                
                temp.swapPixel(i,3*j+1,0);
                temp.swapPixel(i,3*j+2,0);
            } 

            else if(color_choice==2){
                
                temp.swapPixel(i,3*j,0);                
                temp.swapPixel(i,3*j+1,source(i,j,2));
                temp.swapPixel(i,3*j+2,0);   
            } 

            else if(color_choice==3){

                temp.swapPixel(i,3*j,0);                
                temp.swapPixel(i,3*j+1,0);
                temp.swapPixel(i,3*j+2,source(i,j,3)); 
    
            }

            else return temp; 
        }

    return temp;

}

int main(int argc, char** argv)
{
//  check for number of command line arguments
//  the first argument is going to be choice number
//  the second argument is going to be a ppm_file_name1
//  the third argument is going to be ppm_file_name2 (this is optional)
//  the third argument is going to be ppm_file_name3 (this is optional)
    
    int choice; //  HOLDS THE USER CHOICE

    if(argc>1)  //  IF THERE IS NOT ENOUGH INPUT OR USER ENTERS WRONG INPUT , FUNCTION EXITS
        if(isdigit(argv[1][0])) 
            choice=stoi(argv[1]);
        else    exit(1);

    else exit(1);

    if(choice){

        switch(choice){
            // if choice number is 1
            // check the existence of the optional arguments. If they are not given, exit
            case 1: 
                    if(argc>=5){
                        int result = test_addition(argv[2],argv[3],argv[4]);
                        cout << "test_addition result is " << result << endl;
                        int printTest = test_print(argv[4]);
                        cout << "test_print result is " << printTest << endl;
                    }    
                    else
                        exit(1);
                    break;

            // if choice number is 2
            // check the existence of the optional arguments. If they are not given, exit
            case 2:
                    if(argc>=5){
                        int result = test_substraction(argv[2],argv[3],argv[4]);
                        cout << "test_substraction result is " << result << endl;
                        int printTest = test_print(argv[4]);
                        cout << "test_print result is " << printTest << endl;                        
                    }    
                    else
                        exit(1);
                    break;                         

            //  if choice number is 3
            //  read ppm_file_name1 using function read_ppm
            //  swap red and blue channels
            //  write the updated data to a file named "ppm_file_name2". use write_ppm function.
            case 3:
                    if(argc>=4){
                        ppmImage test;
                        int res1 = read_ppm(argv[2],test);
                        cout << "read_ppm result is " << res1 << endl;
                        int res2 = swap_channels(test,2);
                        cout << "swap_channel result is " << res2 << endl;
                        int res3 = write_ppm(argv[3],test);
                        cout << "write_ppm result is " << res3 << endl;
                        int printTest = test_print(argv[3]);
                        cout << "test_print result is " << printTest << endl;
                    }    
                    else
                        exit(1);
                    break;

            //  if choice number is 4
            //  read ppm_file_name1 using function read_ppm
            //  swap green and blue channels. use swap_channels function
            //  write the updated data to a file named "ppm_file_name2". use write_ppm function.
            case 4:
                    if(argc>=4){
                        ppmImage test;
                        int res1 = read_ppm(argv[2],test);
                        cout << "read_ppm result is " << res1 << endl;
                        int res2 = swap_channels(test,3);
                        cout << "swap_channel result is " << res2 << endl;
                        int res3 = write_ppm(argv[3],test);
                        cout << "write_ppm result is " << res3 << endl;
                        int printTest = test_print(argv[3]);
                        cout << "test_print result is " << printTest << endl;
                    }    
                    else
                        exit(1);
                    break;

            // if choice number is 5
            // read ppm_file_name1 using function read_ppm
            // create a new object which only contains red channel data of the file read.
            // use single_color function
            // write the data of the new object to a file named "ppm_file_name2". use write_ppm function.
            case 5:
                    if(argc>=4){
                        ppmImage test;
                        int res1 = read_ppm(argv[2],test);
                        cout << "read_ppm result is " << res1 << endl;
                        test = single_color(test,1);
                        int res2 = write_ppm(argv[3],test);
                        cout << "write_ppm result is " << res2 << endl;
                        int printTest = test_print(argv[3]);
                        cout << "test_print result is " << printTest << endl;                       
                    }    
                    else
                        exit(1);
                    break;

            // if choice number is 6
            //  read ppm_file_name1 using function read_ppm
            //  create a new object which only contains green channel data of the file read. use
            //  single_color function
            //  write the data of the new object to a file named "ppm_file_name2". use write_ppm function.
            case 6:
                    if(argc>=4){
                        ppmImage test;
                        int res1 = read_ppm(argv[2],test);
                        cout << "read_ppm result is " << res1 << endl;
                        test = single_color(test,2);
                        int res2 = write_ppm(argv[3],test);
                        cout << "write_ppm result is " << res2 << endl;
                        int printTest = test_print(argv[3]);
                        cout << "test_print result is " << printTest << endl;                       
                    }    
                    else
                        exit(1);
                    break;

            //  if choice number is 7
            //  read ppm_file_name1 using function read_ppm
            //  create a new object which only contains blue channel data of the file read. use
            //  single_color function
            //  write the data of the new object to a file named "ppm_file_name2". use write_ppm function.
            case 7:
                    if(argc>=4){
                        ppmImage test;
                        int res1 = read_ppm(argv[2],test);
                        cout << "read_ppm result is " << res1 << endl;
                        test = single_color(test,3);
                        int res2 = write_ppm(argv[3],test);
                        cout << "write_ppm result is " << res2 << endl;
                        int printTest = test_print(argv[3]);
                        cout << "test_print result is " << printTest << endl;
                    }    
                    else
                        exit(1);
                    break;
            
            //  If users enters different choice number
            default: 
                    cout << " Invalid request " << endl;
                    break;
        }

    }

}
