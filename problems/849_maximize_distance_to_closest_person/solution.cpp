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
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size(), result = 0, last = -1;
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                if (last == -1) result = i;
                else result = max(result, (i - last) / 2);
                last = i;
            }
        }
        result = max(result, n - 1 - last);
        return result;
    }
};
