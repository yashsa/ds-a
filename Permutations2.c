class Solution {
private:
    void backtrack(vector <vector<int>> &ans, vector<int>& nums, vector<int> &curr, vector<int> &visited){
        if(curr.size()==nums.size()) ans.push_back(curr);
        else{
            for(int i=0;i<nums.size();i++){
                /*if the current element is same as the previous element 
                then we can use it only if the previous element is used*/
                if(i>0 && nums[i]==nums[i-1] && !visited[i-1]) continue; 
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector <vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector <int> visited(nums.size(),0);
        vector<int> curr;
        backtrack(ans,nums,curr,visited);
        return ans;
    }
};
