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
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            unordered_set<int> row(matrix[i].begin(), matrix[i].end());
            if ((int)row.size() != n) return false;
            unordered_set<int> col;
            for (int j = 0; j < n; j++) col.insert(matrix[j][i]);
            if ((int)col.size() != n) return false;
        }
        return true;
    }
};
