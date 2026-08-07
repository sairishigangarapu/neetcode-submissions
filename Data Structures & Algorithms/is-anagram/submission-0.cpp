class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char , int> chars1;
        map<char ,int> chars2;
        if(s.length() != t.length()){
            return false;
        }
        
        for(auto it: s){
            chars1[it]++;
        }
        for(auto its: t){
            chars2[its]++;
        }
        return chars1 == chars2;
    }
};
