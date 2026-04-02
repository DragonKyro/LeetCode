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
    long long minEnd(int n, int x) {
        long long res = x;
        n--;
        int bit = 0;
        for (int i = 0; i < 63; i++) {
            if (!((x >> i) & 1)) {
                if ((n >> bit) & 1) res |= 1LL << i;
                bit++;
            }
        }
        return res;
    }
};
