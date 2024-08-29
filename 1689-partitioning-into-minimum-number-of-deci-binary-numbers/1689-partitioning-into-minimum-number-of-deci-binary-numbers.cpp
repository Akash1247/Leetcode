class Solution {
public:
    int minPartitions(string n) 
    {
        int max = 0;
        for(int i =0;i<n.size();i++)
        {
            int s = n[i]- '0';
            if(s> max)
            {
                max = s;
            }
        }
        return max;
        
    }
};