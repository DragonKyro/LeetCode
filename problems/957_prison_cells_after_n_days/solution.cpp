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
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        map<vector<int>, int> seen;
        while (n > 0) {
            if (seen.count(cells)) n %= seen[cells] - n;
            seen[cells] = n;
            if (n >= 1) {
                n--;
                vector<int> next(8, 0);
                for (int i = 1; i < 7; i++)
                    next[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
                cells = next;
            }
        }
        return cells;
    }
};
