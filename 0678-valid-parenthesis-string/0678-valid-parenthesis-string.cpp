class Solution {
public:
    bool checkValidString(string s) {
        stack<int>open;
        stack<int>star;
        for(int i =0;i<s.length();i++){
            if(s[i] == '('){
                open.push(i);
            }
            else if(s[i] == '*'){
                star.push(i);
            }
            else{
                if(!open.empty()){
                    open.pop();
                }
                else if(!star.empty()){
                    star.pop();
                }
                else {
                    return false;
                }
            }
        }
        while(!open.empty() && !star.empty()) {
            // If the open parenthesis appears before the star, they match
            if(open.top() < star.top()) {
                open.pop();
                star.pop();
            } else {
                // A star before an open parenthesis cannot close it
                return false;
            }
        }

        // If there are still unmatched open parentheses left, it's invalid
        return open.empty();
    }
};