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
    int longestMountain(vector<int>& arr) {
        int n = arr.size(), result = 0, i = 1;
        while (i < n - 1) {
            if (arr[i-1] < arr[i] && arr[i] > arr[i+1]) {
                int left = i, right = i;
                while (left > 0 && arr[left-1] < arr[left]) left--;
                while (right < n-1 && arr[right] > arr[right+1]) right++;
                result = max(result, right - left + 1);
                i = right;
            } else i++;
        }
        return result;
    }
};
