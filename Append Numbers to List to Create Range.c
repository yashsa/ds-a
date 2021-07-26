int solve(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    int count=0;
    int maxSumAchievableTillNow=0;
    int i=0;
    while(i<nums.size()){
        if(maxSumAchievableTillNow>=k) return count;
        else if(nums[i]>maxSumAchievableTillNow+1){
            count++;
            maxSumAchievableTillNow=2*maxSumAchievableTillNow+1;
            continue;
        }
        maxSumAchievableTillNow+=nums[i];
        i++;
    }
    while(maxSumAchievableTillNow<k){
        count++;
        maxSumAchievableTillNow=2*maxSumAchievableTillNow+1;
    }
    return count;
    
}
