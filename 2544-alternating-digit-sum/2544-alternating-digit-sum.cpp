class Solution {
public:
    int alternateDigitSum(int n)
    {
        int count = floor(log10(n) + 1);
        int sum =0;
        while(n)   
        {
            int k = n % 10;
            if(count %2 == 0)
            {
                sum -= k;
            }
            else{
                sum += k;
            }
            count--;
            n = n/10;
        }
        return sum;
        
    }
};