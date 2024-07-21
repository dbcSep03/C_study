#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> temp;
        int length = 0;
        int max_length = 0;
        int left = 0;
        while(left<s.length()){
            if(temp.find(s[left]) == temp.end()){
                length +=1;
                temp[s[left]] = left;
                max_length = max(length, max_length);
                left++;
            }
            else{
                left = temp.find(s[left])->second+1;
                length=0;
                temp.clear();
            }
        }
        return max_length;
    }
};
int main(){
    string s = "abcabcbb";
    Solution sol;
    int res = sol.lengthOfLongestSubstring(s);
    return 0;
}