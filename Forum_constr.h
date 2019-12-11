//
// Created by user on 02/12/2019.
//

#ifndef OOP1_FORUM_CONSTR_H
#define OOP1_FORUM_CONSTR_H



#include <string>
#include <iostream>
#include "Thread_constr.h"
#include "Post_constr.h"

using namespace std;



struct node{
public:
    struct node *newNode(string user, Post& post);
    void inorder(struct node *root);
    struct node* insert_node(struct node* node, string user, Post& post);
    static void deleteTree(node* node);

    node():tree_posts(){};

    ~node(){};
private:
    string user;
    Post* tree_posts[20];
    int post_num;
    node* left;
    node* right;


};

class Forum{
public:
    Forum(const string& title);
    ~Forum();

    void set_title(const string&);
    void set_threads(const Thread&, int index);
    void print_forum();
    void print_thread(const string&);
    void print_post(int);
    void print_sorted();

    string get_title() const;
    Thread get_threads() const;
    int get_num_of_threads() const;

private:
    string title;
    int num_of_threads;
    Thread* threads[5];
};

#endif //OOP1_FORUM_CONSTR_H