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
    int findIntegers(int n) {
        string bits;
        for (int x = n; x > 0; x >>= 1) bits = (char)('0' + (x & 1)) + bits;
        int len = bits.size();
        vector<int> fib(len + 2);
        fib[0] = 1; fib[1] = 2;
        for (int i = 2; i <= len; i++) fib[i] = fib[i-1] + fib[i-2];
        int result = 0, prevBit = 0;
        for (int i = 0; i < len; i++) {
            if (bits[i] == '1') {
                result += fib[len - 1 - i];
                if (prevBit == 1) return result;
                prevBit = 1;
            } else {
                prevBit = 0;
            }
        }
        return result + 1;
    }
};
