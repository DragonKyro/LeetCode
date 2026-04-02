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
    vector<int> sumZero(int n) {
        vector<int> res;
        for (int i = 1; i < n; i++) res.push_back(i);
        int sum = 0;
        for (int x : res) sum += x;
        res.push_back(-sum);
        return res;
    }
};
