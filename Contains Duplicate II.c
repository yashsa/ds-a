class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map <int,int> m;
        int i=0;
        for(int i=0;i<=k&&i<nums.size();i++){
            if(m[nums[i]]>0) return true;
            else m[nums[i]]++;
        }
        i=k;
        while(i+1<nums.size()){
            m[nums[i-k]]--;
            if(m[nums[i+1]]>0) return true;
            else m[nums[i+1]]++;
            i++;
        }
        return false;
    }
};
