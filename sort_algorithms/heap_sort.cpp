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

void swap (int* x, int* y) {
    int temp =  *x;
    *x = *y;
    *y = temp;
}

// return the index of the parent of node at index
int parent(int index) {
    return (index-1)/2;
}

// return the index of left child of node at index
int leftChild(int index) {
    return 2*index + 1;
}

// return the index of right child of node at index
int rightChild(int index) {
    return 2*index + 2;
}

// heap the subtree from top to bottom
void maxHeapify(int arr[], int size, int root) {
    int largest = root;
    int l = leftChild(root);
    int r = rightChild(root);

    // if left child is larger than the roor
    if (l < size && arr[l] > arr[largest])
        largest = l;

    if (r < size && arr[r] > arr[largest])
        largest = r;

    // swap arr at root and largest if they are not equal
    // then heapify
    if (largest != root) {
        swap(&arr[root], &arr[largest]);
        maxHeapify(arr, size, largest); 
    }

}

void heap_sort(int arr[], int size) {
    // create heap
    int start = (size-2)/2;
    for (int i = start; i >= 0; i--) {
        maxHeapify(arr, size, i);
    }

    //print(arr, size);

    // extractMax each time
    // move max to the end each time
    for (int i = size-1; i > 0; i--) {
        // swap with last element
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0); // each time length-1
        //print(arr, size);
    }
    
}

int main() {
    int arr[] = {1, 3, -4, 0, 9, 8, 4, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    heap_sort(arr, size);

    print(arr, size);
    
}