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
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int trim = n / 20;
        double sum = 0;
        for (int i = trim; i < n - trim; i++) {
            sum += arr[i];
        }
        return sum / (n - 2 * trim);
    }
};
