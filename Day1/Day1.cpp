// Day1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <fstream>
#include <vector> 
using namespace std;


int main()
{
    std::ifstream file("input.txt");

    //vectors are like arrays, but the size is dynamic. They're basically the C++ equivalent of lists.
    std::vector<int> nums;
    std::string line;
   
    while (getline(file, line)) {
        
        //atoi will convert a string to its int representation (e.g. TryParse())
        int blah = std::atoi(line.c_str());
        nums.push_back(std::atoi(line.c_str()));
        // <vector>.size() returns the current size of the vector
        //std::cout << nums.size();
        std::cout << "\n";
        //std::cout << std::atoi(line.c_str()) + "\n";
    }

    // Equivalent of a foreach loop
    // auto is the equivalent of var in C#
    for (auto& x : nums) // access by reference to avoid copying
    {
        for (auto& y : nums) {
            for (auto& z : nums) {
                if (x + y + z == 2020) {
                std:cout << "Found the answer! \n" << x << " + " << y << " = 2020\n";
                    std::cout << x * y * z;
                    return 0;
                }
            }
        }
    }


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
