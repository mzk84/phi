#pragma once

#include "ListFunctions.h"

#include "gtest/gtest.h"

TEST(DetectFeedbackTest, TestNullptr) {
	bool result;
	ASSERT_NO_THROW(result = detect_feedback(nullptr));
	ASSERT_FALSE(result);
}

TEST(DetectFeedbackTest, TestSingleElement) {
	std::shared_ptr<ListElem> effect1 = std::make_shared<ListElemImpl>("effect1");
	effect1->next = nullptr;

	bool result;
	ASSERT_NO_THROW(result = detect_feedback(effect1));
	ASSERT_FALSE(result);
}

TEST(DetectFeedbackTest, TestNoFeedback) {
	std::shared_ptr<ListElem> effect1 = std::make_shared<ListElemImpl>("effect1");
	std::shared_ptr<ListElem> effect2 = std::make_shared<ListElemImpl>("effect2");
	std::shared_ptr<ListElem> effect3 = std::make_shared<ListElemImpl>("effect3");
	std::shared_ptr<ListElem> effect4 = std::make_shared<ListElemImpl>("effect4");
	std::shared_ptr<ListElem> effect5 = std::make_shared<ListElemImpl>("effect5");

	// Chain without a feedback
	effect1->next = effect2;
	effect2->next = effect3;
	effect3->next = effect4;
	effect4->next = effect5;
	effect5->next = nullptr;

	bool result;
	ASSERT_NO_THROW(result = detect_feedback(effect1));
	ASSERT_FALSE(result);
}

TEST(DetectFeedbackTest, TestWithFeedback) {
	std::shared_ptr<ListElem> effect1 = std::make_shared<ListElemImpl>("effect1");
	std::shared_ptr<ListElem> effect2 = std::make_shared<ListElemImpl>("effect2");
	std::shared_ptr<ListElem> effect3 = std::make_shared<ListElemImpl>("effect3");
	std::shared_ptr<ListElem> effect4 = std::make_shared<ListElemImpl>("effect4");
	std::shared_ptr<ListElem> effect5 = std::make_shared<ListElemImpl>("effect5");

	// Chain with a feedback from effect5 to effect2
	effect1->next = effect2;
	effect2->next = effect3;
	effect3->next = effect4;
	effect4->next = effect5;
	effect5->next = effect2;

	bool result;
	ASSERT_NO_THROW(result = detect_feedback(effect1));
	ASSERT_TRUE(result);
}

TEST(DetectFeedbackTest, TestWithFeedbackCopyPtr) {
	std::shared_ptr<ListElem> effect1 = std::make_shared<ListElemImpl>("effect1");
	std::shared_ptr<ListElem> effect2 = std::make_shared<ListElemImpl>("effect2");
	std::shared_ptr<ListElem> effect3 = std::make_shared<ListElemImpl>("effect3");
	std::shared_ptr<ListElem> effect4 = effect2;

	// Chain with a feedback from effect3 to effect2
	effect1->next = effect2;
	effect2->next = effect3;
	effect3->next = effect4;

	bool result;
	ASSERT_NO_THROW(result = detect_feedback(effect1));
	ASSERT_TRUE(result);
}
