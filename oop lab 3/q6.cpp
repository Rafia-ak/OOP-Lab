#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    int rows, cols;
    vector<vector<int>> mat;

public:
    Matrix(int r, int c) : rows(r), cols(c), mat(r, vector<int>(c, 0)) {}

    int getRows() { return rows; }
    int getCols() { return cols; }

    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols)
            mat[i][j] = value;
    }

    Matrix operator+(const Matrix &other) {
        if (rows != other.rows || cols != other.cols) {
            cout << "Matrices cannot be added" << endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix &other) {
        if (cols != other.rows) {
            cout << "Matrices cannot be multiplied" << endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc < 5) {
        cout << "Insufficient arguments" << endl;
        return 1;
    }
    int r1 = atoi(argv[1]);
    int c1 = atoi(argv[2]);
    int r2 = atoi(argv[3]);
    int c2 = atoi(argv[4]);
    Matrix mat1(r1, c1);
    Matrix mat2(r2, c2);
    
    int value = 1;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            mat1.setElement(i, j, value++);
        }
    }
    value = 1;
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            mat2.setElement(i, j, value++);
        }
    }
    
    cout << "Matrix 1:" << endl;
    mat1.display();
    cout << "Matrix 2:" << endl;
    mat2.display();
    
    cout << "Addition result:" << endl;
    Matrix sum = mat1 + mat2;
    sum.display();
    
    cout << "Multiplication result:" << endl;
    Matrix product = mat1 * mat2;
    product.display();
    
    return 0;
}
