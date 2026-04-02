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
    bool isFascinating(int n) {
        string s = to_string(n) + to_string(2*n) + to_string(3*n);
        if (s.size() != 9) return false;
        sort(s.begin(), s.end());
        return s == "123456789";
    }
};
