#include <iostream>
#include <string>
#include <stdexcept>

/*
* this code decrypts lowercase letters using the classic ceasar encryption method.
*/

std::string caesarDecrypt(const std::string& text, int shift) {
    std::string result = "";
    shift = shift % 26;

    for (char c : text) {
        if (c >= 'a' && c <= 'z') {
            int originalIndex = c - 'a';
            int newIndex = (originalIndex - shift + 26) % 26;

            char shiftedChar = 'a' + newIndex;
            result += shiftedChar;

            std::cout << "Encrypted character: " << c << " (" << (originalIndex + 1) << "), "
                      << "Decrypted character: " << shiftedChar << " (" << (newIndex + 1) << ")" << std::endl;
        } else {
            throw std::invalid_argument("Input text contains non-alphabetic characters.");
        }
    }

    return result;
}

int main() {
    std::string text;
    int shift;

    std::cout << "Enter text to decrypt (ASCII lowercase letters only): ";
    std::getline(std::cin, text);

    std::cout << "Enter key value: ";
    std::cin >> shift;

    try {
        std::string decryptedText = caesarDecrypt(text, shift);
        std::cout << "Decrypted text: " << decryptedText << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}