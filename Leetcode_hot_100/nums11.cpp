#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    // 超时了
    int maxArea_timeout(vector<int>& height) {
        int maxarea = 0;
        for(int i = 0; i<height.size()-1; i++){
            for(int j = i+1; j < height.size(); j++){
                int area = (j-i) * min(height[i],height[j]);
                maxarea = max(area, maxarea);
            }
        }
        return maxarea;
    }
    //双指针 核心为向内移动较小的那个
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        int left = 0;
        int right =  height.size()-1;
        while(left<right){
            int area = (right-left)*min(height[left], height[right]);
            maxarea = max(maxarea, area);
            if(height[right] > height[left]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxarea;
    }
};