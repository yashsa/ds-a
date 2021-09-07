class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(auto ele: s) m[ele]++;
        vector<vector<char>> buckets(s.length()+1);
        for(auto ele: m) buckets[ele.second].push_back(ele.first);
        string res="";
        for(int i=buckets.size()-1; i>=0; i--){
            for(auto ele: buckets[i]){
                for(int j=0;j<i;j++) res+=ele;
            }
        }
        return res;
    }
};
