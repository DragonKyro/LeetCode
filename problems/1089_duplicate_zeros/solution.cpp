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
    void duplicateZeros(vector<int>& arr) {
        int zeros = count(arr.begin(), arr.end(), 0);
        int n = arr.size(), i = n - 1, j = n + zeros - 1;
        while (i < j) {
            if (arr[i] == 0) {
                if (j < n) arr[j] = 0;
                j--;
                if (j < n) arr[j] = 0;
            } else {
                if (j < n) arr[j] = arr[i];
            }
            i--; j--;
        }
    }
};
