class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map <string, int> freq;
        for(auto str: words) freq[str]++;
        vector<vector<string>> buckets(words.size()+1);
        for(auto ele: freq) buckets[ele.second].push_back(ele.first);
        vector <string> ans;
        for(int i=buckets.size()-1;i>=0;i--){
            sort(buckets[i].begin(),buckets[i].end());
            for(auto str: buckets[i]){
                if(k<=0) break;
                ans.push_back(str);
                k--;
            }
        }
        return ans;
    }
};
