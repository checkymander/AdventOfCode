// Day7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;
std::vector<string> readFile(std::string filename) {
    std::ifstream file(filename);
    std::string line;
    std::vector<string> lines;
    while (getline(file, line)) {
        lines.push_back(line);
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

void part1() {
    std::vector<string> instructions = readFile("instructions.txt");
    std::vector<string> runInstructions;
    std::vector<int> runInstructions2;
    int accVal = 0;
    int i = 0;
    while (i < instructions.size()) {
        //if (std::count(runInstructions.begin(), runInstructions.end(), instructions[i])) {
        //    std::cout << "[REPEAT] " << accVal << " " << runInstructions.size() << " " << instructions[i];
        //    exit(0);
        //}
        if (std::count(runInstructions2.begin(), runInstructions2.end(), i)) {
            std::cout << "[REPEAT] " << accVal;
            exit(0);
        }
        runInstructions2.push_back(i);



        std::istringstream instructionStream(instructions[i]);
        std::vector<string> instruction = splitStringIntoVector(instructionStream, ' ');
        std::cout << instructions[i] << "\n";

        int value = 0;
        if (instruction[0] == "jmp") {
            switch (instruction[1][0]) {
            case '+':
                value = atoi(instruction[1].substr(1).c_str());
                //std::cout << "[Adding] Previous Value: " << i << "\n";
                i += value;
                //std::cout << "[Value] Value: " << value << "\n";
                //std::cout << "[Adding] Current Value: " << i << "\n";
                break;
            case '-':
                //std::cout << "[Subtracting] Previous Value: " << i << "\n";
                value = atoi(instruction[1].substr(1).c_str());
                i -= value;
                //std::cout << "[Subtracting] Current Value: " << i << "\n";
                break;
            }
        }
        else if (instruction[0] == "acc") {
            switch (instruction[1][0]) {
            case '+':
                value = atoi(instruction[1].substr(1).c_str());
                accVal += value;
                i++;
                break;
            case '-':
                value = atoi(instruction[1].substr(1).c_str());
                accVal -= value;
                i++;
                break;
            }
        }
        else if (instruction[0] == "nop") {
            //Don't do anything!
            i++;
        }
        else {
            std::cout << "[Instruction] Value: " << instruction[0] << "\n";
        }
        runInstructions.push_back(instructions[i]);
        //std::cout << "[Current i Value]: " << i << " [Current accVal]: " << accVal << "\n";
    }
}

bool part2(int change) {
    std::vector<string> instructions = readFile("instructions.txt");
    std::vector<string> runInstructions;
    std::vector<int> runInstructions2;
    int accVal = 0;
    int i = 0;
    while (i < instructions.size()-1) {
        //if (std::count(runInstructions.begin(), runInstructions.end(), instructions[i])) {
        //    std::cout << "[REPEAT] " << accVal << " " << runInstructions.size() << " " << instructions[i];
        //    exit(0);
        //}
        if (std::count(runInstructions2.begin(), runInstructions2.end(), i)) {
            return false;
        }
        runInstructions2.push_back(i);



        std::istringstream instructionStream(instructions[i]);
        std::vector<string> instruction = splitStringIntoVector(instructionStream, ' ');
        //std::cout << instructions[i] << "\n";
        std::string curInstruction = instruction[0];


        if (i == change && curInstruction=="jmp") {
            curInstruction = "nop";
        }
        int value = 0;
        if (curInstruction == "jmp") {
            switch (instruction[1][0]) {
            case '+':
                value = atoi(instruction[1].substr(1).c_str());
                //std::cout << "[Adding] Previous Value: " << i << "\n";
                i += value;
                //std::cout << "[Value] Value: " << value << "\n";
                //std::cout << "[Adding] Current Value: " << i << "\n";
                break;
            case '-':
                //std::cout << "[Subtracting] Previous Value: " << i << "\n";
                value = atoi(instruction[1].substr(1).c_str());
                i -= value;
                //std::cout << "[Subtracting] Current Value: " << i << "\n";
                break;
            }
        }
        else if (curInstruction == "acc") {
            switch (instruction[1][0]) {
            case '+':
                value = atoi(instruction[1].substr(1).c_str());
                accVal += value;
                i++;
                break;
            case '-':
                value = atoi(instruction[1].substr(1).c_str());
                accVal -= value;
                i++;
                break;
            }
        }
        else if (curInstruction == "nop") {
            //Don't do anything!
            i++;
        }
        else {
            std::cout << "[Instruction] Value: " << instruction[0] << "\n";
        }
        runInstructions.push_back(instructions[i]);
        //std::cout << "[Current i Value]: " << i << " [Current accVal]: " << accVal << "\n";
    }
    std::cout << "[DONE] " << accVal;
    return true;

}

int main()
{
    //part1();
    std::vector<string> instructions = readFile("instructions.txt");

    int i = 0;
    bool found = false;
    while (!found && i != instructions.size()) {
        part2(i);
        i++;
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
