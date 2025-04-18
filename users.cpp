#include <iostream>
#include "users.h"

int main() {
    users_admin::create_users_arr();

    userNamespace::User user1("Andriy", 9876543210);
    userNamespace::User user2(2);
    userNamespace::User user3("Maria", 3, 5674839019);

    users_admin::add_users_arr(user1);
    users_admin::add_users_arr(user2);
	users_admin::add_users_arr(user3);
 

    users_admin::show_users_arr();

    users_admin::delete_user(user3);
    users_admin::show_users_arr();


}

