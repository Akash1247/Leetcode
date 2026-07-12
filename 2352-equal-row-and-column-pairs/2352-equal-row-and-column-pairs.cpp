class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;
        map<vector<int>, int> rowFreq;
        for (int i = 0; i < n; i++) {
            rowFreq[grid[i]]++;
        }
        for (int j = 0; j < n; j++) {
            vector<int> col;
            for (int i = 0; i < n; i++) {
                col.push_back(grid[i][j]);
            }
            count += rowFreq[col];
        }   
        return count;
    }
};