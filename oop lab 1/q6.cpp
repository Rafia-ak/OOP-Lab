#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[]) {
    string name = argv[1] + string(" ") + argv[2];
    double scores[5];
    for (int i = 0; i < 5; ++i) {
        scores[i] = stod(argv[i + 3]);
    }
    double sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += scores[i];
    }
    double average = sum / 5;
    
    cout << "Student name: " << name << endl;
    cout << "Test scores: ";
    for (int i = 0; i < 5; ++i) {
        printf("%.2f ", scores[i]);
    }
    cout << endl;
    printf("Average test score: %.2f\n", average);
    return 0;
}

