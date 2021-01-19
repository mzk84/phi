#include "ListFunctions.h"

// Floyd's cycle detection algorithm
// Use two pointers that move through the list at different pace - slow moves one step at a time and fast moves two steps.
// If there's a feedback, two pointers will eventually meet.
// Time complexity is linear proportional to number of elements. No additional space required except the two pointers.
bool detectFeedback(const std::shared_ptr<ListElem>& head) {
    std::shared_ptr<ListElem> fast = head, slow = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) {
            return true;
        }
    }
    return false;
}
