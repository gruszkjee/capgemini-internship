#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct Books
{
    string nameofBook;
    string authorofBook;
    string bookGenre;
    string yearofIssue;
    string publisher;
    string pagesNr;
};

short howManyBooks;
Books book[20];

void useEnter();
void addBook();
void checkDatabase();
void saveToFile();
void loadFromFile();
void searchData();
void deletefromData();
int main()
{
    char tescior;
    loadFromFile();
    do
    {
        cout << "Books in database: " << howManyBooks << endl;
        cout << "MENU: " << endl;
        cout << "1. Add new book " << endl;
        cout << "2. Check books in database " << endl;
        cout << "3. Save database to file " << endl;
        cout << "4. Load database from file " << endl;
        cout << "5. Search in database" << endl;
        cout << "6. Delete book from database" << endl << endl;

        tescior = getch();

        switch(tescior)
        {
            case '1':
                addBook();
                break;
            case '2':
                checkDatabase();
                break;
            case '3':
                saveToFile();
                break;
            case '4':
                loadFromFile();
                break;
            case '5':
                searchData();
                break;
            case '6':
                deletefromData();
                break;
        }


        useEnter();
        system("cls");
    }while(tescior != 27);


    return 0;
}
void useEnter()
{
    cout << "Press ENTER to continue. " << endl;
    while(getch() != 13);
}
void addBook()
{
    cout << "Type name of the book: ";
    cin >> book[howManyBooks].nameofBook;

    cout << "Type name and surname of the author: ";
    cin >> book[howManyBooks].authorofBook;

    cout << "Type genre of the book: ";
    cin >> book[howManyBooks].bookGenre;

    cout << "Type year of issue of the book: ";
    cin >> book[howManyBooks].yearofIssue;
    
	cout << "Type publisher of the book: ";
    cin >> book[howManyBooks].publisher;
    
	cout << "Type how many pages does this book have: ";
    cin >> book[howManyBooks].pagesNr;

    howManyBooks++;
}
void checkDatabase()
{
    if (howManyBooks > 0)
    {
        for (int j = 0; j < howManyBooks; j++)
        {
            cout << "Book number: " << (j+1) << endl;
            cout << "Name of book: " << book[j].nameofBook << endl;
            cout << "Name and surname of the atuhor: " << book[j].authorofBook << endl;
            cout << "Book genre: " << book[j].bookGenre << endl;
            cout << "Year of issue: " << book[j].yearofIssue << endl;
            cout << "Publisher: " << book[j].publisher << endl;
            cout << "Number of pages: " << book[j].pagesNr << endl << endl;
        }
    }
    else
        cout << "Database is empty " << endl;
}
void saveToFile()
{
    ofstream file("database.txt");

    if (file.is_open())
    {
        file << howManyBooks << endl;
        for (int j = 0; j < howManyBooks; j++)
        {
            file << book[j].nameofBook << endl;
            file << book[j].authorofBook << endl;
            file << book[j].bookGenre << endl;
            file << book[j].yearofIssue<< endl;
            file << book[j].publisher<< endl;
            file << book[j].pagesNr<< endl;
        }

        file.close();
    }
    else
        cout << "The file didn't open correctly" << endl;


}
void loadFromFile()
{
    ifstream file("database.txt");

    if (file.is_open())
    {
        file >> howManyBooks;
        
        int i = 0;
        do
        {        	
            file >> book[i].nameofBook;
        	file >> book[i].authorofBook;
            file >> book[i].bookGenre;
            file >> book[i].yearofIssue;
            file >> book[i].publisher;
            file >> book[i].pagesNr;
           i++;           
        }while(!file.eof());

        file.close();
    }
    else
        cout << "This file doesn't exist'" << endl;

}
void searchData()
{
    if (howManyBooks != 0)
    {
        string nameofBook;
        cout << "Type name of book and you will receive more informations about it: ";
        cin >> nameofBook;

        for (int j = 0; j < howManyBooks; j++)
        {
            if (nameofBook == book[j].nameofBook)
            {
                                
                cout << "\nBook number: " << (j+1) << endl;
           		cout << "Name of book: " << book[j].nameofBook << endl;
            	cout << "Name and surname of the atuhor: " << book[j].authorofBook << endl;
            	cout << "Book genre: " << book[j].bookGenre << endl;
            	cout << "Year of issue: " << book[j].yearofIssue << endl;
            	cout << "Publisher: " << book[j].publisher << endl;
            	cout << "Number of pages: " << book[j].pagesNr << endl << endl;
            }
        }

    }
    else
        cout <<"We can't find book with such a name" << endl;
}
void deletefromData()
{
    if (howManyBooks != 0)
    {
        short indeks;

        cout << "Type index of book that u want to delete from database: ";
        cin >> indeks;

        for (short k = indeks; k < howManyBooks; k++)
        {
            book[k-1].nameofBook = book[k].nameofBook;
            book[k-1].authorofBook = book[k].authorofBook;
            book[k-1].bookGenre = book[k].bookGenre;
            book[k-1].yearofIssue = book[k].yearofIssue;
            book[k-1].publisher = book[k].publisher;
            book[k-1].pagesNr = book[k].pagesNr;
        }

        howManyBooks--;

        //saveToFile();

        cout << "Book with index " << indeks << " has been deleted." << endl;
    }
    else
        cout << "There's nothing to delete yet." << endl;
}

