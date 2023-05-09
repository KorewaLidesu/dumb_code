#include<string>
#include<iostream>

class Book
{
    private:
        std::string title;
        std::string author;
    public:
        Book(std::string title = "", std::string author = "")
            : title(title), author(author) {}
        std::string getTitle() { return title; }
        void setTitle(std::string title) { this -> title = title; } 
        std::string getAuthor() { return author; }
        void setAuthor(std::string author) { this -> author = author; }
        void display();
};

void Book::display()
{
    std::cout << "Title: " << title << std::endl
            << "Author: " << author << std::endl;
}

class Fiction : public Book
{
    private:
        int numReadLev;
    public:
        Fiction(std::string title = "", std::string author = "", int level = 0)
            : Book(title, author), numReadLev(level) {}
        int getNumReadLev() { return numReadLev; }
        void setNumReadLev(int level) { this -> numReadLev = level; }
        void display();
};

void Fiction::display()
{
    Book::display();
    std::cout << "Numeric grade reading level: " << numReadLev << std::endl;
}

class NonFiction : public Book
{
    private:
        int numofPag;
    public:
        NonFiction(std::string title = "", std::string author = "", int page = 0)
            : Book(title, author), numofPag(page) {}
        int getNumofPag() { return numofPag; }
        void setNumofPag(int page) { this -> numofPag = page; }
        void display();
};

void NonFiction::display()
{
    Book::display();
    std::cout << "Number of pages: " << numofPag << std::endl;
}

int main()
{
    Book normalBook;
    normalBook.display();

    NonFiction nonFiction;
    nonFiction.display();

    Fiction fiction;
    fiction.display();
}