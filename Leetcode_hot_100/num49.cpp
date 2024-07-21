#include<vector>
#include<string>
#include<unordered_map>
#include<iostream>
#include<algorithm>
using namespace std;
// 根据特征进行归类使用散列表
class Solution {
public:
    //超时
    vector<vector<string>> groupAnagrams_raw(vector<string>& strs) {
        vector<vector<string>> temp = {{strs[0]}};
        int kong_flag = 0;
        if (strs[0] == ""){
            kong_flag = 1;
        }
        for(int i = 1 ; i < strs.size(); i++){
            int is_same = 1;
            if (strs[i] == "" and kong_flag == 1){
                for(int j = 0; j<temp.size(); j ++){
                    if (temp[j][0] == ""){
                        temp[j].push_back("");
                        break;
                    }
                }
                continue;
            }
            if (strs[i] == "" and kong_flag == 0){
                cout<<1<<endl;
                kong_flag = 1;
                temp.push_back({""});
                continue;
            }
            for(int j = 0; j<temp.size(); j ++)
            {
                unordered_map<char, int> hashmap;
                // 将temp[j][0]中的字符映射到hashmap中
                for(int k = 0 ; k<temp[j][0].length(); k++){
                    if (hashmap.find(temp[j][0][k]) != hashmap.end()){
                        hashmap[temp[j][0][k]] += 1;
                    }
                    else{
                        hashmap[temp[j][0][k]] = 1;
                    }
                    // cout<<temp[j][0][k]<<typeid(temp[j][0][k]).name()<<endl;
                }
                //遍历strs[i]中的字符，如果在hashmap中找到，则将其删除
                int flag = 0;
                for(int k = 0; k<strs[i].length(); k++){
                    if(hashmap.find(strs[i][k]) != hashmap.end()){
                        hashmap[strs[i][k]] -= 1;
                        if (hashmap[strs[i][k]] == 0){
                            hashmap.erase(strs[i][k]);
                        }
                    }
                    else{
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0 and hashmap.size() == 0){
                    is_same= 0;
                    temp[j].push_back(strs[i]);
                }
            }
            if(is_same == 1){
                temp.push_back({strs[i]});
            }
        }
        return temp;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 对字母进行排序后 归类
        unordered_map<string, vector<string>> hashmap;
        for(string& str:strs){
            string temp_str = str;
            sort(temp_str.begin(), temp_str.end());
            hashmap[temp_str].emplace_back(str);
        }
        vector<vector<string>> res;
        for(auto temp = hashmap.begin(); temp!=hashmap.end(); temp++){
            res.emplace_back(temp->second);
        }
        return res;
    }

};
int main(){
    vector<string> strs = {"ac","c"};
    Solution s;
    vector<vector<string>> res = s.groupAnagrams(strs);
    for(int i = 0; i<res.size(); i++){
        for(int j = 0; j<res[i].size(); j++){
            cout<<res[i][j]<<'\t';
        }
        cout<<endl;
    }
    return 0;
}