#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

void createFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file) {
        std::cout << "File created successfully!" << std::endl;
    } else {
        std::cout << "Error creating file!" << std::endl;
    }
    file.close();
}

void openFile(const std::string& filename, std::string& content) {
    std::ifstream file(filename);
    if (file) {
        std::string line;
        while (std::getline(file, line)) {
            content += line + '\n';
        }
        std::cout << "File opened successfully!" << std::endl;
    } else {
        std::cout << "Error opening file!" << std::endl;
    }
    file.close();
}

void saveFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (file) {
        file << content;
        std::cout << "File saved successfully!" << std::endl;
    } else {
        std::cout << "Error saving file!" << std::endl;
    }
    file.close();
}

void copyText(const std::string& source, std::string& clipboard) {
    clipboard = source;
    std::cout << "Text copied to clipboard!" << std::endl;
}

void pasteText(std::string& destination, const std::string& clipboard) {
    destination += clipboard;
    std::cout << "Text pasted!" << std::endl;
}

void findAndReplace(std::string& content, const std::string& findStr, const std::string& replaceStr) {
    size_t pos = 0;
    while ((pos = content.find(findStr, pos)) != std::string::npos) {
        content.replace(pos, findStr.length(), replaceStr);
        pos += replaceStr.length();
    }
    std::cout << "Find and replace complete!" << std::endl;
}

int main() {
    std::string filename;
    std::string content;
    std::string clipboard;
    std::string findStr;
    std::string replaceStr;
    int choice;

    while (true) {
        std::cout << "1. Create New File" << std::endl;
        std::cout << "2. Open File" << std::endl;
        std::cout << "3. Save File" << std::endl;
        std::cout << "4. Copy Text" << std::endl;
        std::cout << "5. Paste Text" << std::endl;
        std::cout << "6. Find and Replace" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the filename: ";
                std::cin >> filename;
                createFile(filename);
                break;
            case 2:
                std::cout << "Enter the filename: ";
                std::cin >> filename;
                openFile(filename, content);
                break;
            case 3:
                if (!filename.empty()) {
                    saveFile(filename, content);
                } else {
                    std::cout << "No file opened!" << std::endl;
                }
                break;
            case 4:
                if (!content.empty()) {
                    copyText(content, clipboard);
                } else {
                    std::cout << "No text to copy!" << std::endl;
                }
                break;
            case 5:
                if (!clipboard.empty()) {
                    pasteText(content, clipboard);
                } else {
                    std::cout << "Clipboard is empty!" << std::endl;
                }
                break;
            case 6:
                if (!content.empty()) {
                    std::cout << "Enter the text to find: ";
                    std::cin.ignore();
                    std::getline(std::cin, findStr);
                    std::cout << "Enter the replacement text: ";
                    std::getline(std::cin, replaceStr);
                    findAndReplace(content, findStr, replaceStr);
                } else {
                    std::cout << "No text to find and replace!" << std::endl;
                }
                break;
            case 7:
                return 0;
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }

        std::cout << std::endl;
    }

    return 0;
}

