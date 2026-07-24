class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(),points.end());
        pair<int,int>shot;
        int count=1;
        shot={points[0][0],points[0][1]};
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]>=shot.first&&points[i][0]<=shot.second)
            {
                shot={max(points[i][0],shot.first),min(points[i][1],shot.second)};
            }
            else
            {
                count++;
                shot={points[i][0],points[i][1]};
            }
        }
        return count;
    }
};