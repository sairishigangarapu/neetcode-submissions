#include <string>
#include <array>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if (n1 > n2) {
            return false;
        }

        array<int, 26> needle = {0};
        array<int, 26> haystack = {0};

        for (int i = 0; i < n1; ++i) {
            needle[s1[i] - 'a']++;
            haystack[s2[i] - 'a']++;
        }

        if (needle == haystack) {
            return true;
        }

        for (int i = n1; i < n2; ++i) {
            haystack[s2[i] - 'a']++;
            
            haystack[s2[i - n1] - 'a']--;

            if (needle == haystack) {
                return true;
            }
        }

        return false;
    }
};