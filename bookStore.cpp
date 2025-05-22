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

// Function to view all books
void viewAllBooks(const bookStructure books[], int numBooks) {
    if (numBooks == 0) {
        cout << "No books available in the store." << endl;
    } else {
        cout << "\nAll Books in Store:" << endl;
        cout << "-----------------" << endl;
        for (int i = 0; i < numBooks; ++i) {
            cout << "Title: " << books[i].title << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Publication Year: " << books[i].year_of_publication << endl;
            cout << "-----------------" << endl;
        }
    }
    cout << "\nPress Enter to continue...";
    cin.get();
}

// Function to insert a new book
void insertNewBook(bookStructure books[], int& numBooks) {
    if (numBooks < MAX_BOOKS) {
        bookStructure newBook;
        cout << "\nEnter Book Details:" << endl;
        cout << "Title: ";
        getline(cin, newBook.title);
        cout << "Author: ";
        getline(cin, newBook.author);
        cout << "Publication Year: ";
        string year;
        getline(cin, year);
        try {
            newBook.year_of_publication = stoi(year);
            books[numBooks] = newBook; 
            numBooks++;  
            saveBooks(books, numBooks);   
            cout << "Book added successfully!" << endl;
        } catch (...) {
            cout << "Invalid year input!" << endl;
        }
    } else {
        cout << "Maximum number of books reached!" << endl;
    }
    cout << "\nPress Enter to continue...";
    cin.get();
}

// Function to delete a book by title
void deleteBookByTitle(bookStructure books[], int& numBooks) {
    if (numBooks == 0) {
        cout << "No books available to delete!" << endl;
    } else {
        string titleToDelete;
        cout << "Enter the title of the book to delete: ";
        getline(cin, titleToDelete);
    
        bool found = false;
    
        for (int i = 0; i < numBooks; ++i) {
            if (books[i].title == titleToDelete) {
                // Shift all books after the deleted one to the left
                for (int j = i; j < numBooks - 1; ++j) {
                    books[j] = books[j + 1];
                }
                numBooks--;  
                saveBooks(books, numBooks);  
                found = true;
                cout << "Book deleted successfully!" << endl;
                break;
            }
        }
    
        if (!found) {
            cout << "Book not found!" << endl;
        }
    }
    cout << "\nPress Enter to continue...";
    cin.get();
}

// Function to sort books
void sortBooks(bookStructure books[], int numBooks) {
    if (numBooks == 0) {
        cout << "No books available to sort!" << endl;
        cout << "\nPress Enter to continue...";
        cin.get();
        return;
    }

    cout << "\nChoose sorting option: " << endl;
    cout << "a. By Title (A-Z)" << endl;
    cout << "b. By Author (A-Z)" << endl;
    cout << "c. By Date (Oldest to Newest)" << endl;
    cout << "d. By Date (Newest to Oldest)" << endl;
    cout << "Enter your choice (a-d): ";
    
    char sortChoice;
    cin >> sortChoice;
    cin.ignore();

    switch(sortChoice) {
        case 'a':
        case 'A':
            sortByTitle(books, numBooks);
            break;
        case 'b':
        case 'B':
            sortByAuthor(books, numBooks);
            break;
        case 'c':
        case 'C':
            sortByYearAsc(books, numBooks);
            break;
        case 'd':
        case 'D':
            sortByYearDesc(books, numBooks);
            break;
        default:
            cout << "Invalid sorting option!" << endl;
            break;
    }

    cout << "\nSorted Books:" << endl;
    cout << "----------------" << endl;
    for (int i = 0; i < numBooks; ++i) {
        cout << "Title: " << books[i].title << endl;
        cout << "Author: " << books[i].author << endl;
        cout << "Publication Year: " << books[i].year_of_publication << endl;
        cout << "----------------" << endl;
    }

    cout << "\nPress Enter to continue...";
    cin.get();
}

// Function to search books
void searchBooks(const bookStructure books[], int numBooks) {
    cout << "\nChoose search option:" << endl;
    cout << "a. By Title" << endl;
    cout << "b. By Author" << endl;
    cout << "c. Find Newest Book" << endl;
    cout << "d. Find Oldest Book" << endl;
    cout << "Enter your choice (a-d): ";
    
    string searchChoice;
    getline(cin, searchChoice);
    
    if (searchChoice == "a") {
        cout << "Enter title to search: ";
        string searchTitle;
        getline(cin, searchTitle);
        
        sortByTitle(books, numBooks);
        int index = binarySearchByTitle(books, numBooks, searchTitle);
        
        if (index != -1) {
            cout << "\nThe Book is found:" << endl;
            cout << "Title: " << books[index].title << endl;
            cout << "Author: " << books[index].author << endl;
            cout << "Publication Year: " << books[index].year_of_publication << endl;
        } else {
            cout << "Book not found!" << endl;
        }
    } else if (searchChoice == "b") {
        cout << "Enter author to search: ";
        string searchAuthor;
        getline(cin, searchAuthor);
        
        int index = linearSearchByAuthor(books, numBooks, searchAuthor);
        
        if (index != -1) {
            cout << "\nThe Book is found:" << endl;
            cout << "Title: " << books[index].title << endl;
            cout << "Author: " << books[index].author << endl;
            cout << "Publication Year: " << books[index].year_of_publication << endl;
        } else {
            cout << "Book not found!" << endl;
        }
    } else if (searchChoice == "c") {
        if (numBooks == 0) {
            cout << "No books available!" << endl;
        } else {
            sortByYearDesc(books, numBooks);
            cout << "\nThe Newest Book:" << endl;
            cout << "Title: " << books[0].title << endl;
            cout << "Author: " << books[0].author << endl;
            cout << "Publication Year: " << books[0].year_of_publication << endl;
        }
    } else if (searchChoice == "d") {
        if (numBooks == 0) {
            cout << "No books available!" << endl;
        } else {
            sortByYearAsc(books, numBooks);
            cout << "\nThe Oldest Book:" << endl;
            cout << "Title: " << books[0].title << endl;
            cout << "Author: " << books[0].author << endl;
            cout << "Publication Year: " << books[0].year_of_publication << endl;
        }
    } else {
        cout << "Invalid search option!" << endl;
    }

    cout << "\nPress Enter to continue...";
    cin.get();
}



