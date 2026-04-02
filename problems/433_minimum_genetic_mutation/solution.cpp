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
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (!bankSet.count(endGene)) return -1;
        queue<pair<string,int>> q;
        unordered_set<string> visited;
        q.push({startGene, 0});
        visited.insert(startGene);
        string genes = "ACGT";
        while (!q.empty()) {
            auto [gene, steps] = q.front(); q.pop();
            if (gene == endGene) return steps;
            for (int i = 0; i < 8; i++) {
                char old = gene[i];
                for (char c : genes) {
                    gene[i] = c;
                    if (bankSet.count(gene) && !visited.count(gene)) {
                        visited.insert(gene);
                        q.push({gene, steps + 1});
                    }
                }
                gene[i] = old;
            }
        }
        return -1;
    }
};
