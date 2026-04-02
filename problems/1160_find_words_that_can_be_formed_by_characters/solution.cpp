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
    int countCharacters(vector<string>& words, string chars) {
        int charCount[26] = {};
        for (char c : chars) charCount[c - 'a']++;
        int result = 0;
        for (auto& word : words) {
            int wc[26] = {};
            for (char c : word) wc[c - 'a']++;
            bool valid = true;
            for (int i = 0; i < 26; i++) {
                if (wc[i] > charCount[i]) { valid = false; break; }
            }
            if (valid) result += word.size();
        }
        return result;
    }
};
