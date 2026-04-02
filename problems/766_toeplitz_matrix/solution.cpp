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
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = 1; i < (int)matrix.size(); i++)
            for (int j = 1; j < (int)matrix[0].size(); j++)
                if (matrix[i][j] != matrix[i-1][j-1]) return false;
        return true;
    }
};
