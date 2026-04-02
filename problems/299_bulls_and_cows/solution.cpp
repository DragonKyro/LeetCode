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
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        int counts[10] = {};
        for (int i = 0; i < secret.size(); i++) {
            int s = secret[i] - '0', g = guess[i] - '0';
            if (s == g) {
                bulls++;
            } else {
                if (counts[s] < 0) cows++;
                counts[s]++;
                if (counts[g] > 0) cows++;
                counts[g]--;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
