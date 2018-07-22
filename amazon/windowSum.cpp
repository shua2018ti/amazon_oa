// Window Sum
#include<iostream>
#include<numeric>
#include<vector>
using namespace std;

vector<int> slidingWindowSum(vector<int>& nums, int K) {
    if (nums.empty() || K <= 0)
        return {};

    vector<int> res;
    int sum = 0;
    if (nums.size() <= K) {
        sum = accumulate(nums.begin(), nums.end(), 0);
        res.push_back(sum);
        return res; 
    }

    for (int i = 0; i < K; i++)
        sum += nums[i];
    res.push_back(sum);
    
    for (int i = K; i < nums.size(); i++) {
        sum -= nums[i - K];
        sum += nums[i];
        res.push_back(sum);
    }
         
    return res;
}

int main(void) {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    vector<int> res = slidingWindowSum(nums, 3);
    for (int i = 0; i < res.size(); i++)
        cout << "res[" << i << "]" << res[i] << endl;

    return 0;
}
