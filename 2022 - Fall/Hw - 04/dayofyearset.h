#include <iostream>
#include <list>

using namespace std;

namespace cagriYildiz{

	class DayofYearSet{
	
		public:
		
		class DayofYear{
		
			public:
			
			DayofYear();  /*Default constructor*/
			DayofYear(int d,int m);  /*Initializer constructor*/
	
			void setDay(int d);	/*Setters for class*/
            void setMonth(int m);
            void setAll(int d,int m);
	          
            int getDay()const;   /*Getters for class*/
            int getMonth()const;		
					             
            bool operator ==(const DayofYear& other);   /*operator overloading for class*/
            friend ostream& operator<<(ostream &out,const DayofYear& input);

            private:
            
            int day;
            int month;
			
		};
	
		/*Constructor*/
        DayofYearSet();	// Default dayofyearset constructor
		DayofYearSet(list <DayofYear> &l);	// constructor that takes list 
		
		int Size()const;	// function that returns the size of set
		bool empty()const;	// function that checks the given set is empty or not
        void add(const DayofYear& input);	// function that adds new element to set with + operator
        void remove();	// function that removes element with - operator
        void remove(int index);
        void remove(const DayofYear& input);
        		
		bool isThere(const DayofYear& input)const; // checks if the input is in the set already
		
		friend ostream& operator<<(ostream &out,const DayofYearSet& input);	// operator overloading part
		bool operator==(const DayofYearSet& other)const;	
        bool operator!=(const DayofYearSet& other)const;
        
        DayofYear& operator[](int index)const;
		
		const DayofYearSet operator+(const DayofYearSet& other)const;
		const DayofYearSet operator-(const DayofYearSet& other)const;
		const DayofYearSet operator^(const DayofYearSet& other)const;
		const DayofYearSet operator!()const;
		
		const DayofYearSet operator=(const DayofYearSet& other);	// Big 3 ( operator= , destructor , copy constructor)
        ~DayofYearSet();
        DayofYearSet(const DayofYearSet& other);
		
		private:
				
		int size;
        DayofYear * daySet;
	
	};

}
