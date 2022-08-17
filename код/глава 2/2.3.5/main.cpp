#include <iostream>

using namespace std;
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

int main()
{
    int A[6] = {-44, -30, -15, 1 , 11, 12};
    cout << bin_search(A, 0, 5, 133);
}
