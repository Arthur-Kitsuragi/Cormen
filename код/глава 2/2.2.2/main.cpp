#include <iostream>

using namespace std;

int main()
{
    int A[7] = {5, 3, 2, 1, -3, -11, -133};
    for (int j = 0; j < 7-1 ; ++j) {
        int min_index = j;
        for (int i = j + 1; i < 7; ++i) {
            if (A[i] < A[min_index]) {
                min_index = i;
            }
        }
        std::swap(A[min_index], A[j]);
    }
    for (int i = 0; i < 7; ++i) {
        cout<<A[i]<<" ";
    }
}
