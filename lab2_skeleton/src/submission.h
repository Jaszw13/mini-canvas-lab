#include "user.h"

using namespace std;

/**
 * Class representing a submission to an assignment.
 *
 * A submission consists of the user creating the submission, the submitted answer, 
 * and a timestamp of the submission time.
 */
class Submission {
	private:
		User* user;
		string answer;
		int timestamp;
	public:
		/**
		 * Constructs a Submission with the given user, answer, and timestamp.
		 *
		 * @param user The user which created this assignment submission
		 * @param answer The submitted answer for this assignment
		 * @param timestamp The time when this assignment is submitted
		 */
		Submission(User* user, const string& answer, int timestamp);
		/**
		 * Gets the user who has created this submission.
		 *
		 * @return The user creating this submission
		 */
		User* get_user() const;
		/**
		 * Gets the answer of this submission.
		 *
		 * @return The answer of this submission
		 */
		const string& get_answer() const;
		/**
		 * Gets the timestamp of this submission.
		 *
		 * @return The time when this submission is created
		 */
		int get_timestamp() const;
};
