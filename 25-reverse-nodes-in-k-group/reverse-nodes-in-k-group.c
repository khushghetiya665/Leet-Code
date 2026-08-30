/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* ptr = head;
    int count = 0;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    int loop = count / k;
    struct ListNode *ptr1 = NULL, *ptr2 = head, *temp = head;
    struct ListNode *first = NULL, *prev_first = NULL;
    for (int i = 1; i <= loop; i++) {
        int m = 0;
        for (int j = 1; j <= k; j++) {
            if (m == 0) {
                prev_first = first;
                first = temp;
                m = 1;
            }
            ptr2 = ptr2->next;
            temp->next = ptr1;
            ptr1 = temp;
            temp = ptr2;
        }
        if (prev_first != NULL)
            prev_first->next = ptr1;
        else
            head = ptr1;
    }
    if (first != NULL)
        first->next = ptr2;

    return head;
}