#include<vector>
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
    //很容易想到前序遍历 但是需要用一个 vector<TreeNode* >保存后 在连接起来 引用传递等
    void flatten(TreeNode* root) {
        vector<TreeNode*> l;
        formsearch(root, l);
        for(int n =1 ;n<l.size(); n++){
            TreeNode *prev = l[n-1], *curr = l[n];
            prev->left = nullptr;
            prev->right = curr;
        }

    }
    void formsearch(TreeNode* root, vector<TreeNode*> &l){
        if(root==nullptr){
            return;
        }
        l.push_back(root);
        formsearch(root->left, l);
        formsearch(root->right, l);
    }
};