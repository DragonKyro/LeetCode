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
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for (auto& w : words) count[w]++;
        vector<string> keys;
        for (auto& [w, c] : count) keys.push_back(w);
        sort(keys.begin(), keys.end(), [&](auto& a, auto& b) {
            return count[a] == count[b] ? a < b : count[a] > count[b];
        });
        keys.resize(k);
        return keys;
    }
};
