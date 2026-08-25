/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head->next == NULL) {
        return head;
    }
    struct ListNode *ptr1 = head, *ptr2 = head;
    struct ListNode *temp1 = NULL, *temp2 = NULL;
    for (int i = 1; i < left; i++) {
        temp1 = ptr1;
        ptr1 = ptr1->next;
    }
    for (int i = 1; i < right; i++) {
        ptr2 = ptr2->next;
    }
    if (ptr2 != NULL)
        temp2 = ptr2->next;

    struct ListNode* temp = temp2;
    struct ListNode* ptr = ptr1;
    struct ListNode* next_temp = ptr1;
    for (int i = 1; i <= right - left + 1; i++) {
        next_temp = next_temp->next;
        ptr->next = temp;
        temp = ptr;
        ptr = next_temp;
    }
    if (temp1 != NULL)
        temp1->next = temp;
    else
        head = temp;
    return head;
}