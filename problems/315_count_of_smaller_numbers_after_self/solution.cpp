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
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0), idx(n), tempIdx(n);
        iota(idx.begin(), idx.end(), 0);
        function<void(int, int)> mergeSort = [&](int lo, int hi) {
            if (lo >= hi) return;
            int mid = lo + (hi - lo) / 2;
            mergeSort(lo, mid);
            mergeSort(mid + 1, hi);
            int i = lo, j = mid + 1, k = lo;
            while (i <= mid && j <= hi) {
                if (nums[idx[i]] <= nums[idx[j]]) {
                    res[idx[i]] += j - mid - 1;
                    tempIdx[k++] = idx[i++];
                } else {
                    tempIdx[k++] = idx[j++];
                }
            }
            while (i <= mid) {
                res[idx[i]] += j - mid - 1;
                tempIdx[k++] = idx[i++];
            }
            while (j <= hi) tempIdx[k++] = idx[j++];
            for (int p = lo; p <= hi; p++) idx[p] = tempIdx[p];
        };
        mergeSort(0, n - 1);
        return res;
    }
};
