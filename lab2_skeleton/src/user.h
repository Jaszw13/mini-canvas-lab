#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

// Forward declaration.
// This allows us to prevent circular definitions.
class Assignment;

/**
 * Class representing a user of our assignment management system.
 *
 * A user has an integer ID, a name, and a dynamic array of assignments which need to be done.
 */
class User {
	private:
		int id;
		string name;
		Assignment** todo;
		int num_todo;
	public:
		/**
		 * Constructs a user with the given ID and name.
		 *
		 * @param id The ID of this user
		 * @param name The name of this user
		 */
		User(int id, const string& name);
		/**
		 * Destructs this user by deallocating all dynamic memory owned.
		 */
		~User();
		/**
		 * Gets the ID of this user.
		 *
		 * @return The ID of this user
		 */
		int get_id() const;
		/**
		 * Gets the name of this user.
		 *
		 * @return A const reference to the name of this user
		 */
		const string& get_name() const;
		/**
		 * Adds an assignment to the to-do list of this user.
		 * You do not need to consider duplicates when implementing this function.
		 *
		 * Remember to resize the array and update the number of to-dos.
		 *
		 * @param assign The assignment to add
		 */
		void add_todo(Assignment* assign);
		/**
		 * Removes an assignment from the to-do list of this user.
		 * If the assignment is already not on the list, do nothing.
		 *
		 * Otherwise, you should remove the first occurrence assignment from the to-do list and 
		 * resize the array such that there is no "gap" between the assignments.
		 *
		 * As above, remember to resize the array and update the number of to-dos.
		 *
		 * @param assign The assignment to mark as complete
		 */
		void complete(Assignment* assign);
		/**
		 * Gets the to-do list of this user.
		 *
		 * @return A dynamic array of pointers to the assignments which need to be completed
		 */
		Assignment** get_todos() const;

		/**
		 * Gets the number of to-do assignments of this user.
		 *
		 * @return An integer representing the length of the to-do list of this user
		 */
		int get_num_todos() const;
};
#endif
