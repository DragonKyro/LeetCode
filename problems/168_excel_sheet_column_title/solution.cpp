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
    string convertToTitle(int columnNumber) {
        string res;
        while (columnNumber > 0) {
            columnNumber--;
            res += (char)(columnNumber % 26 + 'A');
            columnNumber /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
