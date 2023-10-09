/* CSCI-6659 Reverse Engineering
* Name: Patrick Silver
* Date: 9/23/23
* Title: InstructionParser.cpp
* Description: Takes in a text file of Assembly instructions (already converted from binary),
                and formats it to the example output below. Output goes to console OR a specified test file.
                Depending on whether the boolean writeToFile is true or false.

Sources/References:
https://cplusplus.com/reference/iolibrary/
https://cplusplus.com/reference/sstream/istringstream/
https://cplusplus.com/reference/vector/vector/
https://en.cppreference.com/w/cpp/types/size_t
https://stackoverflow.com/questions/55393578/how-to-remove-an-entire-word-in-a-sentence-c

SAMPLE 1:
Example input: 	0:	d10043ff    sub	sp, sp, #0x10
Example output:
------------------------------------------------------------------
Instruction #<LINE NUMBER>:
------------------------------------------------------------------
Instruction: sub
Operand #1: sp
Operand #2: sp
Operand #3: #0x10

++++++++++++++++++++++

SAMPLE 2
Example input:  8:	f90007e0 	str	x0, [sp, #8]
Example output:
------------------------------------------------------------------
Instruction #<LINE NUMBER>:
------------------------------------------------------------------
Instruction: str
Operand #1: x0
Operand #2: [sp, #8]
*/

// LIBRARIES
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

//Function to remove comments from a line. Modified from code in references
void RemoveComments(string &line) {
    size_t commentPos = line.find("//"); // Find the position of "//" denoting a comment
    if (commentPos != string::npos) {
        line.erase(commentPos); // Remove the comment part of the line
    }
}

vector<vector<string>> ParseInstructions(const string &inputFilePath, const string &outputFilePath, bool writeToFile, vector<vector<string>> &vectorOfVectors) {
    ifstream inputFile(inputFilePath); // Open the input file
    if (!inputFile.is_open()) {
        // Error statement for if the file did not open
        cerr << "Error: Unable to open the input file" << endl;
    }

    ofstream outputFile(outputFilePath); // Creates the output file stream
    if (!outputFile.is_open()) {
        // Error statement for if the output file cannot be created
        cerr << "Error: Unable to create the output file" << endl;
        inputFile.close();
    }

    string line; // Defines the line of text from the file
    int lineNum = 0; // Initializes the line number count

    // Loop through each line of the input file.
    while (getline(inputFile, line)) {

        line = line.substr(14);// Removes the space holding the address and machine code
        RemoveComments(line); //Removes comments from the input file to not mess up parsing

        lineNum++;
        istringstream iss(line);
        string word;
        vector<string> operands; // Vector to store operands

        while (iss >> word) {
            // Checks if the next operand contains '[' to format the instruction to example 2
            if (word.find('[') != string::npos) {
                string operand = word;
                while (iss >> word && word.find(']') == string::npos) {
                    operand += " " + word;
                }
                operand += " " + word; // Add the closing bracket
                operands.push_back(operand);
            } else {
                // Remove any commas at the end of the operand (without brackets)
                while (!word.empty() && word.back() == ',') {
                    word.pop_back();
                }
                //Add the word to vector of operands
                operands.push_back(word);
            }
        }

        //****OUTPUT****
        if (!writeToFile) { // If we do not want to write to the file, output to the console terminal
            cout << "------------------------------------------------------------------" << endl;
            cout << "Instruction #" << lineNum << ":" << endl;
            cout << "------------------------------------------------------------------" << endl;

            cout << "Instruction: " << operands[0] << endl;
            for (size_t i = 1; i < operands.size(); i++) {
                cout << "Operand #" << i << ": " << operands[i] << endl;
            }

        } else { // If we do want to write the output to a file
            outputFile << "------------------------------------------------------------------" << endl;
            outputFile << "Instruction #" << lineNum << ":" << endl;
            outputFile << "------------------------------------------------------------------" << endl;

            outputFile << "Instruction: " << operands[0] << endl;
            for (size_t i = 1; i < operands.size(); i++) {
                outputFile << "Operand #" << i << ": " << operands[i] << endl;
            }
        }
        vectorOfVectors.push_back(operands); //Adds the individual vector before going to next line
    }
    // Close both input and output files
    inputFile.close();
    outputFile.close();
    // Returns all the instructions parsed
    return vectorOfVectors; 
}


//USED FOR TESTING PURPOSES. COMMENT OUT WHEN CALLING FROM MAIN FILE
/*
int main() {
    //Set the input and output text files
    string inputFilePath = "ARM-test-INPUT";
    string outputFilePath = "Arm-Parse-OUTPUT.txt";

    vector<vector<string>> vectorOfVectors; //Vector to store permanent vectors to call for instruciton execution

    //True or False bool determines whether output is printed to file 
    ParseInstructions(inputFilePath, outputFilePath, true, vectorOfVectors);
    return 0;
}
*/
