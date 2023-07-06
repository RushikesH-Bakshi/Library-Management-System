#include <bits/stdc++.h>
#include <fstream>
#include <unistd.h>
using namespace std;

const int m1 = 100;

string BookCode[m1], BookName[m1], AuthorName[m1], Pri[m1];
string IRUID[m1], IRBC[m1];
string UserID[m1], UserName[m1], cntct_num[m1];

class library
{
public:
    int book_counter = 0;

    void book_record();
    void book_record_file();
    void user_record();
};

class librarian : public library
{
public:
    char price[10];
    char book_code[10];
    char book_name[50];
    char author_name[50];

    void add_book();
    void search_book();
    void remove_book();
};

class user : public librarian
{
public:
    int user_counter = 0;
    int issue_counter = 0;
    char id[20];
    char name[50];
    char number[10];

    void add_user();
    void issue_book();
    void issue_record();
    void record_files();
};

void librarian ::add_book()
{
    cout << "\nAdding a new book in the library\n\n";
    cout << "Enter the following details\n\n";
    cin.ignore();
    cout << "Code - ";
    cin.getline(book_code, 10);
    cout << "\nName - ";
    cin.getline(book_name, 50);
    cout << "\nAuthor name - ";
    cin.getline(author_name, 50);
    cout << "\nPrice - ";
    cin.getline(price, 10);

    for (int i = 1; i <= m1; i++)
    {
        if (BookCode[i] == "\0")
        {
            BookCode[i] = book_code;
            BookName[i] = book_name;
            AuthorName[i] = author_name;
            Pri[i] = price;
            book_counter++;
            cout << "\n\nBook added successfully";
            break;
        }
    }
};

void librarian ::search_book()
{
    cout << "\nSearch the Book";
    cin.ignore();
    cout << "\n\nEnter the Code - ";
    cin.getline(book_code, 20);
    cout << "\n\nSearching the book...";
    sleep(2);

    int c = 0;
    for (int j = 1; j <= m1; j++)
    {
        if (BookCode[j] == book_code)
        {
            c++;
            cout << "\nBook Found";
            cout << "\n\nBook name - ";
            cout << book_name;
            cout << "\nAuthor name - ";
            cout << author_name;
            break;
        }
    }

    if (c == 0)
    {
        cout << "\nBook not found";
    }
};

void librarian ::remove_book()
{
    cout << "\nRemove the Book";
    cin.ignore();
    cout << "\n\nEnter the Code - ";
    cin.getline(book_code, 20);

    int u = 0;
    for (int k = 1; k <= m1; k++)
    {
        if (BookCode[k] == book_code)
        {
            u++;
            BookCode[k] = "";
            BookName[k] = "";
            AuthorName[k] = "";
            Pri[k] = "";
            book_counter--;
            cout << "\n\nBook removed successfully";
            break;
        }
    }
    if (u == 0)
    {
        cout << "\n\nBook not found";
    }
};

void user ::issue_book()
{
    cout << "\nIssue the book";
    cin.ignore();
    cout << "\n\nEnter the book code - ";
    cin.getline(book_code, 20);
    cout << "\n\nEnter the User ID - ";
    cin.getline(id, 20);

    for (int e = 1; e <= m1; e++)
    {
        if (IRBC[e] == "\0")
            ;
        {
            IRBC[e] = book_code;
            IRUID[e] = id;
            issue_counter++;
            cout << "\n\nRecord insertd successfully";
            break;
        }
    }
};

void library ::book_record()
{
    cout << "\nRecord of Books in library\n";
    cout << "\n\nTotal books in library - " << book_counter;
    cout << "\n\n"
         << "Book Code"
         << "\t\t"
         << "Book name"
         << "\t\t"
         << "Author Name";
    for (int a = 1; a <= m1; a++)
    {
        if (BookCode[a] != "\0")
        {
            cout << "\n"
                 << BookCode[a] << "\t\t" << BookName[a] << "   \t\t" << AuthorName[a] << endl;
        }
        else
        {
            continue;
        }
    }
};

void user ::issue_record()
{
    cout << "\nRecord of Books issued from library";
    cout << "\n\n"
         << "Book Code"
         << "\t\t"
         << "User ID"
         << "\t\t";
    for (int f = 1; f <= m1; f++)
    {
        if (IRBC[f] != "\0")
        {
            cout << "\n"
                 << IRBC[f] << "\t\t" << IRUID[f] << "\t\t" << endl;
        }
        else
        {
            continue;
        }
    }
};

void user ::add_user()
{
    cout << "\nAdding a new user\n";
    cout << "\nEnter the following details\n";
    cin.ignore();
    cout << "ID - ";
    cin.getline(id, 20);
    cout << "\nName - ";
    cin.getline(name, 50);
    cout << "\nContact Number - ";
    cin.getline(number, 10);

    for (int w = 1; w <= m1; w++)
    {
        if (UserID[w] == "\0")
        {
            UserID[w] = id;
            UserName[w] = name;
            cntct_num[w] = number;
            user_counter++;
            cout << "\n\nUser added successfully";
            break;
        }
    }
};

void library ::user_record()
{
    cout << "\nRecord of Users";
    cout << "\n\n"
         << "User ID"
         << "\t\t"
         << "User name"
         << "\t\t"
         << "Contact Number";
    for (int g = 1; g <= m1; g++)
    {
        if (UserID[g] != "\0")
        {
            cout << "\n"
                 << UserID[g] << "\t\t" << UserName[g] << "\t\t" << cntct_num[g] << "\t\t" << endl;
        }
        else
        {
            continue;
        }
    }
};

int main()
{
    user us;
    int c;
    do
    {
        cout << "\n\t\t\t\t\t_______________________________________________________________";
        cout << "\n\t\t\t\t\t\t\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  ";
        cout << "\n\t\t\t\t\t\t\t|                             |";
        cout << "\n\t\t\t\t\t\t\t|  Library Management System  |";
        cout << "\n\t\t\t\t\t\t\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _| ";

        cout << "\n\n\t\t\t\t\t\t\t1. Add Book";
        cout << "\n\t\t\t\t\t\t\t2. Search Book";
        cout << "\n\t\t\t\t\t\t\t3. Remove Book";
        cout << "\n\t\t\t\t\t\t\t4. Issue Book";
        cout << "\n\t\t\t\t\t\t\t5. Add User";
        cout << "\n\t\t\t\t\t\t\t6. Book Record";
        cout << "\n\t\t\t\t\t\t\t7. User Record";
        cout << "\n\t\t\t\t\t\t\t8. Issue Record";
        cout << "\n\t\t\t\t\t\t\t9. Exit";
        cout << "\n\t\t\t\t\t_______________________________________________________________";
        cout << "\n\t\t\t\t\t\t\tSelect an Option --> ";
        cin >> c;

        switch (c)
        {
        case 1:
            us.add_book();
            break;

        case 2:
            us.search_book();
            break;

        case 3:
            us.remove_book();
            break;

        case 4:
            us.issue_book();
            break;

        case 5:
            us.add_user();
            break;

        case 6:
            us.book_record();
            break;

        case 7:
            us.user_record();
            break;

        case 8:
            us.issue_record();
            break;

        case 9:
            break;

        default:
            cout << "Invalid choice";
            break;
        }
    } while (c != 9);

    return 0;
}