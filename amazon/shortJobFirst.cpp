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
    float getAverageWaitTime(vector<int>& Atime, vector<int>& Etime) {
        if (Atime.empty() || Etime.empty() || Atime.size() != Etime.size())
            return 0;

        int size = Atime.size();
        auto cmp = [&](process& p1, process& p2) {
            return p1.exeTime > p2.exeTime || (p1.exeTime == p2.exeTime && p1.arrTime > p2.arrTime);
        };
        typedef priority_queue<process, vector<process>, decltype(cmp)> PQ;
        PQ pq(cmp);
        int curTime = 0, waitTime = 0;
        int index = 0;
        while (!pq.empty() || index < size) {
            if (!pq.empty()) {
                process cur = pq.top();
                pq.pop();
                waitTime += curTime - cur.arrTime;
                curTime += cur.exeTime;
                for (; index < size && Atime[index] <= curTime; index++)
                    pq.push(process(Atime[index], Etime[index]));
            }
            else {
                pq.push(process(Atime[index], Etime[index]));
                curTime = Atime[index++];
            }
        }
        return (float) waitTime / size;
    }
};

int main(void) {
    RoundRobinScheduling rrs;
    vector<int> Atime = {0, 2, 5, 9};
    vector<int> Etime = {2, 1, 18, 5};
    cout << rrs.getAverageWaitTime(Atime, Etime) << endl;
    return 0;
}
