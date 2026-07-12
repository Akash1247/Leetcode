class Solution {
public:
   vector<vector<int>> ans ;
   void Helper(int k , int t , int s , vector<int>&path){
    if(t==0 && k==0){
     ans.push_back(path);
     return  ;
    }

    for(int  i = s ;  i <= 9 ; i++){
        if(i>t || k<= 0){
            break ;
        }
        path.push_back(i);
        Helper(k-1 ,t - i , i + 1 , path);
        path.pop_back();
    }
   }
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<int>p ;
      Helper(k,n,1,p);
      return ans ;  
    }
};