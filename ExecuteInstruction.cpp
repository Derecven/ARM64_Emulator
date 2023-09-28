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
                } else if (instruction == "AND") {
                    // Execute AND instruction
                }
                break;

            case 'B':
                if (instruction == "B") {
                    // Execute B instruction
                } else if (instruction == "B.GT") {
                    // Execute B.GT instruction
                } else if (instruction == "B.LE") {
                    // Execute B.LE instruction
                }
                break;

            case 'C':
                if (instruction == "CMP") {
                    // Execute CMP instruction
                }
                break;

            case 'E':
                if (instruction == "EOR") {
                    // Execute EOR instruction
                }
                break;

            case 'L':
                if (instruction == "LDR") {
                    // Execute LDR instruction
                } else if (instruction == "LDRB") {
                    // Execute LDRB instruction
                }
                break;

            case 'M':
                if (instruction == "MOV") {
                    // Execute MOV instruction
                } else if (instruction == "MUL") {
                    // Execute MUL instruction
                }
                break;

            case 'N':
                if (instruction == "NOP") {
                    // Execute NOP instruction
                }
                break;

            case 'R':
                if (instruction == "RET") {
                    // Execute RET instruction to end emulation
                }
                break;

            case 'S':
                if (instruction == "SUB") {
                    // Execute SUB instruction
                } else if (instruction == "STR") {
                    // Execute STR instruction
                } else if (instruction == "STRB") {
                    // Execute STRB instruction
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
