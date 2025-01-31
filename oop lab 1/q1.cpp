#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 21) {
        cout << "Error: Please provide exactly 20 float numbers as arguments.\n";
        return 1;
    }

    float array[20];

    for (int i = 1; i < argc; i++) {
        array[i - 1] = atof(argv[i]);
    }

    float *highest = array;
    float *shighest = nullptr;

    for (float *ptr = array; ptr < array + 20; ptr++) {
        if (*ptr > *highest) {
            highest = ptr;
        }
    }

    for (float *ptr = array; ptr < array + 20; ptr++) {
        if (ptr != highest) {
            if (shighest == nullptr || *ptr > *shighest) {
                shighest = ptr;
            }
        }
    }

    if (shighest == nullptr) {
        cout << "No second highest value exists.\n";
    } else {
        cout << "Second highest: " << *shighest << endl;
    }

    return 0;
}
