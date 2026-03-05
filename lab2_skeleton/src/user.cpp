#include "user.h"

User::User(int id, const string& name) : id(id), name(name), todo(nullptr), num_todo(0) {}

User::~User() {
	delete[] this->todo;
}

int User::get_id() const {
	return this->id;
}

const string& User::get_name() const {
	return this->name;
}

Assignment** User::get_todos() const {
	return this->todo;
}

int User::get_num_todos() const {
	return this->num_todo;
}

// Complete Part I here!
void User::add_todo(Assignment* assign){
	/*
Description - Adds an assignment to the to-do list of this user. You do not need to consider duplicates when implementing this function.
// cannot direct copy then first new an array with new size then we copy then we add the new assign then we copy the old one
Remember to resize the array by adding 1 to the size, and update the number of to-dos.
//new size return this->num_todo;
Parameters:
assign - The assignment to add. // add at the back of the array
Return value: None.
*/
    int new_size = this->num_todo+1;
	Assignment** new_todo = new Assignment*[new_size];
	for (int i = 0; i<this->num_todo; i++) {
		new_todo[i] = this->todo[i];
	}
	new_todo[new_size-1] = assign;
	delete[] this->todo;
	this->todo = new_todo;
	this->num_todo = new_size;
}
void User::complete(Assignment* assign){
	/*
	Description - Removes an assignment from the to-do list of this user.
If the assignment is already not on the list, do nothing.(1)
//num_todo =0 or assign not found
Otherwise, you should remove the first occurrence assignment (2)
// first occurrence assignment means we only remove the first one we find, if there are duplicates then we no need to remove all of them
from the to-do list and (3)resize the array such that there is no "gap" between the assignments. //

case 1 if thats at the first we copy from the second to the end by using index+1
case 2 if thats at the middle we copy from the first to the index-1 then we copy from the index+1 to the end by using index+1
case 3 if thats at the end we copy from the first to the index-1
then we need to get the index first

There should NOT be any empty spaces in the array after resizing.
As above, remember to resize the array and update the number of to-dos.
Parameters:
assign - The assignment to mark as complete. // find the index of this and store it
Return value: None.
*/
    if (this->num_todo == 0) {
		return;
	}
	int index = this->num_todo;
	for (int i = 0; i<this->num_todo; i++){ 
		if (this->todo[i] == assign){
			index = i;
			break;
		}

	}
	if (index == this->num_todo) {
		return;
	}
	int new_size = this->num_todo-1;
	Assignment** new_todo = new Assignment*[new_size];
	for (int i = 0; i<index; i++) {
		new_todo[i] = this->todo[i];	
	}
	for (int i = index; i<new_size; i++) {
		new_todo[i] = this->todo[i+1];
	}
	delete[] this->todo;
	this->todo = new_todo;
	this->num_todo = new_size;

}