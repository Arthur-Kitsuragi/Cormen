#include <iostream>

using namespace std;

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
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge_func(A, p, q, r);
    }
}
int main()
{
    int A[9] = {9, 8, 7, 6, 5, 4, 3, 2, -1};
    merge_sort(A, 0, 8);
    for (int i = 0; i < 9; ++ i) {
        cout << A[i] << " ";
    }
}
