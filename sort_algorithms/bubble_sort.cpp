#include <iostream>

using namespace std;

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
    }
    cout << endl;
}

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size-1; i++) { // loop size-1 times since last size-1 elements will be in the right place

        // last (i) elements will be in the right place
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // swap two elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

}

int main() {
    int arr[] = {1, 3, -4, 0, 9, 8, 4, -2};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr, size);

    print(arr, size);
    
}