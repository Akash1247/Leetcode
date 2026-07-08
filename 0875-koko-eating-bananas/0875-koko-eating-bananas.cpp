class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int maxi  = *max_element(piles.begin(), piles.end());
        if(h == piles.size()){
            return maxi;
        }
        int n = piles.size();
        long long sum = 0;
        for(int i =0;i<n;i++){
            sum +=piles[i];
        }
        long long s = {(sum + h -1) / h };
        long long e = sum;
        int ans;
        while(s<e){
            long long sum1 = 0;
            long long mid = s + (e-s) /2;
            for(int i =0;i<piles.size();i++){
                sum1  += (piles[i] + mid -1)/mid;
            }
            if(sum1 > h){
                s = mid+1;
            }
            else{
                ans = mid;
                e = mid;
            }

        }
        return ans;
}
};