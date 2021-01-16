#include "ListFunctions.h"

// Floyd's cycle detection algorithm
// Use two pointers that move through the chain at different pace - slow moves one step at a time and fast moves two steps.
// If there's a feedback, two pointers will eventually meet.
// Time complexity is linear proportional to number of elements chained. No additional space required except the two pointers.

// Additional comment: this is a solution returning if there is a loop or not.
// It can also be extended to find and return pointer to the ListElem at the beginning of the loop.
bool detect_feedback(const std::shared_ptr<ListElem>& head) {
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
