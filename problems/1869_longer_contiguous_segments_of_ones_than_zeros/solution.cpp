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
    bool checkZeroOnes(string s) {
        int max1 = 0, max0 = 0, cur1 = 0, cur0 = 0;
        for (char c : s) {
            if (c == '1') { cur1++; cur0 = 0; }
            else { cur0++; cur1 = 0; }
            max1 = max(max1, cur1);
            max0 = max(max0, cur0);
        }
        return max1 > max0;
    }
};
