class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int maxi = nums[0];
        sum = nums[0];

        unordered_map<int, int> mpp;

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }

            maxi = max(maxi, sum);
        }

        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        int ans = maxi;

        while (mpp.find(ans) != mpp.end()) {
            ans++;
        }

        return ans;
    }
};