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
    vector<int> findEvenNumbers(vector<int>& digits) {
        int freq[10] = {};
        for (int d : digits) freq[d]++;
        vector<int> result;
        for (int num = 100; num < 1000; num += 2) {
            int needed[10] = {};
            int temp = num;
            while (temp > 0) { needed[temp % 10]++; temp /= 10; }
            bool valid = true;
            for (int i = 0; i < 10; i++) {
                if (needed[i] > freq[i]) { valid = false; break; }
            }
            if (valid) result.push_back(num);
        }
        return result;
    }
};
