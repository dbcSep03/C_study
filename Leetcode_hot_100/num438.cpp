#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams_timeout(string s, string p) {
            if(p.length()>s.length()){
                return {};
            }
            sort(p.begin(), p.end());
            vector<int> ans;
            int begin = 0;
            while(begin<=s.length()-p.length()){
                string substr = s.substr(begin, p.length());
                sort(substr.begin(), substr.end());
                if(substr == p){
                    ans.push_back(begin);
                }
                begin++;
            }
            return ans;
        }
    vector<int> findAnagrams(string s, string p) {
        int s_length = s.length(), p_length = p.length();
        vector<int> ans;
        if(p_length> s_length){
            return {};
        }
        vector<int>s_count(26);
        vector<int>p_count(26);
        for (int i = 0; i<p.length(); i++){
            ++s_count[s[i]-'a'];
            ++p_count[p[i]-'a'];
        }
        if(p_count == s_count){
            ans.push_back(0);
        }
        for(int j = 0; j<s_length-p_length; j++){
            --s_count[s[j]-'a'];
            ++s_count[s[j+p_length]-'a'];
            if(s_count == p_count){
                ans.push_back(j+1);
            }
        }
        return ans;
    }
};