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
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        for (int i = 0; i < (int)s.size(); i += k) {
            string group = s.substr(i, k);
            while ((int)group.size() < k) group += fill;
            result.push_back(group);
        }
        return result;
    }
};
