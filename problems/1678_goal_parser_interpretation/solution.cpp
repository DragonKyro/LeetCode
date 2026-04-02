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
    string interpret(string command) {
        string result;
        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'G') result += 'G';
            else if (command[i] == '(' && command[i + 1] == ')') { result += 'o'; i++; }
            else { result += "al"; i += 3; }
        }
        return result;
    }
};
