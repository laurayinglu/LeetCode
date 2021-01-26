// create max-heap with N keys (bottom-up order)
// repeatedly remove the maximum key

#include <iostream>

using namespace std;

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heap_sort(int arr[], int size) {


}

int main() {
    int arr[] = {1, 3, -4, 0, 9, 8, 4, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    heap_sort(arr, size);

    print(arr, size);
    
}