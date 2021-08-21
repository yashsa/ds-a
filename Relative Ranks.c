class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>> p;
        for(int i=0;i<score.size();i++) p.push_back(make_pair(score[i],i));
        vector<string> ans(score.size());
        sort(p.rbegin(),p.rend());
        int count=0;
        for(auto ele:p){
            if(count==0) ans[ele.second]="Gold Medal";
            else if(count==1) ans[ele.second]="Silver Medal";
            else if(count==2) ans[ele.second]="Bronze Medal";
            else ans[ele.second]=to_string(count+1);
            count++;
        }
        return ans;
    }
};
