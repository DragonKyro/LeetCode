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
    vector<string> cellsInRange(string s) {
        vector<string> result;
        for (char c = s[0]; c <= s[3]; c++) {
            for (char r = s[1]; r <= s[4]; r++) {
                result.push_back(string(1, c) + r);
            }
        }
        return result;
    }
};
