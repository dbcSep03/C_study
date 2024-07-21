// 当我们需要枚举数组中的两个元素时，如果我们发现随着第一个元素的递增，第二个元素是递减的，那么就可以使用双指针的方法
// 将枚举的时间复杂度从 O(N^2) 减少至 O(N)
// 先排序 再去重 然后双指针夹逼
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> temp;
    sort(nums.begin(), nums.end());
    for(int i = 0; i< n-2;i ++){
        if(i!=0 and nums[i-1] == nums[i]){
            continue;
        }
        int left =i+1;
        int right = n-1;
        for (int left = i+1; left<nums.size()-1; left++){
            if((left!= i+1) and nums[left-1] == nums[left]){
                continue;
            }
            while(left<right and (nums[left]+nums[right]+nums[i]) > 0){
                right--;
            }
            if(left==right){
                break;
            }
            if(nums[left]+nums[right]+nums[i] == 0){
                temp.push_back({nums[left],nums[right],nums[i]});
            }
        }
        
    }
    return temp;
    }
};