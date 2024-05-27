#include<cmath>
using namespace std;
class Solution {
public:
    // 利用 \sqrt x = e^{\frac{1}{2} \ln x}
    int mySqrt(int x) {
        if(x==0)
            return 0;
        double ans = exp(0.5*log(x));
        return (long long)(ans+1)*(ans+1)<=x?ans+1:ans;
    }
};

class Solution {
public:
    // 利用二分查找 由于超出了
    int mySqrt(int x) {
        if(x==0)
            return 0;
        if(x==1)
            return 1;
        int left = 0;
        int right = x;
        int mid = x/2;
        while(left<= right){
            if ((long long)mid*mid<x)
            {
                left = mid;
                mid = (left+ right)/2;
            }
            if ((long long)mid*mid == x)
            {
                return mid;
            }
            if ((long long)mid*mid>x){
                right = mid;
                mid = (left+right)/2;
            }
            if (mid == left)
            {
                break;
            }
        }
        return left;
    }
};