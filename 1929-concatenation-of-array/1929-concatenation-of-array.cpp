class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        int k = nums.size();
        int l = 2*(nums.size());
        vector<int>v;
        for(int i =0;i<k;i++)
        {
            v.push_back(nums[i]);
        }
        for(int i =k;i<l;i++)
        {
            v.push_back(nums[i-k]);
        }       
        return v;
        
    }
};