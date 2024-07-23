#include<queue>
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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        queue<TreeNode*> Queue;
        Queue.push(root);
        vector<int> ans;
        while(Queue.size()>0){
            int n = Queue.size();
            while(n>0){
                TreeNode* temp = Queue.front();
                Queue.pop();
                if(n==1){
                    ans.push_back(temp->val);
                }
                if(temp->left!=nullptr){
                    Queue.push(temp->left);
                }
                if(temp->right!=nullptr){
                    Queue.push(temp->right);
                }
                n--;
            }
        }
        return ans;
    }
};