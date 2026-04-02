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
    int countTriples(int n) {
        int count = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = a; b <= n; b++) {
                int cSq = a * a + b * b;
                int c = (int)sqrt(cSq);
                if (c <= n && c * c == cSq) count += (a != b) ? 2 : 1;
            }
        }
        return count;
    }
};
