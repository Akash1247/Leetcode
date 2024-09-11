class Solution {
public:
    int minBitFlips(int start, int goal) {
        int s,g,cnt=0;
        while(start!=goal){
            s=start&1;
            g=goal&1;
            if(s!=g)
                cnt++;
                start=start>>1;
                goal=goal>>1;
        }
    return cnt;
    }
};