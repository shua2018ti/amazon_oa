#include<climits>
#include<vector>
using namespace std;

class MaximumMinimumPath {
    private:
    int minVal, maxVal, row, col;
    public:
    int maxMinPath(vector<vector<int> >& matrix) {
        row = matrix.size();
        col = matrix[0].size();
        minVal = INT_MAX;
        maxVal = INT_MIN;
        dfsHelper(matrix, minVal, 0, 0);
     return maxVal;
    }

    void dfsHelper(vector<vector<int> >& matrix, int minVal, int i, int j ){                
        if (i >= row || j >= col) return;
        if (i == row - 1 && j == col - 1) {
            minVal = min(minVal, matrix[i][j]);
            maxVal = max(maxVal, minVal);
            return;
        }
        minVal = min(minVal, matrix[i][j]);
        dfsHelper(matrix, minVal, i, j + 1);
        dfsHelper(matrix, minVal, i + 1, j);
    }
};

