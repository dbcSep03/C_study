#include<vector>
#include<iostream>
#include<queue>
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
int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        queue<TreeNode*>temp;
        temp.push(root);
        int ans = 0;
        while(temp.size()>0){
            int temp1 = temp.size();
            while(temp1>0){
                TreeNode* temp_q = temp.front();
                temp.pop();
                if(temp_q->right!=nullptr){
                    temp.push(temp_q->right);
                }
                if(temp_q->left!=nullptr){
                    temp.push(temp_q->left);
                }
                temp1--;
            }
            ans++;
        }
        return ans;
    }