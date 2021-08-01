class Solution {
private:
    int comb(int x, int y){ // calculates xCy
        if(x<y) return 0;
        if(x==y) return 1;
        else if(y<x-y) return comb(x,x-y);
        long long int ans=1;
        for(int i=y+1;i<=x;i++) ans*=i;
        for(int i=1;i<=x-y;i++) ans/=i;
        return ans;
    }
public:
    int uniquePaths(int m, int n) {
        return comb(m+n-2,m-1);
    }
};
