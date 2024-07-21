#include <iostream>
#include <unordered_map>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> temp;
        int interected = 0;
        while(headA!=NULL){
            temp[headA] = headA->val;
            headA = headA->next;
        }
        while(headB!=NULL){
            if(temp.find(headB)!=temp.end()){
                return headB;
            }
            headB = headB->next;
        }
        return 0;

    }
};