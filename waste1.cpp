
// #include <bits/stdc++.h>
// using namespace std;

// struct student
// {
//     string name;
//     int regno;
//     float marks1;
//     float marks2;
//     struct student *next;
// };

// struct student *node, *head;
// char choice1[1];
// void add_data();
// void search_data();
// void display_data();

// int main()
// {
//     int choice;
//     cout << endl;
//     node = NULL;
// add:
//     cout << "1) Add Record 2) Search Data 3) Display Data" << endl;
//     cout << "Choose Desired Function!" << endl;
//     cin >> choice;

//     // system("cls");
//     if (choice == 1)
//     {
//         add_data();
//         cout << "Press 'Y' To Perform Another Function Or 'N' To Exit.\n"
//              << endl;
//         cin >> choice1[1];
//         if (choice1[1] == 'Y' || choice1[1] == 'y')
//         {
//             goto add;
//         }
//         else if (choice1[1] == 'N' || choice1[1] == 'n')
//         {
//             return 0;
//         }
//     }
//     else if (choice == 2)
//     {
//         search_data();
//         cout << "Press 'Y' To Perform Another Function Or 'N' To Exit.\n"
//              << endl;
//         cin >> choice1[1];
//         if (choice1[1] == 'Y' || choice1[1] == 'y')
//         {
//             goto add;
//         }
//         else if (choice1[1] == 'N' || choice1[1] == 'n')
//         {
//             return 0;
//         }
//     }
//     else if (choice == 2 && node == NULL)
//     {
//         cout << "No Data Detected" << endl;
//     }
//     else if (choice == 3)
//     {
//         display_data();
//         cout << "Press 'Y' To Perform Another Function Or 'N' To Exit.\n"
//              << endl;
//         cin >> choice1[1];
//         if (choice1[1] == 'Y' || choice1[1] == 'y')
//         {
//             goto add;
//         }
//         else if (choice1[1] == 'N' || choice1[1] == 'n')
//         {
//             return 0;
//         }
//     }
//     else if (choice == 3 && node == NULL)
//     {
//         cout << "No Data Detected" << endl;
//     }
//     return 0;
// }

// void add_data()
// {
//     string e;
//     int b;
//     float d, dd;
//     cout << "Student Name." << endl;
//     cin >> e;
//     cin.ignore();
//     cout << "Enter registration number" << endl;

//     cin >> b;
//     cout << "Enter marks CAT 1" << endl;
//     cin >> d;
//     cout << "Enter marks CAT 2" << endl;
//     cin >> dd;
//     if (node == NULL)
//     {
//         node = new student;
//         node->name = e;
//         node->regno = b;
//         node->marks1 = d;
//         node->marks2 = dd;
//         node->next = NULL;
//         head = node;
//     }
//     else
//     {
//         node->next = new student;
//         node->next->name = e;
//         node->next->regno = b;
//         node->next->marks1 = d;
//         node->next->marks2 = dd;
//         node = node->next;
//     }
//     node->next = NULL;
// }

// void display_data()
// {
//     node = head;
//     while (node != NULL)
//     {
//         cout << "\n\tName=" << node->name << endl;

//         cout << "\tRegistration No=" << node->regno << endl;
//         cout << "\tCAT 1 Marks=" << node->marks1 << endl;
//         cout << "\tCAT 2 Marks=" << node->marks2 << endl;
//         node = node->next;
//     }
// }

// void search_data()
// {
//     int choice2;
//     int flag = -1;
//     cout << "Enter PASS mark" << endl;
//     cin >> choice2;

//     node = head;
//     cout << "FAILED IN CAT1" << endl;

//     while (node != NULL)
//     {
//         if (node->marks1 < choice2)
//         {
//             flag = 1;
//             cout << node->name << "   " << node->regno << endl;
//         }
//         node = node->next;
//     }
//     if (flag != 1)
//     {
//         cout << "Record Not Found." << endl;
//     }
//     node = head;
//     cout << "FAILED IN CAT2" << endl;

//     while (node != NULL)
//     {
//         if (node->marks2 < choice2)
//         {
//             flag = 1;
//             cout << node->name << "   " << node->regno << endl;
//         }
//         node = node->next;
//     }
//     if (flag != 1)
//     {
//         cout << "Record Not Found." << endl;
//     }

//     node = head;
//     cout << "FAILED IN BOTH CAT1 and CAT2" << endl;

//     while (node != NULL)
//     {
//         if (node->marks1 < choice2 && node->marks2 < choice2)
//         {
//             flag = 1;
//             cout << node->name << "   " << node->regno << endl;
//         }
//         node = node->next;
//     }
//     // if (flag == 1)
//     // {
//     //     // cout << "Record Found." << endl;
//     // }
//     if (flag != 1)
//     {
//         cout << "Record Not Found." << endl;
//     }
// }
