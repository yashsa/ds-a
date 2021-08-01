class Solution {
private:
    char changeCase(char a){
        if(a>='a' && a<='z') return a+'A'-'a';
        return a+'a'-'A';
    }
public:
    string makeGood(string s) {
        stack <char> stack;
        for(int i=0;i<s.length();i++){
            if(!stack.empty() && changeCase(stack.top())==s[i]) stack.pop();
            else stack.push(s[i]);
        }
        string temp="";
        while(!stack.empty()){
            temp+=stack.top();
            stack.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};
