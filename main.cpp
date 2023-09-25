#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;
//ADD Instruc add 2 numbers
void parseADD(string& line, int lineNum) {
	string mnemonic, op1, op2, op3;
	istringstream inputString(line);
	inputString >> mnemonic >> op1 >> op2 >> op3;
	if (mnemonic == "ADD") {
		return true;
	}
		cout << "-------------------------------------------------------------------------\n";
		cout << "Instruction: " << lineNum << "\n";
		cout << "-------------------------------------------------------------------------\n";
		cout << "Instruction:" << mnemonic << "\n";
		cout << "Operand #1: " << op1 << "\n";
		cout << "Operand #2: " << op2 << "\n";
		cout << "Operand #3: " << op3 << "\n";

		return true;
}
//LDR instruction loads register with a value from memory.
void parseLDR(string& line, int lineNum) {
	string mnemonic, destination, value;
	istringstream inputString(line);
	if (inputString >> mnemonic) {
		if (mnemonic == "ldr") {
			if (inputString >> destination >> value) {
			}
			cout << "-------------------------------------------------------------------------\n";
			cout << "Instruction: " << lineNum << "\n";
			cout << "-------------------------------------------------------------------------\n";
			cout << "Instruction:" << mnemonic << "\n";
			cout << "Operand #1: " << destination << "\n";
			cout << "Operand #2: " << value << "\n";


			return true;
		}

	}
}

//SUB instruc subtracts 2 numbers
void parseSUB(string& line, int lineNum) {
	string mnemonic, op1, op2, op3;
	istringstream inputString(line);
	inputString >> mnemonic >> op1 >> op2 >> op3;
	if (mnemonic == "SUB") {
		return true;
	}
	cout << "-------------------------------------------------------------------------\n";
	cout << "Instruction: " << lineNum << "\n";
	cout << "-------------------------------------------------------------------------\n";
	cout << "Instruction:" << mnemonic << "\n";
	cout << "Operand #1: " << op1 << "\n";
	cout << "Operand #2: " << op2 << "\n";
	cout << "Operand #3: " << op3 << "\n";

	return true;
}

//MOV instruction copies the value of op2 into Rd
void parseMOV(string& line, int lineNum) {
	string mnemonic, op1, op2, op3;
	istringstream inputString(line);
	inputString >> mnemonic >> op1 >> op2;
	if (mnemonic == "MOV") {
		return true;
	}
	cout << "-------------------------------------------------------------------------\n";
	cout << "Instruction: " << lineNum << "\n";
	cout << "-------------------------------------------------------------------------\n";
	cout << "Instruction:" << mnemonic << "\n";
	cout << "Operand #1: " << op1 << "\n";
	cout << "Operand #2: " << op2 << "\n";
	

	return true;
}
//STR stores a register value into memory
void parseSTR(string& line, int lineNum) {
	string mnemonic, op1, op2;
	istringstream inputString(line);
	inputString >> mnemonic >> op1 >> op2;
	if (mnemonic == "STR") {
		return true;
	}
	cout << "-------------------------------------------------------------------------\n";
	cout << "Instruction: " << lineNum << "\n";
	cout << "-------------------------------------------------------------------------\n";
	cout << "Instruction:" << mnemonic << "\n";
	cout << "Operand #1: " << op1 << "\n";
	cout << "Operand #2: " << op2 << "\n";
	

	return true;
}
//Return from the subroutine, branches unconditionally to an address in a register
void parseRET(string& line, int lineNum) {
	string mnemonic, op1, op2, op3;
	istringstream inputString(line);
	inputString >> mnemonic >> op1 >> op2 >> op3;
	if (mnemonic == "RET") {
		return true;
	}
	cout << "-------------------------------------------------------------------------\n";
	cout << "Instruction: " << lineNum << "\n";
	cout << "-------------------------------------------------------------------------\n";
	cout << "Instruction:" << mnemonic << "\n";
	

	return true;
}

//Multiply
void parseMUL(string& line, int lineNum) {
	string mnemonic, op1, op2, op3;
	istringstream inputString(line);
	inputString >> mnemonic >> op1 >> op2 >> op3;
	if (mnemonic == "MUL") {
		return true;
	}
	cout << "-------------------------------------------------------------------------\n";
	cout << "Instruction: " << lineNum << "\n";
	cout << "-------------------------------------------------------------------------\n";
	cout << "Instruction:" << mnemonic << "\n";
	cout << "Operand #1: " << op1 << "\n";
	cout << "Operand #2: " << op2 << "\n";
	cout << "Operand #3: " << op3 << "\n";

	return true;
}

//No operation
void parseNOP(string& line, int lineNum) {
	string mnemonic;
	istringstream inputString(line);
	inputString >> mnemonic;
	if (mnemonic == "NOP") {
		return true;
	}
	cout << "-------------------------------------------------------------------------\n";
	cout << "Instruction: " << lineNum << "\n";
	cout << "-------------------------------------------------------------------------\n";
	cout << "Instruction:" << mnemonic << "\n";

	return true;
}
void parseBGET(string& line, int lineNum) {
	string mnemonic, op1, op2, op3;
	istringstream inputString(line);
	inputString >> mnemonic >> op1 >> op2 >> op3;
	if (mnemonic == "B.GET" || op1[0] == 'X' || op2[0] == 'X' || op3[0] == 'X') {
		return true;
	}
	cout << "-------------------------------------------------------------------------\n";
	cout << "Instruction: " << lineNum << "\n";
	cout << "-------------------------------------------------------------------------\n";
	cout << "Instruction:" << mnemonic << "\n";
	cout << "Operand #1: " << op1 << "\n";
	cout << "Operand #2: " << op2 << "\n";
	cout << "Operand #3: " << op3 << "\n";

	return true;
}

//CMP compare(extended register), setting the condition flags and discarding the results
void parseCMP(string& line, int lineNum) {
	string mnemonic, op1, op2;
	istringstream inputString(line);
	inputString >> mnemonic >> op1 >> op2;
	if (mnemonic == "CMP") {
		return true;
	}
	cout << "-------------------------------------------------------------------------\n";
	cout << "Instruction: " << lineNum << "\n";
	cout << "-------------------------------------------------------------------------\n";
	cout << "Instruction:" << mnemonic << "\n";
	cout << "Operand #1: " << op1 << "\n";
	cout << "Operand #2: " << op2 << "\n";

	return true;
}
//B is branching to another location
void parseB(string& line, int lineNum) {
	string mnemonic,BTarget;
	istringstream inputString(line);
	inputString >> mnemonic >> BTarget;
	if (mnemonic == "b") {
		if (inputString >> BTarget) {
			return true;
		}
		cout << "-------------------------------------------------------------------------\n";
		cout << "Instruction: " << lineNum << "\n";
		cout << "-------------------------------------------------------------------------\n";
		cout << "Instruction:" << mnemonic << "\n";
		cout << "Branch Target:" << BTarget << "\n";

		return true;
	}
}
int main() {
	ofstream OutputFile("test1Output.txt");//Create and open outputfile for test 1.
	ifstream InputFile; InputFile.open("test1.txt"); //Open inputfile.


	//Check if input or output file fail to open, if so then print error statement.
	if (!InputFile.is_open() || !OutputFile.is_open()) {
		cout << "Failed to open the input or output file";
	}
	string line;
	while (getline(InputFile, line)) {
		istringstream inputString(line);
		string mnemonic;
		inputString >> mnemonic;

		if (mnemonic == "add") {
			parseADD(line);
		}
		else if (mnemonic == "sub") {
			parseSUB(line);
		}
		else if (mnemonic == "ldr") {
			parseLDR(line);
		}
		else if (mnemonic == "mov") {
			parseMOV(line);
		}
		else if (mnemonic == "str") {
			parseSTR(line);
		}
		else if (mnemonic == "ret") {
			parseRET(line);
		}
		else if (mnemonic == "mul") {
			parseMUL(line);
		}
		else if (mnemonic == "nop") {
			parseNOP(line);
		}
		else if (mnemonic == "b.get") {
			parseBGET(line);
		}
		else if (mnemonic == "cmp") {
			parseCMP(line);
		}
		else if (mnemonic == "b") {
			parseB(line);
		}
	}
		OutputFile.close();
		InputFile.close();
		return 0;
}