/*
Apenas para adicionar o código do problema
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *auxA = headA;
    struct ListNode *auxB = headB;

    while (auxA != NULL){
        while(auxB != NULL) {

        if (auxA == auxB) return auxA;
            auxB = auxB->next;
        }
        auxB = headB;
        auxA = auxA->next;
    }
    return NULL;
}
