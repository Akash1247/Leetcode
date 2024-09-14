#include<bits/stdc++.h>
class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        map<char,int>mp;
        for(int k =0;k<p.size();k++)
        {
            mp[p[k]]++;
        }
        vector<int>v;
        map<char,int>m;
        int k = p.length();
        int i=0,j=0;
        while(j<s.length())
        {
            m[s[j]]++;
            if(j-i+1 == k)
            {
                if(mp == m)
                {
                    v.push_back(i);
                }
                m[s[i]]--;
                if (m[s[i]] == 0) m.erase(s[i]);
                i++;
                
            }
            j++;
            
        }
        return v;
    }
};