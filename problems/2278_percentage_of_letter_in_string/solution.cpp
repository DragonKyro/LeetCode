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
    int percentageLetter(string s, char letter) {
        int count = 0;
        for (char c : s) if (c == letter) count++;
        return count * 100 / s.size();
    }
};
