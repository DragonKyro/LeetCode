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
    int isWinner(vector<int>& p1, vector<int>& p2) {
        auto score = [](vector<int>& p) {
            int s = 0;
            for (int i = 0; i < p.size(); i++) {
                int m = (i>=1&&p[i-1]==10)||(i>=2&&p[i-2]==10) ? 2 : 1;
                s += m * p[i];
            }
            return s;
        };
        int s1 = score(p1), s2 = score(p2);
        return s1 > s2 ? 1 : s2 > s1 ? 2 : 0;
    }
};
