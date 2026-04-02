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
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        int maxMoves = max(stones[n-1] - stones[1] - n + 2, stones[n-2] - stones[0] - n + 2);
        int minMoves = n, j = 0;
        for (int i = 0; i < n; i++) {
            while (j + 1 < n && stones[j + 1] - stones[i] + 1 <= n) j++;
            int already = j - i + 1;
            if (already == n - 1 && stones[j] - stones[i] + 1 == n - 1)
                minMoves = min(minMoves, 2);
            else
                minMoves = min(minMoves, n - already);
        }
        return {minMoves, maxMoves};
    }
};
