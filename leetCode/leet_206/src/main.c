/*
    Criado apenas para adicionar o código feito para solucionar o problema
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* Add(struct ListNode** list, int num) {
    struct ListNode* new = malloc(sizeof(struct ListNode));
    new->val = num;
    new->next = list;
    return new;
}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* list = NULL; // Cabeça da lista invertida

    while (head != NULL) {
        list = Add(list, head->val);
        head = head->next;
    }

    return list;
}

