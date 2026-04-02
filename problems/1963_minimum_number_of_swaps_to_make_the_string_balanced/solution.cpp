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
    int minSwaps(string s) {
        int unmatched = 0;
        for (char c : s) {
            if (c == '[') unmatched++;
            else if (unmatched > 0) unmatched--;
        }
        return (unmatched + 1) / 2;
    }
};
