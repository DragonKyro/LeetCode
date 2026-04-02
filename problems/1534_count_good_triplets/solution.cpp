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
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size(), count = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                if (abs(arr[i] - arr[j]) > a) continue;
                for (int k = j + 1; k < n; k++)
                    if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) count++;
            }
        return count;
    }
};
