#include<vector>
#include<iostream>
using namespace std;

class DaysChange {
    public:
    vector<int> Solution(vector<int>& days, int n) {
        if (days.empty() || n <= 0)
            return days;
        int size = days.size();
        vector<int> rvalue(size + 2);
        rvalue[0] = rvalue[size + 1] = 0;
        int pre = rvalue[0];
        for (int i = 1; i <= size; i++)
            rvalue[i] = days[i - 1];
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= size; j++) {
                int temp = rvalue[j];
                rvalue[j] = pre ^ rvalue[j + 1];
                pre = temp;
            }
        }
        return vector<int>(rvalue.begin() + 1, rvalue.end() - 1);
    }
};


int main(void) {
    DaysChange  dc;
    vector<int> cells = {1, 0, 0, 0, 0, 1, 0, 0};
    int days = 1;
    vector<int> res = dc.Solution(cells, days);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << (i == res.size() - 1 ? "" : ",");
    cout << endl;

    return 0;
}
