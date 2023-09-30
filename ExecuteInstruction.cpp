#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

/*
Things that need to happen before this code runs:
Define ARM64 registers
Memory for LDR and STR instructions initialized
Figure out how we will move the data and manipulate it 
*/


// Implement other instruction execution functions (EOR, ADD, AND, MUL, MOV, STR, STRB, LDR, LDRB, NOP, B, B.GT, B.LE, CMP, RET)

int main() {
    // Open the input assembly file once parsed. Error check
    ifstream inputFile("assembly_code.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open the input file" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        // Parse the line into instruction and operands
        // **NEED TO IMPLEMENT THE PARSER FOR THE TASK 1 OUTPUT TO DO THIS**

        string instruction; // Extracted instruction
        string dest;        // Extracted destination register

        // I AM THINKING MAYBE MAKE ANOTHER VECTOR TO HOLD THE OPERANDS SINCE THERE CAN BE A VARYING AMOUNT
        string op1;         // Extracted operand 1
        string op2;         // Extracted operand 2

        // Parse the line and populate the above variables

        // Execute the corresponding instruction using switch
        switch (instruction[0]) {
            case 'A':
                if (instruction == "ADD") {
                    // Execute ADD instruction
                    executeAdd(operands);
                } else if (instruction == "AND") {
                    // Execute AND instruction
                    executeAND(operands);
                }
                break;

            case 'B':
                if (instruction == "B") {
                    // Execute B instruction
                    executeB(operands);
                } else if (instruction == "B.GT") {
                    // Execute B.GT instruction
                    executeBGT(operands);
                } else if (instruction == "B.LE") {
                    // Execute B.LE instruction
                    executeBLE(operands);
                }
                break;

            case 'C':
                if (instruction == "CMP") {
                    // Execute CMP instruction
                    executeCMP(operands);
                }
                break;

            case 'E':
                if (instruction == "EOR") {
                    // Execute EOR instruction
                    executeEOR(operands);
                }
                break;

            case 'L':
                if (instruction == "LDR") {
                    // Execute LDR instruction
                    executeLDR(operands);
                } else if (instruction == "LDRB") {
                    // Execute LDRB instruction
                    executeLDRB(operands);
                }
                break;

            case 'M':
                if (instruction == "MOV") {
                    // Execute MOV instruction
                    executeMOV(operands);
                } else if (instruction == "MUL") {
                    // Execute MUL instruction
                    executeMUL(operands);
                }
                break;

            case 'N':
                if (instruction == "NOP") {
                    // Execute NOP instruction
                    executeNOP(operands);
                }
                break;

            case 'R':
                if (instruction == "RET") {
                    // Execute RET instruction to end emulation
                    executeRET(operands);
                }
                break;

            case 'S':
                if (instruction == "SUB") {
                    // Execute SUB instruction
                    executeSUB(operands);
                } else if (instruction == "STR") {
                    // Execute STR instruction
                    executeSTR(operands);
                } else if (instruction == "STRB") {
                    // Execute STRB instruction
                    executeSTRB(operands);
                }
                break;

            default:
                std::cerr << "Unknown instruction: " << instruction << std::endl;
                break;
        }
    }
    // Close the input file
    inputFile.close();

    // Print register and memory contents after emulation

    return 0;
}
