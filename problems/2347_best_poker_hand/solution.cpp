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
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if (set<char>(suits.begin(), suits.end()).size() == 1) return "Flush";
        map<int, int> count;
        for (int r : ranks) count[r]++;
        int mx = 0;
        for (auto& [k, v] : count) mx = max(mx, v);
        if (mx >= 3) return "Three of a Kind";
        if (mx == 2) return "Pair";
        return "High Card";
    }
};
