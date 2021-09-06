class Solution {
    private:
    long long int longDiff(int a, int b){
        long long int x = (long long) a - b;
        return x;
    }
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.empty()) return false;
        unordered_map <int,int> buckets;
        int i;
        for(i=0;i<=k && i<nums.size();i++){
            int bucketIndex = nums[i]/((long) t+1); //write explanation as well
            if(nums[i]<0) bucketIndex--; //to avoid clashes at 0
            if(buckets.find(bucketIndex)!=buckets.end()) return true;
            else{
                if(buckets.find(bucketIndex-1)!=buckets.end()){
                    if(abs(longDiff(buckets[bucketIndex-1],nums[i])) <=t) return true;
                }
                if(buckets.find(bucketIndex+1)!=buckets.end()){
                    if(abs(longDiff(buckets[bucketIndex+1],nums[i])) <=t) return true;
                }
                buckets[bucketIndex] = nums[i];
            }
        }
        i=1;
        while(i+k < nums.size()){
            int prev=nums[i-1];
            int next=nums[i+k];
            int prevBI = prev/((long) t+1);
            buckets.erase(prevBI);
            int bucketIndex = next/((long) t+1); 
            if(next<0) bucketIndex--; //to avoid clashes at 0
            if(buckets.find(bucketIndex)!=buckets.end()) return true;
            else{
                if(buckets.find(bucketIndex-1)!=buckets.end()){
                    if(abs(longDiff(buckets[bucketIndex-1],next)) <=t) return true;
                }
                if(buckets.find(bucketIndex+1)!=buckets.end()){
                    if(abs(longDiff(buckets[bucketIndex+1],next)) <=t) return true;
                }
                buckets[bucketIndex] = next;
            }
            i++;
        }
        return false;
    }
};
