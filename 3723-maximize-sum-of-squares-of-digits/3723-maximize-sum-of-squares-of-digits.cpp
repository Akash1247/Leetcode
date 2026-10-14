class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        //maximum sum for any no of digits is 9,18,27
        if(sum > num*9) return "";
        string ans= "";
        int k = sum;
        for(int i =0;i<num;i++){
            //9 sbse bdaa hai aur uska square v jydaa hgaa lets think of 9
            if(k>=9)
            {
                ans += "9";
                k = k -9;           
            }
            else{
                ans += to_string(k);
                k -= k;
            }
        }
        return ans;
    }
};