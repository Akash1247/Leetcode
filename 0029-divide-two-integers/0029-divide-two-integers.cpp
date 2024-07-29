class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(dividend==INT_MIN && divisor==1) return INT_MIN;

        long int dd=abs(dividend), dv=abs(divisor);
        int ans=0;
        long int temp=dv;

        while(temp<=dd){
            ans+=1;
            temp+=dv;
        }

        if(dividend<0 ^ divisor<0) return -ans;
        else return ans;
    }
};