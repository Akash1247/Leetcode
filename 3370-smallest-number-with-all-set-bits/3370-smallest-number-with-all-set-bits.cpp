class Solution {
public:
    int smallestNumber(int n) 
    {
        vector<int>v;
        int i =0;
        while(n>0)
        {
            v.push_back(n%2);
            n = n/2;
        }
        int k = v.size();
        int arr[k];
        int r = pow (2,k) - 1;
        return r;
        
    }
};