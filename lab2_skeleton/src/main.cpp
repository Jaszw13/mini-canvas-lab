#include <iostream>
#include "assignment.h"

int main() {
	int test_num;
	cout << "Please enter the number of the test to run: ";
	cin >> test_num;
	
	if (test_num == 1) {
		cout << "Testing User::add_todo\n";
		User u(0, "Desmond");
		Assignment a("In this assignment, you will complete a 1000-word essay on why COMP 2012 is the best course.");
		u.add_todo(&a);
		cout << "The number of to-do items is: " << u.get_num_todos() << "\n";
		cout << "The to-do items are:\n";
		for (int i = 0; i < u.get_num_todos(); i++) {
			cout << "Item " << i << ": " << u.get_todos()[i]->get_description() << "\n";
		}
	} else if (test_num == 2) {
		cout << "Testing User::complete\n";
		User u(0, "Colin");
		Assignment a("In this lab, you will be completing a mini-Canvas system.");
		Assignment a2("In this lab, you will be completing a form-building system.");
		u.add_todo(&a);
		u.add_todo(&a2);
		u.complete(&a2);
		cout << "The number of to-do items is: " << u.get_num_todos() << "\n";
		cout << "The to-do items are:\n";
		for (int i = 0; i < u.get_num_todos(); i++) {
			cout << "Item " << i << ": " << u.get_todos()[i]->get_description() << "\n";
		}
	} else if (test_num == 3) {
		cout << "Testing Assignment::add_assignee\n";
		Assignment a("In this assignment, we will complete an assignment.");
		User u(0, "Sunny");
		a.add_assignee(&u);
		cout << "The number of assignees is: " << a.count_assignees() << "\n";
		cout << "The number of to-do items for " << u.get_name() << " is: " << u.get_num_todos() << "\n";
		cout << "The to-do items are:\n";
		for (int i = 0; i < u.get_num_todos(); i++) {
			cout << "Item " << i << ": " << u.get_todos()[i]->get_description() << "\n";
		}
	} else if (test_num == 4) {
		cout << "Testing Assignment::add_submission\n";
		Assignment a("In this assignment, we will complete a lab.");
		User u(0, "Sunny");
		Submission s1(&u, "Lab.", 0);
		Submission s2(&u, "Lab?", 1);
		Submission s3(&u, "Lab!!", 2);
		a.add_assignee(&u);
		a.add_submission(&s1);
		a.add_submission(&s2);
		a.add_submission(&s3);
		cout << "The number of assignees is: " << a.count_assignees() << "\n";
		cout << "The number of to-do items for " << u.get_name() << " is: " << u.get_num_todos() << "\n";
		cout << "The to-do items are:\n";
		for (int i = 0; i < u.get_num_todos(); i++) {
			cout << "Item " << i << ": " << u.get_todos()[i]->get_description() << "\n";
		}
	}  else if (test_num == 5) {
		cout << "Testing Assignment::get_latest_submission\n";
		Assignment a("In this assignment, you will implement a linked list.");
		User u1(0, "Alice");
		User u2(1, "Bob");
		a.add_assignee(&u1);
		Submission* latest = a.get_latest_submission(&u1);
		cout << "Latest before submissions: "
				  << (latest == nullptr ? string("nullptr") : latest->get_answer()) << "\n";
		Submission s1(&u1, "Draft 1", 10);
		Submission s2(&u1, "Draft 2", 11);
		a.add_submission(&s1);
		a.add_submission(&s2);
		latest = a.get_latest_submission(&u1);
		if (latest == nullptr) {
			cout << "Latest after submissions: nullptr\n";
		} else {
			cout << "Latest after submissions: " << latest->get_answer() << " (t="
					  << latest->get_timestamp() << ")\n";
		}
		latest = a.get_latest_submission(&u2);
		cout << "Latest for non-assignee: "
				  << (latest == nullptr ? string("nullptr") : latest->get_answer()) << "\n";
	} else if (test_num == 6) {
		cout << "Testing Assignment::count_submitted\n";
		Assignment a("In this assignment, you will submit your code.");
		User u1(0, "Carol");
		User u2(1, "David");
		User u3(2, "Eve");
		a.add_assignee(&u1);
		a.add_assignee(&u2);
		a.add_assignee(&u3);
		cout << "Initial submitted count is: " << a.count_submitted() << "\n";
		Submission s1(&u1, "Hello", 0);
		Submission s2(&u3, "World", 1);
		a.add_submission(&s1);
		a.add_submission(&s2);
		cout << "Submitted count after u1,u3 submit is: " << a.count_submitted() << "\n";
		Submission s3(&u1, "Hello again", 2);
		a.add_submission(&s3);
		cout << "Submitted count after u1 submits again is: " << a.count_submitted() << "\n";
	} else {
		cout << "No such test!\n";
	}
	return 0;
}
