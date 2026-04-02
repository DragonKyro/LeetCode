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
    vector<int> diStringMatch(string s) {
        int n = s.size(), low = 0, high = n;
        vector<int> result;
        for (char c : s)
            result.push_back(c == 'I' ? low++ : high--);
        result.push_back(low);
        return result;
    }
};
