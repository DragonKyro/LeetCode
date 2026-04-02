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
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        auto check = [&](int target) -> int {
            int rotTop = 0, rotBot = 0;
            for (int i = 0; i < tops.size(); i++) {
                if (tops[i] != target && bottoms[i] != target) return -1;
                else if (tops[i] != target) rotTop++;
                else if (bottoms[i] != target) rotBot++;
            }
            return min(rotTop, rotBot);
        };
        int res = check(tops[0]);
        if (res != -1) return res;
        return check(bottoms[0]);
    }
};
