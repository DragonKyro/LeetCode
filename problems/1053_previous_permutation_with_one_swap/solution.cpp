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
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size(), i = n - 2;
        while (i >= 0 && arr[i] <= arr[i + 1]) i--;
        if (i < 0) return arr;
        int j = n - 1;
        while (arr[j] >= arr[i]) j--;
        while (arr[j] == arr[j - 1]) j--;
        swap(arr[i], arr[j]);
        return arr;
    }
};
