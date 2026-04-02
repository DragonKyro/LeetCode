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
    int minimumDeletions(string s) {
        int bCount = 0, result = 0;
        for (char c : s) {
            if (c == 'b') {
                bCount++;
            } else {
                result = min(result + 1, bCount);
            }
        }
        return result;
    }
};
