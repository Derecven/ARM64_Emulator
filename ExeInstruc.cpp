#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include<unordered_map>
using namespace std;

unordered_map<string, int>register;//temp register 

int memory[1000] = { 0 };// simple temp mem array

//Execute AND instruction 
void executeAND(string op1, string op2, string op3) {
    register[op1] = register[op2] & register[op3];
}
//Execute ADD instruction
void executeADD(string op1, string op2, string op3) {
    //Assuming operands are in the form {"ADD","xd","x1","x2"}
    register[op1] = register[op2] + registers[op3];
}
//Execute B instruction 
void executeB(string destination) {
    //Assuming operands are in the form {"B","target_address"}
    cout<<"Branching to: "<<destination<<"\"
    pc_register = target_address;//update program counter to the target address
}
//Execute B.GET instruction (branch is greater or equal to) 
void executeBGET(string destination, string op1, string op2) {
    //Assuming operands are in the form {"B","target_address"}
    int operand1 = register[op1]; //storing value from register op1
    int operand2 = stoi(op2); //assumes op2 is the immidiate value converts to integer
    
    //checks conditon which is if it is greater than
    if (operand1 >= operand2) {
        cout << "B.GET: Branch to: " << destination << "\n";
    }
    else {
        cout << "B.GET: Cannot branch condition has not been met.\n";
    }
}
//Execute B.LE instruction(less then or equal to)
void executeBLE(string destination, string op1, string op2) {
    //Assuming operands are in the form {"B","target_address"}
    int operand1 = register[op1]; //storing value from register op1
    int operand2 = atoi(op2); //assumes op2 is the immidiate value converts to integer

    //checks conditon which is if it is greater than
    if (operand1 <= operand2) {
        cout << "B.GET: Branch to: " << destination << "\n";
    }
    else {
        cout << "B.GET: Cannot branch condition has not been met.\n";
    }
}
//Execute CMP instruction 
void executeCMP(string op1, string op2) {
    //Assuming operands are in the form {"B","target_address"}
    int zFlag = 0;
    int nFlag = 0;
    int operand1 = register[op1]; //storing value from register op1
    int operand2 = register[op2];//storing value from register op2

    //perform substraction
    int result = operand1 - operand2;
    //set N(negative) and Z(zero) flags
    if (result == 0) {
        zFlag++;
    }
    else if (result < 0) {
        nFlag++;
    }
    cout << "CMP: Zerp Flag = " << zFlag << "Negative Flag = " << nFlag << "\n";
}
//Execute EOR instruction
void executeEOR(string op1, string op2, string op3) {
    register[op1] = register[op1] ^ register[op2]; // performs bitwise XOR

}
//Execute LDR instruction
void executeLDR(string op1, string op2) {
    int address = register[op2];//storing the value stored in op2 inside of address
    register[op1] = memory[address]; //assiging that memory address to the specified target register
}
//Execute LDRB instruction (loads a byte from memory into a register)
void executeLDRB(string op1, string baseReg, int regOffset) {
    int address = register[baseReg] + regOffset; //Takes the base registers mem address  and adds the offset to calculate the new mem address
    register[op1] = memory[address]; //the byte is loaded from mem to the location of destination address
}
//Execute MOV instruction
void executeMOV(string destination, string op1) {
    int operand1 = [op1]; //storing the value store in op1 inside of operand 1
    register[destination] = operand1; //moving the value of operand 1 into the destination register
}
//Execute MUL instruction 
void executeMUL(string op1, string op2, string op3) {

    register[op1] = register[op2] * register[op3]
}

    //Execute NOP instruction 
void executeNOP(string operands) {
        //No operation, do nothing
    }
    //Execute RET instruction 
void executeRET(string operand) {
        cout<<"Emulation complete: Program finished\n"
    }
    //Execute SUB instruction 
void executeSUB(string op1, string op2, string op3) {
        //Assuming operands are in the form {"ADD","xd","x1","x2"}
        register[op1] = register[op2] - register[op3];
    }
    //Execute STR instruction
void executeSTR(string& op1, string& op2) {
    int address = register[op2]; // int address is assigned the value from op 2 is the register containing the address
    memory[address] = register[op1]; //this assigns value in op1 to the memeory address
    }
    //Execute STRB instruction
void executeSTRB(string& op1, string& baseReg, int regOffset) {
    int address = register[baseReg] + regOffset; //Takes the base registers mem address  and adds the offset to calculate the new mem address
    memory[address] = register[op1] & 0x0f; //the stores the lower 8 bits from the source register into memory
    }
