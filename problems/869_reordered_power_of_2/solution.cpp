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
    bool reorderedPowerOf2(int n) {
        string target = to_string(n);
        sort(target.begin(), target.end());
        for (int i = 0; i < 31; i++) {
            string s = to_string(1 << i);
            sort(s.begin(), s.end());
            if (s == target) return true;
        }
        return false;
    }
};
