
#ifndef OOP1_THREAD_CONSTR_H
#define OOP1_THREAD_CONSTR_H

#include <string>
#include <iostream>
#include "Post_constr.h"

//Thread class contains an array of pointers pointing to Posts

using namespace std;

class Thread{
public:

    Thread(){}
    Thread(const string& subject, const string& creator, const Date& creation_date, string* usernames);
    ~Thread();

    void set_subject(const string&);
    void set_creator(const string&);
    void set_creation_date(Date);

    string get_subject() const;
    string get_creator() const;
    Date get_creation_date() const;
    int get_id_of_post(int) const;      //used to print posts
    int get_num_of_posts() const;

    void print_post(int);
    struct node* thread_enter_tree(Thread& thread);

private:
    string subject;
    string creator;
    Date creation_date;
    Post * posts[4];                   //each Thread contains a max of 4 Posts
    int num_of_posts;                  //keeps track of how many posts exist in a Thread
};

#endif