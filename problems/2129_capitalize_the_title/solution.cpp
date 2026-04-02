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
    string capitalizeTitle(string title) {
        istringstream iss(title);
        string word, result;
        while (iss >> word) {
            if (!result.empty()) result += ' ';
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (word.size() > 2) word[0] = toupper(word[0]);
            result += word;
        }
        return result;
    }
};
