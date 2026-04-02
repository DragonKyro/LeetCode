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
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1, width = 0;
        for (char c : s) {
            int w = widths[c - 'a'];
            if (width + w > 100) { lines++; width = w; }
            else width += w;
        }
        return {lines, width};
    }
};
