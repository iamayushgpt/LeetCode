class Solution {
public:
    bool isPalindrome(string s) {
        string res ="";
        for(auto i:s){
            if(isalnum(i)){
                res+=tolower(i);
            }
        }
       
        string dup = res;
        
      
        int start = 0;
        int end = dup.size()-1;
        while(start<end){
            swap(dup[start++],dup[end--]);
        }
        if(dup == res)
        return true;
        return false;
    }
};