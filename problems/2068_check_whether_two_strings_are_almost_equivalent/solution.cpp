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
    bool checkAlmostEquivalent(string word1, string word2) {
        int freq[26] = {};
        for (char c : word1) freq[c - 'a']++;
        for (char c : word2) freq[c - 'a']--;
        for (int i = 0; i < 26; i++) {
            if (abs(freq[i]) > 3) return false;
        }
        return true;
    }
};
