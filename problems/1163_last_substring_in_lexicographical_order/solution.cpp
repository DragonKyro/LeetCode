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
    string lastSubstring(string s) {
        int i = 0, j = 1, k = 0, n = s.size();
        while (j + k < n) {
            if (s[i + k] == s[j + k]) {
                k++;
            } else if (s[i + k] > s[j + k]) {
                j = j + k + 1;
                k = 0;
            } else {
                i = max(i + k + 1, j);
                j = i + 1;
                k = 0;
            }
        }
        return s.substr(i);
    }
};
