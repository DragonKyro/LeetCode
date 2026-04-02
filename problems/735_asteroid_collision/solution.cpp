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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        for (int a : asteroids) {
            bool alive = true;
            while (alive && a < 0 && !stack.empty() && stack.back() > 0) {
                if (stack.back() < -a) stack.pop_back();
                else if (stack.back() == -a) { stack.pop_back(); alive = false; }
                else alive = false;
            }
            if (alive) stack.push_back(a);
        }
        return stack;
    }
};
