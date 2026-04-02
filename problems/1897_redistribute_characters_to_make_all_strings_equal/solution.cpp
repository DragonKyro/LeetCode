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
    bool makeEqual(vector<string>& words) {
        int count[26] = {};
        for (auto& w : words) for (char c : w) count[c - 'a']++;
        int n = words.size();
        for (int c : count) if (c % n != 0) return false;
        return true;
    }
};
