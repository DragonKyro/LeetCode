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
    vector<string> ambiguousCoordinates(string s) {
        s = s.substr(1, s.size() - 2);
        vector<string> result;
        for (int i = 1; i < s.size(); i++)
            for (auto& x : make(s.substr(0, i)))
                for (auto& y : make(s.substr(i)))
                    result.push_back("(" + x + ", " + y + ")");
        return result;
    }
    vector<string> make(string s) {
        vector<string> res;
        for (int d = 1; d <= s.size(); d++) {
            string left = s.substr(0, d), right = s.substr(d);
            if ((left == "0" || left[0] != '0') && (right.empty() || right.back() != '0'))
                res.push_back(left + (right.empty() ? "" : ".") + right);
        }
        return res;
    }
};
