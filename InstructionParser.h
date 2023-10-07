#ifndef INSTRUCTION_PARSER_H
#define INSTRUCTION_PARSER_H

#include <string>
#include <vector>

// Function to remove comments from a line
void RemoveComments(std::string &line);

// Function to parse instructions from an input file and store them in a vector of vectors
void ParseInstructions(const std::string &inputFilePath, const std::string &outputFilePath, bool writeToFile, std::vector<std::vector<std::string>> &vectorOfVectors);

#endif
