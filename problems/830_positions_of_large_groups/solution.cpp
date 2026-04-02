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
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> result;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (j < s.size() && s[j] == s[i]) j++;
            if (j - i >= 3) result.push_back({i, j - 1});
            i = j;
        }
        return result;
    }
};
