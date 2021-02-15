#pragma once
#include "MyList.h"

#include "gtest/gtest.h"

TEST(MyListTest, Test1) {
    MyList myList;
    auto elem1 = myList.push_back(3);
    auto elem2 = myList.push_back(4);
    auto elem3 = myList.push_back(5);
    auto elem4 = myList.push_back(6);
    auto elem5 = myList.push_back(7);
    myList.print();

    myList.insert_after(elem3, 55);
    myList.print();

    myList.pop_back();
    myList.print();

    myList.pop_front();
    myList.print();

    myList.push_front(1);
    myList.print();

    myList.remove_element(elem4);
    myList.print();
}
