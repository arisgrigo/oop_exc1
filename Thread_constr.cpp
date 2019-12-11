
#include <string>
#include <iostream>
#include <string>
#include <ctime>
#include "Thread_constr.h"
#include "Forum_constr.h"

using namespace std;

static int post_id = 0;             //post_id is static since the id is unique for each post and must not be reset

Thread::Thread(const string& subject, const string& creator, const Date& creation_date, string* usernames)
        : subject(subject), creator(creator), creation_date(creation_date), posts(){
    cout << "Thread with subject: " << subject << " has just been created by: " << creator << endl;

    num_of_posts = (rand()%3)+1;

    string texts[5] = {"text0 ","text1 ","text2 ","text3 ","text4 "};               //array containing random texts to pass in the post creation

    for(int i = 0; i<= num_of_posts; i++){
        this -> posts[i] = new Post(post_id++, "title"+ to_string(i) , usernames[rand()%8], creation_date, texts[rand()%5]);
    }
    cout<<endl;
}

Thread::~Thread()
{
    cout << "Thread with subject: " << subject << " is about to be destroyed"<< endl ;

    for(int i = 0; i<= num_of_posts; i++) {
        delete posts[i];
    }
}

void Thread::set_subject(const string& new_subject)
{
    subject = new_subject;
}

void Thread::set_creator(const string& new_creator)
{
    creator = new_creator;
}


void Thread::set_creation_date(Date date)
{
    int d,m,y;
    date.get_date(d,m,y);

    creation_date.set_date(d,m,y);
}

string Thread::get_subject() const {
    return subject;
}

string Thread::get_creator() const
{
    return creator;
}

Date Thread::get_creation_date() const {
    return creation_date;
}

int Thread::get_id_of_post(const int post) const {
   return posts[post]->get_id();
}

int Thread::get_num_of_posts() const {
    return num_of_posts;
}

void Thread::print_post(const int post){
    int d,m,y;
    Date date;

    date = posts[post]->get_creation_date();
    date.get_date(d,m,y);

    cout << "Posts's id: " << posts[post]->get_id() << endl;
    cout << "Posts's title: " << posts[post]->get_title() << endl;
    cout << "Posts's creator: " << posts[post]->get_creator() << endl;
    cout << "Posts's creation date: " << d << "." << m << "." << y << endl;
    cout << "Posts's text: " << posts[post]->get_text() << endl << endl;
}

node* Thread::thread_enter_tree(Thread& thread){
    int i = 0;
    struct node* root = NULL;
    for(i; i <= num_of_posts; i++){
        root = root->insert_node(root, posts[i]->get_creator(), *posts[i]);
    }
    cout << "begin inorder" <<endl;
    root->inorder(root);
    cout << "stop inorder" <<endl;
    return root;
}