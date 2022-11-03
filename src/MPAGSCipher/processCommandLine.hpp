#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

bool processCommandLine(const std::vector<std::string> &args, bool& helpRequested, bool&versionRequested, std::string& inputFileName, std::string& outputFileName,  bool&encryption, bool&decryption, std::string& key);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP