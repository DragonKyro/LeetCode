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
    int captureForts(vector<int>& forts) {
        int ans = 0, prev = -1;
        for (int i = 0; i < forts.size(); i++) {
            if (forts[i] != 0) {
                if (prev >= 0 && forts[prev] != forts[i]) ans = max(ans, i - prev - 1);
                prev = i;
            }
        }
        return ans;
    }
};
