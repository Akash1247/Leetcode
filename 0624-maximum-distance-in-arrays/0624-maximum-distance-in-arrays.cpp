class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int globalmin = arr[0].front();
        int globalmax = arr[0].back();
        int res =0;
        for(int i=1;i<arr.size();i++){
            int localmin = arr[i].front();
            int localmax = arr[i].back();
            res = max(res,max(localmax-globalmin,globalmax-localmin));
            globalmax= max(globalmax,localmax);
            globalmin = min(globalmin,localmin);
        }
        return res;
    }
};