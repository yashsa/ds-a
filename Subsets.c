class Solution {
private:
    void backtrack(vector <vector<int>> &ans, vector<int>& nums, vector<int> &curr, int startIndex){
        if(curr.size()<=nums.size()) ans.push_back(curr);
        for(int i=startIndex;i<nums.size();i++){
            curr.push_back(nums[i]);
            backtrack(ans,nums,curr,i+1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector<int>> ans;
        vector<int> curr;
        backtrack(ans,nums,curr,0);
        return ans;
    }
};
