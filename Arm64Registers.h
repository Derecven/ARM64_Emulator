#ifndef ARM64_REGISTERS_H
#define ARM64_REGISTERS_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

// Number of general-purpose registers
extern const int numberOfRegisters;

// General-purpose registers (X0-X30)
extern uint64_t x_registers[];

// Special-purpose registers
extern uint64_t xzr_register;
extern uint64_t sp_register;
extern uint64_t pc_register;
extern uint64_t x30_register;
extern int processorState_N_bit;
extern int processorState_Z_bit;

// Function to print registers to the specified output stream
void printRegisters(std::ostream& output);

// Function to write registers to a file with the given filename
void writeToFile(const std::string& filename);

#endif
