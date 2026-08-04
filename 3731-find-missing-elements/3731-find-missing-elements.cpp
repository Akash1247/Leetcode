class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int k  = nums[0];
        unordered_map<int,int>mp;
        for(int i =0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int>ans;
        for(int i=nums[0];i<=nums[n-1];i++){
            if(mp.find(i) == mp.end()){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};