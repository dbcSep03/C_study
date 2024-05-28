#include<string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int flag = 0;
        if (needle.length() > haystack.length())
            return -1;
        for(int i = 0;i<=haystack.length()-needle.length(); i++){
            for (int j = 0; j < needle.length(); j++){
                if (needle[j] != haystack[i+j]){
                    flag = 1;
                    break;
                }
            }
            if (flag == 0){
                return i;
            }
            flag = 0;
        }
        return -1;
    }
};