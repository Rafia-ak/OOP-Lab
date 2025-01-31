#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Error: Please provide at least one number as an argument.\n";
        return 1;
    }

    float sum = 0;
    float array[argc - 1];

    for (int i = 1; i < argc; i++) {
        array[i - 1] = atof(argv[i]);
    }

    float *ptr = array;
    for (int i = 0; i < argc - 1; i++) {
        sum = sum + *ptr;
        ptr++;
    }

    cout << "Sum of all elements: " << sum << endl;
    return 0;
}
