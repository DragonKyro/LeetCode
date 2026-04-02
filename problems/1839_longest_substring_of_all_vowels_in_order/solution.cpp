#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int maxLen = 0, count = 1, distinct = 1;
        for (int i = 1; i < word.size(); i++) {
            if (word[i] >= word[i - 1]) {
                count++;
                if (word[i] != word[i - 1]) distinct++;
            } else {
                count = 1;
                distinct = 1;
            }
            if (distinct == 5) maxLen = max(maxLen, count);
        }
        return maxLen;
    }
};
