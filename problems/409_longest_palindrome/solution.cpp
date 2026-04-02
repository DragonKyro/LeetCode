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
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        for (char c : s) count[c]++;
        int length = 0;
        bool oddFound = false;
        for (auto& [ch, cnt] : count) {
            length += cnt / 2 * 2;
            if (cnt % 2 == 1) oddFound = true;
        }
        return length + (oddFound ? 1 : 0);
    }
};
