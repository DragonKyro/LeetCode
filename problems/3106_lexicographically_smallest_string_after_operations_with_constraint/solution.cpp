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
    string getSmallestString(string s, int k) {
        for (int i = 0; i < s.size(); i++) {
            int dist = min(s[i] - 'a', 'z' - s[i] + 1);
            if (dist <= k) { s[i] = 'a'; k -= dist; }
            else { s[i] = s[i] - k; k = 0; }
        }
        return s;
    }
};
