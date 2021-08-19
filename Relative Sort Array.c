class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> m;
        for(auto ele: arr1) m[ele]++;
        int i=0;
        for(auto ele: arr2){
            while(m[ele]>0){
                m[ele]--;
                arr1[i]=ele;
                i++;
            }
        }
        for(auto ele: m){//will be sorted. Also the elements whose frequency has become zero will have been removed
            while(ele.second>0){
                arr1[i]=ele.first;
                ele.second--;
                i++;
            }
        }
        return arr1;
    }
};
