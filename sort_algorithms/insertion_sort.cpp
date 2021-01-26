//O(n^2)
#include <iostream>

using namespace std;

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertion_sort(int arr[], int size) { 

    for (int i = 1; i < size; i++) {
        
        // for loop version: compare with previous i elements
        // for (int j = i; j >= 1; j--) {
        //     if (arr[j] < arr[j-1]) {
        //         // swap 
        //         int temp = arr[j-1];
        //         arr[j-1] = arr[j];
        //         arr[j] = temp;
        //     }
        // }

        // while loop version 
        int j = i-1;
        int curr = arr[i];
        while(j >= 0 && curr < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = curr;

        // end while loop

        print(arr, size);

    }
}


int main() {
    int arr[] = {1, 3, -4, 0, 9, 8, 4, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr, size);

    print(arr, size);
    
}