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
    int countArrangement(int n) {
        function<int(int, int)> backtrack = [&](int pos, int visited) -> int {
            if (pos > n) return 1;
            int count = 0;
            for (int i = 1; i <= n; i++) {
                if (!(visited & (1 << i)) && (i % pos == 0 || pos % i == 0))
                    count += backtrack(pos + 1, visited | (1 << i));
            }
            return count;
        };
        return backtrack(1, 0);
    }
};
