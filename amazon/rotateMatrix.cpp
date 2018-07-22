#include<vector>
#include<iostream>
using namespace std;

vector<vector<int>> transpose(vector<vector<int> >& matrix, const int& M, const int& N) {
    vector<vector<int> > res(N, vector<int>(M, 0));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
        res[j][i] = matrix[i][j];
    }

    return res;
}

vector<vector<int>> rotateMatrixLeft90Degree(vector<vector<int> >& matrix) {
    if (matrix.empty())
        return {};

    int M = matrix.size();
    int N = matrix[0].size();
    vector<vector<int> > res(N, vector<int>(M, 0));
    
    res = transpose(matrix, M, N);

    // reverse rows
    return vector<vector<int> > (res.rbegin(), res.rend());
}

vector<vector<int>> rotateMatrixRight90Degree(vector<vector<int> >& matrix) {
    if (matrix.empty())
        return {};

    int M = matrix.size();
    int N = matrix[0].size();
    vector<vector<int> > res(N, vector<int>(M, 0));
    
    res = transpose(matrix, M, N);

    // reverse cols
    for (auto& row : res) {
        reverse(row.begin(), row.end());
    }

    return res;
}


void printMatrix(vector<vector<int> >& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++)
            cout << matrix[i][j] << (j == matrix[0].size() - 1 ? "" : ",");
        cout << endl;
    }
}

int main(void) {
    vector<vector<int> > matrix = { {1, 2, 3}, {5, 6, 7} };
    cout << "Original Matrix:" << endl;
    printMatrix(matrix);
    vector<vector<int> > res = move(rotateMatrixLeft90Degree(matrix));
    cout << "Rotate left 90 degree:" << endl;
    printMatrix(res);

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);
    res = move(rotateMatrixRight90Degree(matrix));
    cout << "Rotate right 90 degree:" << endl;
    printMatrix(res);
    
    return 0;
}
