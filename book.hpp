#pragma once
#include <string>
#include <vector>
using namespace std;

class book{
    public:
    string title, author;
    int ID;
};

enum Result{
    NOT_FOUND,
    CANCELLED,
    DELETED,
};

void addBook(vector<book> &books);
void viewBooks(vector<book> &books);
Result removeBook(vector<book> &books);
char continuum(bool &continu);
