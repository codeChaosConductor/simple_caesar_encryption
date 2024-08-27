#include <iostream>
#include <string>
#include <stdexcept>

/*
* this code encrypts lowercase letters using the classic ceasar encryption method
*/

std::string caesarEncrypt(const std::string& text, int shift) {
    std::string result = "";
    shift = shift % 26;

    for (char c : text) {
        if (c >= 'a' && c <= 'z') {
            int originalIndex = c - 'a';
            int newIndex = (originalIndex + shift) % 26;

            char shiftedChar = 'a' + newIndex;
            result += shiftedChar;

            std::cout << "Original character: " << c << " (" << (originalIndex + 1) << "), "
                      << "Shifted character: " << shiftedChar << " (" << (newIndex + 1) << ")" << std::endl;
        } else {
            throw std::invalid_argument("Input text contains non-alphabetic characters.");
        }
    }

    return result;
}

int main() {
    std::string text;
    int shift;

    std::cout << "Enter text to encrypt (ASCII lowercase letters only): ";
    std::getline(std::cin, text);

    std::cout << "Enter key value: ";
    std::cin >> shift;

    try {
        std::string encryptedText = caesarEncrypt(text, shift);
        std::cout << "Encrypted text: " << encryptedText << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
