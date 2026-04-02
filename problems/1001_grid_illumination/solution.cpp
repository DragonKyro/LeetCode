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
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int,int> rows, cols, d1, d2;
        set<pair<int,int>> lampSet;
        for (auto& l : lamps) {
            if (lampSet.insert({l[0], l[1]}).second) {
                rows[l[0]]++; cols[l[1]]++;
                d1[l[0]-l[1]]++; d2[l[0]+l[1]]++;
            }
        }
        vector<int> ans;
        for (auto& q : queries) {
            int r = q[0], c = q[1];
            ans.push_back(rows[r] > 0 || cols[c] > 0 || d1[r-c] > 0 || d2[r+c] > 0 ? 1 : 0);
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    int nr = r+dr, nc = c+dc;
                    if (lampSet.erase({nr, nc})) {
                        rows[nr]--; cols[nc]--;
                        d1[nr-nc]--; d2[nr+nc]--;
                    }
                }
            }
        }
        return ans;
    }
};
