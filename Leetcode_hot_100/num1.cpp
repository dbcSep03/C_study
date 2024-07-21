#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size()-1; i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    vector<int> temp = {i,j};
                    return temp;
                }
            }
        }
        vector<int> temp = {1,2};
        return temp;
    }
    vector<int> twoSum_hash(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i = 0 ; i <nums.size(); i++){
            auto find_mapper = map.find(target - nums[i]);
            if(find_mapper!= map.end())
            {
                return{find_mapper->second, i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    vector<int> nums = {2,7,11,15};
    int target = 9;
    Solution s;
    vector<int> res = s.twoSum(nums, target);
    vector<int> res_hash = s.twoSum_hash(nums, target);
    cout<<res[0]<<'\t'<<res[1]<<endl;
    cout<<res_hash[0]<<'\t'<<res_hash[1]<<endl;
    return 0;
}