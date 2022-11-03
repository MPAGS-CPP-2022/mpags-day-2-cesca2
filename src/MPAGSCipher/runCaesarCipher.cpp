// header
#include "runCaesarCipher.hpp"

std::string runCaesarCipher( const std::string& inputText, const size_t key, const bool encrypt )
{   
    // Create the alphabet container and output string
    std::string output{""};
    std::vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    // Loop over the input text
    // loop over characters in string
    for(char inputCharacter : inputText) {
 
    // For each character find the corresponding position in the alphabet
    //find element in alphabet container
    int position = inputCharacter - 'A';
   
    // Apply the shift (+ve or –ve depending on encrypt/decrypt)
    // to the position, handling correctly potential wrap-around
    // Determine the new character and add it to the output string
    if(encrypt==true){
       
        int shifted_position = (position + key) % 26;
        char new_character = alphabet[shifted_position];
        output += new_character;
    }
    else{
        int shifted_position = (position + (26 - key)) % 26;
        char new_character = alphabet[shifted_position];
        output += new_character;
    }
    
    }
    // Finally (after the loop), return the output string
    return output;
}