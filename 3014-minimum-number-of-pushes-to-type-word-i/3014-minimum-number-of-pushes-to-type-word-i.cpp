class Solution {
public:
    int minimumPushes(string word) {
        int n  = word.length();
        if(n<=8){
            return n;
        }
        int k = n / 8;
        int l = n % 8;
        int ans;
        if(k == 1){
            ans = 8 + l *2;
        }
        else if(k == 2){
            ans = 24 + l*3;
        }        
        else{
            ans = 48 + l *4;
        }
        return ans ;
    }
};