// Day2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>


using namespace std;
std::vector<string> readFile(std::string filename) {
    std::ifstream file(filename);
    std::string line;
    std::vector<string> lines;
    while (getline(file, line)) {
        //atoi will convert a string to its int representation (e.g. TryParse())
        int blah = std::atoi(line.c_str());
        lines.push_back(line);
        // <vector>.size() returns the current size of the vector
        //std::cout << nums.size();
        //std::cout << "\n";
        //std::cout << std::atoi(line.c_str()) + "\n";
    }

    return lines;
}

std::vector<string> splitStringIntoVector(std::istringstream& iss, char delim) {
std:vector<string> result;
    std::string item;
    while (std::getline(iss, item, delim)) {
        result.push_back(item);
    }
    return result;
}

int countString(std::string str, char checkCharacter) {
    int count = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == checkCharacter)
        {
            ++count;
        }
    }
    return count;
}

bool checkIfValid(std::string pass,char checkCharacter, int high, int low) {
    int count = 0;

    for (int i = 0; i < pass.size(); i++)
    {
        if (pass[i] == checkCharacter)
        {
            ++count;
        }
    }
    std::cout << low << "-" << high << " : " << count << "\n";
    if (count >= low && count <= high) {
        return true;
    }
    else {
        return false;
    }
}

bool checkIfValid2(std::string pass, char checkCharacter, int allowed, int notAllowed) {
    if (pass[allowed - 1] == checkCharacter && pass[notAllowed - 1] != checkCharacter) {
        return true;
    }
    else if (pass[allowed - 1] != checkCharacter && pass[notAllowed - 1] == checkCharacter) {
        return true;
    }
    else return false;
}


inline std::string BoolToString(bool b)
{
    return b ? "true" : "false";
}

int main()
{
    std::vector<string> lines = readFile("passwords.txt");
    int valid = 0;
    int invalid = 0;

    for (auto& s : lines) {
        std::istringstream iss(s);
        std::string item;
        std::vector<string> strSplit = splitStringIntoVector(iss, ' ');
        char checkCharacter = strSplit[1][0];
        std::istringstream rules(strSplit[0]);
        std::vector<string> rulesSplit = splitStringIntoVector(rules, '-');
        //std::cout << "High: " << rulesSplit[0] << "\nLow: " << rulesSplit[1] << "\n";
        int high = atoi(rulesSplit[1].c_str());
        int low = atoi(rulesSplit[0].c_str());

        //std::cout << "Checking Password: " << strSplit[2] << " - " << BoolToString(checkIfValid(strSplit[2], checkCharacter, high, low)) << "\n";

        if (checkIfValid2(strSplit[2], checkCharacter, high, low)) {
            valid++;
        }
        else {
            invalid++;
        }
    }
    std::cout << "Valid Passwords: " << valid << "\nInvalid Passwords: " << invalid << "\n";
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
