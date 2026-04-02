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
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total = 0;
        for (int c : chalk) total += c;
        k %= total;
        for (int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) return i;
            k -= chalk[i];
        }
        return 0;
    }
};
