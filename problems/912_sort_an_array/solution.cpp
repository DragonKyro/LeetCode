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
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        vector<int> tmp;
        int i = l, j = mid + 1;
        while (i <= mid && j <= r)
            tmp.push_back(nums[i] <= nums[j] ? nums[i++] : nums[j++]);
        while (i <= mid) tmp.push_back(nums[i++]);
        while (j <= r) tmp.push_back(nums[j++]);
        copy(tmp.begin(), tmp.end(), nums.begin() + l);
    }
};
