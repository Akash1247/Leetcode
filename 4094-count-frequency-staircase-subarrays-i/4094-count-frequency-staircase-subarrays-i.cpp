class Solution {
public:
    int countStaircase(vector<int>& nums) 
    {
        int n = nums.size();
        int ans = 0;

        //Since the size is very small we can go for 3 loops
        for(int i = 0; i<n;i++){ // Outer loop
            vector<int>visited;
            unordered_map<int,int>freq;
            for(int j = i;j<n;j++){

                // if frequency is 0, this is the first time we are seeing this number
                if(freq[nums[j]] == 0 ){
                    visited.push_back(nums[j]);
                }
                //Incrmnt frequency
                freq[nums[j]]++;

                bool present = true;
                //This step is particularly for staircase e.g. if for any case in current loop
                // it forms statircase element at 0 will have 1 frequency
                // idx [1] --> 2 
                // 2 -->3, similarly continued further
                for(int k = 0;k<visited.size();k++){

                    //if doesnt follow break loop
                    if(freq[visited[k]]  != k+1 ){
                        present = false;
                        break;
                    }
                }
                if(present){
                    ans++;
                }
            }
        }
        return ans;
    }
};