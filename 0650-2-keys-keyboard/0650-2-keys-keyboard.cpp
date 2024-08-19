class Solution {
public:
    int minSteps(int n) {
        
        
        int ans = knapSack(1, 1, n);
        return (ans) ? ans + 1 : 0;  // extra one for inital copy
    }
    int knapSack(int n, int steps, int len) {
        if (n == len) return 0; // base case
        if (n > len || steps > (len - n)) return len; // base case
		// Either copy-->then-->paste   OR just keep pasting
        return 1 + min(1 + knapSack(2*n, n, len), knapSack(n + steps, steps, len));
    
        
    }
};