class Solution {
public:

    int hammingWeight(int n)
    {
        int count = 0;
        while(n != 0)
        {
            n = n & (n-1);
            count++;
        }
        return count;
    }

    vector<int> countBits(int n) 
    {
        int r;
        vector<int> ans;
        for(int i =0;i <=n;i++)
        {
            r = hammingWeight(i);
            ans.push_back(r);
        }
        return ans;
    }
};