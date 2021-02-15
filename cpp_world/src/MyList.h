#pragma once

#include "_std_includes.h"

struct ListElement {

	explicit ListElement(int value) : data(value), prev(nullptr), next(nullptr) {};

	int data;
	ListElement* prev;
	ListElement* next;
};

class MyList {
public:
	MyList(): head(nullptr), tail(nullptr), count(0) {};

	ListElement* push_back(int value);
	void pop_back();

	ListElement* push_front(int value);
	void pop_front();

	ListElement* get_nth_element(size_t n) const;

	void insert_after(ListElement* elem, int value);
	void remove_element(ListElement* elem);

	void print() const;

private:
	ListElement* head;
	ListElement* tail;
	size_t count;
};