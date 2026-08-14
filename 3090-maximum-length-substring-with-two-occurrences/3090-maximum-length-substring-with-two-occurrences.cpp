class Solution {
public:
    int maxi(string &k)
    {
        int maxo = 0;
        for (int p =0;p<k.length();p++)
        {
            map<char,int>mp;
            int count =0;
            
            for(int e = p; e<k.length();e++)
            {
                mp[k[e]]++;
                
                if(mp[k[e]] <= 2) {
                    count = e-p+1;
                    maxo = max(maxo,count);
                }
                else
                {
                    break;
                }
            }
            
        }
        return maxo;
    }
    int maximumLengthSubstring(string s) 
    {
        map<int,int>m;
        for(int i =0 ;i<s.size();i++)
        {
            m[s[i]]++;
        }
        int gate = 0;
        for(auto it:m)
        {
            if(it.second >2)
            {
                gate =1;
            }
        }
        int ans;
        string k = s;
        if(gate == 0)
        {
            ans = s.size();
        }
        else 
        {
            ans = maxi(k);
        }
        return ans;
        
    }
};