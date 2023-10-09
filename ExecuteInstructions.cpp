#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "ARM64Instructions.h"
using namespace std;

// Implement other instruction execution functions (EOR, ADD, AND, MUL, MOV, STR, STRB, LDR, LDRB, NOP, B, B.GT, B.LE, CMP, RET)

void ExecuteInstructions(vector<vector<string>> &vectorOfVectors) {
    for (const vector<string> &instructionVec : vectorOfVectors) {
        // Ensure the current vector has at least one element
        if (instructionVec.empty()) {
            cerr << "Empty instruction vector encountered." << endl;
            continue; // Skip to the next vector
        }

        // Extract instruction and operands from the current vector
        string instruction = instructionVec[0];
        // Initialize as empty, add logic if needed
        string dest = ""; 
        string op1 = "";  
        string op2 = "";  

        // Execute the corresponding instruction using switch
        switch (instruction[0]) {
            case 'A':
                if (instruction == "ADD") {
                    // Execute ADD instruction
                    executeADD(instructionVec[1], instructionVec[2], instructionVec[3]);
                } else if (instruction == "AND") {
                    // Execute AND instruction
                    executeAND(instructionVec[1], instructionVec[2], instructionVec[3]);
                }
                break;

            case 'B':
                if (instruction == "B") {
                    // Execute B instruction 
                    //instruction is the destination
                    executeB(instructionVec[1]); 
                } else if (instruction == "B.GT") {
                    // Execute B.GT instruction
                    //Instr 1 is destination, 2 & 3 are operands
                    executeBGET(instructionVec[1], instructionVec[2], instructionVec[3]);
                } else if (instruction == "B.LE") {
                    // Execute B.LE instruction
                    executeBLE(instructionVec[1], instructionVec[2], instructionVec[3]);
                    //Instr 1 is destination, 2 & 3 are operands
                }
                break;

            case 'C':
                if (instruction == "CMP") {
                    // Execute CMP instruction
                    executeCMP(instructionVec[1], instructionVec[2]);
                }
                break;

            case 'E':
                if (instruction == "EOR") {
                    // Execute EOR instruction
                    executeEOR(instructionVec[1], instructionVec[2], instructionVec[3]);
                }
                break;

            case 'L':
                if (instruction == "LDR") {
                    // Execute LDR instruction
                    executeLDR(instructionVec[1], instructionVec[2]);
                } else if (instruction == "LDRB") {
                    // Execute LDRB instruction
                    //Instr 1 is operand, 2 is baseReg, 3 is regOffset
                    executeLDRB(instructionVec[1], instructionVec[2], stoi(instructionVec[3]));
                }
                break;

            case 'M':
                if (instruction == "MOV") {
                    // Execute MOV instruction
                    //Instr 1 is destination,  is operand
                    executeMOV(instructionVec[1], instructionVec[2]);
                } else if (instruction == "MUL") {
                    // Execute MUL instruction
                    executeMUL(instructionVec[1], instructionVec[2], instructionVec[3]);
                }   
                break;

            case 'N':
                if (instruction == "NOP") {
                    // Execute NOP instruction
                    executeNOP(instructionVec[1]);
                }
                break;

            case 'R':
                if (instruction == "RET") {
                    // Execute RET instruction to end emulation
                    executeRET(instructionVec[1]);
                }
                break;

            case 'S':
                if (instruction == "SUB") {
                    // Execute SUB instruction
                    executeSUB(instructionVec[1], instructionVec[2], instructionVec[3]);
                } else if (instruction == "STR") {
                    // Execute STR instruction
                    executeSTR(instructionVec[1], instructionVec[2]);
                } else if (instruction == "STRB") {
                    // Execute STRB instruction
                    //Instr 1 is operand, 2 is baseReg, 3 is regOffset
                    executeSTRB(instructionVec[1], instructionVec[2], stoi(instructionVec[3]));
                }
                break;

            default:
                cerr << "Unknown instruction: " << instruction << endl;
                break;
        }
    }
}
