#include <iostream>
#include <string>
using namespace std;

class Glass{
	int LiquidLevel;
	
	public:
		Glass(){
			LiquidLevel = 200;
		}
		
		void displaylevel(){
			cout<<"Current liquid level is: "<<LiquidLevel<<"ml"<<endl;
		}
		
		void drink(int ml){
			LiquidLevel = LiquidLevel - ml;
			displaylevel();
			if(LiquidLevel<0){
				LiquidLevel = 0;
			}
			if (LiquidLevel<100){
				refill();
			}
		}
		
		void refill(){
			LiquidLevel = 200;
			cout<<"Glass refilled!"<<endl;
			displaylevel();
		}
		
		
};

int main(int argc, char* argv[]){
	Glass one;
    int amount;
	
	for (int i = 1; i < argc; i++){  
        int amount = atoi(argv[i]);
        one.drink(amount);
    }
    
    return 0;
}