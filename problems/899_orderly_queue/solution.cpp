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
    string orderlyQueue(string s, int k) {
        if (k > 1) { sort(s.begin(), s.end()); return s; }
        string result = s;
        for (int i = 1; i < s.size(); i++)
            result = min(result, s.substr(i) + s.substr(0, i));
        return result;
    }
};
