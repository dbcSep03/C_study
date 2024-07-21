#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int sumRange(vector<int>&nums, int left, int right){
        int sum = 0;
        for(int i = left; i<right; i++){
            sum += nums[i];
        }
        return sum;
    }
    // 未考虑到负数的情况
    int subarraySum_erroe(vector<int>& nums, int k) {
        int ans = 0;
        int left = 0, right = 1;
        while(left<nums.size()){
            
            int sum = sumRange(nums, left, right);
            if(sum == k){
                
                ans += 1;
                if(right==nums.size()){
                    left++;
                }
                else{
                    right++;
                }
                continue;
            }
            
            if(right<nums.size() and sum<k){
                right++;
                continue;
            }
            left++;
            
            
        }
        return ans;
    }
    // 超时tiemout
    int subarraySum_tiemout(vector<int>& nums, int k) {
        int count = 0;
        for(int start = 0; start<nums.size(); start++){
            int sum = 0;
            for(int end = start; end>=0 ; end--){
                sum += nums[end];
                if(sum == k){
                    count ++;
                }
            }
        }
        return count;
    }
    // 前缀和+哈希表 核心为sum(i,j) = sum(0,j) - sum(0,i)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> temp;
        temp[0]=1;
        int ans = 0;
        int sum = 0;
        for(auto pre: nums){
            sum += pre;
            if(temp.find(sum-k)!=temp.end()){
                ans+=temp[sum-k];
            }
            temp[sum] += 1;
        }
        return ans;
    }
};
int main(){
    vector<int> nums = {1,-1,0};
    Solution s;
    int ans = s.subarraySum(nums, 0);
    cout<<ans<<endl;
    return 0;
}