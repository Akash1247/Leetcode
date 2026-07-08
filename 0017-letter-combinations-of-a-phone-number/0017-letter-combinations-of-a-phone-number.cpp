class Solution {
public:
    vector<string>result;
    void solve(int idx,unordered_map<char,string>&mp,string &digits, string &temp){
        if(idx>=digits.length()){
            result.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string s = mp[ch];
        for(int i =0;i<s.length();i++){
            temp.push_back(s[i]);
            solve(idx+1 ,mp,digits,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        if(digits.length() == 0){
            return {};
        }
        unordered_map<char,string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        string temp = "";
        solve(0,mp,digits,temp);
        return result;
    }
};