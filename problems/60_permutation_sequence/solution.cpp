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
    string getPermutation(int n, int k) {
        vector<int> numbers;
        vector<int> factorial(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i;
            numbers.push_back(i);
        }
        k--;
        string result;
        for (int i = n; i > 0; i--) {
            int idx = k / factorial[i - 1];
            result += to_string(numbers[idx]);
            numbers.erase(numbers.begin() + idx);
            k %= factorial[i - 1];
        }
        return result;
    }
};
