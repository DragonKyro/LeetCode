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
    int binaryGap(int n) {
        int last = -1, result = 0;
        for (int i = 0; n > 0; i++, n >>= 1) {
            if (n & 1) {
                if (last >= 0) result = max(result, i - last);
                last = i;
            }
        }
        return result;
    }
};
