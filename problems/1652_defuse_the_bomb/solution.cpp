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
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        if (k == 0) return result;
        for (int i = 0; i < n; i++) {
            if (k > 0) {
                for (int j = 1; j <= k; j++) result[i] += code[(i + j) % n];
            } else {
                for (int j = k; j < 0; j++) result[i] += code[((i + j) % n + n) % n];
            }
        }
        return result;
    }
};
