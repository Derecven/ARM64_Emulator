#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;

// Number of general-purpose registers
const int numberOfRegisters = 31; // general-purpose registers and include XZR

// General-purpose registers (X0-X30)
uint64_t x_registers[numberOfRegisters + 1] = { 0 }; // Array of type uint64, size of the number of registers initialized to 0.

// Special-purpose registers
uint64_t xzr_register = 0x0000000000000000; // zero register
uint64_t sp_register = 0x0000000000000000;   // stack pointer
uint64_t pc_register = 0x0000000000000000;   // program counter
uint64_t x30_register = 0x0000000000000000;  // link register (x30)
int processorState_N_bit = 0;
int processorState_Z_bit = 0;

//Function to read 32 bit value from 64 bit register
uint64_t read32bit(uint64_t regValue) {
    //type casting to convert bit masking op into unsigned 32 bit int. 
    return static_cast<uint32_t>(regValue & 0x000000000FFFFFFFF);//bit masking '0xffffffff' using AND operation 
}

//Function to write 32 bit value from 64 bit register
uint64_t write32bit(uint64_t regValue) {
    regValue = (regValue & 0x00000000FFFFFFFF); //Sets the upper 32 bits to zero and keeps lower 32 unchanged
    return regValue;
}

void printRegisters(ostream& output) { //Pass the output stream
    output << "-----------------------------------------------------------------------\n";
    output << "Registers:\n";
    output << "-----------------------------------------------------------------------\n";

    int registersPerColumn = (numberOfRegisters) / 3; //Purpose registers (X0 to X30)

    for (int i = 0; i < registersPerColumn; i++) {
        int regNum1 = i; //Column 1
        int regNum2 = i + registersPerColumn; //Column 2
        int regNum3 = i + 2 * registersPerColumn; //Column 3

        //Prints register names/labels in decimal format and values in hexadecimal line by line (rows)
        output << "X" << dec << regNum1 << ": 0x" << hex << setfill('0') << setw(16) << x_registers[regNum1] << "\t";
        output << "X" << dec << regNum2 << ": 0x" << hex << setfill('0') << setw(16) << x_registers[regNum2] << "\t";
        output << "X" << dec << regNum3 << ": 0x" << hex << setfill('0') << setw(16) << x_registers[regNum3] << "\n";
    }

    //Print other registers at the end
    output << "SP: 0x" << hex << setfill('0') << setw(16) << sp_register << "\t";
    output << "PC: 0x" << hex << setfill('0') << setw(16) << pc_register << "\t";
    output << "X30: 0x" << hex << setfill('0') << setw(16) << x30_register << "\n";
    output << "Processor State N bit: " << processorState_N_bit << "\n";
    output << "Processor State Z bit: " << processorState_Z_bit << "\n";
}

void writeToFile(string& filename) {
    ofstream outputFile(filename);
    //Check if it opens correctly
    if (!outputFile.is_open()) {
        cout << "Error: Unable to open file";
        return;
    }
    //Write the output to the file stream and close the file
    printRegisters(outputFile);
    outputFile.close();
}

int main() {
	//Defines output file name and writes to the file
    string filename = "arm64Registers_output.txt";
    writeToFile(filename);
    return 0;
}
