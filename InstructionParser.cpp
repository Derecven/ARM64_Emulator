/* CSCI-6659 Reverse Engineering
* Name: Patrick Silver
* Date: 9/23/23
* Title: InstructionParser.cpp
* Description: Takes in a text file of Assembly instructions (already converted from binary),
                and formats it to the example output below. Output goes to console OR a specified test file.
                Depending on whether the toggle boolean writeToFile is true or false.

Sources/References:
https://cplusplus.com/reference/iolibrary/
https://cplusplus.com/reference/sstream/istringstream/
https://cplusplus.com/reference/vector/vector/
https://en.cppreference.com/w/cpp/types/size_t

SAMPLE 1:
Example input: 	ADD X1, X2, X3
Example output:

------------------------------------------------------------------
Instruction #<LINE NUMBER>:
------------------------------------------------------------------
Instruction: ADD
Operand #1: X1
Operand #2: X2
Operand #3: X3

++++++++++++++++++++++

SAMPLE 2
Example input: 	LDR X0, [SP, 0x08]
Example output:
------------------------------------------------------------------
Instruction #<LINE NUMBER>:
------------------------------------------------------------------
Instruction: LDR
Operand #1: X0
Operand #2: [SP, 0x08] --> SP + 0x08
*/

//LIBRARIES
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string inputFilePath = "ARM-instructions.txt"; 
    ifstream inputFile(inputFilePath); //Open the input file
    //Error statement for if the file did not open
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open the input file" << endl;
        return 1;
    }

    ofstream outputFile("Arm_Instr_Parsed.txt"); //Creates the output file stream 
    //Error statement for if output file cannot be created
    if(!outputFile.is_open()){
        cerr << "Error: Unable to create the output file" << endl;
        inputFile.close(); 
        return 1;
    }

    string line; //Defines the line of text from the file
    int lineNum = 0; //Initializes the line number count

    //**********TOGGLE VARIABLE************
    //Variable to control whether to write output to a file or console.
    bool writeToFile = true;  

    //Loop through each line of the input file.
    while (getline(inputFile, line)) { 
        lineNum++;
        istringstream iss(line);
        string word;
        vector<string> operands;
        bool firstWord = true;

        while (iss >> word) {
            //Checks if the next operand contains '[' to format the instruction to example 2
            if (word.find('[') != string::npos) {
                string operand = word;
                while (iss >> word && word.find(']') == string::npos) {
                    operand += " " + word;
                }
                operand += " " + word; //Add the closing bracket
                operands.push_back(operand);
            } else {
                operands.push_back(word);
            }
        }

        //****OUTPUT****
        if(!writeToFile){ //If we do not want to write to the file, output to the console terminal
            cout << "------------------------------------------------------------------" << endl;
            cout << "Instruction #" << lineNum << ":" << endl;
            cout << "------------------------------------------------------------------" << endl;
            
            cout << "Instruction: " << operands[0] << endl;
            for (size_t i = 1; i < operands.size(); ++i) {
                cout << "Operand #" << i + 1 << ": " << operands[i] << endl;
            }  
        }
        else{ //If we do want to write the output to a file 
            outputFile << "------------------------------------------------------------------" << endl;
            outputFile << "Instruction #" << lineNum << ":" << endl;
            outputFile << "------------------------------------------------------------------" << endl;
            outputFile << "Instruction: " << operands[0] << endl;
        }
        for (size_t i = 1; i < operands.size(); ++i) {
            outputFile << "Operand #" << i + 1 << ": " << operands[i] << endl;
        }
    }
    //Close both input and output files. Return success code
    inputFile.close();
    outputFile.close();
    return 0;
}
