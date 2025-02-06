#include <iostream>
#include <cstdlib>
using namespace std;

void* addToArray(void* arr, int size, int addValue) {
    int* intArr = (int*)arr;
    for (int i = 0; i < size; i++) {
        intArr[i] += addValue;
    }
    return arr;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return 1;
    }

    int size = argc - 1;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = atoi(argv[i + 1]);
    }

    arr = (int*)addToArray(arr, size, 5);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
