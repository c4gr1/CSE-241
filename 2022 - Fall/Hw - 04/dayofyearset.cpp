#include <iostream>
#include <list>
#include "dayofyearset.h"

using namespace std;

namespace cagriYildiz{


	DayofYearSet :: DayofYear :: DayofYear() : day(1),month(1)
	{
	
		//Initially empty	
	
	}
	
/*********************************************************************/	
	
	DayofYearSet :: DayofYear :: DayofYear(int d , int m)
	{
			
		//number of days in months
			
        int const arrMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; 

		//checks if input is valid

        if(m<0 || m>12){ 
            cout << endl << "Invalid month value" << endl;
            exit(1); 
        }

		//checks if input is valid
		
        if(d < 0 || d > arrMonth[m-1]){ 
            cout << endl << "Invalid day value" << endl;
            exit(1); 
        }

        day = d;
        month = m;
	
	}
	
/*********************************************************************/
	
    void DayofYearSet :: DayofYear :: setDay(int d){
        
        //number of days in months
        
        int const arrMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
        
        //checks if input is valid
        
        if(d < 0 || d > arrMonth[month-1]){ 
            cout << endl << "Invalid day value" << endl;
            exit(1); 
        }

        day = d;
    }

/*********************************************************************/
    
        void DayofYearSet :: DayofYear :: setMonth(int m){

		 //checks if input is valid

        if(m<0 || m>12){ 
            cout << endl << "Invalid month value" << endl;
            exit(1); 
        }

        month = m;
    }

/*********************************************************************/

    void DayofYearSet :: DayofYear :: setAll(int d,int m){
        
        
        //number of days in months
        
        int const arrMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
        
        //checks if input is valid

        if(m<0 || m>12){ 
            cout << endl << "Invalid month vaule" << endl;
            exit(1); 
        }

		//checks if input is valid

        if(d < 0 || d > arrMonth[m-1]){ 
            cout << endl << "Invalid day vaule" << endl;
            exit(1); 
        }

        day = d;
        month = m;

    }

/*********************************************************************/
    
    /*Getters*/
    int DayofYearSet :: DayofYear :: getDay()const{return day;} 
    int DayofYearSet :: DayofYear :: getMonth()const{return month;}	

	    bool DayofYearSet :: DayofYear :: operator ==(const DayofYear& other){ //checks if dayofyears are same
        if(day == other.day && month == other.month) return true;
        else return false;
    }

/*********************************************************************/

    ostream& operator<<(ostream &out,const DayofYearSet :: DayofYear& input){ //ostream operator overloading for dayofyear
        out << endl << "Day:" << input.getDay() << endl <<  "Month:" << input.getMonth() << endl;
        return out;
    }

/*********************************************************************/
    
    DayofYearSet :: DayofYearSet(){
        daySet = nullptr;
         size = 0; 
    }

/*********************************************************************/
    
 	DayofYearSet :: DayofYearSet(list <DayofYear> &l){
 	
	 	size=l.size();
	 	
	 	daySet = new DayofYear[size];
	 	
	 	copy(l.begin(),l.end(),daySet);  
 	
 	}

/*********************************************************************/
 	 	
    ostream& operator<<(ostream &out,const DayofYearSet& input){
               
        if(input.empty()){
            out << "There is not any element in this set" << endl;
            return out;
        }
        
        for(int i=0;i<input.size ;i++){
            out << "Element "<< i+1 << "   ->\tDay:" << input.daySet[i].getDay() << "\tMonth:" << input.daySet[i].getMonth() << endl;
        }
        return out;
    } 

/*********************************************************************/
    
    bool DayofYearSet :: operator==(const DayofYearSet& other)const{
        
        if(size != other.Size())
            return false;


        for(int i = 0; i < other.Size();i++){
            if(!isThere(other[i]) ){return false;}
        }
        return true;
    }

/*********************************************************************/

    bool DayofYearSet :: operator!=(const DayofYearSet& other)const{
        
        if( *this == other) return false;
        else return true;
    }

/*********************************************************************/
    
    int DayofYearSet :: Size()const{return size;}	

/*********************************************************************/
 	  
	bool DayofYearSet :: isThere(const DayofYear& input)const{

        for(int i=0;i<size;i++){
            if(daySet[i] == input) return true;
        }
        return false;
    }

/*********************************************************************/
    
    DayofYearSet :: DayofYear& DayofYearSet :: operator[](int index)const{
        
        //if(index < 0 || index>=setSize){cerr << endl << "---Error: Invalid Selection---" << endl; return  }

        
        return daySet[index];
    }

/*********************************************************************/
    
  	bool DayofYearSet :: empty()const{
        if(size == 0 || daySet == nullptr)
            return true;
        else return false;
    }

/*********************************************************************/
    
    const DayofYearSet DayofYearSet :: operator+(const DayofYearSet& other)const{
        
        DayofYearSet temp;

        if(empty()){
            return other;
        }

        else if(other.empty()){
            return *this;
        }

        else{
            
            for(int i = 0; i<size;i++){
                temp.add(daySet[i]);
            }

            for(int i = 0; i<other.Size();i++){
                temp.add(other[i]);
            }

            return temp;
        }
    } 

/*********************************************************************/
    
     void DayofYearSet :: add(const DayofYear& input){
        
        if(empty()){
            daySet = new DayofYear[1];
            daySet[0] = input;
            size++;
        }

        else if(!isThere(input)){
            
            DayofYear * temp = new DayofYear[size+1];
            
            for(int i=0;i<size;i++){
                temp[i] = daySet[i];
            }

            temp[size] = input;

            delete[] daySet;

            daySet = temp;

            
            size++;
        }
        
    }

/*********************************************************************/
    
    void DayofYearSet :: remove(){
        if(empty()){
            cout << endl << "---Error:there is not any element in set ---" << endl;
            return;
        }

        else{
            
            if(size == 1){
                delete[] daySet;
                daySet = nullptr;
                size--;
                return;
            }

            DayofYear * temp = new DayofYear[size-1];
            
            for(int i=0;i<size-1;i++){
                temp[i] = daySet[i];
            }

            delete[] daySet;

            daySet = temp;
            
            size--;
        }
    }

/*********************************************************************/

    void DayofYearSet :: remove(int index){
        
        if(empty()){
            cout << endl << "---Error:there is not any element in set ---" << endl;
        }

        else{
            
            if(index>size){
                cerr << endl <<  "---Error:Invalid index---" << endl;
                return;
            }

            if(size == 1){
                delete[] daySet;
                daySet = nullptr;
                size--;
                return;
            }

            DayofYear * temp = new DayofYear[size-1];
            int j = 0; 
            for(decltype(j)i=0;i<size-1;i++,j++){
                
                if(i==index) j++;

                temp[i] = daySet[j];
            }

            delete[] daySet;

            daySet = temp;
            
            size--;
        }
    }

/*********************************************************************/

    void DayofYearSet :: remove(const DayofYear& input){
        
        if(empty()){
            cout << endl << "---ERROR:there is not any element in set---" << endl;
        }

        else{
            
            if(!isThere(input)){
                cout << endl << "this element is not in the set" << endl;
                return;
            }

            if(size == 1){
                delete[] daySet;
                daySet = nullptr;
                size--;
                return;
            }

            DayofYear * temp = new DayofYear[size-1];
            int j = 0; 
            for(int i=0;i<size-1;i++,j++){
                
                if(daySet[i]==input) j++;

                temp[i] = daySet[j];
            }

            delete[] daySet;

            daySet = temp;
            
            size--;

        }
        

    }
    
/*********************************************************************/
    
    const DayofYearSet DayofYearSet :: operator-(const DayofYearSet& other)const{
        
        DayofYearSet temp;

        if(empty() || other.empty()){
            return *this;
        }
        
        else{
            for(int i = 0; i<size ; i++){
                if(!other.isThere(daySet[i]))
                    temp.add(daySet[i]);
            }
            return temp;
        }
    }

/*********************************************************************/
    
  	DayofYearSet :: ~DayofYearSet(){
        
        if(!(daySet == nullptr))
        delete []daySet;
    }

/*********************************************************************/

    DayofYearSet :: DayofYearSet(const DayofYearSet& other){
        
        if(other.empty()){
            daySet = nullptr;
            size = 0;
        }

        else{
            
            daySet = new DayofYear[other.Size()];
                
            for(int i=0;i<other.Size();i++){
                daySet[i] = other[i];
            }
            size = other.Size();
        }

    }

/*********************************************************************/
    
    const DayofYearSet DayofYearSet :: operator=(const DayofYearSet& other){
        
        if(other.empty()){
            daySet = nullptr;
            size = 0;
        }

        else{
            
            daySet = new DayofYear[other.Size()];
                
            for(int i=0;i<other.Size();i++){
                daySet[i] = other[i];
            }
            size = other.Size();
            
        }

        return *this;
    }

/*********************************************************************/
    
    const DayofYearSet DayofYearSet :: operator^(const DayofYearSet& other)const{
        
        DayofYearSet temp;

        if(empty() || other.empty()){
            return temp;
        }

        else{
            
            for(int i = 0; i<size ; i++){
                if(other.isThere(daySet[i]))
                    temp.add(daySet[i]);
            }
            return temp;
        }
    }

/*********************************************************************/
    
    const DayofYearSet DayofYearSet :: operator!()const{
        int const arrMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

        DayofYearSet tempSet;
        DayofYear tempDay;
        
        
        for(int i=0 ; i<12;i++){
            for(auto j = 0; j<arrMonth[i];j++){
                tempDay.setAll(j+1,i+1);
                if(!isThere(tempDay))
                    tempSet.add(tempDay);
            }
        }

        return tempSet;
    }              

}

/*********************************************************************/
