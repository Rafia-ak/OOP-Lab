#include <iostream>
#include <string>
using namespace std;

class Date{
	int month;
	int day;
	int year;
	
	public:
		void setmonth(int m){
			month = m;
		}
		void setday(int d){
			day = d;
		}
		void setyear(int y){
			year = y;
		}
		
		int getmonth(){
			return month;
		}
		int getday(){
			return day;	
		}
		int getyear(){
			return year;
		}
		
		void displayDate(){
			cout<<getmonth()<<"/"<<getday()<<"/"<<getyear()<<endl;
		}
};

int main(int argc, char* argv[]){
	Date DateTest;
	
	DateTest.setmonth(atoi(argv[1]));
	DateTest.setday(atoi(argv[2]));
	DateTest.setyear(atoi(argv[3]));
	
	DateTest.displayDate();
	return 0;
}




