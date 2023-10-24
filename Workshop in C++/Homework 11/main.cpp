/*
Adina Lev
566021464
Homework 11
This program deals with files and registering families for activities.
*/


#include <queue>
#include <iostream>
#include <fstream>
#include "Family.h"
#include <exception>
using namespace std;

enum { EXIT, ADD, DEL, COUNT, UPDATE, WAITING, PRINT };

enum ACTIVITY {
    NONE,
    SWIMMING,
    GYMNASTICS,
    DANCE = 4,
    ART = 8,
    SELF_DEFENSE = 16,
    MUSIC = 32,
    DRAMA = 64,
    BASKETBALL = 128
};

void setFile(fstream& families)
{
    Family fam;
    for (int i = 0; i < 2; i++) { //CHANGE THIS TO 100
        families.write((char*)&fam, sizeof(Family));
    }
}

bool inFile(fstream& families, int id)
{
    //bool flag = false;
    //families.seekg(0, ios::beg); //start at the beginning
    //Family fam;
    //while (!families.eof()) {
    //    families.read((char*)&fam, sizeof(Family));
    //    if (fam.getID() == id) flag = true;
    //}
    //return flag;

    families.seekg((id - 1) * sizeof(Family), ios::beg); //getting to right place in file to read record
    Family fam;
    families.read((char*)&fam, sizeof(Family)); //reading info at that place in database to a temp object

    return (id == fam.getID()); //returns if ids are the same (if doesn't exist will be 0)
}

void add(fstream& families)
{
    Family fam;
    int id, people, phone;
    char lastName[20];
    cout << "enter the family's:  id, name, amount of people and a phone number: " << endl;
    cin >> id >> lastName >> people >> phone;
   // if (inFile(families, id)) throw "Family is already in the file";// if the family does not exist in the database, throw an error
    if (id < 1 || id > 100) throw "ERROR: Invalid family number"; // need to make a catch
    fam.setID(id);
    fam.setName(lastName);
    fam.setFamMems(people);
    fam.setPhone(phone);
    
    //write the family into the record:
    families.seekp((fam.getID() - 1) * sizeof(Family), ios::beg); // why would it not be +?
    families.write((char*)&fam, sizeof(Family));

//    Family fam;
//    int input;
//
//    cout << "Enter the family ID\n";
//    cin >> input;
//    if ((input < 1) || (input > 100)) throw "ERROR: Invalid family number\n";
//
//    bool famExists = inFile(families, input); //checking if id exists
//    if (famExists) throw "ERROR: Family is already in the file\n"; //id found in database so already exists
//
//    fam.setID(input);
//
//    cout << "Enter family name, amount of family members, and a phone number\n";
//    char name[20];
//    cin >> name;
//    fam.setName(name);
//    cin >> input;
//    fam.setFamMems(input);
//    cin >> input;
//    fam.setPhone(input);
//
//    //now will write family into record
//    families.seekp((fam.getID() - 1) * sizeof(Family), ios::beg);
//    families.write((char*)&fam, sizeof(Family));
//}

void del(fstream& families, int id)
{
    if (id < 1 || id > 100) throw "ERROR: Invalid family number"; // need to make a catch
    if (!(inFile(families, id))) throw "Family is not in the file";// if the family does not exist in the database, throw an error
    families.seekp((id - 1) * sizeof(Family), ios::beg);
    int _id = 0;
    families.write((char*)&_id, sizeof(_id));
}

int count(fstream& families, int activity) // short int?
{
    int counter = 0;
    families.seekg(0, ios::beg); // get the file pointer to the beginning
    for (int i = 0; i < 100; i++) {
        Family fam;
        families.read((char*)&fam, sizeof(Family));
        if ((fam.getActivities() & activity) != 0) {
            counter++;
        }
    }
    return counter;
}

void update(fstream& families, int id, queue<Family>& qu)
{
    char ans;
    Family fam;
    if (id < 1 || id > 100) throw "ERROR: Invalid family number"; // need to make a catch
    if (!(inFile(families, id))) throw "Family is not in the file";// if the family does not exist in the database, throw an error
    families.seekg((id - 1) * sizeof(Family), ios::beg);
    families.read((char*)&fam, sizeof(Family));
    short int famActs = fam.getActivities(), waitingActs = 0;
    cout << "Do you want to register for swimming? \n";
    cin >> ans;
    if (ans == 'Y' || 'y') {
        if (count(families, SWIMMING) < 10) 
            famActs |= SWIMMING;   
        else 
            waitingActs |= SWIMMING;
    }
    cout << "Do you want to register for gymnastics? \n";
    cin >> ans;
    if (ans == 'Y' || ans == 'y') {
        if (count(families, GYMNASTICS) < 10) 
            famActs |= GYMNASTICS;
        else 
            waitingActs |= GYMNASTICS;

    }
    cout << "Do you want to register for dance? \n";
    cin >> ans;
    if (ans == 'Y' || ans == 'y') {
        if (count(families, DANCE) < 10)
            famActs |= DANCE;
        else 
            waitingActs |= DANCE;
    }
    cout << "Do you want to register for art? \n";
    cin >> ans;
    if (ans == 'Y' || and == 'y') {
        if (count(families, ART) < 10)
            famActs |= ART;
        else
            waitingActs |= ART;
    }
    cout << "Do you want to register for self defense? \n";
    cin >> ans;
    if (ans == 'Y' || ans == 'y') {
        if (count(families, SELF_DEFENSE) < 10) 
            famActs |= SELF_DEFENSE;
        else 
            waitingActs |= SELF_DEFENSE;
    }
    cout << "Do you want to register for music? \n";
    cin >> ans;
    if (ans == 'Y' || ans == 'y') {
        if (count(families, MUSIC) < 10) 
            famActs |= MUSIC;
        else 
            waitingActs |= MUSIC;
    }
    cout << "Do you want to register for drama? \n";
    cin >> ans;
    if (ans == 'Y' || ans == 'y') {
        if (count(families, DRAMA) < 10)
            famActs |= DRAMA;
        else
            waitingActs |= DRAMA;
    }
    cout << "Do you want to register for basketball? \n";
    cin >> ans;
    if (ans == 'Y' || ans == 'y') {
        if (count(families, BASKETBALL) < 10)
            famActs |= BASKETBALL;
        else
            waitingActs |= BASKETBALL;
    }
    fam.setWaitingActivities(waitingActs);
    qu.push(fam); // pushing the family onto the waiting list for the activities they couldn't sign up for
    fam.setActivities(famActs); // re-setting the activities of the family to include the news ones added
    families.seekp((id - 1) * sizeof(Family), ios::beg);
    families.write((char*)&fam, sizeof(Family));
}

void waiting(queue<Family>& waiting)
{
    Family fam = waiting.front();
    short int waitingActs = fam.getWaitingActivities();
    cout << "family name: " << fam.getName() << endl;
    cout << "number of persons" << fam.getFamMems() << endl;
    cout << "phone number: " << fam.getPhone() << endl;
    if ((waitingActs & SWIMMING) != 0) cout << "SWIMMING \n"; // why does it not like this?
    if ((waitingActs & GYMNASTICS) != 0) cout << "GYMNASTICS \n";
    if ((waitingActs & DANCE) != 0) cout << "DANCE \n";
    if ((waitingActs & ART) != 0) cout << "ART \n";
    if ((waitingActs & SELF_DEFENSE) != 0) cout << "SELF DEFENSE \n";
    if ((waitingActs & MUSIC) != 0) cout << "MUSIC \n";
    if ((waitingActs & DRAMA) != 0) cout << "DRAMA \n";
    if ((waitingActs & BASKETBALL) != 0) cout << "BASKETBALL \n";
    // i think it wants us to do more things but i dont quite understand what it's asking of us
}

void print(fstream& families, int id)
{
    if (id < 1 || id > 100) throw "ERROR: Invalid family number"; // need to make a catch
    if (!(inFile(families, id))) throw "Family is not in the file";// if the family does not exist in the database, throw an error
    Family fam;
    families.seekg((id - 1) * sizeof(Family), ios::beg);
    families.read((char*)&fam, sizeof(Family));
    short int enrolled = fam.getActivities();
    cout << "family name: " << fam.getName() << endl;
    cout << "number of persons: " << fam.getFamMems() << endl;
    cout << "phone number: " << fam.getPhone() << endl;
    if ((enrolled & SWIMMING) != 0) cout << "SWIMMING \n"; // why does it not like this?
    if ((enrolled & GYMNASTICS) != 0) cout << "GYMNASTICS \n";
    if ((enrolled & DANCE) != 0) cout << "DANCE \n";
    if ((enrolled & ART) != 0) cout << "ART \n";
    if ((enrolled & SELF_DEFENSE) != 0) cout << "SELF DEFENSE \n";
    if ((enrolled & MUSIC) != 0) cout << "MUSIC \n";
    if ((enrolled & DRAMA) != 0) cout << "DRAMA \n";
    if ((enrolled & BASKETBALL) != 0) cout << "BASKETBALL \n";
}

// to test whether a family with a specific id number exists in the file
//bool exists(fstream families, int id) // should this be &?
//{
//    families.seekg((id - 1) * sizeof(Family), ios::beg); //getting to right place in file to read record
//    Family fam;
//    families.read((char*)&fam, sizeof(Family)); //reading info at that place in database to a temp object
//    return (id == fam.getID()); //returns if ids are the same (if doesn't exist will be 0)
//}

//bool inFile(fstream& families, int id)
//{
//    bool flag = false;
//    families.seekg(0, ios::beg); //start at the beginning
//    Family fam;
//    while (!families.eof()) {
//        families.read((char*)&fam, sizeof(Family));
//        if (fam.getID() == id) flag = true;
//    }
//    return flag;
//}

void handleCount(fstream& file) {
    int snum;
    cout << "enter activity number to count:\n";
    cout << "Choices are:\n1 SWIMMING\n2 GYMNASTICS\n3 DANCE\n4 ART\n5 SELF DEFENSE \n6 MUSIC \n7 DRAMA\n8 BASKETBALL\n";
    cin >> snum;
    cout << "there are ";
    switch (snum) {
    case 1:
        cout << count(file, SWIMMING);
        break;
    case 2:
        cout << count(file, GYMNASTICS);
        break;
    case 3:
        cout << count(file, DANCE);
        break;
    case 4:
        cout << count(file, ART);
        break;
    case 5:
        cout << count(file, SELF_DEFENSE);
        break;
    case 6:
        cout << count(file, MUSIC);
        break;
    case 7:
        cout << count(file, DRAMA);
        break;
    case 8:
        cout << count(file, BASKETBALL);
        break;
    }
    cout << " families registered\n";
}


int main()
{
    queue<Family> q;

    queue<Family> jv;
    fstream file;
    file.open("families.txt", ios::binary | ios::out);

    if (!file)
    {
        cout << "ERROR: couldn't open file\n";
        return 0;
    }
    setFile(file);
    file.close();

    file.open("families.txt", ios::binary | ios::in | ios::out);
    int choice;
    int snum;
    int cnum;
    cout << "Choices are:\n0 to exit\n1 to add a family\n2 to delete a family\n3 to  count number of families signed up\n4 to update the activities of a family \n5 print the waiting list \n6 to print a family\n";
    cout << "enter 0-6:\n";
    cin >> choice;
    while (choice) {
    try {
        switch (choice)
        {
        case ADD://add to the file
            add(file);
            break;
        case DEL://delete from file
            cout << "enter number of family to delete:\n";
            cin >> snum;
            del(file, snum);
            break;
        case COUNT:
            handleCount(file);
            break;
        case UPDATE://update the list of classes of a family
            cout << "enter number of family to update:\n";
            cin >> snum;
            update(file, snum, jv);
            break;
        case WAITING://update the list of classes of a waiting family
            waiting(jv);
            break;

        case PRINT://print the details of a specific family
            cout << "enter number of family to print:\n";
            cin >> snum;
            print(file, snum);
            break;
        default:
            cout << "ERROR: invalid choice\n";

        }
    }// try
    catch (exception& e) {
        cout << e.what();
    }
    catch (const char* msg) { // added this
        cout << msg << endl;
    }
    cout << "\nenter 0-6:\n";
    cin >> choice;

    }
    file.close();
    return 0;
}
