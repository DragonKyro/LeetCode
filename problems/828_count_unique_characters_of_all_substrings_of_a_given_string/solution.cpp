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
    int uniqueLetterString(string s) {
        int index[26][2];
        memset(index, -1, sizeof(index));
        int result = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'A';
            result += (i - index[c][1]) * (index[c][1] - index[c][0]);
            index[c][0] = index[c][1];
            index[c][1] = i;
        }
        for (int c = 0; c < 26; c++)
            result += (n - index[c][1]) * (index[c][1] - index[c][0]);
        return result;
    }
};
