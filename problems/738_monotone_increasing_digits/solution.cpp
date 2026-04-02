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
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int mark = s.size();
        for (int i = s.size() - 1; i > 0; i--) {
            if (s[i] < s[i-1]) {
                mark = i;
                s[i-1]--;
            }
        }
        for (int i = mark; i < (int)s.size(); i++) s[i] = '9';
        return stoi(s);
    }
};
