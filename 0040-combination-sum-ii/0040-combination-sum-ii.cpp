class Solution {
public:

    void solve(vector<int> &a, int indx, int target,vector<int> &cand, vector<vector<int>> &ans) {
        if(target == 0) {
            ans.push_back(a);
            return;
        }

        for(int i=indx; i<cand.size(); i++) {
            if(i>indx && cand[i]==cand[i-1]) continue;
            if(cand[i]>target) break;
            a.push_back(cand[i]);
            solve(a, i+1, target-cand[i],cand,ans);
            a.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> arr;
        solve(arr,0,target,candidates,ans);
        return ans;
    }
};