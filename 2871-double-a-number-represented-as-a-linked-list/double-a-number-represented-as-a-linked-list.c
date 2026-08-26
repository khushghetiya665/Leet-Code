/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* doubleIt(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* next2 = head;
    while (head != NULL) {
        next2 = next2->next;
        head->next = prev;
        prev = head;
        head = next2;
    }
    head = prev;

    struct ListNode* temp = head;
    struct ListNode* temp_prev = NULL;
    int carry = 0;
    while (temp != NULL) {
        int value = 2 * temp->val + carry;
        temp->val = value % 10;
        carry = value / 10;
        temp_prev = temp;
        temp = temp->next;
    }
    if (carry != 0) {
        struct ListNode* new =
            (struct ListNode*)malloc(sizeof(struct ListNode));
        new->val = carry;
        new->next = NULL;
        temp_prev->next = new;
    }

    struct ListNode* prev1 = NULL;
    struct ListNode* next3 = head;
    while (head != NULL) {
        next3 = next3->next;
        head->next = prev1;
        prev1 = head;
        head = next3;
    }
    head = prev1;

    return head;
}