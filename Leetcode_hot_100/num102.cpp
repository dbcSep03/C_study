#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr){
            return {};
        }
        queue<TreeNode*> tree;
        tree.push(root);
        while(tree.size()>0){
            int n = tree.size();
            vector<int> ans_temp;
            while(n>0){
                TreeNode* node = tree.front();
                tree.pop();
                ans_temp.push_back(node->val);
                if(node->left!=nullptr){
                    tree.push(node->left);
                }
                if(node->right!=nullptr){
                    tree.push(node->right);
                }
                n--;
            }
            ans.push_back(ans_temp);
        }
        return ans;
    }
};