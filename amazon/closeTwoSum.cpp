#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
struct Container {
    int first;
    int second;

    Container(int first, int second) {
        this->first = first;
        this->second = second;
    }
};

class TwoClose {
    public:
    Container closeTwoSum(vector<int>& nums, int capacity) {
        sort(nums.begin(), nums.end());
        int maxSum = INT_MIN;
        int first = 0, second = 0;

        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int sum = nums[start] + nums[end];
            if (sum == capacity) {
                return Container(nums[start], nums[end]);

            } else if (sum < capacity) {
                if (sum > maxSum) {
                    first = nums[start];
                    second = nums[end];
                    maxSum = sum;
                }
                start++;
            } else {
                end--;
            }
        }

        return Container(first, second);
    }
};


int main(void) {
    vector<int> nums = {10,24,30,9,19,23,7};
    TwoClose test;
    Container res = test.closeTwoSum(nums, 40);

    cout << "first:" << res.first << ", second:" << res.second << endl;
    return 0;
}


