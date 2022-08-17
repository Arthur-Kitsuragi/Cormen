#include <iostream>

using namespace std;
void insertion_sort (int* A, int p, int r) {
    for (int j = p + 1; j < r + 1; ++j) {
        int key = A[j];
        int i = j - 1;

        while (i > p - 1 && A[i] > key) {
            A[i + 1] = A[i];
            i-=1;
        }
        A[i+1]=key;
    }
}
void merge_func (int* A, int p, int q, int r) {
    int* B = new int [q - p + 1 + 1];
    int* C = new int [r - q + 1];
    for (int i = 0; i < q - p + 1; ++i) {
        B[i] = A[p + i];
        C[i] = A[q + 1 + i];
    }
    B[q - p + 1] = 6186186; // signal card
    C[r - q] = 6186186; // signal card
    int i = 0;
    int j = 0;
    for (int k = p; k <= r; ++ k) {
        if (B[i] < C[j]) {
            A[k] = B[i];
            i+=1;
        } else {
            A[k] = C[j];
            j+=1;
        }
    }
}
void merge_sort (int* A, int p, int r) {
    if (p < r) {
        if (r - p + 1 < 3) {
            insertion_sort (A, p, r);

        } else {
            int q = (p + r) / 2;
            merge_sort(A, p, q);
            merge_sort(A, q+1, r);
            merge_func(A, p, q, r);
        }
    }
}
int main()
{
    int A[10] = {55, 33, 22 , 11, 0, -11, -22, -33, -44, -55};
    merge_sort(A, 0 , 9);
   for (int j = 0; j < 10; ++j) {
        cout<<A[j]<<" ";
    }
    return 0;
}
