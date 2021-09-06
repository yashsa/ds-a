class Solution {
public:
    int search(vector<int>& nums, int target) {
        //if rotation happens then left half will always be larger than the right half
        int lo=0;
        int hi=nums.size()-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>nums[hi]){ //rotation has happened between lo and hi, mid is in the left half
                if(!(target<=nums[nums.size()-1])) //target in left half
                {
                    if(nums[mid]>target) hi=mid-1;
                    else lo=mid+1;
                }
                else if(!(target>=nums[0])) //target in right half
                {
                    lo=mid+1;
                }
            }
            else if(nums[mid]<nums[lo]){ //rotation has happened between lo and hi, mid is in the right half
                if(!(target<=nums[nums.size()-1])) //target in left half
                {
                   hi=mid-1;
                }
                else if(!(target>=nums[0])) //target in right half
                {
                    if(nums[mid]<target) lo=mid+1;
                    else hi=mid-1;
                }
            }
            else{ // no rotation between lo and hi ==> normal binary search
                if(nums[mid]<target) lo=mid+1;
                else hi=mid-1;
            }
        }
        return -1;
    }
};
