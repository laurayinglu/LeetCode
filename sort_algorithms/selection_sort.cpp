//O(n^2)
#include <iostream>

using namespace std;

void selection_sort(int arr[], int size) {
    
    for (int i = 0 ; i < size-1; i++){ // i is curr index 
        int min_index = i;
        // find minimum element
        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        // swap curr index and min index
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[] = {1,3, -4, 0, 9, 8, 4, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}