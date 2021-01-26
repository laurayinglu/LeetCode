#include <iostream>

using namespace std;

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void shell_sort(int arr[], int size) {
    for (int gap = size/2; gap > 0; gap /=2 ) {
        // insertion sort with gap 
        for (int i = gap; i < size; i++) {
            // // for loop version: compare with previous i elements
            // for (int j = i; j >= gap; j-=gap) {
            //     if (arr[j] < arr[j-gap]) {
            //         // swap 
            //         int temp = arr[j-gap];
            //         arr[j-gap] = arr[j];
            //         arr[j] = temp;
            //     }
            // }

            int j = i-gap;
            int curr = arr[i];
            while(j >= 0 && curr < arr[j]) {
                arr[j+gap] = arr[j];
                j-=gap;
            }

            arr[j+gap] = curr;
        }
    }

}


int main() {
    int arr[] = {1, 3, -4, 0, 9, 8, 4, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    shell_sort(arr, size);

    print(arr, size);
    
}


