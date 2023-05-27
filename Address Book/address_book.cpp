#include <iostream>
#include <vector>
#include <algorithm>

struct Contact {
    std::string name;
    std::string phoneNumber;
    std::string email;
};

class AddressBook {
private:
    std::vector<Contact> contacts;

public:
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
        std::cout << "Contact added successfully!" << std::endl;
    }

    void editContact(const std::string& name) {
        auto it = std::find_if(contacts.begin(), contacts.end(), [&](const Contact& contact) {
            return contact.name == name;
        });

        if (it != contacts.end()) {
            Contact& contact = *it;
            std::cout << "Enter the new phone number: ";
            std::cin >> contact.phoneNumber;
            std::cout << "Enter the new email: ";
            std::cin >> contact.email;
            std::cout << "Contact updated successfully!" << std::endl;
        } else {
            std::cout << "Contact not found!" << std::endl;
        }
    }

    void deleteContact(const std::string& name) {
        auto it = std::find_if(contacts.begin(), contacts.end(), [&](const Contact& contact) {
            return contact.name == name;
        });

        if (it != contacts.end()) {
            contacts.erase(it);
            std::cout << "Contact deleted successfully!" << std::endl;
        } else {
            std::cout << "Contact not found!" << std::endl;
        }
    }

    void searchContact(const std::string& name) {
        auto it = std::find_if(contacts.begin(), contacts.end(), [&](const Contact& contact) {
            return contact.name == name;
        });

        if (it != contacts.end()) {
            const Contact& contact = *it;
            std::cout << "Name: " << contact.name << std::endl;
            std::cout << "Phone Number: " << contact.phoneNumber << std::endl;
            std::cout << "Email: " << contact.email << std::endl;
        } else {
            std::cout << "Contact not found!" << std::endl;
        }
    }
};

int main() {
    AddressBook addressBook;

    int choice;
    while (true) {
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "2. Edit Contact" << std::endl;
        std::cout << "3. Delete Contact" << std::endl;
        std::cout << "4. Search Contact" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            Contact contact;
            std::cout << "Enter name: ";
            std::cin >> contact.name;
            std::cout << "Enter phone number: ";
            std::cin >> contact.phoneNumber;
            std::cout << "Enter email: ";
            std::cin >> contact.email;
            addressBook.addContact(contact);
        } else if (choice == 2) {
            std::string name;
            std::cout << "Enter the name of the contact to edit: ";
            std::cin >> name;
            addressBook.editContact(name);
        } else if (choice == 3) {
            std::string name;
            std::cout << "Enter the name of the contact to delete: ";
            std::cin >> name;
            addressBook.deleteContact(name);
        } else if (choice == 4) {
            std::string name;
            std::cout << "Enter the name of the contact to search: ";
            std::cin >> name;
            addressBook.searchContact(name);
        } else if (choice == 5) {
            break;
        } else {
            std::cout << "Invalid choice!" << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}

