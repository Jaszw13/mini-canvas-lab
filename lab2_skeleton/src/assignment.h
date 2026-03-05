#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "user.h"
#include "submission.h"

using namespace std;

/**
 * Class representing an Assignment. Users can add submissions to the assignment, and retrieve their latest submission.
 * Counting the number of assignees who have submitted something is also supported.
 *
 * An assignment has a description, a list of assignees, and a list of submissions per assignee.
 * It is guaranteed that the length of the assignees array and the submissions array are the same,
 * and the submissions of `assignee[i]` are stored at `submissions[i]`.
 *
 * The list of assignees is stored as a dynamic array, and the submissions per assignee is stored as
 * as a linked list. If an assignee has no submissions, store `nullptr` in the corresponding index of 
 * `submissions`.
 */
class Assignment {
	private:
		struct SubmissionNode { // the node of the linked list storing submissions for each assignee
			SubmissionNode* next; // pointer to the next node in the linked list
			Submission* submission; // pointer to the submission stored in this node
		};
		int num_assignees; // the number of assignees, and also the size of the assignees and submissions arrays
		User** assignees; //  users who are assigned to this assignment
		SubmissionNode** submissions; // linked list of submissions for each
		string description; // the description of this assignment
	public:
		/**
		 * Constructs an Assignment with no assignees. 
		 * You should initialize the number of assignees to zero, 
		 * and the assignees / submissions pointers to nullptr.
		 *
		 * @param description The description of this assignment
		 */
		Assignment(const string& description);
		/**
		 * Destructs this assignment. You should free the dynamically allocated arrays and linked lists.
		 * Note that you should NOT delete the user objects; this is handled by the main functions.
		 */
		~Assignment();
		/**
		 * Adds an assignee to the assignment. You do NOT need to handle duplicate assignees.
		 * Remember to deep copy and expand the `assignees` and `submissions` arrays by 1,
		 * and update the to-do list of the input user.
		 *
		 * @param user The assignee to add
		 */
		void add_assignee(User* user);
		/**
		 * Adds a submission to the assignment.
		 * 
		 * You should first find the position of the user in the `assignees` array who has created this submission.
		 * If the user is not an assignee of this assignment, do nothing and return.
		 * 
		 * Otherwise, you should check whether the user already has a submission.
		 * If the user has no prior submissions, initialize a new linked list holding the submission.
		 * Otherwise, append the submission to the existing linked list.
		 *
		 * You should mark the assignment as complete for the user at the end.
		 *
		 * @param submission The submission to add
		 */
		void add_submission(Submission* submission);
		/**
		 * Gets the latest submission from a given user. You may assume that submissions must be added in order of timestamp 
		 * (i.e. the latest submission must be at the end of the linked list).
		 *
		 * If the user is not an assignee, or if the user has no prior submissions, return `nullptr`.
		 *
		 * @param user The user to search the latest submission for
		 * @return A pointer to the latest submission of this assignment by this user; 
		 *         or a `nullptr` if the user is not an assignee or has no prior submissions.
		 */
		Submission* get_latest_submission(User* user) const;
		/**
		 * Computes the number of assignees who has submitted the assignment at least once.
		 *
		 * @return The number of assignees with at least one submission
		 */
		int count_submitted() const;
		/**
		 * Gets the number of assignees currently assigned for this assignment.
		 *
		 * @return The total number of assignees
		 */
		int count_assignees() const;
		/**
		 * Gets the description of the assignment.
		 * 
		 * @return The text describing the assignment
		 */
		const string& get_description() const;
};
#endif
