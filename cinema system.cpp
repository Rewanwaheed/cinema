#include<iostream>
using namespace std;
string* arr_for_username;
int* arr_for_password;
int sizee = 20;
bool mousa = true;
int total_price;
bool enque;

void data_base() {
    arr_for_username = NULL;
    arr_for_username = new string[sizee];
    arr_for_password = NULL;
    arr_for_password = new int[sizee];
}
void login(string u, int p) {
    bool ahmed = false;
    bool hazem = false;
    int counter = 0;
    for (int i = 0; i < sizee; ++i) {
        if (arr_for_username[i] == u) {
            ahmed = true;
            counter = i;
            break;
        }
    }
    if (ahmed) {
        if (arr_for_password[counter] == p) {
            hazem = true;
        }


    }
    if (ahmed == false) {
        cout << "Sorry, we can't find an account with this username" << endl;
        mousa = false;

    }
    else if (ahmed == true && hazem == false) {
        cout << "Incorrect password." << endl;
        mousa = false;
    }
}
void admin() {
    arr_for_username[0] = "ahmed_hazem";
    arr_for_password[0] = 1234;

}
int i = 1;
void create(string x, int y) {
    bool check = false;
    for (int j = 0; j < sizee; ++j) {

        if (x == arr_for_username[j]) {
            check = true;
            break;

        }
    }
    if (check == false) {
        arr_for_username[i] = x;
        arr_for_password[i] = y;
        i++;
        sizee++;
        cout << "\t" << "REGISTRATION COMPLETED SUCCESSFULLY" << endl;
    }
    else {
        cout << "\t" << "THE USERNAME YOU ENTERED IS ALREADY TAKEN. PLEASE CHOOSE A DIFFERENT ONE" << endl;
    }
}
struct node {
    string time;
    string name;
    node* next;
};
node* head = NULL;

void add_film(string y) {
    node* new_node = new node;
    new_node->name = y;
    new_node->next = NULL;
    node* last;
    if (head == NULL) {
        head = new_node;
    }
    else {
        last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
    }
}
void list_film() {
    node* temp;
    temp = head;
    if (head == NULL) {
        cout << "\t" << "We regret to inform you that there are no films available for viewing at the cinema at this time";
    }
    else {
        while (temp != NULL) {
            cout << temp->name;
            cout << temp->time << "\t";
            temp = temp->next;
        }
    }
    cout << endl;
}

bool search(string x) {
    node* temp;
    temp = head;
    if (head == NULL) {
        cout << "We regret to inform you that there are no films available for viewing at the cinema at this time" << endl;

    }
    else {
        while (temp != NULL) {
            if (temp->name == x) {
                return true;
            }
            temp = temp->next;
        }


    }
    return false;
}

struct nodee {
    int data;
    char clas;
    nodee* nexxt;
};

nodee* last_out = NULL;
nodee* first_out = NULL;

void reservation(int x, char y) {
    nodee* new_res = new nodee;
    new_res->data = x;
    new_res->clas = y;
    new_res->nexxt = NULL;
    if (last_out == NULL) {
        last_out = new_res;
        first_out = new_res;
    }
    else {
        new_res->nexxt = last_out;
        last_out = new_res;
    }
}
///--------------------------------------------------------
bool sear_rever(int a) {///check if info right or not
    nodee* temp = first_out;
    if (first_out == NULL) {
        cout << "No chairs have been reserved yet.";
        return false;
    }
    else {
        while (temp != NULL) {
            if (temp->data == a) {
                cout << "This chair is taken. Please choose another one";
                return false;

            }
            temp = temp->nexxt;
        }
        return true;
    }

}
bool search_rever(int x) {
    nodee* temp = first_out;
    if (first_out == NULL) {
        return true;
    }
    else {
        while (temp != NULL) {
            if (temp->data == x) {
                return false;
            }
            temp = temp->nexxt;
        }
        return true;

    }
}

void deletee_reser(int x) {
    nodee* temp;
    temp = first_out;
    while (temp != NULL) {
        if (temp->data == x) {
            first_out = temp->nexxt;
            delete temp;
            break;

        }
        else {
            int w = temp->data;
            char q = temp->clas;
            reservation(w, q);
            first_out = temp->nexxt;
            delete temp;



        }

    }
    cout << "\t" << "  " << "Operation completed successfully" << endl;

}

///-------------------------------------------------------------
struct category {
    int price;
    char cat;
    category* nexxxt;
};

category* top = NULL;

void add_cat(int x, char z) {
    category* new_cat = new category;
    new_cat->price = x;
    new_cat->cat = z;
    if (top == NULL) {
        top = new_cat;
        new_cat->nexxxt = NULL;
    }
    else {
        new_cat->nexxxt = top;
        top = new_cat;

    }


}

void dis_cat() {
    category* temp;
    temp = top;
    while (temp != NULL) {
        cout << "class" << temp->cat << "  " << "the price:" << temp->price << "EGP" << "\t" << "   ";
        temp = temp->nexxxt;
    }
    cout << endl;
}


void payment_method(string x) {
    if (x == "CASH") {
        cout << "thanks" << endl;
    }
    else {

        cout << "\t" << "the operation was completed successfully" << endl;
    }



}



int main() {
    cout << "\t" << "\t" << "\t" << "\t" << "\t" << "   " << "WELCOME TO THE CINEMA" << endl << endl;
    add_cat(1000, 'A');
    add_cat(500, 'B');
    add_cat(150, 'C');

    data_base();
    admin();
    cout << "do you have account(Yes/No):";
    string question;
    cin >> question;
    string a;
    int x;
    add_film("aaa");
    while (question == "NO" || question == "no" || question == "N" || question == "n" || question == "No") {
        cout << "REGISTRATION" << endl;
        cout << "Enter your username:";
        cin >> a;
        cout << "password:";
        cin >> x;
        create(a, x);
        cout << "do you have account(Yes/No):";
        cin >> question;

    }
    cout << "complete steps to login" << endl;
    cout << "LOGIN" << endl;
    cout << "Enter your username:";
    cin >> a;
    cout << "password:";
    cin >> x;
    login(a, x);
    int u;
    string fav;
    string payment;
    category ahmed;
    ahmed.price;
    string name_of_film;
    if (mousa) {
        string contniue;
        cout << "Would you like to continue?";
        cin >> contniue;
        while (contniue == "YES" || contniue == "yes" || contniue == "y" || contniue == "Y" || contniue == "Yes") {
            cout << "\t" << "\t" << "1-booking tickets" << endl;
            cout << "\t" << "\t" << "2-retrieval tickets" << endl;
            cout << "\t" << "\t" << "3-contact us" << endl;
            cout << "Which operation would you like to perform?";
            cin >> u;
            int numofset;
            char categories;


            if (u == 1) {
                list_film();
                cout << "choose film you want to watch it from list:";
                cin >> fav;
                if (search(fav) == true) {
                    cout << "Great choice for the movie" << endl;
                }
                else {
                    cout << "Unfortunately, this film is not currently available" << endl;
                }
                dis_cat();
                ///--------------------------------------------------------------------
                string res_again = "yes";
                while (res_again == "yes" || res_again == "YES" || res_again == "y" || res_again == "Y") {
                    cout << "Please enter the number of chair you would like to reserve:";
                    cin >> numofset;
                    cout << "Please enter the category of the ticket(A,B,C)";
                    cin >> categories;
                    if (search_rever(numofset) == false) {
                        continue;
                    }
                    reservation(numofset, categories);
                    cout << "Do you need another chair?";
                    cin >> res_again;
                }
                ///-------------------------------------------------------------------------
                cout << "the payment method:" << endl;
                cout << "\t" << "  " << "VISA" << endl << "\t" << "  " << "CASH" << endl << "\t" << "  "
                    << "MOBILE PAYMENT" << endl;
                cout << "what is your suitable payment method:" << endl;
                cin >> payment;
                payment_method(payment);
            }
            else if (u == 2) {
                cout << "name of film you reserve it:";
                cin >> name_of_film;
                if (search(name_of_film) == false) {
                    cout << "There is no film with this name";
                    return 0;
                }
                else {
                    int f;
                    cout << "What is the number of chairs you would like to cancel the reservation for?";
                    cin >> f;
                    while (f--) {

                        string cancel;
                        cout << "Do you want to cancel your reservation?(y/n)";
                        cin >> cancel;
                        if (cancel == "YES" || cancel == "yes" || cancel == "Y" || cancel == "y" || cancel == "Yes") {
                            int y;
                            cout << "Please enter the number of chairs you have reserved";
                            cin >> y;
                            deletee_reser(y);

                        }
                        else {
                            return 0;
                        }

                    }
                }


            }
            else {
                cout << "ahmed1234hazem@gmail.com" << endl;
                cout << "01274346758";
            }


            cout << "Would you like to go back ?";
            cin >> contniue;
        }
    }



    return 0;
}

