class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int n=height.size();
        int j=n-1;
        int ans = (j-i)*min(height[i],height[j]);
        int curr;
        while(i<j && i<n && j>=0){
            curr = (j-i)*min(height[i],height[j]);
            if(curr>ans) ans=curr;
            int h = min(height[i],height[j]);
            while(i<n && height[i]<=h) i++;
            while(j>=0 && height[j]<=h) j--;
        }
        return ans;
    }
};
