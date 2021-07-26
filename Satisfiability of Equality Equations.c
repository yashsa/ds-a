class Solution {
private: 
    char disjointFind(char ch, vector <char> &root){
        if(root[ch-'a']=='\0') return ch;
        root[ch-'a'] = disjointFind(root[ch-'a'],root);
        return root[ch-'a'];
    }
    void disjointUnion(char a, char b, vector <char> &root){
        char root_a = disjointFind(a,root);
        char root_b = disjointFind(b,root);
        int index=root_a - 'a';
        root[index] = root_b;
    }
public:
    bool equationsPossible(vector<string>& equations) {
        vector <char> root(26,'\0');
        for(auto e:equations){
            if(e[1]=='='){
                disjointUnion(e[0],e[3],root);
            }
        }
        for(auto e:equations){
            if(e[1]=='!'){
                if(disjointFind(e[0],root)==disjointFind(e[3],root)) return false;
            }
        }
        return true;
    }
};
