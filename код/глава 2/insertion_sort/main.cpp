#include <iostream>

using namespace std;

int main()
{
    int A[10] = {31, 41, 59, 26, 41, 58};
    for (int j = 1; j < 6; ++j) {
        int key = A[j];
        int i = j - 1;
        while (i > -1 && A[i] > key) {
            A[i + 1] = A[i];
            i-=1;
        }
        A[i+1]=key;
    }

    for (int j = 0; j < 6; ++j) {
        cout<<A[j]<<" ";
    }
}
