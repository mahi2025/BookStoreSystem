#include "book.h"


void viewBooks(Book books[], int size){
        if (size == 0){
            cout<<"No books available in the book store\n";
            return;
        }
        cout<<"Available Books in the bookstore: \n";
        for(int i =0; i<size; i++){
            cout<<"Title: "<<books[i].title<<endl;
            cout<<"Author: "<<books[i].author<<endl;
            cout<<"Year of publication: "<<books[i].year_of_publication<<endl;
        }

}
void insertBook(Book books[], int &size){
        if(size >=MAX_BOOKS){
            cout<<"The Book store is full.You can't add any more book. \n";
            return;
        }
        Book newBook;
        cout<<"Enter the book title: ";
       
        getline(cin, newBook.title);

        cout<<"Enter the author name: ";
        getline(cin, newBook.author);

        cout<<"Enter year of publication: ";
        cin>>newBook.year_of_publication;

        books[size] = newBook;
        size++;
        cout<<"The Book  added successfully\n";
}

void deleteBook(Book books[], int &size, const string &title){
    int index = -1;
    for(int i =0; i < size; i++){
        if(books[i].title == title){
            index =i;
            break;
        }
    }

    if (index == -1){
        cout<<"The Books is not found.\n";
        return;
    }

    for(int i = index; i<size-1; i++){
        books[i] = books[i+1];
    }
    size--;
    cout<<"The Book deleted successfully.\n";
}

void sortByTitle(Book books[], int size) {
        for (int i = 1; i < size; i++) {
            Book key = books[i];
            int j = i - 1;
    
            while (j >= 0 && books[j].title > key.title) {
                books[j + 1] = books[j];
                j--;
            }
            books[j + 1] = key;
        }
        cout << "Books sorted by title.\n";
 }


void sortByAuthor(Book books[], int size) {
    for (int i = 1; i < size; i++) {
        Book key = books[i];
        int j = i - 1;

        while (j >= 0 && books[j].author > key.author) {
            books[j + 1] = books[j];
            j--;
        }
        books[j + 1] = key;
    }
    cout << "Books sorted by author.\n";
}

void sortByYearAsc(Book books[], int size) {
    for (int i = 1; i < size; i++) {
        Book key = books[i];
        int j = i - 1;

        while (j >= 0 && books[j].year_of_publication > key.year_of_publication) {
            books[j + 1] = books[j];
            j--;
        }
        books[j + 1] = key;
    }
    cout << "Books sorted by year (ascending).\n";
}

void sortByYearDesc(Book books[], int size) {
    for (int i = 1; i < size; i++) {
        Book key = books[i];
        int j = i - 1;

        while (j >= 0 && books[j].year_of_publication< key.year_of_publication) {
            books[j + 1] = books[j];
            j--;
        }
        books[j + 1] = key;
    }
    cout << "Books sorted by year (descending).\n";
}


int linearSearchByTitle(Book books[], int size, const string &title) {
    for (int i = 0; i < size; i++) {
        if (books[i].title == title) {
            return i; 
        }
    }
    return -1; 
}

int linearSearchByAuthor(Book books[], int size, const string &author) {
    for (int i = 0; i < size; i++) {
        if (books[i].author == author) {
            return i; 
        }
    }
    return -1; 
}


int binarySearchByTitle(Book books[], int size, const string &title) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (books[mid].title == title) {
            return mid;
        } else if (books[mid].title < title) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; 
}
