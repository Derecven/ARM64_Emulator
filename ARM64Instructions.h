#ifndef ARM64_INSTRUCTIONS_H
#define ARM64_INSTRUCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include "ARM64Registers.h"

// Function declarations for ARM64 instruction execution
void executeAND(std::string op1, std::string op2, std::string op3);
void executeADD(std::string op1, std::string op2, std::string op3);
void executeB(std::string destination);
void executeBGET(std::string destination, std::string op1, std::string op2);
void executeBLE(std::string destination, std::string op1, std::string op2);
void executeCMP(std::string op1, std::string op2);
void executeEOR(std::string op1, std::string op2, std::string op3);
void executeLDR(std::string op1, std::string op2);
void executeLDRB(std::string op1, std::string baseReg, int regOffset);
void executeMOV(std::string destination, std::string op1);
void executeMUL(std::string op1, std::string op2, std::string op3);
void executeNOP(std::string operands);
void executeRET(std::string operand);
void executeSUB(std::string op1, std::string op2, std::string op3);
void executeSTR(std::string op1, std::string op2);
void executeSTRB(std::string op1, std::string baseReg, int regOffset);

#endif
