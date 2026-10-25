#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    if (head == nullptr) {
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    Node* curr = head;
    Node* rest = head->next;
    curr->next = nullptr;

    Node* smallRest = nullptr;
    Node* largeRest = nullptr;

    llpivot(rest, smallRest, largeRest, pivot);

    if (curr->val <= pivot) {
        smaller = curr;
        curr->next = smallRest;
        larger = largeRest;
    } else {
        larger = curr;
        curr->next = largeRest;
        smaller = smallRest;
    }

    head = nullptr;
}
