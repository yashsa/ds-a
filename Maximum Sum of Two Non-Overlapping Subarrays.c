class Solution {
private:
    void formSlidingWindow(vector<int> nums, int k, vector<int>& res){
        int sum=0;
        int i;
        for(i=0;i<k;i++) sum+=nums[i];
        res.push_back(sum);
        while(i<nums.size()){
            sum=sum+nums[i]-nums[i-k];
            res.push_back(sum);
            i++;
        }
        while(res.size()<nums.size()) res.push_back(-1);
    }
    void getMaxAhead(vector<int>& arr){
        int i=arr.size()-2;
        while(i>=0){
            arr[i]=max(arr[i],arr[i+1]);
            i--;
        }
    }
    void getMaxBehind(vector<int> &arr, vector<int> &res){
        int i=1;
        res.push_back(arr[0]);
        while(i<arr.size()){
            res.push_back(max(arr[i],res[i-1]));
            i++;
        }
    }
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        vector<int> slidingWindow1;
        vector<int> slidingWindow2;        
        vector<int> maxBehind;
        formSlidingWindow(nums,firstLen,slidingWindow1);
        formSlidingWindow(nums,secondLen,slidingWindow2);
        getMaxBehind(slidingWindow2,maxBehind);
        getMaxAhead(slidingWindow2);
        int maximum=INT_MIN;
        for(int i=0;i<slidingWindow1.size();i++){
            if(slidingWindow1[i]==-1) break;
            int mx=0;
            if(i>=secondLen) mx=maxBehind[i-secondLen];
            if(i+firstLen<slidingWindow2.size()){
                if(slidingWindow2[i+firstLen]!=-1 && mx<slidingWindow2[i+firstLen]) mx=slidingWindow2[i+firstLen];
            }
            //slidingWindow1[i] contains the sum of the window from i to i+firstLen-1
            int curr=slidingWindow1[i]+mx;
            if(maximum<curr) maximum=curr;
        }
        return maximum==INT_MIN?0:maximum;
    }
};
