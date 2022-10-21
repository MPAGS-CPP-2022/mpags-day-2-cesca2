#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Our project headers
#include "TransformChar.hpp"
#include "processCommandLine.hpp"

int main(int argc, char* argv[])
{
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    
    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{""};
    std::string outputFile{""};

    //call processCommandLine here
    if(processCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile)==false){
        return 1;
    };

    // Handle help, if requested
    if (helpRequested) {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << std::endl;
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
        std::cout << "0.1.0" << std::endl;
        return 0;
    }

    
    // Warn that input file option not yet implemented
    std::string inputText{""};

    // Read in user input from stdin
    if (inputFile.empty()) {
        std::cerr << "No input file, specified, using std/in: \n";
    
        // Print out the transliterated text
        char in_char{'x'};
        
        while (std::cin >> in_char) {
            inputText += transformChar(in_char);
        
        }
        
        
    }
    // Read in user input from file
    else{
        std::ifstream in_file {inputFile};
        bool ok_to_read=in_file.good();
        if (ok_to_read == true){
            char inputChar {'x'};
        
            while (in_file >> inputChar){
                inputText += transformChar(inputChar);
            }
            
        }
        else{
            std::cerr << "[error] Could not read input file \n";
            return 1;
        }
    }
    
    // Outputting, printing if no output file, else printing to file
    if (outputFile.empty()) {
        std::cout << "No output file, specified, printing to terminal" << std::endl;
        std::cout << inputText << std::endl;
    }
    else{
        std::ofstream out_file {outputFile};
        bool ok_to_write = out_file.good();
        if(ok_to_write==true){
            out_file << inputText;
        }
        else{
            std::cerr << "[error] Could not write to output file \n";
            return 1;

        }
    
    
    }
    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}
