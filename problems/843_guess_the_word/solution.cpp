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
    void findSecretWord(vector<string>& words, Master& master) {
        auto matches = [](string& a, string& b) {
            int c = 0;
            for (int i = 0; i < a.size(); i++) if (a[i] == b[i]) c++;
            return c;
        };
        for (int t = 0; t < 10; t++) {
            string guess = words[rand() % words.size()];
            int m = master.guess(guess);
            if (m == 6) return;
            vector<string> next;
            for (auto& w : words) if (matches(w, guess) == m) next.push_back(w);
            words = next;
        }
    }
};
