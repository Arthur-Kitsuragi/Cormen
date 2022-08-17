#include <iostream>

using namespace std;

int merge_inversions(int* A, int p, int q, int r) {
    int nL = q - p + 1;
    int nR = r - q;
    int L[nL];
    int R[nR];
    for (int i = 0; i < nL; i++) {
        L[i] = A[p + i];
    }
    for (int i = 0; i < nR; i++) {
        R[i] = A[q + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = p;
    int inversions = 0;
    while (nL > 0 && nR > 0) {
        if (R[j] < L[i]) {
            inversions += nL;
            nR -= 1;
            A[k] = R[j];
            j+=1;
        } else {
            nL -= 1;
            A[k] = L[i];
            i+=1;
        }
        k+=1;
    }
    while (nL > 0) {
        A[k] = L[i];
        k+=1;
        i+=1;
        nL -=1;
    }
    while (nR > 0) {
        A[k] = R[j];
        k+=1;
        j+=1;
        nR -=1;
    }
    return inversions;
}
int count_inversions(int* A, int p, int r) {
    int inversions = 0;
    if (p < r) {
        int q = (p + r) / 2;
        inversions += count_inversions(A, p, q);
        inversions += count_inversions(A, q + 1, r);
        inversions += merge_inversions(A, p, q, r);
    }
    return inversions;
}
int main()
{
    int A[10] = {5,4,3,2,1};
    cout<<count_inversions(A, 0, 3);
    return 0;
}
