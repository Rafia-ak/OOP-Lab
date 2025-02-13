#include <iostream>
#include <string>
using namespace std;

class User{
	string name;
	int age;
	
	public:
		void setname(string n){
			name = n;
		}
		void setage(int a){
			age = a;
		}
		string getname(){
			return name;
		}
		int getage(){
			return age;	
		}
		
};

int main(int argc, char* argv[]){
	User one;
	one.setname(argv[1]);
	one.setage(atoi(argv[2]));
	
	cout<<"My name is "<<one.getname()<<" and I'm "<<one.getage()<<" years old."<<endl;
	return 0;
}