class Solution {
private:
    void swap(vector<int> &nums, int i, int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=0;
        while(j<nums.size()){
            if(nums[j]==nums[i]) j++;
            else{
                swap(nums,i+1,j);
                i++;
                j++;
            }
        }
        return j==0?0:i+1; //i+1 is the length (i is 0 based index)
    }
};
