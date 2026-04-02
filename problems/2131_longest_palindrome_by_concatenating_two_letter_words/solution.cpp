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
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        for (auto& w : words) freq[w]++;
        int length = 0;
        bool hasCenter = false;
        for (auto& [word, count] : freq) {
            string rev(word.rbegin(), word.rend());
            if (word == rev) {
                length += (count / 2) * 4;
                if (count % 2 == 1) hasCenter = true;
            } else if (word < rev && freq.count(rev)) {
                length += min(count, freq[rev]) * 4;
            }
        }
        if (hasCenter) length += 2;
        return length;
    }
};
