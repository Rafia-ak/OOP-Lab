#include<iostream>
#include<cstdlib>
using namespace std;

int main(int argc, char* argv[]){
	int sum = 0;
	char **ptr = argv + 1;

    for (int i = 1; i < argc; i++, ptr++) {  
        sum += atoi(*ptr);
    }
    
	cout<<"Sum of all the elements: "<<sum;
	return 0;
}