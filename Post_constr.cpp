
#include <string>
#include <iostream>
#include "Post_constr.h"

using namespace std;

void Date::set_date(int i, int j, int k)
{
    month = i;
    day = j;
    year = k;

}

void Date::get_date(int& i, int& j, int& k)
{
    i = month;
    j = day ;
    k = year;
}


Post::Post(int id, const string& title, const string& creator, const Date& creation_date, const string& text)
        : id(id), title(title), creator(creator), creation_date(creation_date), text(text){

    cout << "Post with id: "<< id <<", title: "<< title << ", and text: "<< text << "has just been created by: " << creator << endl;

}

Post::~Post()
{
    cout << "Post number: " << id <<" is about to be destroyed"<< endl ;
}

void Post::set_id(int n)
{
    id = n;
}

void Post::set_title(const string& new_title)
{
    title = new_title;
}

void Post::set_creator(string new_creator)
{
    creator = new_creator;
}


void Post::set_creation_date(Date& date)
{
    int d,m,y;                              //creates varieables to pass values from date
    date.get_date(d,m,y);

    creation_date.set_date(d,m,y);
}

void Post::set_text(string new_text)
{
    text = new_text;
}

// get functions are const since they don't change values of any variables

int Post::get_id() const
{
    return id;
}

string Post::get_title() const
{
    return title;
}

string Post::get_creator() const
{
    return creator;
}

Date Post::get_creation_date() const {
    return creation_date;
}

string Post::get_text() const
{
    return text;
}







