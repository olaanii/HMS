/*              TITLE:   HOSPITAL MANAGEENT SYSTEM
           Group Members                     ID

           olani     Shambel                  UGR/31097/15
           Mekdes    Urgi                     UGR/30875/15
           Teshome   Worku                    UGR/31291/15
           Tsion     Wubshet                  UGR/31333/15
           Yohanis   Tulu                     UGR/31420/15

*/
// This is a C++ program that includes several standard libraries.
#include<iostream> // This library is for input and output operations.
#include<conio.h> // This library is for console input and output operations.
#include<string.h> // This library is for string manipulation operations.
#include<stdlib.h> // This library is for general purpose operations.
#include<fstream> // This library is for file input and output operations.
#include<sstream> // This library is for string stream operations.
using namespace std;

// Structure to store patient data
struct patient
{
    long long ID;
    string firstname;
    string lastname;
    int age;
    char blood[5];
    char gender;
    patient* next;
};

// Class to implement a linked queue
class queue
{
    patient* head, * last;
public:
    queue() //constructor
    {
        head = NULL;
        last = NULL;
    }
    // Method to get patient input
    patient input();
    // Method to insert patient at the end of the queue
    void insertatend();
    // Method to insert patient at the beginning of the queue
    void insertatbeg();
    // Method to remove and return patient from the front of the queue
    void getpatientout();
    // Method to display list of all patients in the queue
    void listofpatients();
    // Method to search for a patient by their ID
    int search(int);
    // Character array to store department name
    char departmentname[50];
};

// Method to search for a patient by their ID
int queue::search(int item)
{
    if (head == NULL)
        return false;
    else
    {
        int flag = 0;
        patient* p = new patient();
        p = head;

        while (p->next != NULL && p->ID != item)
        {
            p = p->next;
        }
        if (p->ID == item)
        {
            flag = 1;
            return true;
        }
        {if (flag == 0)
            return false;}
    }
}

// Function to read an integer from the console
int readnumber()
{
    char b[20];
    cin.getline(b, sizeof(b));
    return atoi(b);
}

// Method to get patient input
patient queue::input()
{
    int flag = 0;
    patient* p = new patient();
    cout << "\n   Please enter data for patient\n";
    cout << "\n   First name     : ";
    ofstream file;
    file.open("Patient.txt", ios::out | ios::app);
    getline(cin, p->firstname);
    file << "First Name : " << p->firstname<<endl;
    cout << "   Last name      : ";
    getline(cin, p->lastname);
    file <<"Last Name : " << p->lastname<<endl;
again:
    cout << "   Blood Group    : ";
    cin >> p->blood;
    file <<"Blood Group : "<< p->blood<<endl;
    if ((strcmp(p->blood, "A+") == 0) || (strcmp(p->blood, "a+") == 0) || (strcmp(p->blood, "A-") == 0) || (strcmp(p->blood, "a-") == 0) ||
        (strcmp(p->blood, "B+") == 0) || (strcmp(p->blood, "b+") == 0) || (strcmp(p->blood, "B-") == 0) || (strcmp(p->blood, "b-") == 0) ||
        (strcmp(p->blood, "O+") == 0) || (strcmp(p->blood, "o+") == 0) || (strcmp(p->blood, "O-") == 0) || (strcmp(p->blood, "o-") == 0) ||
        (strcmp(p->blood, "AB+") == 0) || (strcmp(p->blood, "ab+") == 0) || (strcmp(p->blood, "AB-") == 0) || (strcmp(p->blood, "ab-") == 0))
        flag = 1;
    if (flag == 0)
    {
        cout << "\n   Invalid Blood Group Try Again..\n\n";
        goto again;

    }
    cout << "   Gender(m/f)    : ";
    cin >> p->gender;
    file <<"Gender(m/f): "<< p->gender << endl;
    cout << "   Age            : ";
    cin >> p->age;
    file <<"Age: "<< p->age<<endl;
    cout << "   Mobile number  : +251";
    cin >> p->ID;
    file <<"Mobile number: +251"<<p->ID<<endl;
    file <<"\n"<<endl;
    file.close();

    if (search(p->ID))
    {
        p->ID = 0;
        cout << "\n   Data not valid. Operation cancelled.";
    }
    return *p;
}

// This function displays the history of patients.
void queue_history(){
    system("cls"); // Clears the console screen.
    string line; // Declares a string variable to store each line of the file.
    ifstream file("Patient.txt"); // Opens the file "Patient.txt" for reading.
    while(getline(file,line)){ // Reads each line of the file and stores it in the string variable "line".
        cout << line << endl; // Prints the line to the console.
    }
    file.close(); // Closes the file.
}

// This function displays the details of a patient.
void output(patient* p)
{
    cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n   Patient data:\n";
    cout << "\n   First Name         : " << p->firstname;
    cout << "\n   Last Name          : " << p->lastname;
    cout << "\n   Gender             : " << p->gender;
    cout << "\n   Age                : " << p->age;
    cout << "\n   Blood Group        : " << p->blood;
    cout << "\n   Mobile Number      : " << p->ID;
    cout << "\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
}

// This function inserts a patient at the beginning of the queue.
void queue::insertatbeg()
{
    patient* p = new patient(); // Creates a new patient object.
    *p = input(); // Gets the patient's details from the user.
    if (p->ID == 0) // If the patient's ID is 0, the patient is not added to the queue.
        return;

    if (head == NULL) // If the queue is empty, the patient is added as the first patient.

    {
        head = p;
        last = p;
        p->next = NULL;
    }
    else
    {
        p->next = head; // The patient is added at the beginning of the queue.
        head = p;
    }
    system("cls"); // Clears the console screen.
    cout << "\n\tPatient added:";
    output(p); // Displays the details of the patient.
}

// This function inserts a patient at the end of the queue.
void queue::insertatend()
{
    patient* p = new patient(); // Creates a new patient object.
    *p = input(); // Gets the patient's details from the user.
    if (p->ID == 0) // If the patient's ID is 0, the patient is not added to the queue.
        return;

    if (head == NULL) // If the queue is empty, the patient is added as the first patient.
    {
        head = p;
        last = p;
        p->next = NULL;
    }
    else
    {
        p->next = NULL; // The patient is added at the end of the queue.
        last->next = p;
        last = p;
    }
    system("cls"); // Clears the console screen.
    cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n  |--  HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
    cout << "\n  ----------PATIENT ADDED-----------";
    output(p); // Displays the details of the patient.
}

// This function removes the first patient from the queue.
void queue::getpatientout()
{
    system("cls"); // Clears the console screen.
    if (head == NULL) // If the queue is empty, a message is displayed.
    {
        cout << "\n  No Patient to operate";
    }
    else
    {
        patient* p = new patient(); // Creates a new patient object.
        p = head; // The patient object is assigned the first patient in the queue.
        head = head->next; // The first patient is removed from the queue.
        cout << "\n  Patient to operate:";
        output(p); // Displays the details of the patient.
    }
}

// This function displays the list of patients in the queue.
void queue::listofpatients()
{
    if (head == NULL) // If the queue is empty, a message is displayed.
    {
        cout << "\n  No patient";
    }
    system("cls"); // Clears the console screen.
    cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n  |--  HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
    patient* p = new patient; // Creates a new patient object.
    p = head; // The patient object is assigned the first patient in the queue.
    while (p != NULL) // The loop continues until the last patient is reached.
    {
        cout << "\n   Patient data:\n";
        cout << "\n   First Name       : " << p->firstname;
        cout << "\n   Last Name        : " << p->lastname;
        cout << "\n   Gender           : " << p->gender;
        cout << "\n   Age              : " << p->age;
        cout << "\n   Blood Group      : " << p->blood;
        cout << "\n   Mobile Number    : " << p->ID;
        cout << "\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
        p = p->next; // The patient object is assigned the next patient in the queue.
    }
    cout << "\n"; // A newline is printed.
}


// This function displays the department menu.
void departmentmenu(queue* q)
{
    int choice = 0, success; // Declares and initializes variables.
    patient p; // Declares a patient object.
    while (choice != 5) // The loop continues until the user chooses to exit.
    {
        system("cls"); // Clears the console screen.
        cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout << "\n  |--  HOSPITAL MANAGEMENT SYSTEM --|";
        cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout << "\n\n   " << q->departmentname; // Displays the department name.
        cout << "\n   [1] Add normal patient\n";
        cout << "   [2] Add critically ill patient\n";
        cout << "   [3] Take patient to Doctor\n";
        cout << "   [4] Display list\n";
        cout << "   [5] Change department or exit\n";
        cout << "\n   Please enter your choice : ";
        choice = readnumber(); // Reads the user's choice.
        cout << "  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";

        switch (choice) // A switch statement is used to handle the user's choice.
        {
        case 1:	q->insertatend(); // Calls the insertatend() function to add a normal patient.
            cout << "\n   Press any key";
            getch(); // Pauses the console until a key is pressed.
            break;

        case 2:	q->insertatbeg(); // Calls the insertatbeg() function to add a critically ill patient.
            cout << "\n   Press any key";
            getch(); // Pauses the console until a key is pressed.
            break;

        case 3:	q->getpatientout(); // Calls the getpatientout() function to remove the first patient from the queue.
            cout << "\n   Press any key";
            getch(); // Pauses the console until a key is pressed.
            break;

        case 4:	system("cls"); // Clears the console screen.
            q->listofpatients(); // Calls the listofpatients() function to display the list of patients.
            cout << "\n   Press any key";
            getch(); // Pauses the console until a key is pressed.
            break;
        }
    }
}

// This is the main function of the program.
int main()
{
    int i, choice = 0; // Declares and initializes variables.
    queue departments[5]; // Declares an array of linkedqueue objects.

    while (choice != 6) // The loop continues until the user chooses to exit.
    {
        strcpy(departments[0].departmentname, "GENERAL CLINIC\n"); // Copies the department name to the first linkedqueue object.
        strcpy(departments[1].departmentname, "HEART CLINIC\n"); // Copies the department name to the second linkedqueue object.
        strcpy(departments[2].departmentname, "LUNG CLINIC\n"); // Copies the department name to the third linkedqueue object.
        strcpy(departments[3].departmentname, "EYE CLINIC\n"); // Copies the department name to the fourth linkedqueue object.
        strcpy(departments[4].departmentname, "PLASTIC SURGERY\n"); // Copies the department name to the fifth linkedqueue object.
        system("cls"); // Clears the console screen.
        cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout << "\n  |--  HOSPITAL MANAGEMENT SYSTEM --|";
        cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";
        cout << "   Main Menu\n\n"; // Displays the main menu.
        for (i = 0; i < 5; i++) // A loop is used to display the department names.
        {
            cout << "   " << (i + 1) << ": " << departments[i].departmentname;
        }
        cout << "   6: EXIT"; // Displays the exit option.
        cout << "\n\n   Please enter your choice : ";
        choice = readnumber(); // Reads the user's choice.
        if (choice >= 1 && choice <= 5) // If the user chooses a valid department, the department menu is displayed.
        {
            departmentmenu(&departments[choice - 1]); // Calls the departmentmenu() function to display the department menu.
        }
        system("cls"); // Clears the console screen.
    }
    if (choice == 6){ // If the user chooses to exit, a message is displayed.
        cout << "\n\t\t  Thank you! \n";
        cout <<"\n\t HOSPITAL MANAGEMENT SYSTEM\n"<< endl;}
        cout << "    \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";
    exit(0); // Exits the program.
}
/*  This is a C++ program that implements a hospital management system using a  queue data structure.
    The program includes several standard libraries, such as iostream, conio.h, string.h, stdlib.h, fstream, and sstream,
    which are used for input/output, console input/output, string manipulation, general purpose operations, file input/output,
    and string stream operations, respectively.

    The program consists of several classes and structures, including patient, queue, and department.
    The patient structure stores patient data such as ID, first name, last name, age, blood group, gender,
    and a pointer to the next patient in the queue. The queue class implements a queue data
    structure and provides methods for adding, removing, searching, and displaying patients. The department
    structure stores the department name.

    The program begins by declaring several variables, including choice, i, p, and success. The choice variable
    stores the user's choice, i is a loop index, p is a patient object, and success is a variable used to track
    the success of an operation.

    The code then defines a main function that initializes the hospital management system. The program displays
    the main menu, which includes options for adding a normal patient, adding a critically ill patient, taking a
    patient to the doctor, displaying the list of patients, changing departments, or exiting the program.

    If the user chooses a valid department, the department menu is displayed. This menu allows the user to add a
    normal patient, add a critically ill patient, take a patient to the doctor, display the list of patients, or
    change departments.

    The code is well-structured and easy to understand. However, there are a few areas where the code could be improved:

    1.The program uses strcpy to copy the department name to the department structure, which is inefficient and could be
    replaced with a more efficient method.
    2.The program uses system("cls") to clear the console screen, which can be slow and cause performance issues. A more
    efficient approach would be to use a library that provides a faster and more reliable way to clear the console screen.
    3.The program uses getch to pause the console, which can be unreliable and cause issues in some environments. A more robust
    approach would be to use a library that provides a more reliable way to pause the console.


    Overall, it is a program  to implement a hospital management system using a queue data structure in C++
*/
