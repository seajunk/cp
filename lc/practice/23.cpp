#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* mergeKLists(vector<ListNode*>& lists) {

    make_heap(lists.begin(), lists.end(), [](auto l, auto r){
            return l->val < r->val;
            });

        
    while(lists.size()){

    }

    return NULL;
}
