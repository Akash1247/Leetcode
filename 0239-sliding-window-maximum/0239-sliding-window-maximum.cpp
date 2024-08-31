class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int i =0, j =0;
        vector<int>v;
        if(k == 0) return v; // khaali rhe to uske liye
        list<int>l;
        while(j<n)
        {
            while(l.size()>0 && l.back()<nums[j])
            {
                l.pop_back();
            }
            l.push_back(nums[j]);
            if(j-i+1 == k)
            {
                v.push_back(l.front());
                if(nums[i]==l.front())
                {
                    l.pop_front();
                }
                i++;
            }
            j++;
        }
        return v;
        
    }
};