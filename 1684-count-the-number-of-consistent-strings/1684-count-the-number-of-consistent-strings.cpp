class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool v[26];
        memset(v,false,sizeof(v));
        for(char c: allowed) v[c-'a']=true;
        int count=0;
        for(string& word:words){
            count++;
            for(char c:word){
                if(!v[c-'a']){
                    count--;
                    break;
                }
            }
        }
        return count;
    }
};