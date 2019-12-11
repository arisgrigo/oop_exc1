
#ifndef OOP1_POST_CONSTR_H
#define OOP1_POST_CONSTR_H
#include <string>
#include <iostream>

using namespace std;

//file contains both Date and Post Classes

class Date {
public:
    Date(){};
    Date(int const d, int const m, int const y): day(d),month(m),year(y){};
    ~Date(){};

    void set_date(int, int, int);
    void get_date(int&, int&, int&);
private:
    int day, month, year;
};

class Post{
public:
    Post(int id, const string& title, const string& creator, const Date& creation_date, const string& text);
    Post(){}
    ~Post();

    void set_id(int);
    void set_title(const string&);
    void set_creator(string);
    void set_creation_date(Date&);
    void set_text(string);

    int get_id() const;
    string get_title() const;
    string get_creator() const;
    Date get_creation_date() const;
    string get_text() const;

private:
    int id;             //unique for each post
    string title;
    string creator;
    Date creation_date;
    string text;
};


#endif

