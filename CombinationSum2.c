class Solution {
private:
    void backtrack(vector<vector<int>> &ans,vector<int> &candidates, vector<int> &curr,
                   int target, int currSum, int startIndex){
        if(currSum==target)
            ans.push_back(curr);
        else{
            for(int i=startIndex;i<candidates.size();i++){
                if(i>startIndex && candidates[i]==candidates[i-1]) continue;
                if(currSum+candidates[i]<=target){
                    curr.push_back(candidates[i]);
                    currSum+=candidates[i];
                    backtrack(ans,candidates,curr,target,currSum,i+1);
                    currSum-=candidates[i];
                    curr.pop_back();
                }
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans,candidates,curr,target,0,0);
        return ans;
    }
};
