#include "MyList.h"

ListElement* MyList::push_back(int value) {
	ListElement* elem = new ListElement(value);
	if (tail) {
		elem->prev = tail;
		tail->next = elem;
		tail = elem;
	}
	else {
		tail = elem;
		head = elem;
	}
	tail->next = nullptr;
	count++;
	return elem;
}

void MyList::pop_back() {
	if (tail) {
		auto old_tail = tail;
		tail = old_tail->prev;
		tail->next = nullptr;
		delete old_tail;
		count--;
	}
}

ListElement* MyList::push_front(int value) {
	ListElement* elem = new ListElement(value);
	if (head) {
		head->prev = elem;
		elem->next = head;
		head = elem;
	}
	else {
		head = elem;
		tail = elem;
	}
	count++;
	return elem;
}

void MyList::pop_front() {
	if (head) {
		auto old_head = head;
		head = old_head->next;
		delete old_head;
		count--;
	}
}

ListElement* MyList::get_nth_element(size_t n) const {
	if (n > count)
		return nullptr;

	size_t i = 0;
	ListElement* iter = head;
	while (i != n) {
		iter = iter->next;
		i++;
	}
	return iter;
}

void MyList::insert_after(ListElement* elem, int value) {
	ListElement* iter = head;
	while (iter) {
		if (iter == elem) {
			ListElement* new_elem = new ListElement(value);
			auto saved_next = iter->next;
			iter->next = new_elem;
			new_elem->prev = iter;
			new_elem->next = saved_next;
			break;
		}
		iter = iter->next;
	}
}

void MyList::remove_element(ListElement* elem) {
	if (elem == head) {
		pop_front();
	}
	else if (elem == tail) {
		pop_back();
	}
	else {
		ListElement* iter = head;
		while (iter) {
			if (iter == elem) {
				auto prev = iter->prev;
				auto next = iter->next;
				prev->next = next;
				if (next)
					next->prev = prev;
				break;
			}
			iter = iter->next;
		}
	}
}

void MyList::print() const {
	ListElement* iter = head;
	std::cout << "\n";
	while (iter) {
		std::cout << iter->data << " ";
		iter = iter->next;
	}
	std::cout << "\n";
}
