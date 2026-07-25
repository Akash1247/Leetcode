class Solution {
public:
    unordered_map<string, vector<pair<string,double>>> g;

    double dfs(string u, string v, unordered_set<string>& vis) {
        if (u == v) return 1.0;
        vis.insert(u);

        for (auto &[nbr, wt] : g[u]) {
            if (!vis.count(nbr)) {
                double res = dfs(nbr, v, vis);
                if (res != -1.0) return res * wt;
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& q) {
        
        // build graph
        for (int i = 0; i < eq.size(); i++) {
            auto &a = eq[i][0], &b = eq[i][1];
            g[a].push_back({b, val[i]});
            g[b].push_back({a, 1.0 / val[i]});
        }

        vector<double> ans;

        for (auto &query : q) {
            string a = query[0], b = query[1];

            if (!g.count(a) || !g.count(b)) {
                ans.push_back(-1.0);
                continue;
            }

            unordered_set<string> vis;
            ans.push_back(dfs(a, b, vis));
        }

        return ans;
    }
};