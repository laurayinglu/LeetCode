// divide array into half -> recursively sort each half -> merge two halves
// divide and conquer
// O(nlogn): C(N) <= 2*C(N/2) + N
// not in-place sort: In-place means that the algorithm does not use extra space 
// for manipulating the input but may require a small though nonconstant extra space for its operation. 
// in-place sort: use <= clogN extra memory

// improvements: use insertion sort for small subarrays
// best case comparison: (1/2)nlgn
// best case using checking arr[m] <= arr[m+1]: n-1

#include <iostream>

using namespace std;

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// merge two subarrays of arr[], arr[l]-arr[m], arr[m+1]-arr[r]
void merge(int arr[], int l, int m, int r) {
    int n1 = m-l+1;
    int n2 = r-m;
    int subarr1[n1];
    int subarr2[n2];

    // copy data
    for (int i = 0 ; i < n1; i++)
        subarr1[i] = arr[l+i];
    
    for (int i = 0 ; i < n2; i++)
        subarr2[i] = arr[m+1+i];

    int i = 0;
    int j = 0;
    int k = l;

    while(i < n1 && j < n2) {
        if (subarr1[i] <= subarr2[j]) {
            arr[k++] = subarr1[i++];
            //i++;
        } else {
            arr[k++] = subarr2[j++]; 
        }
    }

    // copy rest data into arr
    for (int p = i; p < n1; p++)
        arr[k++] = subarr1[p];
    
    for (int q = j; q < n2; q++)
        arr[k++] = subarr2[q];

}

void merge_sort(int arr[], int l, int r) {
    if (l >= r) 
        return;
    
    // use insertion sort for size <= 7, CUTOFF = 7
    // if (l+CUTOFF-1 >= r) {
    //     insertion_sort(arr, l, r);
    //     return;
    // }
    
    int m = (l+r)/2;
    merge_sort(arr, l, m);
    merge_sort(arr, m+1, r);
    // stops if already sorted
    if (arr[m] <= arr[m+1])
        return;

    merge(arr, l, m, r);
}

int main() {
    int arr[] = {1, 3, -4, 0, 9, 8, 4, 2, -10};
    int size = sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr, 0, size-1);

    print(arr, size);
}


// bottom-up merge-sort, no recursion needed
/*
void merge_sort(int arr[], int size) {
    int aux[size];
    for (int sz = 1; sz < size; sz*=2) {
        for (int lo = 0; lo < size-sz; lo += sz+sz) {
            merge(arr, lo, lo+sz-1, min(lo+sz+sz-1, size-1));
        }
    }
}



*/