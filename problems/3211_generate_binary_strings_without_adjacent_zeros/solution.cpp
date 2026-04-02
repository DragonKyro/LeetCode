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
    vector<string> validStrings(int n) {
        vector<string> res;
        string s;
        function<void()> bt = [&]() {
            if (s.size() == n) { res.push_back(s); return; }
            s += '1'; bt(); s.pop_back();
            if (s.empty() || s.back() == '1') { s += '0'; bt(); s.pop_back(); }
        };
        bt();
        return res;
    }
};
