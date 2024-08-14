class Solution {
public:
   
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());

        vector<int> mp(nums[n-1]+1,0);
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                mp[abs(nums[j]-nums[i])]++;
            }
        }
        
        for(int i=0;i<=nums[n-1];++i)
        {
            if(mp[i]<k)
            {
                k = k - mp[i];
            }
            else
            {
                return i;
            }
        }

        return -1;
    }
};