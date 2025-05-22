#include "book.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

void saveBooksToFile(const bookStructure books[], int numBooks) {
    ofstream file("sampleBooks.txt");  // Opens a file to save books
    for (int i = 0; i < numBooks; ++i) {
        file << books[i].title << "|" << books[i].author << "|" << books[i].year_of_publication << endl;
    }
}

void loadBooksFromFile(bookStructure books[], int& numBooks) {
    ifstream file("sampleBooks.txt");  // Opens the file for reading
    if (!file.is_open()) {
        cout << "No existing books file found." << endl;
        return;
    }

    numBooks = 0;  // Reset the number of books
    string line;
    while (getline(file, line)) {  // Read file line by line
        if (numBooks >= 100) break;  // Prevent overflow, since max size is 100

        stringstream ss(line);  // Convert line into stringstream
        bookStructure book;  // Temporary book object
        getline(ss, book.title, '|');  // Read title, author, and year
        getline(ss, book.author, '|');
        string year;
        getline(ss, year, '|');
        try {
            book.year_of_publication = stoi(year);  // Convert string to integer
            books[numBooks] = book;  // Insert into the array
            numBooks++;  // Increment the book count
        } catch (const std::invalid_argument& e) {
            cout << "Invalid year format: not a number" << endl;
        } catch (const std::out_of_range& e) {
            cout << "Invalid year format: number too large" << endl;
        }
    }
    file.close();
}

void sortByTitle(bookStructure books[], int numBooks) {
    for (int i = 1; i < numBooks; ++i) {
        bookStructure key = books[i];
        int j;
        for (j = i - 1; j >= 0 && books[j].title > key.title; --j) {
            books[j + 1] = books[j];
        }
        books[j + 1] = key;
    }
}

void sortByAuthor(bookStructure books[], int numBooks) {
    for (int i = 1; i < numBooks; ++i) {
        bookStructure key = books[i];
        int j;
        for (j = i - 1; j >= 0 && books[j].author > key.author; --j) {
            books[j + 1] = books[j];
        }
        books[j + 1] = key;
    }
}

void sortByYearAsc(bookStructure books[], int numBooks) {
    for (int i = 1; i < numBooks; ++i) {
        bookStructure key = books[i];
        int j;
        for (j = i - 1; j >= 0 && books[j].year_of_publication > key.year_of_publication; --j) {
            books[j + 1] = books[j];
        }
        books[j + 1] = key;
    }
}

void sortByYearDesc(bookStructure books[], int numBooks) {
    for (int i = 1; i < numBooks; ++i) {
        bookStructure key = books[i];
        int j;
        for (j = i - 1; j >= 0 && books[j].year_of_publication < key.year_of_publication; --j) {
            books[j + 1] = books[j];
        }
        books[j + 1] = key;
    }
}

int linearSearchByTitle(const bookStructure books[], int numBooks, const string& title) {
    for (int i = 0; i < numBooks; ++i) {
        if (books[i].title == title) {
            return i;  // Return the index of the found book
        }
    }
    return -1;  // Return -1 if not found
}

int linearSearchByAuthor(const bookStructure books[], int numBooks, const string& author) {
    for (int i = 0; i < numBooks; ++i) {
        if (books[i].author == author) {
            return i;  // Return the index of the found book
        }
    }
    return -1;  // Return -1 if not found
}

int binarySearchByTitle(const bookStructure books[], int numBooks, const string& title) {
    size_t left = 0;
    size_t right = numBooks - 1;
    
    while (left <= right) {
        size_t mid = left + (right - left) / 2;
        
        if (books[mid].title == title) {
            return mid;  // Return the index of the found book
        }
        
        if (books[mid].title < title) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // Return -1 if not found
}



