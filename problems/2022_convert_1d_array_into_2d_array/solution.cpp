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
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if ((int)original.size() != m * n) return {};
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < (int)original.size(); i++) {
            result[i / n][i % n] = original[i];
        }
        return result;
    }
};
