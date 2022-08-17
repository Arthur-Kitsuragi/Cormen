#include <iostream>

using namespace std;

void merge_func (int* A, int p, int q, int r) {
    int* B = new int [q - p + 1];
    int* C = new int [r - q];
    for (int i = 0; i < q - p + 1; ++i) {
        B[i] = A[p + i];
        C[i] = A[q + 1 + i];
    }
    int i = 0;
    int j = 0;
    for (int k = p; k <= r; ++ k) {
        if (B[i] < C[j]) {
            A[k] = B[i];
            i+=1;
            if (i >= q - p + 1) {
                int e = 1;
                while (j < r - q) {
                    A[k + e] = C[j];
                    j+=1;
                    e+=1;
                }
                return;
            }
        } else {
            A[k] = C[j];
            j+=1;
            if (j >= r - q) {
                int e = 1;
                while (i < q - p + 1) {
                    A[k + e] = B[i];
                    e += 1;
                    i+=1;
                }
                return;
            }
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

