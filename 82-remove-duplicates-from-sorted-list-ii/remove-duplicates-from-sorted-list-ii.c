/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *ptr1 = head, *ptr2 = head->next, *temp = NULL;
    while (ptr2 != NULL) {
        int flag = 0;
        while (ptr2 != NULL && ptr1->val == ptr2->val) {
            struct ListNode* duplicate = ptr2;
            ptr2 = ptr2->next;
            free(duplicate);
            ptr1->next = ptr2;
            flag = 1;
        }

        if (flag == 1) {
            struct ListNode* delete = ptr1;
            ptr1 = ptr2;

            free(delete);

            if (temp != NULL)
                temp->next = ptr1;
            else {
                head = ptr1;
            }

            if (ptr1 != NULL) {
                ptr2 = ptr1->next;
            } else {
                ptr2 = NULL;
            }
        } else {
            temp = ptr1;
            ptr1 = ptr2;
            if (ptr2 != NULL)
                ptr2 = ptr2->next;
            else
                ptr2 = NULL;
        }
    }
    return head;
}