#include <iostream>
#include <ctime>
#include "Forum_constr.h"


using namespace std;





int main() {

    srand((unsigned)time(0));
    int post_id = 0;

    Forum forum1("Αντικειμενοστραφής Προγραμματισμός");
    forum1.print_forum();
    forum1.print_thread("rules3");
    for(int i = 0; i<= 0; i++){
        post_id = rand()%10;
        forum1.print_post(post_id);
    }
    forum1.print_sorted();
    return 0;
}


