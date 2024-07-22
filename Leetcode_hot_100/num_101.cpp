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
public:
    //无法解决子树不对称一半为零的情况
    bool isSymmetric_wrong(TreeNode* root) {
        if(root->left==nullptr and root->right==nullptr){
            return true;
        }
        if(root->left==nullptr or root->right==nullptr){
            return false;
        }
        queue<TreeNode*> Q;
        Q.push(root->left);
        Q.push(root->right);
        while(Q.size()>0){
            int n = Q.size();
            int all = n;
            if(n%2==1){
                return false;
            }
            stack<int> nums_all;
            while(n>0){
                TreeNode* temp = Q.front();
                Q.pop();
                if(n > all/2){
                    nums_all.push(temp->val);
                }
                else{
                    int nums = nums_all.top();
                    nums_all.pop();
                    if (nums != temp->val){
                        return false;
                    }
                }
                n--;
                if(temp->right==nullptr and temp->left == nullptr){
                    continue;
                }
                if(temp->right!= nullptr){
                    Q.push(temp->right);
                }
                else{
                    Q.push(new TreeNode(0));
                }
                if(temp->left!=nullptr){
                    Q.push(temp->left);
                }
                else{
                    Q.push(new TreeNode(0));
                }
            }
        }
        return true;
    }
};