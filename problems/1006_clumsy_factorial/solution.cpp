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
    int clumsy(int n) {
        vector<int> stack = {n};
        n--;
        int idx = 0;
        while (n > 0) {
            switch (idx % 4) {
                case 0: stack.back() *= n; break;
                case 1: stack.back() /= n; break;
                case 2: stack.push_back(n); break;
                case 3: stack.push_back(-n); break;
            }
            idx++;
            n--;
        }
        return accumulate(stack.begin(), stack.end(), 0);
    }
};
