class Solution {
private:
    void backtrack(vector <vector<int>> &ans, vector<int>& nums, vector<int> &curr, vector<int> &visited){
        if(curr.size()==nums.size()) ans.push_back(curr);
        else{
            for(int i=0;i<nums.size();i++){
                if(visited[i]==0){
                    visited[i]=1;
                    curr.push_back(nums[i]);
                    backtrack(ans,nums,curr,visited);
                    curr.pop_back();
                    visited[i]=0;
                }
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector<int>> ans;
        vector<int> visited(nums.size(),0);
        vector<int> curr;
        backtrack(ans,nums,curr,visited);
        return ans;
    }
};
