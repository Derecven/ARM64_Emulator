#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

//Execute AND instruction
void executeAND(vector<::string>& operands){
    //Assuming operands are in the form {"AND","xd","x1","x2"}
    uint64_t results = getRegisterValue(operands[2])//Retrieves the value of the register specifed by the second operand("Xn")
     & getRegisterValue(operands[3]);//Retrieves the value of the register specified by the third operand ("Xm")
    setRegisterValue(operands[1],result);//Stores the result of the AND operation in the register specified by the first operand ("xd")
}
//Execute ADD instruction
void executeADD(vector<::string>& operands){
  //Assuming operands are in the form {"ADD","xd","x1","x2"}
    uint64_t results = getRegisterValue(operands[2])//Retrieves the value of the register specifed by the second operand("Xn")
     + getRegisterValue(operands[3]);//Retrieves the value of the register specified by the third operand ("Xm")
    setRegisterValue(operands[1],result);//Stores the result of the AND operation in the register specified by the first operand ("xd")  
}
//Execute B instruction
void executeB(vector<::string>& operands){
    //Assuming operands are in the form {"B","target_address"}
    if(operands.size()!=2){
        cout<<"Error: Invalid number of operands for branch instruction"<<
        return;//checks whether vector has only two elements if not it gives error message
    uint64_t target_address = stoull(operands[1], nullptr,0);//second element in vector is taddr, is converted to unsigned ll(64-bit integer). 'nullptr' is pointer set to  f_char in string
        }
    pc_register = target_address;//update program counter to the target address
}
//Execute B.GET instruction
void executeBGET(vector<::string>& operands){
    //Assuming operands are in the form {"B","target_address"}
    if(operands.size()!=2){
        cout<<"Error: Invalid number of operands for branch instruction"<<
        return;//checks whether vector has only two elements if not it gives error message
        }
    pc_register = target_address;//update program counter to the target address
}
//Execute B.LE instruction
void executeBLE(vector<::string>& operands){
    if(operands.size()!=2){
        cout<<"Error: Invalid number of operands for branch instruction"<<
        return;//checks whether vector has only two elements if not it gives error message
        }
        //Get mem address from the operands
        uint64_t mem_address = stoull(operands[1], nullptr,0 );

        //check if mem address is less than or equal
        if(mem_address >=sizeof(memory)/sizeof(memory[0])){
            cout<<"Error: Memory address not in range"
            return 0;
        }
}
//Execute CMP instruction
void executeCMP(vector<::string>& operands){
    //Assuming operands are in the form {"CMP","x1","x2"}

    //Get values from registers x1 and x2
    uint64_t x1_register = x_registers[stoi(operands[1].substr(1))];
    uint64_t x2_register = x_registers[stoi(operands[2].substr(1))];
    //perform comparison
    uint64_t results = static_cast<uint64_t<(x1_register) - static_cast<uint64_t>(x2_register);
}
//Execute EOR instruction
void executeEOR(vector<::string>& operands){
    
}
//Execute LDR instruction
void executeLDR(vector<::string>& operands){
    
}
//Execute LDRB instruction
void executeLDRB(vector<::string>& operands){
    
}
//Execute MOV instruction
void executeMOV(vector<::string>& operands){
    
}
//Execute MUL instruction
void executeMUL(vector<::string>& operands){
    void executeSUB(vector<::string>& operands){
    //Assuming operands are in the form {"ADD","xd","x1","x2"}
    uint64_t results = getRegisterValue(operands[2])//Retrieves the value of the register specifed by the second operand("Xn")
     * getRegisterValue(operands[3]);//Retrieves the value of the register specified by the third operand ("Xm")
    setRegisterValue(operands[1],result);//Stores the result of the AND operation in the register specified by the first operand ("xd")  
    
}
//Execute NOP instruction
void executeNOP(vector<::string>& operands){
    
}
//Execute RET instruction
void executeRET(vector<::string>& operands){
    
}
//Execute SUB instruction
void executeSUB(vector<::string>& operands){
    //Assuming operands are in the form {"ADD","xd","x1","x2"}
    uint64_t results = getRegisterValue(operands[2])//Retrieves the value of the register specifed by the second operand("Xn")
     - getRegisterValue(operands[3]);//Retrieves the value of the register specified by the third operand ("Xm")
    setRegisterValue(operands[1],result);//Stores the result of the AND operation in the register specified by the first operand ("xd")  
    
}
//Execute STR instruction
void executeSTR(vector<::string>& operands){
    
}
//Execute STRB instruction
void executeSTRB(vector<::string>& operands){
    
}