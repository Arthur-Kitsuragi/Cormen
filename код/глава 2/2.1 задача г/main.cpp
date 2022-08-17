#include <iostream>
#include <ctime>
using namespace std;
void insertion_sort (int* A, int p, int r) {
    for (int j = 1; j < r - p + 1; ++j) {
        int key = A[j];
        int i = j - 1;
        while (i > -1 && A[i] > key) {
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
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge_func(A, p, q, r);
    }
}
int main()
{
    int A[500000];
    for (int i = 0; i < 500000; i ++) {
        A[i] = 500000 - i;
    }
    clock_t t1, t2, t3, t4;
    int t = 1;
    do {

        t1 = clock();
        insertion_sort(A, 0, t);
        t2 = clock();
        t3 = t2 - t1;

        for (int i = 0; i < t+1; i ++) {
            A[i] = 500000 - i;
        }
        t1 = clock();
        merge_sort(A, 0, t);
        t2 = clock();
        t4 = t2 - t1;
        for (int i = 0; i < t+1; i ++) {
            A[i] = 500000 - i;
        }
        cout<<t3<<" "<<t4<<endl;
        t = t + 1;
    } while (t3 <= t4 && t<=500001);
    cout << t;
}
