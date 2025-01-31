#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  
    if (argc != 2) {
        cout << "Please provide weight in kilograms as a command-line argument." << endl;
        return 1;
    }

    float weight = atof(argv[1]);

    float weight_in_pounds = 2.2 * weight;

    printf("Weight in kg: %.2f \nWeight in pounds: %.2f\n", weight, weight_in_pounds);

    return 0;
}
