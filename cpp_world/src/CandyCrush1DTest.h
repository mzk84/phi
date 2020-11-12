#pragma once
#include "CandyCrush1D.h"

void CandyCrush1DTest() {
    std::cout << "\n************************************************************\n";
    std::cout << "Candy Crush 1D Test\n\n";

    std::string input1 = "abbcccbbbaaeefffre";
    std::string input2 = "abbcaabadddaeeffft";
    std::string input3 = "abcdef";
    std::string input4 = "abbaabgggffefee";

    std::cout << "Reducing input: " << input1 << ". Result is:" << CandyCrush1D(input1) << ".\n";
    std::cout << "Reducing input: " << input2 << ". Result is:" << CandyCrush1D(input2) << ".\n";
    std::cout << "Reducing input: " << input3 << ". Result is:" << CandyCrush1D(input3) << ".\n";
    std::cout << "Reducing input: " << input4 << ". Result is:" << CandyCrush1D(input4) << ".\n";
}
