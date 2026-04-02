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
    int maxRepOpt1(string text) {
        int count[26] = {};
        for (char c : text) count[c - 'a']++;
        vector<pair<int, int>> groups;
        int i = 0;
        while (i < text.size()) {
            int j = i;
            while (j < text.size() && text[j] == text[i]) j++;
            groups.push_back({text[i] - 'a', j - i});
            i = j;
        }
        int result = 0;
        for (int k = 0; k < groups.size(); k++) {
            auto [ch, len] = groups[k];
            result = max(result, min(len + 1, count[ch]));
            if (k + 2 < (int)groups.size() && groups[k + 2].first == ch && groups[k + 1].second == 1) {
                result = max(result, min(len + groups[k + 2].second + 1, count[ch]));
            }
        }
        return result;
    }
};
