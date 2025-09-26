#include<iostream> 

using namespace std; 

struct ListNode{
public: 
      int val; 
      ListNode* next; 
      ListNode(): val(0), next(NULL){}
      ListNode(int _val): val(_val), next(NULL) {}
      ListNode(int _val, ListNode* _next): val(_val), next(_next){}
};

class Solution{
public: 
     ListNode* detectCycle(ListNode* head) {
       if(!head || !head->next) return NULL: 
       ListNode* slow = head; 
       ListNode* fast = head; 
       while(fast && fast->next) {
         fast = fast ->next->next; 
         slow = slow->next; 
         if(slow == fast){
           fast = head; 
           while(slow!=fast){
             slow = slow->next; 
             fast = fast->next; 
           }
           return slow; 
         }
       }
       return NULL; 
     }
};
int main(){
  ListNode* head = new ListNode(1); 
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
    // create cycle: 5 -> 3
  head->next->next->next->next->next = head->next->next;
  Solution sol; 
  ListNode* cycle = sol.detectCycle(head); 
  if(cycle) cout << "there is cycle at node " << cycle ->val << endl; 
  else cout << "there is no cycle in this LinkLsit" << endl ; 

  return 0; 
}
