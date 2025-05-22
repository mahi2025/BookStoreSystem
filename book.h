#ifndef BOOK_H
#define BOOK_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

using namespace std;

struct bookStructure {
    string title;
    string author;
    int year_of_publication;
};
void viewAllBooks(const bookStructure books[], int numBooks);
void insertNewBook(bookStructure books[], int& numBooks);
void deleteBookByTitle(bookStructure books[], int& numBooks);
void sortBooks(bookStructure books[], int numBooks);
void searchBooks(const bookStructure books[], int numBooks);
void saveBooks(const bookStructure books[], int numBooks);
void loadBooks(bookStructure books[], int& numBooks);



#endif
