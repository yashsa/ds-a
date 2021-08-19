class Solution {
private:
    bool helper(vector<int>& bits,int index){
        if(index<0) return true;
        if(index==0){
            if(bits[index]==1) return false;  
            else return true;
        }
        if(bits[index]==1){
            if(bits[index-1]==0) return false;
            else return helper(bits,index-2);
        } 
        else return (helper(bits,index-1) || helper(bits,index-2));
    }
public:
    bool isOneBitCharacter(vector<int>& bits) {
        return helper(bits,bits.size()-2);
    }
};
