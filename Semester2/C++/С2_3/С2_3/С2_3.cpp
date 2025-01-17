﻿//#include <iostream>
//#include <string>
//
//using namespace std;
//
//// Public:
////     initialize(void): initializing surname(str); name(str); patronymic(str); address(str); birthYear(int);
////                       phone(str); height(int); weight(int); gender(int);
////     print(void): Show all options
//class Person {
//public:
//    string surname;
//    string name;
//    string patronymic;
//    string address;
//    int birthYear;
//    string phone;
//    int height;
//    int weight;
//    char gender;
//
//    void initialize() {
//        cout << "Enter surname: "; cin >> surname;
//        cout << "Enter name: "; cin >> name;
//        cout << "Enter patronymic: "; cin >> patronymic;
//        cout << "Enter address: ";  cin >> address;
//        cout << "Enter birth year: "; cin >> birthYear;
//        cout << "Enter phone: "; cin >> phone;
//        cout << "Enter height: "; cin >> height;
//        cout << "Enter weight: "; cin >> weight;
//        cout << "Enter gender (M/F): "; cin >> gender;
//    }
//
//    void print() {
//        cout << "Surname: " << surname << endl;
//        cout << "Name: " << name << endl;
//        cout << "Patronymic: " << patronymic << endl;
//        cout << "Address: " << address << endl;
//        cout << "Birth year: " << birthYear << endl;
//        cout << "Phone: " << phone << endl;
//        cout << "Height: " << height << endl;
//        cout << "Weight: " << weight << endl;
//        cout << "Gender: " << gender << endl;
//    }
//
//    friend int countByGender(Person* people, int n, char gender);
//};
//
////  doc: 
////     Show the number of people with the selected gender 
////  args:
////      people(person*): array with all person
////      n(int): how many people
////      gender(char): gender for search (M - man /F - female)
////  return:
////      count(int): quality how many people with selected gender
////
//int countByGender(Person* people, int n, char gender) {
//    int count = 0;
//    for (int i = 0; i < n; i++) {
//        if (people[i].gender == gender) {
//            count++;
//        }
//    }
//    return count;
//}
//
////  variables:
////      n(int): how many people
////      count(int): quality how many people with selected gender
////      gender(char): gender for search (M - man /F - female)
//int main() {
//    int n, count;
//    char gender;
//
//    cout << "Enter number of people: "; cin >> n;
//
//    Person* people = new Person[n];
//
//    for (int i = 0; i < n; i++) {
//        cout << "\n\nEnter information for person " << i + 1 << ":" << endl;
//        people[i].initialize();
//    }
//
//    while (true) {
//        cout << "-------------People list---------------" << endl;
//        for (int i = 0; i < n; i++) {
//            people[i].print();
//            cout << endl;
//        }
//        cout << "---------------------------------------" << endl;
//
//        cout << "Enter gender to count (M/F): "; cin >> gender;
//
//        count = countByGender(people, n, gender);
//
//        cout << "Number of people with gender " << gender << ": " << count << endl;
//
//        system("PAUSE");
//        system("cls");
//    }
//
//    delete[] people;
//    return 0;
//}

#include <iostream>
#include <string>

using namespace std;


// Public:
//     init: initializing surname(str); name(str); patronymic(str); address(str); birthYear(int);
//                       phone(str); height(int); weight(int); gender(int);
//     print(void): Show all options
//     countByGender(char): how mach person by gender
class Person {
public:
    string surname;
    string name;
    string patronymic;
    string address;
    int birthYear;
    string phone;
    int height;
    int weight;
    char gender;

    Person() {}

    Person(string surname, string name, string patronymic, string address,
        int birthYear, string phone, int height, int weight, char gender)
        : surname(surname), name(name), patronymic(patronymic), address(address),
        birthYear(birthYear), phone(phone), height(height), weight(weight), gender(gender) {}

    void print() {
        cout << "\n";
        cout << "Surname: " << surname << endl;
        cout << "Name: " << name << endl;
        cout << "Patronymic: " << patronymic << endl;
        cout << "Address: " << address << endl;
        cout << "Birth year: " << birthYear << endl;
        cout << "Phone: " << phone << endl;
        cout << "Height: " << height << endl;
        cout << "Weight: " << weight << endl;
        cout << "Gender: " << gender << endl;
    }

    int countByGender(char gender) {
        int count = 0;
        if (this->gender == gender) {
            count++;
        }
        return count;
    }
};


//  variables:
//      n(int): how many people
//      count(int): quality how many people with selected gender
//      gender(char): gender for search (M - man /F - female)
int main() {
    int n;
    cout << "Enter number of people: "; cin >> n;

    Person* people = new Person[n];

    for (int i = 0; i < n; i++) {
        string surname, name, patronymic, address, phone;
        int birthYear, height, weight;
        char gender;

        cout << "Enter details for person #" << i + 1 << ":" << endl;

        cout << "Surname: "; cin >> surname;
        cout << "Name: "; cin >> name;
        cout << "Patronymic: "; cin >> patronymic;
        cout << "Address: "; cin >> address;
        cout << "Birth year: "; cin >> birthYear;
        cout << "Phone: "; cin >> phone;
        cout << "Height: "; cin >> height;
        cout << "Weight: "; cin >> weight;
        cout << "Gender (M/F): "; cin >> gender;

        people[i] = Person(surname, name, patronymic, address, birthYear, phone, height, weight, gender);
    }

    for (int i = 0; i < n; i++) {
        people[i].print();
    }
    cout << "\n";
    char gender;
    cout << "Enter gender to count (M/F): "; cin >> gender;

    int count = 0;
    for (int i = 0; i < n; i++) {
        count += people[i].countByGender(gender);
    }
    cout << "Number of people with gender " << gender << ": " << count << endl;

    delete[] people;
    return 0;
}
