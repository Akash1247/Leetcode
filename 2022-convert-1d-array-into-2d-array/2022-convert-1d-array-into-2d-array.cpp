class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans( m , vector<int> (n));
        if(original.size()>m*n)
        {
            ans.clear();
            return ans;
        }
       else if(original.size()<m*n){
        ans.clear();
        return ans;

       }else{
       int s=original.size();
       int i=0,j=0,k=0;
       while(s>0)
       {
        ans[i][j]=original[k++];
        s--;
        if(j>=n-1)
        {
            j=0,i++;
        }
        else
        {
            j++;
        }
       }
        return ans;}
        
    }
};