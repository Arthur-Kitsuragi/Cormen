#include <iostream>

using namespace std;

void bubble_sort(int* A, int p, int r) {
    for (int i = 0; i < r - p; ++i) {
        for (int j = r; j > p + i; --j) {
            if (A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
            }
        }
    }
}
int main()
{
    int A[5] = {3, 13, -1 ,3 , 1};
    bubble_sort(A, 0, 4);
    for (int j = 0; j < 5; ++j) {
        cout << A[j] << " ";
    }
}
