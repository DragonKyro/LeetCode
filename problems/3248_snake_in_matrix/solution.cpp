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
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int r = 0, c = 0;
        for (auto& cmd : commands) {
            if (cmd == "UP") r--;
            else if (cmd == "DOWN") r++;
            else if (cmd == "LEFT") c--;
            else c++;
        }
        return r * n + c;
    }
};
