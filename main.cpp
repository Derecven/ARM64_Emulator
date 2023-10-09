#include"StackMemory.h"
#include"ARM64Registers.h"
#include"InstructionParser.h"
#include"ARM64Instructions.h"
#include"ExecuteInstruction.h"



//TESTING CODE (StackMemory): 
int testStackMemory() {
    // Example vector (you can replace this with your own data)
    vector<unsigned char> data = {
        0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48,
        0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50,
        0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58,
        0x59, 0x5A
    };

    while (data.size() < 256) {
        //Add more data to the example until it is 256 bytes if data provided is smaller
        data.insert(data.end(), data.begin(), data.end());
    }

    data.resize(256); // Ensures that the data is no bigger than 256 bytes
    // Call the hexDump function to display the hex dump of the vector data. Return success code
    stackMemDump(data);
    return 0;
}


int main() {

    //Set the input and output text files
    string inputFilePath = "ARM-instructions.txt";//This needs to change to input test cases
    string outputFilePath = "Arm_Instr_Parsed.txt";

    vector<vector<string>> vectorOfVectors; //Vector to store permanent vectors to call for instruciton execution

    // NEED TO MAKE A DATA SET TO PERMANENTLY HOLD ALL CHANGES TO DATA (REGISTERS/STACK)

    //Parse through the input file and sorts instruction/operands into vectors
    //True or False bool determines whether output is printed to file 
    ParseInstructions(inputFilePath, outputFilePath, true, vectorOfVectors);

    //Loops through vectors and exetutes instructions
    ExecuteInstructions(vectorOfVectors); 
    
    writeRegistersToFile(filename);//function call for registerrs printing
    printStackMem(); //ADD DATA FINALIZED DATA SET (needs to be a vector)
}

