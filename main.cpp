#include "book.hpp"
#include <string>
#include <iomanip>
#include <vector>
#include <iostream>
using namespace std;

void printmenu();
int promptmenu(int &menuselect);

int main() {
    int i, menuselect;
    book b;;
    vector<book> books;

    for(i = 0; menuselect != 4; i++){
        printmenu();
        promptmenu(menuselect);
        
        switch(menuselect){
            case 1:{
                bool continu = true;
                while (continu == true){
                    addBook(books);
                    cout << "\nDo you wish to add another book (Y/N) ?" << endl;
                    continuum(continu);
                }
            break;}
              
            case 2 :{
                string nothin;
                viewBooks(books);
                cout << "\n\nEnter Any Key to go back to Main Menu : ";
                cin >> nothin;
            break;}

            case 3 :{
                bool continu = true;
                
                while(continu == true){
                    Result result = removeBook(books);

                    switch(result){

                        case DELETED:
                            cout << "\nDo you wish to remove another book (Y/N) ? ";
                            continuum(continu);
                            break;
                        
                        case CANCELLED:
                            continu = false;
                            break;

                        case NOT_FOUND:
                            continu = false;
                            break;
                    }
                }
            }
        }

    }
}

void printmenu(){
    cout << "\n--------------------------------------------------------------------------------------";
    cout << "\n                          Book Record Management System";
    cout << "\n--------------------------------------------------------------------------------------";
    cout << "\n 1. Add Book";
    cout << "\n 2. View Books";
    cout << "\n 3. Remove Book";
    cout << "\n 4. Exit";
    cout << "\n--------------------------------------------------------------------------------------";
}

int promptmenu(int &menuselect){
    cout << "\nSelect an option (1 - 4) : ";
    cin >> menuselect;
    return menuselect;
}

