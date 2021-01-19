#pragma once
#include "ListFunctions.h"

#include "gtest/gtest.h"

TEST(ListFunctionsTest, TestNullptr) {
	bool result;
	ASSERT_NO_THROW(result = detectFeedback(nullptr));
	ASSERT_FALSE(result);
}

TEST(ListFunctionsTest, TestSingleElement) {
	std::shared_ptr<ListElem> elem1 = std::make_shared<ListElemImpl>("elem1");
    elem1->next = nullptr;

	bool result;
	ASSERT_NO_THROW(result = detectFeedback(elem1));
	ASSERT_FALSE(result);
}

TEST(ListFunctionsTest, TestNoFeedback) {
	std::shared_ptr<ListElem> elem1 = std::make_shared<ListElemImpl>("elem1");
	std::shared_ptr<ListElem> elem2 = std::make_shared<ListElemImpl>("elem2");
	std::shared_ptr<ListElem> elem3 = std::make_shared<ListElemImpl>("elem3");
	std::shared_ptr<ListElem> elem4 = std::make_shared<ListElemImpl>("elem4");
	std::shared_ptr<ListElem> elem5 = std::make_shared<ListElemImpl>("elem5");

	// No feedback
	elem1->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	elem4->next = elem5;
	elem5->next = nullptr;

	bool result;
	ASSERT_NO_THROW(result = detectFeedback(elem1));
	ASSERT_FALSE(result);
}

TEST(ListFunctionsTest, TestWithFeedback) {
	std::shared_ptr<ListElem> elem1 = std::make_shared<ListElemImpl>("elem1");
	std::shared_ptr<ListElem> elem2 = std::make_shared<ListElemImpl>("elem2");
	std::shared_ptr<ListElem> elem3 = std::make_shared<ListElemImpl>("elem3");
	std::shared_ptr<ListElem> elem4 = std::make_shared<ListElemImpl>("elem4");
	std::shared_ptr<ListElem> elem5 = std::make_shared<ListElemImpl>("elem5");

	// Feedback from elem5 to elem2
	elem1->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	elem4->next = elem5;
	elem5->next = elem2;

	bool result;
	ASSERT_NO_THROW(result = detectFeedback(elem1));
	ASSERT_TRUE(result);
}

TEST(ListFunctionsTest, TestWithFeedbackCopyPtr) {
	std::shared_ptr<ListElem> elem1 = std::make_shared<ListElemImpl>("elem1");
	std::shared_ptr<ListElem> elem2 = std::make_shared<ListElemImpl>("elem2");
	std::shared_ptr<ListElem> elem3 = std::make_shared<ListElemImpl>("elem3");
	std::shared_ptr<ListElem> elem4 = elem2;

	// Feedback from elem3 to elem2
	elem1->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;

	bool result;
	ASSERT_NO_THROW(result = detectFeedback(elem1));
	ASSERT_TRUE(result);
}
