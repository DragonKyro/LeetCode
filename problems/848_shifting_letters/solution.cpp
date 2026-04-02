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
    string shiftingLetters(string s, vector<int>& shifts) {
        long total = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            total += shifts[i];
            s[i] = (s[i] - 'a' + total) % 26 + 'a';
        }
        return s;
    }
};
