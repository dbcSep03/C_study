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
    //无法解决二级子节点不符合的情况 如[5,4,6,null,null,3,7]
    bool isValidBST_error(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        return helper_error(root) and isValidBST_error(root->left) and isValidBST_error(root->right);
    }
    bool helper_error(TreeNode* root){
        return check_left(root) and check_right(root);
    }
    int getnum(TreeNode* root){
        return root->val;
    }
    bool check_left(TreeNode* root){  
        if(!root->left){
            return true;
        }
        return getnum(root->left)<getnum(root);
    }
    bool check_right(TreeNode* root){
        if(!root->right){
            return true;
        }
        return getnum(root)<getnum(root->right);
    }
};