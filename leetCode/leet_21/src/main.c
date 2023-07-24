#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void Add(struct ListNode *head, int val);
void Write(struct ListNode *head);
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);

int main(){   
    struct ListNode *list1, *list2, *head;

    list1 = malloc (sizeof(struct ListNode));
    list1->next = NULL;
    Add(list1, 4);
    Add(list1, 2);
    Add(list1, 1);
    Write(list1);

    list2 = malloc (sizeof(struct ListNode));
    list2->next = NULL;
    Add(list2, 4);
    Add(list2, 3);
    Add(list2, 1);
    Write(list2);

    head = mergeTwoLists(list1, list2);

    Write(head);

    return 0;
}

void Add(struct ListNode* head, int val) {
    struct ListNode *aux, *new = malloc(sizeof(struct ListNode));
    new->val = val;

    if( head == NULL){
        new->next = NULL;
        head = new;
    } else if( new->val  < head->val ){
        new->next = head;
        head = new;
            } else{
                aux = head;
                while( aux->next && new->val > aux->next->val) aux = aux->next;

                new->next = aux->next;
                aux->next = new;
            }  


}
void Write(struct ListNode *head){
    while(head != NULL){
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *head = malloc (sizeof(struct ListNode));
    

    while(list1 != NULL && list2 != NULL){
        if(list1->val <= list2->val){
            Add(head, list1->val);
            list1 = list1->next;
        }else{
            Add(head, list2->val);
            list2 = list2->next;
        }
    }
    while(list1 != NULL){
        Add(head, list1->val);
        list1 = list1->next;
    }
    
    while(list2 != NULL){
        Add(head, list2->val);
        list2 = list2->next;
    }
    
    return head;
}