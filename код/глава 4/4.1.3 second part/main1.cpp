//
// Created by Пользователь on 23.08.2022.
//

#include <iostream>
#include <chrono>

using namespace std;
struct answer {
    int left;
    int right;
    int sum = -9999999;
};

answer force_method (int* A, int r, int l) {

    answer ans;
    for (int i = r; i <= l; ++i) {
        int sum = 0;
        for (int j = i; j <= l; ++j) {    //works
            sum+=A[j];
            if (sum >= ans.sum) {
                ans.sum = sum;
                ans.left = i;
                ans.right = j;
            }
        }
    }

    return ans;
}
//second variant
answer cross_subarray (int* A, int low, int mid, int high) {
    int maxsum_l = -99999999;
    int sum = 0;
    int left;
    for (int i = mid; i >= low; --i) {
        sum+=A[i];
        if (sum >= maxsum_l) {
            maxsum_l = sum;
            left = i;
        }
    }
    int maxsum_r = -99999999;
    sum = 0;
    int right;
    for (int i = mid + 1; i <= high; ++i) {
        sum += A[i];
        if (sum >= maxsum_r) {
            maxsum_r = sum;
            right = i;
        }
    }
    answer ans;
    ans.left = left;
    ans.right = right;
    ans.sum = maxsum_l + maxsum_r;
    return ans;
}
answer recursive_method (int* A, int r, int l) {
    if (r == l) {
        answer ans;
        ans.right = ans.left = r;
        ans.sum = A[r];
        return ans;
    } else {
        int mid = (l + r - 1) / 2;
        answer left = recursive_method(A, r, mid);
        answer right = recursive_method(A, mid + 1, l);
        answer cross = cross_subarray(A, r, mid, l);
        if (left.sum >= right.sum && left.sum >= cross.sum) {

            return left;
        } else if (right.sum >= left.sum && right.sum >= cross.sum) {
            return right;
        } else {
            return cross;
        }
    }
}
int main()
{   int A[56] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7, 44, 14, 11, -44, 2, 4, -11, 4, -31, 10, 11, 43,
                 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7, 44, 14, 11, -44, 2, 4, -11, 4, -31, 10, 11, 43};
    //answer t;
    //t = force_method(A, 0, 27);
    //cout<<t.left<< " " << t.right << " " << t.sum << endl;
    auto begin = chrono::high_resolution_clock::now();
    answer p = recursive_method(A, 0, 38);
    auto end = chrono::high_resolution_clock::now();
    cout<<chrono::duration_cast<chrono::nanoseconds>(end-begin).count()<<"ns"<< endl;
    cout<<p.left << " " << p.right << " " << p.sum;
    return 0;
}