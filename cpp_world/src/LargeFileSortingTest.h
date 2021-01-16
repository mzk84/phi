#pragma once
#include "LargeFileSorting.h"

void LargeFileSortingTest() {
    std::cout << "\n************************************************************\n";
    std::cout << "Large File Sorting Test\n\n";

    std::string inputFile = "../data/LargeFileExample.txt";
    sortLargeFile(inputFile);
}
