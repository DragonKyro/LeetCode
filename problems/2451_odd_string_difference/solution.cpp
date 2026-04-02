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
    string oddString(vector<string>& words) {
        map<vector<int>, vector<string>> mp;
        for (auto& w : words) {
            vector<int> d;
            for (int i = 1; i < w.size(); i++) d.push_back(w[i] - w[i-1]);
            mp[d].push_back(w);
        }
        for (auto& [k, v] : mp) if (v.size() == 1) return v[0];
        return "";
    }
};
