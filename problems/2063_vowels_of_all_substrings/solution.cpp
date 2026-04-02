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
    long long countVowels(string word) {
        long long result = 0;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (string("aeiou").find(word[i]) != string::npos) {
                result += (long long)(i + 1) * (n - i);
            }
        }
        return result;
    }
};
