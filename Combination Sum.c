class Solution {
private:
    void backtrack(vector<vector<int>> &ans,vector<int> &candidates, vector<int> &curr,
                   int target, int currSum, int startIndex){
        if(currSum==target)
            ans.push_back(curr);
        else{
            for(int i=startIndex;i<candidates.size();i++){
                if(currSum+candidates[i]<=target){
                    curr.push_back(candidates[i]);
                    currSum+=candidates[i];
                    backtrack(ans,candidates,curr,target,currSum,i);
                    currSum-=candidates[i];
                    curr.pop_back();
                }
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans,candidates,curr,target,0,0);
        return ans;
    }
};
