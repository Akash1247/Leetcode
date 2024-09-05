class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> res;
        int s = 0;
        for (auto u : rolls)
            s += u;
        int x = mean * (n + rolls.size()) - s;
        int num = int(x / n);
        int d = x % n;

        if (num > 6 || num < 0 || d<0)
            return {};

        while (n--)
            res.push_back(num);
        int id = 0;
        while (d--) {
            res[id++]++;
            id %= res.size();
        }
        for (auto u : res)
            if (u > 6 || u < 1)
                return {};
        return res;
    }
};