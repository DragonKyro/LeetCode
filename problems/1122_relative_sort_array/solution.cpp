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
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> order;
        for (int i = 0; i < arr2.size(); i++) order[arr2[i]] = i;
        sort(arr1.begin(), arr1.end(), [&](int a, int b) {
            bool aIn = order.count(a), bIn = order.count(b);
            if (aIn && bIn) return order[a] < order[b];
            if (aIn) return true;
            if (bIn) return false;
            return a < b;
        });
        return arr1;
    }
};
