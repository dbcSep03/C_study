#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        // 队列 默认是最大队列，先进先出 按照重要性进行排序
        priority_queue<pair<int,int>> temp;
        for(int i=0; i < k; i++){
            temp.emplace(nums[i], i);
        }
        vector<int> ans = {temp.top().first};
        for(int j = k; j<nums.size();j++){
            temp.emplace(nums[j], j);
            // while很重要，保证队列中的元素是在窗口内的
            while(temp.top().second<j-k){
                temp.pop();
            }
            ans.push_back(temp.top().first);
        }
        return ans;
    }
};