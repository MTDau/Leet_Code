#include <string>
#include <vector>
using std::vector;
class Solution
{
public:
    inline void build_adj(vector<vector<int>> &adj, const vector<vector<int>> &edges)
    {
        for (const auto &e : edges)
        {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    int dfs(int i, int parent, int edges, const vector<vector<int>> &adj)
    {
        if (edges < 0)
            return 0;
        int target{1}; // the node itself
        for (int j : adj[i])
        {
            if (j == parent)
                continue;
            target += dfs(j, i, edges - 1, adj);
        }
        return target;
    }
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k)
    {
        // Member in each tree is one less than total nodes in that tree.
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        // Get all the adjaction nodes to each node of the two tree
        vector<vector<int>> adj1(n), adj2(m);
        build_adj(adj1, edges1);
        build_adj(adj2, edges2);
        // Search for the node in the second tree that have the most target.
        int target2{};
        for (int i{}; i < m; i++)
            target2 = std::max(target2, dfs(i, -1, k - 1, adj2)); // use -1 as parent for node 0
        std::vector<int> ans(n);
        // Add the max targets in the second tree with all the target in the first tree.
        for (int i{}; i < n; i++)
            ans[i] = dfs(i, -1, k, adj1) + target2;
        return ans;
    }
};
