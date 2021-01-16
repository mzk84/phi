#pragma once

#include "ListElem.h"
#include "ListElemImpl.h"

// Implement a function that checks if there is a feedback loop in the list.

// Parameter: first ListElem in chain - head of the linked list of effects
// Return: true if feedback is detected, false if it is not
bool detect_feedback(const std::shared_ptr<ListElem>& head);
