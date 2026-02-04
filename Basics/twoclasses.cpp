#include <iostream>
using namespace std;

class student {
public:
    string name;
    string place;
    int id;
    void details();
};

class emp {
public:
    int emp_id;
    int salary;
    void details();
};

void student::details() {
	cout << "name: " << name << "\n";
	cout << "place: " << place << "\n";
	cout << "id: " << id << "\n";
}

void emp::details() {
	cout << "emp_id: " << emp_id << "\n";
	cout << "salary: " << salary << "\n";
}

int main() {
    student s;
    s.name = "Anurag";
    s.place = "BBS";
    s.id = 101;
    emp e;
    e.emp_id = 501;
    e.salary = 50000;

    cout << "Student details:\n";
    s.details();

    cout << "\nEmployee details:\n";
    e.details();

    return 0;
}

