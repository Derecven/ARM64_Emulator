#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;
//Number of general purpose registers

//create file to write too

void writeToFile(string& filename) {
	ofstream outputFile(filename);

	//check if it opens correctly
	if (!outputFile.is_open()) {
		cout << "Error: Unable to open file";
		return;
	}
	printRegisters();
	outputFile.close();
}
const int numberOfRegisters = 31; //general purpose registers and include XZR

//General purpose registers (X0-X30)
uint64_t x_registers[numberOfRegisters + 1] = { 0 };//Array  of type uint64, size of the number of registers initialized to 0.

//special purpose register
uint64_t xzr_register = 0x0000000000000000;//zero register
uint64_t sp_register = 0x0000000000000000;//stack pointer
uint64_t pc_register = 0x0000000000000000;//program counter
uint64_t x30_register = 0x0000000000000000;//link register (x30)
int processorState_N_bit = 0;
int processorState_Z_bit = 0;

void printRegisters() {
	cout << "----------------------------------------------------\n";
	cout << "Registers: \n";
	cout << "----------------------------------------------------\n";
	for (int x = 0; x < numberOfRegisters + 1; x += 3) {
		cout << "X" << setw(2) << x << ": 0x" << hex << setfill('0') << setw(16) << x_registers[x] << " ";
		cout << "X" << setw(2) << x + 10 << ": 0x" << hex << setfill('0') << setw(16) << x_registers[x + 3] << " ";
		cout << "X" << setw(2) << x + 20 << ": 0x" << hex << setfill('0') << setw(16) << x_registers[x + 6] << "\n";
		cout << "Xzr: 0x" << hex << setfill('0') << setw(16) << sp_register << " ";
		cout << "SP: 0x" << hex <<setfill('0')<<setw(16)<< sp_register << " ";
		cout << "PC: 0x" << hex <<setfill('0')<<setw(16)<< pc_register << " ";
		cout << "X30: 0x" <<hex << setfill('0') << setw(16) << x30_register << "\n ";

		cout << "Processor State N bit: " << processorState_N_bit << "\n";
		cout << "Processor State Z bit: " << processorState_Z_bit << "\n";
	}
}
int main() {
	printRegisters();
	string filename = "arm64Registers_output.txt";
	writeToFile(filename);

}
