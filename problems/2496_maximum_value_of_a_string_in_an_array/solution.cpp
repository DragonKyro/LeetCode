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
    int maximumValue(vector<string>& strs) {
        int result = 0;
        for (auto& s : strs) {
            bool allDigit = true;
            for (char c : s) if (!isdigit(c)) { allDigit = false; break; }
            result = max(result, allDigit ? stoi(s) : (int)s.size());
        }
        return result;
    }
};
