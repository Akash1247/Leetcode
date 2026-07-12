class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int phigh = intervals[0][1];
        int count = 0;
        for(int i =1;i<intervals.size();i++){
            if(phigh> intervals[i][0]){
                count++;
                phigh = min(phigh,intervals[i][1]);
            }
            else{
                phigh = intervals[i][1];
            }
        }
        return count;
    }
};





