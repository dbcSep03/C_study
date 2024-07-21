#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;
class Solution {
public:
    //使用公共变量，减少内存开销，减少比较时间 保存起始位置 而不是对应字符串 减少对应的内存开销
    unordered_map<char, int>target, needed;
    bool check(){
        for(const auto& temp: target){
            if (needed[temp.first]< temp.second){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int left = 0, right = 0;
        for(const auto & temp: t){
            target[temp] += 1;
        }
        int min_length = 1e5;
        int start_pos = -1;
        while(right<s.length()){
            char temp = s[right];
            right++;
            if (target.count(temp)!= 0){
                needed[temp] +=1;
            }
            while(check()){
                char temp = s[left];
                if(right-left < min_length){
                
                    min_length = right-left;
                    start_pos = left;
                }
                needed[temp] -= 1;
                left++;               
            }
        }
        cout<<start_pos;
        return start_pos < 0 ? "":s.substr(start_pos, min_length);

    }
};
int mian(){
    Solution s;
    string s1 = "ADOBECODEBANC";
    string s2 = "ABC";
    cout<<s.minWindow(s1, s2)<<endl;
    return 0;
}