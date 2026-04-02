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
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int current = num;
                int streak = 1;
                while (numSet.count(current + 1)) {
                    current++;
                    streak++;
                }
                longest = max(longest, streak);
            }
        }
        return longest;
    }
};
