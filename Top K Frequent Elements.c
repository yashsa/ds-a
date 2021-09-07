class Solution {
public:
    Approach 1: using buckets
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> freq;
        for(auto ele: nums) freq[ele]++;
        vector<vector<int>> buckets;
        buckets.resize(nums.size()+1);
        for(auto ele: freq){
            buckets[ele.second].push_back(ele.first);
        }
        vector<int> res;
        int count=0;
        for(int i = buckets.size()-1; i>=0; i--){
            for(auto ele: buckets[i]) {
                if(count==k) return res;
                res.push_back(ele);
                count++;
            }
        }
        return res;
     }    
};
