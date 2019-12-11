//
// Created by user on 02/12/2019.
//

#include <iostream>
#include <ctime>
#include <string>
#include "Forum_constr.h"
#include "Thread_constr.h"
#include "Post_constr.h"

using namespace std;

Forum::Forum(const string& title)
        :title(title), threads(){

    cout << "Forum with title: " << title << " has just been created!" << endl;

    Date date1{};
    date1.set_date(1,12,2019);

    num_of_threads = (rand()%3)+1;

    string usernames[8] = {"Nikos ","Danai ","Maria ","Aris ","Eva ", "Antzello" , "Myrto ", "Adamantia "};

    this -> threads[0] = new Thread("Κανόνες και χρήσιμες πληροφορίες",usernames[rand()%8], date1, usernames);

   for(int i = 1; i<= num_of_threads; i++){
       this -> threads[i] = new Thread("rules"+ to_string(i),usernames[rand()%8], date1, usernames);
   }

}

Forum::~Forum()
{
    for(int i = 0; i<= num_of_threads; i++) {
        delete threads[i];
    }
    cout << "Forum with title: " << title << " is about to be destroyed"<< endl ;
}

void Forum::print_forum() {
    int i=0;

    cout << "Printing forum with title: " << this->title << endl;
    cout << "Threads in forum " << this->title << ": " << endl << endl;

   for(i;  i <= num_of_threads; i++){
        cout << threads[i]->get_subject() << endl;
    }
    cout << endl;
}

void Forum::print_thread(const string& given_subject) {                  //print_thread looks if the given string matches any Thread in the Forum and prints it out
    int i = 0;
    string temp_subj;

    for( i; i <= num_of_threads; i++){
        temp_subj = threads[i]->get_subject();
        if(temp_subj == given_subject)
            break;
    }


    if(temp_subj  != given_subject)
        cout << "No thread with this title: " << given_subject << " exists!" <<endl <<endl;
    else {
        cout << "About to print thread with title: " << given_subject << endl << endl;

        int d, m, y;
        Date date(0,0,0);

        date = threads[i]->get_creation_date();
        date.get_date(d, m, y);

        cout << "Thread's subject: " << threads[i]->get_subject() << endl;

        cout << "Thread's creator: " << threads[i]->get_creator() << endl;

        cout << "Thread's creation date: " << d << "." << m << "." << y << endl << endl;
    }
}

void Forum::print_post(const int given_id){
    int i = 0;
    int y = 0;
    int post_id = 0;

    for(i = 0 ; i <= num_of_threads; i++){
        for(y = 0; y <= threads[i]->get_num_of_posts(); y++){
            post_id = threads[i]->get_id_of_post(y);
            if(post_id == given_id) {
                break;
            }
        }
        if(post_id == given_id) {
            break;
        }
    }

    if(post_id != given_id) {
        cout << "No post with id: " << given_id << " exists!" << endl<< endl;
        return;
    }
    else {
        cout << "About to print post with id: " << given_id << endl << endl;
        threads[i]->print_post(y);
    }
}

void Forum::print_sorted() {

    node* roots[num_of_threads];

    for(int i = 0; i <=num_of_threads; i++) {
       roots[i] = threads[i]->thread_enter_tree(*threads[i]);
    }
    node* final;
    for(int i = 0; i <=num_of_threads; i++) {
        node::deleteTree(roots[i]);
    }

}

void Forum::set_title(const string& new_title)
{
    title = new_title;
}

void Forum::set_threads(const Thread& new_thread, int index)
{
    *threads[index] = new_thread;
}


string Forum::get_title() const {
    return title;
}

Thread Forum::get_threads() const
{
    return *threads[0];
}

int Forum::get_num_of_threads() const {
    return num_of_threads;
}

struct node* node::newNode(string username, Post& post)
{
    struct node* temp =  new struct node();
    temp->user = username;
    temp->tree_posts[0] = &post;
    temp->post_num = 0;
    temp->left = temp->right = nullptr;
    cout << "created node with username: " << username << endl;
    return temp;
}

void node::inorder(struct node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout<<"username: " <<root->user<<endl;
        for(int i=0; i <= root->post_num; i++){
            cout <<" id: " << root->tree_posts[i]->get_id() <<endl;
        }
        inorder(root->right);
    }
}

struct node* node::insert_node(struct node* node, string username, Post& post)
{
    //tree is empty;return a new node

    if (node == nullptr) return newNode(username, post);

    //if tree is not empty find the proper place to insert new node

    if (username < node->user)
        node->left  = insert_node(node->left, username, post);
    if(username > node->user)
        node->right = insert_node(node->right, username, post);

    //if same username then just add user's post to post array

    if(username == node->user){
        node->post_num++;
        node->tree_posts[node->post_num] = &post;
        return node;
    }

    //return the node pointer
    return node;
}

void node::deleteTree(node* node)
{
    if (node == nullptr) return;

    /* first delete both subtrees */
    deleteTree(node->left);
    deleteTree(node->right);

    /* then delete the node */
    cout << "Deleting node: " << node->user <<endl;
    delete node;
}