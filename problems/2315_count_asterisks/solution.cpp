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
    int countAsterisks(string s) {
        int count = 0;
        bool inside = false;
        for (char c : s) {
            if (c == '|') inside = !inside;
            else if (c == '*' && !inside) count++;
        }
        return count;
    }
};
