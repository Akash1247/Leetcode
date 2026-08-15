class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int n1  = requests.size();
        int change = requests[0];
        for(int i =1;i<n1;i++){
            change += abs(requests[i] - requests[i-1]);
        }
        return change;
    }
};