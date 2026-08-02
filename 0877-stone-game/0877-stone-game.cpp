class Solution {
public:
    bool stoneGame(vector<int>& piles) 
    {
        int j = piles.size()-1;
        int n = piles.size();
        deque<int>dq;
        for(int i =0;i<piles.size();i++){
            dq.push_back(piles[i]);
        }
        int i =0;
        int turn= 0;
        int sum1 = 0, sum2 =0;
        while(i<=j){
            if(turn%2 ==0 ){
                if(piles[i]>piles[j]){
                    sum1 += piles[i];
                    i++;
                }
                else{
                    sum1 += piles[j];
                    j--;
                }
            }
            else{
                if(piles[i]>piles[j]){
                    sum2 += piles[j];
                    j--;
                }
                else{
                    sum2 += piles[i];
                    i++;
                }
            }
        }
        return (sum1>sum2);
    }
};