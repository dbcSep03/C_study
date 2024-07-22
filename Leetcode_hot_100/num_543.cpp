#include <iostream>
#include<queue>
#include<stack>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
    int ans;
    int depth(TreeNode* rt){
        if (rt == NULL) {
            return 0; // 访问到空节点了，返回0
        }
        int L = depth(rt->left); // 左儿子为根的子树的深度
        int R = depth(rt->right); // 右儿子为根的子树的深度
        ans = max(ans, L + R + 1); // 计算d_node即L+R+1 并更新ans
        return max(L, R) + 1; // 返回该节点为根的子树的深度
    }
public:

    int depth_error(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return max(depth_error(root->left), depth_error(root->right))+1;
    }
    //解决不了根节点不是最长路径的情况
    int diameterOfBinaryTree_error(TreeNode* root) {
        int left = depth_error(root->left);
        int right = depth_error(root->right);
        return left + right;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }


};