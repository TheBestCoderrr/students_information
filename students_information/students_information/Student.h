#pragma once
#include <iostream>
#include <string>
using namespace std;

class PIB {
public:
	string Fname;
	string Lname;
	string Sname;
};

class Student : private PIB
{
public:
	void setAge(size_t age) { this->age = age; }
	size_t getAge() const { return age; }
	void setFname(string Fname) { this->Fname = Fname; }
	string getFname() const { return Fname; }
	void setLname(string Lname) { this->Lname = Lname; }
	string getLname() const { return Lname; }
	void setSname(string Sname) { this->Sname = Sname; }
	string getSname() const { return Sname; }

	bool operator==(const Student& other) const;
	bool operator!=(const Student& other) const;
private:
	size_t age;
};

inline ostream& operator<<(ostream& out, const Student& student) {
	out << "PIB: " <<  student.getFname() << ' ' << student.getLname() << ' ' << student.getSname() << ' ' << endl;
	out << "Age: " << student.getAge() << endl;
	return out;
}

inline istream& operator>>(istream& in, Student& student) {
	string txt;
	cout << "Enter PIB: ";
	in >> txt;
	student.setFname(txt);
	in >> txt;
	student.setLname(txt);
	in >> txt;
	student.setSname(txt);
	size_t num;
	cout << "Enter age: ";
	in >> num;
	student.setAge(num);
	return in;
}
