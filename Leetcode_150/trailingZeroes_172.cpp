class Solution {
public:
    int trailingZeroes(int n) {
        int x[2] = {0,0};
        for(int i = 1; i<=n; i++){
            int temp = i;
            while(temp%2==0){
                temp = temp/2;
                x[0] +=1;
            }
            temp = i;
            while(temp%5==0){
                temp = temp/5;
                x[1] += 1;
            }
        }
        return x[0]>x[1]?x[1]:x[0];
    }
};