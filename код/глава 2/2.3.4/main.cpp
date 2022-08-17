#include <iostream>

using namespace std;
void rec_ins_sort (int* A, int a, int b) {
    if (a < b) {
        rec_ins_sort(A, a, b-1);
        int i = b - 1;
        int key = A[b];
        while (i > -1 && A[i] > key) {
            A[i+1] = A[i];
            i -= 1;

        }
        A[i+1] = key;
    }
}

int main()
{
    int A[6] = {6,5,4,3,2,1};
    rec_ins_sort(A, 0, 5);
    for (int j = 0; j < 6; j++) {
        cout << A[j] << " ";
    }
}
