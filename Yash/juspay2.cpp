#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> children;
    TreeNode(int value) : val(value) {}
};

// Helper function to perform BFS and return level-order traversal and depth information
void bfs(TreeNode* root, unordered_map<int, int>& depthCount, unordered_map<int, TreeNode*>& parentMap, unordered_map<int, int>& nodeDepth) {
    queue<TreeNode*> q;
    q.push(root);
    nodeDepth[root->val] = 0;  // root is at depth 0
    parentMap[root->val] = nullptr; // root has no parent
    
    // Perform BFS
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        int currentDepth = nodeDepth[node->val];
        depthCount[currentDepth]++;
        
        for (TreeNode* child : node->children) {
            nodeDepth[child->val] = currentDepth + 1;
            parentMap[child->val] = node;
            q.push(child);
        }
    }
}

// Function to perform level-order traversal of the forest
void levelOrderTraversal(vector<TreeNode*>& forest) {
    for (TreeNode* root : forest) {
        unordered_map<int, int> depthCount;  // To store count of nodes at each depth
        unordered_map<int, TreeNode*> parentMap;
        unordered_map<int, int> nodeDepth;  // To store depth of each node
        
        bfs(root, depthCount, parentMap, nodeDepth);
        
        // Print nodes at each level
        int maxDepth = *max_element(depthCount.begin(), depthCount.end(), 
                                   [](const pair<int, int>& p1, const pair<int, int>& p2) { return p1.second < p2.second; }).first;
        
        cout << "Level order traversal of tree rooted at " << root->val << ":\n";
        for (auto& p : depthCount) {
            cout << "Level " << p.first << ": ";
            for (TreeNode* node : nodeDepth) {
                if (node.second == p.first) {
                    cout << node.first << " ";
                }
            }
            cout << endl;
        }
    }
}

// Task 1: Find the depth with maximum nodes
int maxNodesDepth(const unordered_map<int, int>& depthCount) {
    int maxDepth = -1;
    int maxCount = -1;
    
    for (const auto& p : depthCount) {
        if (p.second > maxCount || (p.second == maxCount && p.first > maxDepth)) {
            maxDepth = p.first;
            maxCount = p.second;
        }
    }
    return maxDepth;
}

// Task 2: Find the nearest common ancestor (NCA) of two nodes in a tree
TreeNode* findNCA(int node1, int node2, unordered_map<int, TreeNode*>& parentMap, unordered_map<int, int>& nodeDepth) {
    // Bring both nodes to the same depth
    if (nodeDepth[node1] > nodeDepth[node2]) {
        swap(node1, node2);
    }
    
    // Move node2 upwards to the same depth as node1
    while (nodeDepth[node2] > nodeDepth[node1]) {
        node2 = parentMap[node2]->val;
    }
    
    // Now move both nodes up until they meet
    while (node1 != node2) {
        node1 = parentMap[node1]->val;
        node2 = parentMap[node2]->val;
    }
    
    return parentMap[node1];  // This is the NCA
}

int main() {
    // Example of a forest with two trees
    TreeNode* root1 = new TreeNode(0);
    TreeNode* child1 = new TreeNode(1);
    TreeNode* child2 = new TreeNode(2);
    root1->children.push_back(child1);
    root1->children.push_back(child2);
    
    TreeNode* root2 = new TreeNode(3);
    TreeNode* child3 = new TreeNode(4);
    root2->children.push_back(child3);
    
    vector<TreeNode*> forest = {root1, root2};
    
    // Level order traversal and printing nodes at each level
    levelOrderTraversal(forest);
    
    // Task 1: Finding the depth with maximum nodes
    unordered_map<int, int> depthCount;  // Store count of nodes at each depth
    unordered_map<int, TreeNode*> parentMap;
    unordered_map<int, int> nodeDepth;
    bfs(root1, depthCount, parentMap, nodeDepth);
    int maxDepth = maxNodesDepth(depthCount);
    cout << "Maximum depth with most nodes: " << maxDepth << endl;
    
    // Task 2: Finding the NCA of nodes 1 and 2
    TreeNode* nca = findNCA(1, 2, parentMap, nodeDepth);
    cout << "Nearest Common Ancestor of 1 and 2: " << nca->val << endl;

    return 0;
}
