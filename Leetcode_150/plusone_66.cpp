#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits[0] == 0)
        {
            vector<int> temp = {1};
            return temp;
        }
        int is_plus = 0;
        for (int n = digits.size()-1;n>=0; n--){
            if (digits[n]!= 9 and is_plus == 0){
                digits[n] += 1;
                is_plus = 1;
            }
            if (digits[n] == 9 and is_plus == 0){
                digits[n] = 0;
            }
            if (is_plus == 1){
                continue;
            }            
        }
        if (is_plus == 0){
            vector<int> temp(digits.size()+1, 0);
            temp[0] = 1;
            return temp;
        }
        return digits;
    }
};