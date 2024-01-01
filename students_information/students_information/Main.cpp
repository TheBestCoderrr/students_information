#include "Student.h"
#include <deque>

template<class T>
ostream& operator<<(ostream& out, const deque<T>& d) {
	for (auto x : d)
		out << x << endl;
	return out;
}

int getIndex_deque(const Student& st, const deque<Student>& d) {
	int i;
	for (i = 0; i < d.size(); i++)
		if (d[i] == st) return i;
	throw exception("Student not found");
}

int main() {
	deque<Student> group;
	size_t user_answer = 1;
	cout << "0 - Exit\n1 - add student\n2 - delete student\n3 - cout students\n4 - cout student\n5 - cout students(age student > n)" << endl;
	while (user_answer != 0) {
		cout << "Enter num: ";
		cin >> user_answer;
		switch (user_answer) {
		case 0:
			break;
		case 1:
			{
				Student student;
				cin >> student;
				group.emplace_back(student);
			}
			break;
		case 2:
			{
				Student student;
				cin >> student;
				try {
					int i = getIndex_deque(student, group);
					group.erase(group.begin() + i);
				}
				catch (exception ex) { cout << ex.what() << endl; }
			}
			break;
		case 3:
			cout << group;
			break;
		case 4:
			{
				Student student;
				cin >> student;
				try {
					int i = getIndex_deque(student, group);
					cout << group[i] << endl;
				}
				catch (exception ex) { cout << ex.what() << endl; }
			}
			break;
		case 5:
			{
				size_t age;
				cout << "Enter age: ";
				cin >> age;
				for (size_t i = 0; i < group.size(); i++)
					if (group[i].getAge() > age) cout << group[i] << endl;
			}
			break;
		default:
			cout << "Invalid variant" << endl;
			break;
		}
	}
}