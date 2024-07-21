#include<vector>
using namespace std;
// 核心是一个指向0 一个指向非零，当非零的时候交换
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        while(right < n ){
            if (nums[right]){
                // 交换
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};