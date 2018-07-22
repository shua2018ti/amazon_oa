#include<queue>
#include<vector>
#include<iostream>
using namespace std;

struct process {
    int arrTime;
    int exeTime;
    process(int arr, int exe) {
        arrTime = arr;
        exeTime = exe;
    }
};

class RoundRobinScheduling {
    public:
    float getAverageWaitTime(vector<int>& Atime, vector<int>& Etime, int maxExeDuration) {
        if (Atime.empty() || Etime.empty() || Atime.size() != Etime.size())
            return 0;

        int size = Atime.size();
        queue<process> q;
        int curTime = 0, waitTime = 0;
        int index = 0;
        while (!q.empty() || index < size) {
            if (!q.empty()) {
                process cur = q.front();
                q.pop();
                waitTime += curTime - cur.arrTime;
                curTime += min(cur.exeTime, maxExeDuration);
                for (; index < size && Atime[index] <= curTime; index++)
                    q.push(process(Atime[index], Etime[index]));
                if (cur.exeTime > maxExeDuration)
                    q.push(process(curTime, cur.exeTime - maxExeDuration));
            }
            else {
                q.push(process(Atime[index], Etime[index]));
                curTime = Atime[index++];
            }
        }
        return (float) waitTime / size;
    }
};

int main(void) {
    RoundRobinScheduling rrs;
    vector<int> Atime = {0, 1, 4};
    vector<int> Etime = {5, 2, 3};
    int maxExeDuration = 3;
    cout << rrs.getAverageWaitTime(Atime, Etime, maxExeDuration) << endl;
    return 0;
}
