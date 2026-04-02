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
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int target[26] = {};
        for (char c : licensePlate) if (isalpha(c)) target[tolower(c) - 'a']++;
        string result;
        for (auto& word : words) {
            int wc[26] = {};
            for (char c : word) wc[tolower(c) - 'a']++;
            bool valid = true;
            for (int i = 0; i < 26; i++) if (wc[i] < target[i]) { valid = false; break; }
            if (valid && (result.empty() || word.size() < result.size())) result = word;
        }
        return result;
    }
};
