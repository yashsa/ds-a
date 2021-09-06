class Solution {
private:
    int rowContains(vector<vector<int>>& matrix, int target,int mid){
        if(matrix[mid][0]> target) return -1;
        if(matrix[mid][matrix[0].size()-1]<target) return 1;
        return 0;
        
    }
    bool binSearch(vector<int> &row, int target, int low, int high){
        if(low>high) return false;
        int mid=(low+high)/2;
        if(row[mid]==target) return true;
        else if(row[mid] > target) return binSearch(row,target,low,mid-1);
        return binSearch(row,target,mid+1,high);
    }
    bool rowBinarySearch(vector<vector<int>>& matrix, int target,int low,int high){
        if(low>high) return false;
        int mid=(low+high)/2;
        if(rowContains(matrix,target,mid)==0) return binSearch(matrix[mid],target,0,matrix[0].size()-1);
        else if(rowContains(matrix,target,mid)==-1) return rowBinarySearch(matrix,target,low,mid-1);
        else return rowBinarySearch(matrix,target,mid+1,high);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        return rowBinarySearch(matrix, target,0, m-1);
    }
};
