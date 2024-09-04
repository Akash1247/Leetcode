class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
         auto stringify = [](const pair<int, int>& p, string sep = "-")-> string{
            return to_string(p.first) + sep + to_string(p.second);
        };
        int maximum_dis=0;
        int start=1;
        unordered_set<string> obstacles_set;
        for(const auto& obstacle:obstacles){
            obstacles_set.insert(stringify(make_pair(obstacle[0],obstacle[1])));
        }
        vector<int> cor(2);
        string dir="+Y";
        for(const auto& command: commands){
            
            if(dir=="+Y"){
                if(command==-1){
                    dir="+X";
                }else if(command==-2){
                    dir="-X";
                }else{
                    int j;
                    for(j=cor[1]; j<=cor[1]+command; ++j){
                        if(cor[0]==0 && j==0 && start==1){
                            start=0;
                            continue;
                        }
                        if(obstacles_set.count(stringify(make_pair(cor[0],j)))){
                            break;
                        }
                    }
                    cor={cor[0], j-1};
                }
            }else if(dir=="+X"){
                if(command==-1){
                    dir="-Y";
                }else if(command==-2){
                    dir="+Y";
                }else{
                    int i;
                    for(i=cor[0]; i<=cor[0]+command; ++i){
                        if(i==0 && cor[1]==0 && start==1){
                            start=0;
                            continue;
                        }
                        if(obstacles_set.count(stringify(make_pair(i,cor[1])))){
                            break;
                        }
                    }
                    cor={i-1, cor[1]};
                }
            }else if(dir=="-Y"){
                if(command==-1){
                    dir="-X";
                }else if(command==-2){
                    dir="+X";
                }else{
                    int j;
                    for(j=cor[1]; j>=cor[1]-command; --j){
                        if(cor[0]==0 && j==0 && start==1){
                            start=0;
                            continue;
                        }
                        if(obstacles_set.count(stringify(make_pair(cor[0],j)))){
                            break;
                        }
                    }
                    cor={cor[0], j+1};
                }
            }else if(dir=="-X"){
                if(command==-1){
                    dir="+Y";
                }else if(command==-2){
                    dir="-Y";
                }else{
                    int i;
                    for(i=cor[0]; i>=cor[0]-command; --i){
                        if(i==0 && cor[1]==0 && start==1){
                            start=0;
                            continue;
                        }
                        if(obstacles_set.count(stringify(make_pair(i,cor[1])))){
                            break;
                        }
                    }
                    cor={i+1, cor[1]};
                }
            }
            maximum_dis=max(maximum_dis, cor[0]*cor[0]+cor[1]*cor[1]);
        }
        return maximum_dis;
    }
};