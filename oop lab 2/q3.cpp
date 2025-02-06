#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

void resizeArray(int*& arr, int& capacity, int newSize) {
    int* temp = new int[newSize];  
    memcpy(temp, arr, capacity * sizeof(int));  
    delete[] arr;
    arr = temp;
    capacity = newSize;
}

int main(int argc, char* argv[]) {
    int capacity = 5;
    int count = 0;
    int* arr = new int[capacity];

    for (int i = 1; i < argc; i++) {
        if (count >= capacity) {  
            resizeArray(arr, capacity, capacity * 2);
        }
        arr[count] = atoi(argv[i]);  
        count++;
    }

    resizeArray(arr, capacity, count);  

    cout << "Final array: ";
    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nFinal array size: " << count << endl;

    delete[] arr; 
    return 0;
}






