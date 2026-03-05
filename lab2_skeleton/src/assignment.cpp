#include "assignment.h"

int Assignment::count_assignees() const {
	return this->num_assignees;
}

const string& Assignment::get_description() const {
	return this->description;
}

// Complete Part II here!
Assignment::Assignment(const string& description){
/*
Description - Constructs an Assignment with no assignees.
You should initialize the number of assignees to zero, and the assignees / submissions pointers to nullptr.
Parameters:
description - The description of the assignment.
*/
	this-> description = description;
	this-> num_assignees = 0;
	this-> assignees = nullptr;
	this-> submissions = nullptr;
}


Assignment::~Assignment(){
/*
Description - Destructs this assignment.
You should free the dynamically allocated arrays and linked lists. Note that you should NOT delete the user objects; this is handled by the main functions.
free assign
Parameters: None.
*/
	for (int i = 0; i<this->num_assignees; i++) {
		SubmissionNode* curr = this->submissions[i];
		while (curr != nullptr) {
			SubmissionNode* temp = curr;
			curr = curr->next;
			delete temp;
		}
	}
	delete[] this->submissions;
    delete[] this->assignees;
}

void Assignment::add_assignee(User* user){
/*
Description - Adds an assignee to the assignment. //  assignee is the user who need to submit the assignment // update assignment
		1)int num_assignees; // the number of assignees, and also the size of the assignees and submissions arrays
		User** assignees; //  users who are assigned to this assignment
		2)SubmissionNode** submissions; // linked list of submissions for each
		string description; // the description of this assignment

			struct SubmissionNode { // the node of the linked list storing submissions for each assignee
			SubmissionNode* next; // pointer to the next node in the linked list
			Submission* submission; // pointer to the submission stored in this node
		};

You do NOT need to handle duplicate assignees.
Remember to deep copy and expand the assignees and submissions arrays themselves by 1, and update the to-do list of the input user.
// add at the last?
For clarity, you do NOT need to copy the user objects themselves. You only need to copy the arrays.
Parameters:
user - The assignee to add.
Return value: None.
*/
int new_size_assignees = this->num_assignees+1;
    User** new_assignees = new User*[new_size_assignees];
	SubmissionNode** new_submissions = new SubmissionNode*[new_size_assignees];
	for (int i = 0; i<this->num_assignees; i++) {
		new_assignees[i] = this->assignees[i];
		new_submissions[i] = this->submissions[i];
	}
	new_assignees[new_size_assignees-1] = user;
	new_submissions[new_size_assignees-1] = nullptr;
	delete[] this->assignees;
	delete[] this->submissions;
	this->assignees = new_assignees;
	this->submissions = new_submissions;
	this->num_assignees = new_size_assignees;
	user->add_todo(this);
}

void Assignment::add_submission(Submission* submission){
/*
Description - Adds a submission to the assignment. 
You should first find the position of the user in the assignees array who has created this submission.// using index same
If the user is not an assignee of this assignment, do nothing and return.
Otherwise, you should check whether the user already has a submission. If the user has no prior submissions
, initialize a new linked list holding the submission. Otherwise
, append the submission to the existing linked list.
You should mark the assignment as complete for the user at the end.
Parameters:
submission - The submission to add.
Return value: None.
*/
    User* user = submission->get_user();
	int index = this->num_assignees;
	for (int i = 0; i<this->num_assignees; i++){ 
		if (this->assignees[i] == user){
			index = i;
			break;
		}

	}
	if (index == this->num_assignees) {
		return;
	}
	SubmissionNode* new_node = new SubmissionNode;
	new_node->submission = submission;
	new_node->next = nullptr;
	if (this->submissions[index] == nullptr) {
		this->submissions[index] = new_node;
	} 
	else {
		SubmissionNode* curr = this->submissions[index];
		while (curr->next != nullptr) {
			curr = curr->next;
		}
		curr->next = new_node;
	}
	user->complete(this);
}


Submission* Assignment::get_latest_submission(User* user) const{
/*
Description - Gets the latest submission from a given user.// using index same
You may assume that submissions must be added in order of timestamp (i.e. the latest submission must be at the end of the linked list).
If the user is not an assignee, or if the user has no prior submissions, return nullptr.
Parameters:
user - The user to search the latest submission for.
Return value: A pointer to the latest submission of this assignment by this user; or a nullptr if the user is not an assignee or has no prior submissions.
*/
int index = this->num_assignees;
	for (int i = 0; i<this->num_assignees; i++){ 
		if (this->assignees[i] == user){
			index = i;
			break;
		}
	}
	if (index == this->num_assignees) {
		return nullptr;
	}
	if (this->submissions[index] == nullptr) {
		return nullptr;
	}
	SubmissionNode* curr = this->submissions[index];
	while (curr->next != nullptr) {
		curr = curr->next;
	}
	return curr->submission;
}

int Assignment::count_submitted() const{
/*
Description - Computes the number of assignees who has submitted the assignment at least once.
Parameters: None.
Return value: The number of assignees with at least one submission. return count
*/
	int count = 0;
	for (int i = 0; i<this->num_assignees; i++) {
		if (this->submissions[i] != nullptr) {
			count++;
		}
	}
	return count;
}

