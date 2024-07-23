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
    vector<int> nums;
    void middlesearch(TreeNode* root){
        if(root==nullptr){
            return ;
        }
        middlesearch(root->left);
        nums.push_back(root->val);
        middlesearch(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        middlesearch(root);
        return nums[k-1];
    }
};