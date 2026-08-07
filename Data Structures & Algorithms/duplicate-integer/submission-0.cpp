class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> elements;

        for(auto it : nums){
            if(elements.count(it)){
                return true;
            }
            else{
                elements.insert(it);
            }
        }
        return false;
    }
};