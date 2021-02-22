/*
in-place 
avg: O(nlogn)
worst case: O(n^2)
improvements: insertion sort small subarrays
best choice of pivot: median
this takes last element as pivot
*/


#include <iostream>

using namespace std;

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
    }
    cout << endl;
}

// last element is in the correct place after partitioning
int partition(int arr[], int low, int high) {
    //int size = high-low+1;
    int pivot = arr[high];
    int i = low - 1; // i is the index of the last element that is <= pivot
    // loop through all elements except pivot
    for (int j = low; j <= high-1; j++) {
        if (arr[j] <= pivot) {
            i++;
            // swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // swap pivot so that it's in the right place arr[i+1]
    int temp = arr[i+1];
    arr[i+1] = pivot;
    arr[high] = temp;

    return i+1; // the pivot index
}

void quick_sort(int arr[], int low, int high) {
    if (low >= high)
        return;
    
    int pivot_idx = partition(arr, low, high);
    // sort two parts divided by pivot index, pivot is already in the right place
    quick_sort(arr, low, pivot_idx-1);
    quick_sort(arr, pivot_idx+1, high);
}

int main() {
    int arr[] = {12, 3, -4, 10, 9, 8, 4, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr, 0, size - 1);

    print(arr, size);
    
}
