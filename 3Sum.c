class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int curr=nums[i];
            int val = 0 - nums[i];
            int lo = i+1;
            int hi = nums.size()-1;
            vector <int> ts;
            while(lo<hi){
                int sum = nums[lo]+nums[hi];
                if(sum<val) lo++;
                else if(sum>val) hi--;
                else{
                    ts.push_back(nums[lo]);   
                    ts.push_back(nums[hi]);
                    ts.push_back(nums[i]);
                    res.push_back(ts);
                    ts.clear();
                    int nl=nums[lo];
                    int nh=nums[hi];
                    while(hi>=0 && nums[hi]==nh) hi--;
                    while(lo<nums.size() && nums[lo]==nl) lo++;
                }
            }   
        }
        return res;
    }
};
