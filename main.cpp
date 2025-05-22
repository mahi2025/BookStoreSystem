#include "book.h"

const int MAX_BOOKS = 10000;

int main() {
    bookStructure books[MAX_BOOKS];
    int numBooks = 0; // Tracks how many books are currently in the array
    loadBooks(books, numBooks); // Load books from file initially

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

        string input;
        getline(cin, input);

        try {
            choice = stoi(input);
        } catch (...) {
            cout << "Invalid input! Please enter a number between (1-6)." << endl;
            cout << "Press Enter to continue...";
            cin.get();
            continue;
        }

        switch(choice) {
            case 1: 
                viewAllBooks(books, numBooks);
                break;

            case 2: 
                insertNewBook(books, numBooks);
                break;

            case 3: 
                deleteBookByTitle(books, numBooks);
                break;

            case 4: 
                sortBooks(books, numBooks);
                break;

            case 5: 
                searchBooks(books, numBooks);
                break;

            case 6:
                cout << "Thank you for using BookStore System." << endl;
                run = false;
                break;

            default:
                cout << "Invalid choice! Please enter a number between 1 and 6." << endl;
                cout << "Press Enter to continue...";
                cin.get();
                break;
        }
    }
    return 0;
}
