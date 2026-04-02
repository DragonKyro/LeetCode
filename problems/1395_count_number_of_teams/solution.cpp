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
    int numTeams(vector<int>& rating) {
        int n = rating.size(), res = 0;
        for (int j = 0; j < n; j++) {
            int ll = 0, lg = 0, rl = 0, rg = 0;
            for (int i = 0; i < j; i++) { if (rating[i] < rating[j]) ll++; else if (rating[i] > rating[j]) lg++; }
            for (int k = j+1; k < n; k++) { if (rating[k] < rating[j]) rl++; else if (rating[k] > rating[j]) rg++; }
            res += ll * rg + lg * rl;
        }
        return res;
    }
};
