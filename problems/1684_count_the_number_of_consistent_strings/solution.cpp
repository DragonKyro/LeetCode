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
    int countConsistentStrings(string allowed, vector<string>& words) {
        bitset<26> allow;
        for (char c : allowed) allow[c - 'a'] = 1;
        int count = 0;
        for (auto& word : words) {
            bool valid = true;
            for (char c : word) {
                if (!allow[c - 'a']) { valid = false; break; }
            }
            if (valid) count++;
        }
        return count;
    }
};
