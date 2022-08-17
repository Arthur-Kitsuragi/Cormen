#include <iostream>

using namespace std;

int main()
{
    int A[5] = {1, 1, 1, 1, 1};
    int B[5] = {1, 0, 1, 0, 1};
    int C[6];
    int storage = 0;
    for (int j = 4; j >0 ; --j) {
        int sum = storage + A[j] + B [j];
        C[j + 1] = sum % 2 ;
        storage = sum/2;
    }
    C[0] = 1;
    for (int j = 0; j < 6 ; ++j) {
        cout<< C[j] << " ";
    }
}
