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
int bin_search (int* A, int a, int b, int v) {
    while (a < b) {
        int q = (a + b) / 2;
        if (A[q] == v) {
            return q;
        } else if (A[q] > v) {
            b = q - 1;
        } else {
            a = q + 1;
        }
    }
    if (A[a] == v) {
        return a;
    }
    return -1;
}
void sum_search(int* A, int a, int b, int x) {
    merge_sort(A, a, b);
    for (int i = a; i <= b; ++i) {
        if (bin_search(A, a, i - 1, x - A[i]) != -1 || bin_search(A, i + 1, b, x - A[i]) != -1) {
            cout << " exists ";
            return;
        }
    }
    cout<<" does not exist";
}
int main()
{
    int A[7] = {1, 3, -4, 5, 6, 1, 0};
    sum_search(A, 0, 6, -7);
}
