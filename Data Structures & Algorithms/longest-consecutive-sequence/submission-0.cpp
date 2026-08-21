#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int n : nums) {
            if (numSet.find(n - 1) == numSet.end()) {
                int length = 0;
                
                while (numSet.find(n + length) != numSet.end()) {
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};