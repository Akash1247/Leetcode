class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> radiant, dire;

        // Store indices of R and D senators
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }

        // Process rounds
        while (!radiant.empty() && !dire.empty()) {
            int rIndex = radiant.front();
            radiant.pop();
            int dIndex = dire.front();
            dire.pop();

            // Smaller index bans the other
            if (rIndex < dIndex)
                radiant.push(rIndex + n);
            else
                dire.push(dIndex + n);
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};