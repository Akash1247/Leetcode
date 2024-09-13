class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int n=arr.size();
        vector<int>PrefixXOR(n+1, 0);
        for(int i=1;i<=n;i++)
            PrefixXOR[i]=PrefixXOR[i-1]^arr[i-1];

        vector<int> res;
        for(auto query: queries){
            int left=query[0], right=query[1];
            int ans=PrefixXOR[left]^PrefixXOR[right+1];
            res.push_back(ans);
        }
        return res;
    }
};