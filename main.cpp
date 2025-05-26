#include "book.h"

int main() {
    Book books[MAX_BOOKS];
    int size = 0;
    string input;
    int choice;
    bool run = true;

    while (run) {
        system("cls"); 

        cout << "\n=== Welcome to BookStore System ===" << endl;
        cout << "1. View All Books" << endl;
        cout << "2. Insert a New Book" << endl;
        cout << "3. Delete a Book (by Title)" << endl;
        cout << "4. Sort Books" << endl;
        cout << "5. Search Books" << endl;
        cout << "6. Exit program" << endl;
        cout << "\nEnter your choice (1-6): ";

        getline(cin, input);
        try {
            choice = stoi(input);
        } catch (...) {
            cout << "Invalid input! Please enter a number between 1 and 6." << endl;
            cout << "Press Enter to continue...";
            cin.get();
            continue;
        }

        switch (choice) {
            case 1:
                viewBooks(books, size);
                break;
            case 2:
                insertBook(books, size);
                break;
            case 3:
                cout << "Enter the title of the book to delete: ";
                getline(cin, input);
                deleteBook(books, size, input);
                break;
            case 4: {
                int sortChoice;
                cout << "Sort by:\n1. Title\n2. Author\n3. Year Asc\n4. Year Desc\nEnter choice: ";
                cin >> sortChoice;
                cin.ignore();
                switch (sortChoice) {
                    case 1: 
                        sortByTitle(books, size); 
                        break;
                    case 2:
                        sortByAuthor(books, size);
                        break;
                    case 3: 
                        sortByYearAsc(books, size);
                         break;
                    case 4: 
                        sortByYearDesc(books, size);
                        break;
                    default:
                        cout << "Invalid option.\n"; 
                        break;
                }
                break;
            }
            case 5: {
                int searchChoice;
                cout << "Search by:\n1. Title (Linear)\n2. Author (Linear)\n3. Title (Binary - sorted only)\nEnter choice: ";
                cin >> searchChoice;
                cin.ignore();
                cout << "Enter search text: ";
                getline(cin, input);

                int index = -1;
                switch (searchChoice) {
                    case 1:
                        index = linearSearchByTitle(books, size, input);
                        break;
                    case 2:
                        index = linearSearchByAuthor(books, size, input);
                        break;
                    case 3:
                        index = binarySearchByTitle(books, size, input);
                        break;
                    default:
                        cout << "Invalid search option.\n";
                        break;
                }

                if (index != -1) {
                cout << "Book found:\n";    
                cout << "Title: " << books[index].title << endl;
                cout << "Author: " << books[index].author << endl;
                cout << "Year: " << books[index].year_of_publication << endl;
                } else {
                    cout << "Book not found.\n";
                }
                break;
            }
            case 6:
                cout << "Thank you for using BookStore System.\n";
                run = false;
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 6.\n";
                break;
        }
        cout << "Press Enter to continue...";
        cin.get();
    }

    return 0;
}
