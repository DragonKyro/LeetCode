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
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orig = image[sr][sc];
        if (orig != color) dfs(image, sr, sc, orig, color);
        return image;
    }

    void dfs(vector<vector<int>>& image, int r, int c, int orig, int color) {
        if (r < 0 || r >= (int)image.size() || c < 0 || c >= (int)image[0].size() || image[r][c] != orig) return;
        image[r][c] = color;
        dfs(image, r+1, c, orig, color);
        dfs(image, r-1, c, orig, color);
        dfs(image, r, c+1, orig, color);
        dfs(image, r, c-1, orig, color);
    }
};
