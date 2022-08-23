#include <iostream>
#include <vector>
using namespace std;
struct matrix {
    vector<vector<int>> Matrix;
    size_t original_size;
};
bool degree_of_2(matrix &Matrix) {
    size_t Size = Matrix.Matrix.size();
    while (Size > 1) {
        if (Size % 2 != 0) {
            return false;
        } else {
            Size /= 2;
        }
    }
    return true;
}
size_t next_degree(size_t num) {
    size_t j = 1;
    while (num > j) {
        j *= 2;
    }
    return j;
}
matrix minuss(matrix &A, matrix &B) {
    matrix C;
    vector<vector<int>> q;
    q.resize(A.Matrix.size());
    for (int j = 0; j < A.Matrix.size(); ++j) {
        q[j].resize(A.Matrix.size());
    }
    for (int j = 0; j < q.size(); ++j) {
        for (int i = 0; i < q.size(); ++i) {
            q[j][i] = A.Matrix[j][i] - B.Matrix[j][i];
        }
    }
    C.Matrix = q;
    return C;
}
matrix pluss(matrix &A, matrix &B) {
    matrix C;
    vector<vector<int>> q;
    q.resize(A.Matrix.size());
    for (int j = 0; j < A.Matrix.size(); ++j) {
        q[j].resize(A.Matrix.size());
    }
    for (int j = 0; j < q.size(); ++j) {
        for (int i = 0; i < q.size(); ++i) {
            q[j][i] = A.Matrix[j][i] + B.Matrix[j][i];
        }
    }
    C.Matrix = q;
    return C;
}
void strassen_transfer(matrix &Matrix) {
    if (!degree_of_2(Matrix)) {
        Matrix.Matrix.resize(next_degree(Matrix.original_size));
        for (int j = 0; j < Matrix.Matrix.size(); j++) {
            Matrix.Matrix[j].resize(next_degree(Matrix.original_size));
        }
    }
}
matrix Strassen_algo(matrix &A, matrix &B) {
    size_t n = A.Matrix.size();
    matrix C;
    C.Matrix.resize(n);
    for (int i = 0; i < n; ++i) {
        C.Matrix[i].resize(n);
    }
    if (n == 1) {
        C.Matrix[0][0] = A.Matrix[0][0] * B.Matrix[0][0];
    } else {
        matrix A11, A12, A21, A22, B11, B12, B21, B22;
        A11.Matrix.resize(n/2);
        A12.Matrix.resize(n/2);
        A21.Matrix.resize(n/2);
        A22.Matrix.resize(n/2);
        B11.Matrix.resize(n/2);
        B12.Matrix.resize(n/2);
        B21.Matrix.resize(n/2);
        B22.Matrix.resize(n/2);
        for (int i = 0; i < n/2; ++i) {
            A11.Matrix[i].resize(n/2);
            A12.Matrix[i].resize(n/2);
            A21.Matrix[i].resize(n/2);
            A22.Matrix[i].resize(n/2);
            B11.Matrix[i].resize(n/2);
            B12.Matrix[i].resize(n/2);
            B21.Matrix[i].resize(n/2);
            B22.Matrix[i].resize(n/2);
        }
        for (int i = 0; i < n/2; ++i) {
            for (int j = 0; j < n/2; ++j) {
                A11.Matrix[i][j] = A.Matrix[i][j];
                B11.Matrix[i][j] = B.Matrix[i][j];
            }
        }
        for (int i = 0; i < n/2; ++i) {
            for (int j = 0; j < n/2; ++j) {
                A12.Matrix[i][j] = A.Matrix[i][n/2+j];
                B12.Matrix[i][j] = B.Matrix[i][n/2+j];
            }
        }
        for (int i = 0; i < n/2; ++i) {
            for (int j = 0; j < n/2; ++j) {
                A21.Matrix[i][j] = A.Matrix[n/2+i][j];
                B21.Matrix[i][j] = B.Matrix[n/2+i][j];
            }
        }
        for (int i = 0; i < n/2; ++i) {
            for (int j = 0; j < n/2; ++j) {
                A22.Matrix[i][j] = A.Matrix[n/2+i][n/2+j];
                B22.Matrix[i][j] = B.Matrix[n/2+i][n/2+j];
            }
        }
        matrix S1 = minuss(B12, B22);
        matrix S2 = pluss(A11, A12);
        matrix S3 = pluss (A21, A22);
        matrix S4 = minuss (B21, B11);
        matrix S5 = pluss(A11, A22);
        matrix S6 = pluss (B11, B22);
        matrix S7 = minuss (A12, A22);
        matrix S8 = pluss (B21, B22);
        matrix S9 = minuss (A11, A21);
        matrix S10 = pluss (B11, B12);
        matrix P1 =  Strassen_algo(A11, S1);
        matrix P2 =  Strassen_algo(S2, B22);
        matrix P3 =  Strassen_algo(S3, B11);
        matrix P4 =  Strassen_algo(A22, S4);
        matrix P5 =  Strassen_algo(S5, S6);
        matrix P6 =  Strassen_algo(S7, S8);
        matrix P7 =  Strassen_algo(S9, S10);
        matrix buff = minuss(P6, P2);
        matrix buff1 = pluss(P4, buff);
        matrix C11 = pluss(P5, buff1);
        matrix C12 = pluss (P1, P2);
        matrix C21 = pluss (P3, P4);
        buff = minuss(P5, P3);
        buff1 = minuss(P1, P7);
        matrix C22 = pluss (buff, buff1);
        for (int i = 0; i < n/2; ++i) {
            for (int j = 0; j < n/2; ++j) {
                C.Matrix[i][j] = C11.Matrix[i][j];
            }
        }
        for (int i = 0; i < n/2; ++i) {
            for (int j = 0; j < n/2; ++j) {
                C.Matrix[i][n/2+j] = C12.Matrix[i][j];
            }
        }
        for (int i = 0; i < n/2; ++i) {
            for (int j = 0; j < n/2; ++j) {
                C.Matrix[n/2+i][j] = C21.Matrix[i][j];
            }
        }
        for (int i = 0; i < n/2; ++i) {
            for (int j = 0; j < n/2; ++j) {
                C.Matrix[n/2+i][n/2+j] = C22.Matrix[i][j];
            }
        }
    }
    return C;
}
int main() {
    matrix A,B;
    A.original_size = 5;
    B.original_size = A.original_size;
    A.Matrix.resize(A.original_size);
    B.Matrix.resize(A.original_size);
    for (int i = 0; i < A.original_size; ++i) {
        A.Matrix[i].resize(A.original_size);
        B.Matrix[i].resize(A.original_size);
    }
    for (int i = 0; i < A.original_size; ++i) {
        for (int j = 0; j < A.original_size; ++j) {
            A.Matrix[i][j] = i * j + 1;
            B.Matrix[i][j] = i * j + 2;
        }
    }
    for (int i = 0; i < A.original_size; ++i) {
        for (int j = 0; j < A.original_size; ++j) {
            cout<< A.Matrix[i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i = 0; i < A.original_size; ++i) {
        for (int j = 0; j < A.original_size; ++j) {
            cout<< B.Matrix[i][j] << " ";
        }
        cout<<endl;
    }
    strassen_transfer(A);
    strassen_transfer(B);
    cout<<endl;
    matrix C = Strassen_algo(A,B);
    for (int i = 0; i < A.original_size; ++i) {
        for (int j = 0; j < A.original_size; ++j) {
            cout<< C.Matrix[i][j] << " ";
        }
        cout<<endl;
    }
}
