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
    string validIPAddress(string queryIP) {
        if (queryIP.find('.') != string::npos) {
            stringstream ss(queryIP);
            string part;
            int count = 0;
            while (getline(ss, part, '.')) {
                count++;
                if (part.empty() || part.size() > 3) return "Neither";
                for (char c : part) if (!isdigit(c)) return "Neither";
                if (part.size() > 1 && part[0] == '0') return "Neither";
                if (stoi(part) > 255) return "Neither";
            }
            if (count != 4 || queryIP.back() == '.') return "Neither";
            return "IPv4";
        } else if (queryIP.find(':') != string::npos) {
            stringstream ss(queryIP);
            string part;
            int count = 0;
            while (getline(ss, part, ':')) {
                count++;
                if (part.empty() || part.size() > 4) return "Neither";
                for (char c : part) if (!isxdigit(c)) return "Neither";
            }
            if (count != 8 || queryIP.back() == ':') return "Neither";
            return "IPv6";
        }
        return "Neither";
    }
};
