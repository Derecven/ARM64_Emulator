/* CSCI-6659 Reverse Engineering
* Name: Patrick Silver
* Date: 9/27/23
* Title: StackMemory.cpp
* Description: Takes in a specified vector of 256 bytes and creates the output format of stack memory.

Sources/References:
https://cplusplus.com/reference/iolibrary/
https://cplusplus.com/reference/vector/vector/
https://en.cppreference.com/w/cpp/types/size_t
https://cplusplus.com/reference/iomanip/
https://people.sc.fsu.edu/~jburkardt/cpp_src/hexdump/hexdump.html

ASCII CHART: https://en.cppreference.com/w/cpp/language/ascii

Example output:
------------------------------------------------------------------------------
Stack:
------------------------------------------------------------------------------
00000000  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
00000000  65 98 d8 4e de 3e ef ef  76 fb a2 dd 92 64 26 d4  |e..N.>..v....d&.|
00000010  6b 50 24 e9 91 b8 62 b7  12 40 7e 0f 49 b6 7d b1  |kP$...b..@~.I.}.|
00000020  72 74 66 26 e9 a9 6f 18  02 93 20 e6 ed d6 d5 02  |rtf&..o... .....|
00000030  56 6f 15 7e 32 7e 6d 04  ea 3c 1f 5b 4a 49 7f c1  |Vo.~2~m..<.[JI..|
00000040  a8 66 80 10 68 46 bc f7  6f 23 56 9b 3f 0e 98 b5  |.f..hF..o#V.?...|
00000050  03 f0 09 92 1e 4e a0 ee  ed ce 78 ab fb b7 5e fb  |.....N....x...^.|
00000060  f2 ad 6a 67 3f eb b4 21  cd ba ba 84 91 85 d6 58  |..jg?..!.......X|
00000070  e2 6d 09 68 10 00 09 aa  cc a0 86 13 d9 7f bb 50  |.m.h...........P|
00000080  09 ad 90 58 61 c7 3e a4  bd db b2 8f d7 c4 cb 38  |...Xa.>........8|
00000090  36 c7 f7 99 1c dc 50 15  8d 9e af 4d f8 f9 31 c8  |6.....P....M..1.|
000000a0  43 7e 41 6f 99 85 c1 25  34 76 41 7d 99 fb f5 ba  |C~Ao...%4vA}....|
000000b0  5c 97 23 11 6b 49 a7 ac  2f f9 2f 6a 97 c7 b4 d0  |\.#.kI.././j....|
000000c0  7b b0 88 ad ab d8 af 09  a9 19 d8 13 87 8f 18 d5  |{...............|
000000d0  3c 72 8a 06 da 36 54 e6  d2 8e 37 70 7b 6e b9 24  |<r...6T...7p{n.$|
000000e0  c8 d9 9c 5c e9 e4 5b ae  03 e4 5f 95 d1 e9 a2 3c  |...\..[..._....<|
000000f0  f6 94 95 1f 6d de 22 21  63 35 f6 9d 03 da 5e 23  |....m."!c5....^#|
00000100
*/

//LIBRARIES
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// Function to perform a hex dump of a vector of unsigned characters
void hexDump(const vector<unsigned char>& data) {
    const size_t size = data.size();
    const size_t bytesPerLine = 16; // Number of bytes to print per line

    // Print the header
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "Stack:" << endl;
    cout << "------------------------------------------------------------------------------" << endl;

    // Print the current memory address in hexadecimal
    for (size_t i = 0; i < size; i += bytesPerLine) {
        cout << hex << setw(8) << setfill('0') << i << "  ";
        //setw to 8 characters as the width
        //setfill to pad with zeros if necessary.

        // Print the hexadecimal representation of bytes
        for (size_t j = 0; j < bytesPerLine; j++) {
            if (i + j < size) {
                cout << setw(2) << setfill('0') << static_cast<int>(data[i + j]) << " ";
                //setw(2) ensures that each byte is printed as two characters
                //setfill('0') pads with zeros if needed.
            } else {
                cout << "   "; // Print spaces for padding if data size does not fit
            }
        }
        // Print separator
        cout << " |";

        // Print ASCII characters (print '.' if it is not a character)
        for (size_t j = 0; j < bytesPerLine; j++) {
            if (i + j < size) {
                unsigned char c = data[i + j];
                cout << (isprint(c) ? static_cast<char>(c) : '.');
            } else {
                cout << " "; // Print spaces for padding if data size is not a multiple of bytesPerLine
            }
        }
        // Print the closing '|' and a newline
        cout << "|" << std::endl;
    }
}

int main() {
    // Example vector (you can replace this with your own data)
    vector<unsigned char> data = {
        0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48,
        0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50,
        0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58,
        0x59, 0x5A
    };


//TESTING CODE: (Comment out when running in program)
//****************************************************
    while (data.size() < 256) {
        //Add more data to the example until it is 256 bytes if data provided is smaller
        data.insert(data.end(), data.begin(), data.end());
    }
//****************************************************

    data.resize(256); // Ensures that the data is no bigger than 256 bytes
    // Call the hexDump function to display the hex dump of the vector data. Return success code
    hexDump(data);
    return 0;
}

