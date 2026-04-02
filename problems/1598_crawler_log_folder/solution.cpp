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
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for (auto& log : logs) {
            if (log == "../") depth = max(0, depth - 1);
            else if (log != "./") depth++;
        }
        return depth;
    }
};
