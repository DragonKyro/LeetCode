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
    vector<int> pathInZigZagTree(int label) {
        vector<int> result;
        int node = label;
        while (node >= 1) {
            result.push_back(node);
            int level = (int)(log2(node));
            int levelMax = (1 << (level + 1)) - 1;
            int levelMin = 1 << level;
            node = (levelMax + levelMin - node) / 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
