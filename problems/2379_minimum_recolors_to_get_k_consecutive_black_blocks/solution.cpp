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
    int minimumRecolors(string blocks, int k) {
        int whites = 0;
        for (int i = 0; i < k; i++) if (blocks[i] == 'W') whites++;
        int minOps = whites;
        for (int i = k; i < blocks.size(); i++) {
            whites += (blocks[i] == 'W') - (blocks[i-k] == 'W');
            minOps = min(minOps, whites);
        }
        return minOps;
    }
};
