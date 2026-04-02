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
    int reinitializePermutation(int n) {
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 0);
        vector<int> target = perm;
        int ops = 0;
        do {
            ops++;
            vector<int> arr(n);
            for (int i = 0; i < n; i++) {
                arr[i] = (i % 2 == 0) ? perm[i / 2] : perm[n / 2 + (i - 1) / 2];
            }
            perm = arr;
        } while (perm != target);
        return ops;
    }
};
