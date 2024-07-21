# include <iostream>
# include <vector>
# include <unordered_set>
using namespace std;
// 无序的有 unordered_set, unordered_map, unordered_multiset, unordered_multimap
// 核心逻辑是找到第一个 然后向后寻找
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }
        int max_length = 0;
        for (const int& num_all : num_set) {
            if (num_set.count(num_all - 1)==0) {
                int length = 1;
                int num = num_all;
                while (num_set.count(num+1) != 0) {
                    num += 1;
                    length += 1;
                }
                if (length > max_length) {
                    max_length = length;
                }
            }
        }
        return max_length;
    }
};