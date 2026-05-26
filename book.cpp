#include "book.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void addBook(vector<book> &books){
    book b;
    cout << "\nEnter the ID of this book : ";
    cin >> b.ID;
    cout << "Enter the title of the book : ";
    cin.ignore();
    getline(cin,b.title);
    cout << "Enter the name of the Author : ";
    getline(cin,b.author);
    books.push_back(b);
}

char continuum(bool &continu){
    char c;
    cin >> c;

    switch(c){
        case 'y' :
            continu = true;
            break;
        case 'Y' : 
            continu = true;
            break;
        case 'N' :
            continu = false;
            break;
        case 'n' :
            continu = false;
            break;
    }
    return continu;
}

void viewBooks(const vector<book> &books){
    if(books.size() == 0){
        cout << "\n***** No Books currently exist in the records. Please add Books first *****";
    }
    else{
        cout << "\n--------------------------------------------------------------------------";
        cout << "\n                          Book Records";
        cout << "\n--------------------------------------------------------------------------\n";
        cout << left
             << setw(15) << "ID"
             << setw(35) << "Title"
             << setw(30) << "Author";
        cout << "\n--------------------------------------------------------------------------\n";

        for(const book &b: books){
            cout << left
                 << setw(15) << b.ID
                 << setw(35) << b.title 
                 << setw(30) << b.author
                 << endl;
        }
        cout << "--------------------------------------------------------------------------\n";
    }
}

Result removeBook(vector<book> &books){
    bool found = false;

    if(books.size() == 0){
        cout << "\n***** No Books currently exist in the records! *****";
    }

    else{
        viewBooks(books);
        int targetID;
        cout << "\nEnter the ID of the book you wish to remove : ";
        cin >> targetID;

        for(vector<book>::iterator it = books.begin(); it != books.end(); ++it){
            if(targetID == it->ID){
                char confirm;
                found = false;
                cout << "\nAre you sure you wish to remove '" << it->title << "'? ";
                cin >> confirm;

                if (confirm == 'y' || confirm == 'Y'){
                    cout << "\n'" << it->title << "' has been removed";
                    it = books.erase(it);
                    return DELETED;
                }
                
                if (confirm == 'n' || confirm == 'N'){
                    cout << "\n'" << it->title << "' has not been removed";
                    return CANCELLED;
                }
            }
        }
        cout << targetID << " does not exist in the records ! ";
    }
    return NOT_FOUND;
}
