#include <iostream>
using namespace std;
struct answer {
    int left;
    int right;
    int sum = -9999999;
};

answer linear_subarr (int* A, int p, int r) {
    int best = -9999999;
    int temp = 0;
    int low, high;
    int low_temp = p;
    for (int i = p; i != r; ++i) {
        temp += A[i];
        if (temp > best) {
            low = low_temp;
            high = i;
            best = temp;
        }
        if (temp < 0) {
            low_temp = i + 1;
            temp = 0;
        }
    }
    answer ans;
    ans.sum = best;
    ans.left = low;
    ans.right = high;
    return ans;
}
int main() {
    int A[56] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7, 44, 14, 11, -44, 2, 4, -11, 4, -31, 10, 11, 43,
                 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7, 44, 14, 11, -44, 2, 4, -11, 4, -31, 10, 11, 43};
    answer p = linear_subarr(A, 0, 38);
    cout<<p.left << " " << p.right << " " << p.sum;
    return 0;
}
