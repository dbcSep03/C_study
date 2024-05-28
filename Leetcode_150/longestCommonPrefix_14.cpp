#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1){
            return strs[0];
        }
        int min_length = 2000;
        int index = -1;
        for(int i = 0; i<strs.size(); i++){
            if (strs[i].length() < min_length){
                min_length = strs[i].length();
                index = i;
            }
        }
        string CommonPrefix = "";
        int flag = 0;
        int length = -1;
        for (int i = 0 ;i<strs[index].length(); i++){
            for(int j = 0; j<strs.size(); j++){
                if (strs[index][i] != strs[j][i]){
                    flag = 1;
                    break;
                }
            } 
            if (flag == 1){
                break;
            }
            length = i;
        }
        for(int i = 0; i<=length; i++){
            CommonPrefix += strs[index][i];
        }
        return CommonPrefix;
    }
};
class Solution {
public:

    static string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) {
            return {};
        }
        sort(strs.begin(), strs.end());
        string st = strs.front();
        string en = strs.back();
        int i;
        int num = (int) min(st.size(), en.size());
        for (i = 0; i < num && st[i] == en[i]; i++);
        string res = string(st, 0, i);
        return res;
    }
};
// 作者：15066212pp
// 链接：https://leetcode.cn/problems/longest-common-prefix/solutions/2328190/yun-xing-shi-jian-0mspai-xu-qiu-jie-by-1-r37b/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
int main(){
    vector<string> strs = {"flower","flow","flight"};
    Solution sol;
    string result = sol.longestCommonPrefix(strs);
    printf("%s\n", result.c_str());
}