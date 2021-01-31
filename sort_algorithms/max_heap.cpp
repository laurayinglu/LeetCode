// given an array, create max-heap
// heaps are an implementation of priority queue
#include <iostream>

using namespace std;

void swap (int* x, int* y) {
    int temp =  *x;
    *x = *y;
    *y = temp;
}

/* heap starts with index 0 */
class MaxHeap {
    private:
        int *arr;
        int size; // size of the arr
        int heap_size; // size of the heap
        
    public: 

        MaxHeap (int s) {
            size = s;
            heap_size = 0;
            arr = new int[s];
        }

        ~MaxHeap() {
            delete [] arr;
        }

        int getHeapSize() {
            return heap_size;
        }

        // using siftup - move large element upward
        void maxHeapify(int root) {
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
                maxHeapify(largest); 
            }

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

        // remove the max value from the heap
        int extractMax() {
            if (heap_size <= 0)
                return INT_MIN;

            if (heap_size == 1) {
                heap_size--;
                return arr[0];
            }

            // swap arr[0] with the last element
            int max = arr[0];
            arr[0] = arr[heap_size-1];
            heap_size--;
            maxHeapify(0);

            return max;            
        }

        // return the max key of the max heap
        int getMax() {
            return arr[0];
        }

        // delete key sorted at index 
        void deleteKey(int index) {
            // first increase the value to INT_MAX
            // then call extractMax()
            arr[index] = INT_MAX;
            extractMax();
        }
        
        // insert key that has value 
        void insertKey(int value) {
            // insert key at the end first
            if (heap_size >= size) {
                cout << "heap is full" << endl;
                return;
            }

            heap_size++;
            arr[heap_size-1] = value;
            int p = heap_size-1;
            // adjust heap, bottom-up
            while (p >= 1 && arr[p] > arr[parent(p)]) {
                swap(&arr[p], &arr[parent(p)]);
                p = parent(p);
            }

        }

        void print() {
            for (int i = 0; i < size; i++)
                cout << arr[i] << " ";
            
            cout << endl;
        }
}
