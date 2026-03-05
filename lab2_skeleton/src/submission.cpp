#include "submission.h"

Submission::Submission(User* user, const string& answer, int timestamp) :
	user(user), answer(answer), timestamp(timestamp) {}

User* Submission::get_user() const {
	return this->user;
}

const string& Submission::get_answer() const {
	return this->answer;
}

int Submission::get_timestamp() const {
	return this->timestamp;
}
