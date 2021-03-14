// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// same as how many levels of the tree
class Solution {
public:
    int maxDepth(Node* root) {
        // my solution: recursive DFS
        // if (!root)
        //     return 0;
        // int m = 0;
        // vector<Node*> ch = root->children;
        // for (int i = 0; i < ch.size(); i++) {
        //     m = max(m, maxDepth(ch[i]));
        // }
        // //for (auto child : root->children) depth = max(depth, maxDepth(child));
        // return 1 + m;
        
        // solution 2: BFS using queue
        // basically push each level node to queue 
        if (!root)
            return 0;
        
        queue<Node*> q;
        q.push(root);
        int dep = 0;
        while(!q.empty()) {
            int size = q.size(); // number of nodes of this level
            
            for (int i = 0; i < size; i++) {
                Node* c = q.front();
                q.pop();
                for (auto n: c->children)
                    if(n) // don't have to actually check since null won't count into size of vector
                        q.push(n); // push child if it's not null
            }
            
            dep++;
        }
        
        return dep;
   