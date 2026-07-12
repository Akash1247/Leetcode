class Solution {
    int dfs(int node, int parent, vector<vector<int>>& al) {
        int change = 0;
        
        // Is node ke saare padosiyon (neighbors) ko check karo
        for (auto to : al[node]) {
            // Agar padosi parent nahi hai, tabhi aage badho (taaki peeche na mud jayein)
            if (abs(to) != parent) {
                // (to > 0) check karta hai ki raasta palatna hai ya nahi
                change += (to > 0) + dfs(abs(to), node, al);
            }
        }
        return change;
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> al(n);
        
        // Step 1: Graph banana (+ve aur -ve numbers ke saath)
        for (auto& c : connections) {
            al[c[0]].push_back(c[1]);  // Original direction: Positive
            al[c[1]].push_back(-c[0]); // Reverse direction: Negative
        }
        
        // Step 2: City 0 se DFS shuru karna
        return dfs(0, -1, al); 
    }
};
