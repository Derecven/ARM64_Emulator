#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include<unordered_map>
#include"ARM64Registers.h"
using namespace std;

//unordered_map<string, int>register;//temp register  
int memory[1000] = { 0 };// simple temp mem array

int regStrToInt(string op) {
    if(op[0] == 'x')
       return stoi(op.substr(1));
    else
       return stoi(op);
}

//Execute AND instruction 
void executeAND(string op1, string op2, string op3) {
    x_registers[regStrToInt(op1)] = x_registers[regStrToInt(op2)] & x_registers[regStrToInt(op3)];//Takes the value inside register op2 and op3 and performs bitwise operation, stores resutls in op1.
}
//Execute ADD instruction
void executeADD(string op1, string op2, string op3) {
    //Assuming operands are in the form {"ADD","xd","x1","x2"}
    x_registers[regStrToInt(op1)] = x_registers[regStrToInt(op2)] + x_registers[regStrToInt(op3)];//Takes the value inside register op2 and op3 and add them together, stores resutls in op1.
}
//Execute B instruction 
void executeB(string destination) {
    //Assuming operands are in the form {"B","target_address"}
    cout << "Branching to: " << destination << "\n";//branches to destination provided by instruction
    pc_register = regStrToInt(destination);//updates program counter to the new destination
}
//Execute B.GET instruction (branch if greater or equal to) 
void executeBGET(string destination, string op1, string op2) {
    //Assuming operands are in the form {"B","target_address"}
    int operand1 = x_registers[regStrToInt(op1)]; //storing value from register op1
    int operand2 = regStrToInt(op2); //assumes op2 is the immidiate value converts string to integer.
    
    //checks conditon which is if it is greater than or equal
    if (operand1 >= operand2) {
        cout << "B.GET: Branch to: " << destination << "\n";
        pc_register = regStrToInt(destination);//updates  program counter to new destination
    }
    else {
        cout << "B.GET: Cannot branch condition has not been met.\n";//if branch instruction is not greater or equal too, error message is printed out.
    }
}
//Execute B.LE instruction(less then or equal to)
void executeBLE(string destination, string op1, string op2) {
    //Assuming operands are in the form {"B","target_address"}
    int operand1 = x_registers[regStrToInt(op1)]; //storing value from register op1
    int operand2 = regStrToInt(op2); //assumes op2 is the immidiate value converts string to integer

    //checks conditon which is if it is less than or equal to
    if (operand1 <= operand2) {
        cout << "B.GET: Branch to: " << destination << "\n";//branch to destination
        pc_register = regStrToInt(destination);//update program counter to destination.
    }
    else {
        cout << "B.GET: Cannot branch condition has not been met.\n";//If condition is not met, error message is printed out.
    }
}
//Execute CMP instruction (compare)
void executeCMP(string op1, string op2) {
    int zFlag = 0;
    int nFlag = 0;
    int operand1 = x_registers[regStrToInt(op1)]; //storing value from register op1
    int operand2 = x_registers[regStrToInt(op2)];//storing value from register op2

    //perform substraction
    int result = operand1 - operand2;
    //set N(negative) and Z(zero) flags
    if (result == 0) {
        zFlag++;//increment Z flag is results from compare is 0
    }
    else if (result < 0) {
        nFlag++;//If result is less than zero increment N flag
    }
    cout << "CMP: Zerp Flag = " << zFlag << "Negative Flag = " << nFlag << "\n";//print out result of both flags
}
//Execute EOR instruction
void executeEOR(string op1, string op2, string op3) {
    x_registers[regStrToInt(op1)] = x_registers[regStrToInt(op1)] ^ x_registers[regStrToInt(op2)]; //Takes value from op2 & op3, performs XOR bitwise op and stores results in op1.

}
//Execute LDR instruction
void executeLDR(string op1, string op2) {
    int address = x_registers[regStrToInt(op2)];//storing the value stored in op2 inside of address
    x_registers[regStrToInt(op1)] = memory[address]; //assiging that memory address to the specified target register which is op1.
}
//Execute LDRB instruction (loads a byte from memory into a register)
void executeLDRB(string op1, string baseReg, int regOffset) {
    int address = x_registers[regStrToInt(baseReg)] + regOffset; //Takes the base registers mem address  and adds the offset to calculate the new mem address
    x_registers[regStrToInt(op1)] = memory[address]; //the byte is loaded from mem address to the location of new destination.
}
//Execute MOV instruction
void executeMOV(string destination, string op1) {
    int operand1 = x_registers[regStrToInt(op1)]; //storing the value store in op1 inside of operand 1
    x_registers[regStrToInt(destination)] = operand1; //moving the value of operand 1 into the destination register.
}
//Execute MUL instruction 
void executeMUL(string op1, string op2, string op3) {
    x_registers[regStrToInt(op1)] = x_registers[regStrToInt(op2)] * x_registers[regStrToInt(op3)]; //Takes values from op2 and op3, multiplies them and stores results in register op1.
}

    //Execute NOP instruction 
void executeNOP(string operands) {
        //No operation, do nothing
    }
    //Execute RET instruction 
void executeRET(string operand) {
    cout << "Emulation complete: Program finished\n";//Prints program has finished statement.
    }
    //Execute SUB instruction 
void executeSUB(string op1, string op2, string op3) {
        x_registers[regStrToInt(op1)] = x_registers[regStrToInt(op2)] - x_registers[regStrToInt(op3)];//Takes value from op2 and op3 and stores the value in op1.
    }
    //Execute STR instruction
void executeSTR(string op1, string op2) {
    int address = x_registers[regStrToInt(op2)]; // int address is assigned the value from op 2 
    memory[address] = x_registers[regStrToInt(op1)]; //this assigns value in op2 to the memeory address
    }
    //Execute STRB instruction
void executeSTRB(string op1, string baseReg, int regOffset) {
    int address = x_registers[regStrToInt(baseReg)] + regOffset; //Takes the base registers mem address  and adds the offset to calculate the new mem address
    memory[address] = x_registers[regStrToInt(op1)] & 0x0f; //the stores the lower 8 bits from the source register into memory
    }

