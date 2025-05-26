#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Book{
    string title;
    string author;
    int year_of_publication;
};

const int MAX_BOOKS= 10000;

//function declaration
void viewBooks(Book books[], int size);
void insertBook(Book books[], int &size);
void deleteBook(Book books[], int &size, const string &title);


//Sorting Functions using Insertion Sort
void sortByTitle(Book books[], int size);
void sortByAuthor(Book books[], int size);
void sortByYearAsc(Book books[], int size);
void sortByYearDesc(Book books[], int size);
//searching
int linearSearchByTitle(Book books[], int size, const string &title);
int linearSearchByAuthor(Book books[], int size, const string &author);
int binarySearchByTitle(Book books[], int size, const string &title);

#endif