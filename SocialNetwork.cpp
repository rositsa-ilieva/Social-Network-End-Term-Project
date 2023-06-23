#include "SocialNetwork.h"
#include <fstream>

void SocialNetwork::execute() {

	MyString command;

	std::cout << "-- CHOOSE A COMMAND--" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "* list of commands *" << std::endl;
	std::cout << "-->" << " " << "signup" << std::endl;
	std::cout << "-->" << " " << "login" << std::endl;
	std::cout << "-->" << " " << "logout" << std::endl;
	std::cout << "-->" << " " << "search" << std::endl;
	std::cout << "-->" << " " << "create" << std::endl;
	std::cout << "-->" << " " << "open" << std::endl;
	std::cout << "-->" << " " << "p_open" << std::endl;
	std::cout << "-->" << " " << "list" << std::endl;
	std::cout << "-->" << " " << "post" << std::endl;
	std::cout << "-->" << " " << "comment" << std::endl;
	std::cout << "-->" << " " << "comments" << std::endl;
	std::cout << "-->" << " " << "reply" << std::endl;
	std::cout << "-->" << " " << "upvote" << std::endl;
	std::cout << "-->" << " " << "downvote" << std::endl;
	std::cout << "-->" << " " << "p_close" << std::endl;
	std::cout << "-->" << " " << "quit" << std::endl;
	std::cout << "-->" << " " << "whoami" << std::endl;
	std::cout << "-->" << " " << "about" << std::endl;
	std::cout << "-->" << " " << "exit" << std::endl;

	while (true) {
		std::cout << "--- ";
		std::cout << "Enter command: ";
		std::cout << "---" << std::endl;
		std::cout << "----------------------" << std::endl;
		std::cout << std::endl;
		std::cin >> command;
		std::cout << std::endl;

		if (command == "exit") {
			break;
		}

		else if (command == "signup") {
			signUp();
		}

		else if (command == "login") {
			logIn();
		}

		else if (command == "logout") {
			logOut();
		}

		else if (command == "search") {
			MyString input;
			std::cout << "Enter the topic you are searching for: ";
			std::cin >> input;
			search(input);
		}

		else if (command == "create") {
			create();
		}

		else if (command == "open") {
			MyString input;
			std::cout << "Select criteria ( id / name ): ";
			std::cin >> input;

			if (input == "name") {
				MyString name;
				std::cout << "Enter topic name: ";
				std::cin >> name;
				open(name);
			}
			else if (input == "id") {
				unsigned id;
				std::cout << "Enter id: ";
				std::cin >> id;
				if (isValidIndex(id)) {
					open(id);
				}
				else {
					std::cout << "Invalid id" << std::endl;
				}
			}
			else
				std::cout << "There is no such command, please try again." << std::endl;
		}

		else if (command == "p_open") {
			MyString input;
			std::cout << "Select criteria ( id / name ): ";
			std::cin >> input;

			if (input == "name") {
				MyString name;
				std::cout << "Enter topic name: ";
				std::cin >> name;
				p_open(name);
			}
			else if (input == "id") {
				unsigned id;
				std::cout << "Enter id: ";
				std::cin >> id;
				p_open(id);
			}
			else
				std::cout << "There is no such command, please try again." << std::endl;
		}

		else if (command == "post") {
			post();
		}

		else if (command == "comment") {
			comment();
		}

		else if (command == "comments") {
			comments();
		}

		else if (command == "reply") {
			/*unsigned id;
			std::cout << "Enter comment id: ";
			std::cin >> id;
			std::cin.ignore();*/
			reply(id);
		}

		else if (command == "upvote") {
			unsigned id;
			std::cout << "Enter comment id: ";
			std::cin >> id;
			std::cin.ignore();
			upvote(id);
		}

		else if (command == "downvote") {
			unsigned id;
			std::cout << "Enter comment id: ";
			std::cin >> id;
			std::cin.ignore();
			downvote(id);
		}

		else if (command == "list") {
			list();
		}

		else if (command == "p_close") {
			p_close();
		}

		else if (command == "quit") {
			quit();
		}

		else if (command == "whoami") {
			whoami();
		}

		else if (command == "about") {
			unsigned id;
			std::cout << "Enter id: ";
			std::cin >> id;
			std::cin.ignore();
			about(id);
		}

		else {
			std::cout << "Invalid command" << std::endl;
		}
		std::cout << std::endl;
	}
}

unsigned SocialNetwork::id = 0;

bool SocialNetwork::isValidIndex(unsigned id) {
	for (size_t i = 0; i < topics.getSize(); i++)
	{
		if (topics[i].uniqueID == id - 1) {
			return true;
		}
	}

	return false;
}

bool SocialNetwork::userExists(const User& user) {
	for (unsigned i = 0; i < users.getSize(); i++)
	{
		if (users[i].first_name == user.first_name &&
			users[i].second_name == user.second_name &&
			users[i].unique_ID == user.unique_ID) {

			return true;
		}
	}
	return false;
}

bool SocialNetwork::userExists(const MyString& username, const MyString& password) {
	for (unsigned i = 0; i < users.getSize(); i++)
	{
		if (users[i].first_name == username && users[i].password == password) {
			return true;
			break;
		}
	}
	return false;
}

bool SocialNetwork::signUp() {
	std::cout << "----------------------" << std::endl;
	User user;
	std::cin >> user;

	if (!userExists(user)) {

		std::cout << "----------------------" << std::endl;
		std::cout << "Successful registration! " << std::endl;
		std::cout << "----------------------" << std::endl;
		users.pushBack(user);
		return false;
	}

	std::cout << "----------------------" << std::endl;
	std::cout << user.first_name << ", you already have profile!" << std::endl;
	std::cout << "----------------------" << std::endl;
	return true;
}

bool SocialNetwork::logIn() {
	std::cout << "----------------------" << std::endl;
	MyString name;
	MyString password;
	std::cout << "Username: ";
	std::cin >> name;
	std::cout << std::endl;
	std::cout << "Password: ";
	std::cin >> password;
	std::cout << std::endl;


	if (userExists(name, password)) {
		for (unsigned i = 0; i < users.getSize(); i++)
		{
			if (users[i].first_name == name && users[i].password == password) {
				std::cout << "----------------------" << std::endl;
				std::cout << "~~> " << name << ", you have successfully logged in!" << std::endl;
				std::cout << "----------------------" << std::endl;
				loggedUser = &users[i];
				return true;
			}

		}
	}
	else {
		std::cout << "----------------------" << std::endl;
		std::cout << "There is no such user! Try again." << std::endl;
		std::cout << "----------------------" << std::endl;
		return false;
	}
}

void SocialNetwork::logOut() {
	if (loggedUser != nullptr) {
		std::cout << "----------------------" << std::endl;
		std::cout << loggedUser->first_name << ", exited their profile!" << std::endl;
		std::cout << "----------------------" << std::endl;
		loggedUser = nullptr;
	}
	else {
		std::cout << "Try to log in first!" << std::endl;
	}
}

void SocialNetwork::create() {

	if (loggedUser != nullptr) {
		Topic topic;
		std::cin >> topic;

		topic.setId(id++);
		topic.setCreator(*loggedUser);
		topic.indexOfCreator = userIndex();

		topics.pushBack(topic);
	}

	else {
		std::cout << "You have not logged in." << std::endl;
	}
}

namespace {
	bool isPrefix(const char* pattern, const char* text)
	{
		while (*text != '\0' && *pattern != '\0')
		{
			if (*text != *pattern)
				return false;
			text++;
			pattern++;
		}
		return *pattern == '\0';
	}
}

bool searchInText(const char* text, const char* pattern)
{
	size_t textLen = strlen(text);
	size_t patternLen = strlen(pattern);
	while (patternLen <= textLen)
	{
		if (isPrefix(pattern, text))
			return true;
		text++;
		textLen--;
	}
	return false;
}

void SocialNetwork::search(const MyString& name) {
	if (loggedUser != nullptr) {
		for (unsigned i = 0; i < topics.getSize(); i++)
		{
			if (searchInText(topics[i].topic.c_str(), name.c_str())) {
				std::cout << topics[i].topic << " {id:" << topics[i].uniqueID + 1 << "}" << std::endl;
			}
		}
	}
	else {
		std::cout << "There is no such topic. Try again." << std::endl;
	}

}

void SocialNetwork::open(const MyString& name)
{
	if (loggedUser != nullptr) {
		for (unsigned i = 0; i <= topics.getSize(); i++)
		{
			if (searchInText(topics[i].topic.c_str(), name.c_str())) {
				std::cout << "----------------------" << std::endl;
				std::cout << "Welcome to " << topics[i].topic << "!" << std::endl;
				std::cout << "----------------------" << std::endl;
				openedTopic = &topics[i];
				break;
			}
		}
	}

	else {
		std::cout << "----------------------" << std::endl;
		std::cout << "You have not created a topic." << std::endl;
		std::cout << "----------------------" << std::endl;
	}

}

void SocialNetwork::open(unsigned id)
{

	if (loggedUser != nullptr && isValidIndex(id) == true) {
		for (unsigned i = 0; i < topics.getSize(); i++)
		{
			if (topics[i].uniqueID == id - 1) {
				std::cout << "----------------------" << std::endl;
				std::cout << "Welcome to " << topics[i].topic << "!" << std::endl;
				std::cout << "----------------------" << std::endl;
				openedTopic = &topics[i];
				break;
			}
		}
	}

	else {
		std::cout << "----------------------" << std::endl;
		std::cout << "You have not created a topic." << std::endl;
		std::cout << "----------------------" << std::endl;
	}
}

unsigned SocialNetwork::userIndex() const {

	for (unsigned i = 0; i < users.getSize(); i++) {
		if (&users[i] == loggedUser) {
			return i;
		}
	}
	return -1;
}

void SocialNetwork::post() {
	if (loggedUser != nullptr && openedTopic != nullptr) {
		Post post;
		std::cin >> post;
		post.uniqueId = openedTopic->postCounter;
		openedTopic->postCounter++;
		openedTopic->posts.pushBack(post);

	}

	else {
		std::cout << "----------------------" << std::endl;
		std::cout << "Post error." << std::endl;
		std::cout << "----------------------" << std::endl;
	}
}

void SocialNetwork::list() const {
	if (loggedUser != nullptr && openedTopic != nullptr) {
		for (unsigned i = 0; i < openedTopic->getPosts().getSize(); i++) {
			std::cout << "----------------------" << std::endl;
			std::cout << ">> " << openedTopic->getPosts()[i];
			std::cout << "----------------------" << std::endl;
		}
	}

	else {
		std::cout << "----------------------" << std::endl;
		std::cout << "You have not created any posts." << std::endl;
		std::cout << "----------------------" << std::endl;
	}
}

void SocialNetwork::p_open(const MyString& title) {
	if (loggedUser != nullptr && openedTopic != nullptr) {
		for (unsigned i = 0; i < openedTopic->getPosts().getSize(); i++) {
			if (searchInText(openedTopic->getPosts()[i].getTopic().c_str(), title.c_str())) {
				std::cout << "----------------------" << std::endl;
				std::cout << "Q: " << openedTopic->getPosts()[i];
				std::cout << "----------------------" << std::endl;
				openedPost = &(openedTopic->posts[i]);
				return;
			}
		}
	}

	else {
		std::cout << "Error." << std::endl;
	}
}

void SocialNetwork::p_open(unsigned id) {
	if (loggedUser != nullptr && openedTopic != nullptr) {
		for (unsigned i = 0; i < openedTopic->getPosts().getSize(); i++) {
			if (openedTopic->getPosts()[i].getUniqueID() == id) {
				std::cout << "----------------------" << std::endl;
				std::cout << "Q: " << openedTopic->getPosts()[i];
				std::cout << "----------------------" << std::endl;
				openedPost = &(openedTopic->posts[i]);
				return;
			}
		}
	}

	else {
		std::cout << "----------------------" << std::endl;
		std::cout << "Error." << std::endl;
		std::cout << "----------------------" << std::endl;
	}
}

void SocialNetwork::comment() {

	if (loggedUser != nullptr && openedTopic != nullptr && openedPost != nullptr) {
		Comment comment;
		std::cout << "----------------------" << std::endl;
		std::cout << "Say something: ";
		std::cin >> comment;
		std::cout << "----------------------" << std::endl;
		loggedUser->points++;
		comment.uniqueID = openedPost->postCounter++;
		openedPost->comments.pushBack(comment);
	}

	else {
		std::cout << "----------------------" << std::endl;
		std::cout << "Error." << std::endl;
		std::cout << "----------------------" << std::endl;
	}
}

void SocialNetwork::printComments(const Comment& comment, int indentLevel)
{
	for (int i = 0; i < indentLevel; i++) {
		std::cout << '\t';
	}
	std::cout << comment << std::endl;

	unsigned size = comment.comments.getSize();
	for (unsigned i = 0; i < size; i++) {
		printComments(comment.comments[i], indentLevel + 1);
	}
}

void SocialNetwork::comments() {
	if (openedPost != nullptr) {
		unsigned size = openedPost->comments.getSize();
		for (unsigned i = 0; i < size; i++) {
			printComments(openedPost->comments[i], 0);
		}
		return;
	}
	std::cout << "----------------------" << std::endl;
	std::cout << "Error" << std::endl;
	std::cout << "----------------------" << std::endl;
}

void SocialNetwork::reply(unsigned id) {

	std::cout << "----------------------" << std::endl;
	if (loggedUser != nullptr && openedTopic != nullptr && openedPost != nullptr) {
		std::cout << "Comment id: ";
		std::cin >> id;
		std::cout << std::endl;

		Comment reply;
		std::cout << "Enter a reply on comment: ";
		std::cin >> reply;

		reply.user = loggedUser;
		reply.uniqueID = openedPost->postCounter++;

		bool foundComment = false;

		unsigned size = openedPost->comments.getSize();
		for (unsigned i = 0; i < size; i++) {
			if (openedPost->comments[i].uniqueID == id) {
				openedPost->comments[i].comments.pushBack(reply);
				foundComment = true;
				break;
			}
			else {
				unsigned subSize = openedPost->comments[i].comments.getSize();
				for (unsigned j = 0; j < subSize; j++) {
					if (openedPost->comments[i].comments[j].uniqueID == id) {
						openedPost->comments[i].comments[j].comments.pushBack(reply);
						foundComment = true;
						break;
					}
				}
				if (foundComment)
					break;
			}
		}
		if (foundComment) {
			std::cout << "----------------------" << std::endl;
			std::cout << "Posted" << std::endl;
			std::cout << "----------------------" << std::endl;
			return;
		}
	}
	std::cout << "----------------------" << std::endl;
	std::cout << "Error." << std::endl;
	std::cout << "----------------------" << std::endl;
}

bool SocialNetwork::hasUpvoted(unsigned id) {
	for (unsigned i = 0; i < loggedUser->upvoteIDs.getSize(); i++)
	{
		if (loggedUser->upvoteIDs[i] == id) {
			return true;
		}
	}
	return false;
}

bool SocialNetwork::hasDownvoted(unsigned id) {
	for (unsigned i = 0; i < loggedUser->downvoteIDs.getSize(); i++)
	{
		if (loggedUser->downvoteIDs[i] == id) {
			return true;
		}
	}
	return false;
}

void SocialNetwork::upvote(unsigned id) {

	if (loggedUser != nullptr && openedTopic != nullptr && openedPost != nullptr) {

		for (unsigned i = 0; i < openedPost->getComments().getSize(); i++)
		{
			/*if (openedPost[i].getUniqueID() == id)*/ 
			if (openedPost->comments[i].getUniqueID() == id) {
				if (hasUpvoted(id) == false && hasDownvoted(id) == false) {
					openedPost->comments[i].upvotes++;
					loggedUser->upvoteIDs.pushBack(id);
				}

				else if (hasUpvoted(id) == true && hasDownvoted(id) == false) {
					openedPost->comments[i].upvotes--;
					for (unsigned j = 0; j < loggedUser->upvoteIDs.getSize(); j++)
					{
						if (loggedUser->upvoteIDs[j] == id) {
							loggedUser->upvoteIDs.popAt(j);
							break;
						}
					}
				}
				else if (hasUpvoted(id) == false && hasDownvoted(id) == true) {
					openedPost->comments[i].downvotes--;
					for (unsigned j = 0; j < loggedUser->downvoteIDs.getSize(); j++)
					{
						if (loggedUser->downvoteIDs[j] == id) {
							loggedUser->downvoteIDs.popAt(j);
							break;
						}
					}
					openedPost->comments[i].upvotes++;
					loggedUser->upvoteIDs.pushBack(id);
				}

				if (openedPost->comments[i].upvotes < 0) {
					openedPost->comments[i].upvotes = 0;
				}
				else if (openedPost->comments[i].downvotes < 0) {
					openedPost->comments[i].downvotes = 0;
				}
			}
		}
	}

	else {
		std::cout << "----------------------" << std::endl;
		std::cout << "Error." << std::endl;
		std::cout << "----------------------" << std::endl;
	}
}

void SocialNetwork::downvote(unsigned id) {

	if (loggedUser != nullptr && openedTopic != nullptr && openedPost != nullptr) {

		for (unsigned i = 0; i < openedPost->getComments().getSize(); i++)
		{
			/*if (openedPost[i].getUniqueID() == id)*/ 
			if (openedPost->comments[i].getUniqueID() == id) {
				if (hasUpvoted(id) == false && hasDownvoted(id) == false) {
					openedPost->comments[i].downvotes++;
					loggedUser->downvoteIDs.pushBack(id);
				}

				else if (hasUpvoted(id) == true && hasDownvoted(id) == false) {
					openedPost->comments[i].upvotes--;
					for (unsigned j = 0; j < loggedUser->upvoteIDs.getSize(); j++)
					{
						if (loggedUser->upvoteIDs[j] == id) {
							loggedUser->upvoteIDs.popAt(j);
							break;
						}
					}
					openedPost->comments[i].downvotes++;
					loggedUser->downvoteIDs.pushBack(id);
				}
				else if (hasUpvoted(id) == false && hasDownvoted(id) == true) {
					openedPost->comments[i].downvotes--;
					for (unsigned j = 0; j < loggedUser->downvoteIDs.getSize(); j++)
					{
						if (loggedUser->downvoteIDs[j] == id) {
							loggedUser->downvoteIDs.popAt(j);
							break;
						}
					}
				}

				if (openedPost->comments[i].downvotes < 0) {
					openedPost->comments[i].downvotes = 0;
				}
				else if (openedPost->comments[i].upvotes < 0) {
					openedPost->comments[i].upvotes = 0;
				}

			}
		}
	}

	else {
		std::cout << "----------------------" << std::endl;
		std::cout << "Error." << std::endl;
		std::cout << "----------------------" << std::endl;
	}
}

void SocialNetwork::p_close() {
	if (openedTopic != nullptr && loggedUser != nullptr && openedPost != nullptr) {

		std::cout << "----------------------" << std::endl;
		std::cout << openedPost->topic << " was closed." << std::endl;
		std::cout << "----------------------" << std::endl;

		openedPost = nullptr;
	}

	else {
		std::cout << "----------------------" << std::endl;
		std::cout << "Error." << std::endl;
		std::cout << "----------------------" << std::endl;
	}
}

void SocialNetwork::quit() {
	if (openedTopic != nullptr && loggedUser != nullptr) {

		std::cout << "----------------------" << std::endl;
		std::cout << openedTopic->topic << " was closed." << std::endl;
		std::cout << "----------------------" << std::endl;
		openedTopic = nullptr;
	}

	else {
		std::cout << "----------------------" << std::endl;
		std::cout << "Error." << std::endl;
		std::cout << "----------------------" << std::endl;
	}
}

void SocialNetwork::whoami() {
	std::cout << "----------------------" << std::endl;
	if (loggedUser != nullptr) {
		std::cout << *(loggedUser);
	}

	else {
		std::cout << "----------------------" << std::endl;
		std::cout << "Error." << std::endl;
		std::cout << "----------------------" << std::endl;
	}
}

unsigned SocialNetwork::topicIndex(unsigned ind) {

	for (unsigned i = 0; i < topics.getSize(); i++) {
		if (topics[i].uniqueID == ind) {
			return i;
		}
	}
	return -1;
}

void SocialNetwork::about(unsigned id) {
	std::cout << "----------------------" << std::endl;
	if (topicIndex(id) != -1 && loggedUser != nullptr) {
		std::cout << topics[topicIndex(id) - 1];
	}

	else {
		std::cout << "----------------------" << std::endl;
		std::cout << "Error." << std::endl;
		std::cout << "----------------------" << std::endl;
	}
}

namespace {
	MyString readFromFile(std::ifstream& ifs) {
		int stringLength;
		ifs.read((char*)&stringLength, sizeof(int));
		char* str = new char[stringLength + 1];
		ifs.read(str, stringLength);
		str[stringLength] = '\0';

		return str;
	}
}

bool SocialNetwork::searchComments(Comment& searchedComment, const Comment& reply, unsigned id) {

	for (unsigned i = 0; i < searchedComment.comments.getSize(); i++) {
		if (searchedComment.comments[i].uniqueID == id) {
			searchedComment.comments[i].comments.pushBack(reply);
			std::cout << "Posted" << std::endl;
			return true;
		}
		if (searchedComment.comments[i].comments.getSize() > 0) {
			searchComments(searchedComment.comments[i], reply, id);
		}
	}
	return false;
}

User SocialNetwork::readUser(std::ifstream& ifs) {
	User user;
	user.first_name = readFromFile(ifs);
	user.second_name = readFromFile(ifs);
	user.password = readFromFile(ifs);

	unsigned id, points;
	ifs.read((char*)&id, sizeof(unsigned));
	ifs.read((char*)&points, sizeof(unsigned));
	user.unique_ID = id;
	user.points = points;


	size_t upvotesCout;
	ifs.read((char*)&upvotesCout, sizeof(size_t));

	for (unsigned i = 0; i < upvotesCout; i++) {
		unsigned number;
		ifs.read((char*)&number, sizeof(unsigned));
		user.upvoteIDs.pushBack(number);

	}

	size_t downvotesCount;
	ifs.read((char*)&downvotesCount, sizeof(size_t));

	for (unsigned i = 0; i < downvotesCount; i++)
	{
		unsigned number;
		ifs.read((char*)&number, sizeof(unsigned));
		user.downvoteIDs.pushBack(number);

	}

	return user;
}

Topic SocialNetwork::readTopic(std::ifstream& ifs) {
	Topic topic;
	topic.topic = readFromFile(ifs);

	unsigned ind, id;
	ifs.read((char*)&ind, sizeof(unsigned));
	topic.indexOfCreator = ind;

	topic.creator = &users[ind];

	topic.content = readFromFile(ifs);

	ifs.read((char*)&id, sizeof(unsigned));
	topic.uniqueID = id;

	int postCount;
	ifs.read((char*)&postCount, sizeof(int));

	for (unsigned i = 0; i < postCount; i++)
	{
		topic.posts.pushBack(readPost(ifs));
	}

	return topic;
}

Comment SocialNetwork::readComment(std::ifstream& ifs) {
	Comment comment;

	unsigned index, countUpvotes, countDownvotes, id;
	ifs.read((char*)&index, sizeof(unsigned));
	comment.user = &users[index];
	comment.indexOfCreator = index;

	ifs.read((char*)&countUpvotes, sizeof(unsigned));
	comment.upvotes = countUpvotes;

	ifs.read((char*)&countDownvotes, sizeof(unsigned));
	comment.downvotes = countDownvotes;

	ifs.read((char*)&id, sizeof(unsigned));
	comment.uniqueID = id;

	int repliesCount;
	ifs.read((char*)&repliesCount, sizeof(unsigned));

	for (unsigned i = 0; i < repliesCount; i++)
		comment.comments.pushBack(readComment(ifs));

	return comment;
}

Post SocialNetwork::readPost(std::ifstream& ifs) {
	Post post;

	post.topic = readFromFile(ifs);
	post.content = readFromFile(ifs);

	unsigned counter, id;
	static unsigned size = sizeof(unsigned);
	ifs.read((char*)&counter, size);
	post.postCounter = counter;

	ifs.read((char*)&id, size);
	post.uniqueId = id;

	int post_count;
	ifs.read((char*)&post_count, sizeof(unsigned));

	for (size_t i = 0; i < post_count; i++)
		post.comments.pushBack(readComment(ifs));

	return post;
}

namespace {
	void writeToFile(std::ofstream& ofs, const char* text) {
		unsigned stringLength = strlen(text);
		ofs.write((const char*)&stringLength, sizeof(unsigned));
		ofs.write(text, stringLength);
	}
}

void SocialNetwork::writeUser(std::ofstream& ofs, const User& user) {
	writeToFile(ofs, user.first_name.c_str());
	writeToFile(ofs, user.second_name.c_str());
	writeToFile(ofs, user.password.c_str());
	ofs.write((const char*)&user.unique_ID, sizeof(unsigned));
	ofs.write((const char*)&user.points, sizeof(unsigned));

	size_t size = user.upvoteIDs.getSize();
	ofs.write((const char*)&size, sizeof(size_t));

	for (size_t i = 0; i < size; i++)
	{
		ofs.write((const char*)&user.upvoteIDs[i], sizeof(size_t));
	}

	size = user.downvoteIDs.getSize();
	ofs.write((const char*)&size, sizeof(size_t));

	for (size_t i = 0; i < size; i++)
	{
		ofs.write((const char*)&user.downvoteIDs[i], sizeof(size_t));
	}
}

void SocialNetwork::writeTopic(std::ofstream& ofs, const Topic& topic) {
	writeToFile(ofs, topic.topic.c_str());
	ofs.write((const char*)&topic.indexOfCreator, sizeof(unsigned));
	writeToFile(ofs, topic.content.c_str());
	ofs.write((const char*)&topic.uniqueID, sizeof(unsigned));
	int postsSize = topic.posts.getSize();
	ofs.write((const char*)&postsSize, sizeof(unsigned));

	for (size_t i = 0; i < postsSize; i++)
		writePost(ofs, topic.posts[i]);
}

void SocialNetwork::writeComment(std::ofstream& ofs, const Comment& comment) {

	ofs.write((const char*)&comment.indexOfCreator, sizeof(unsigned));

	writeToFile(ofs, comment.content.c_str());

	ofs.write((const char*)&comment.upvotes, sizeof(unsigned));
	ofs.write((const char*)&comment.downvotes, sizeof(unsigned));
	ofs.write((const char*)&comment.uniqueID, sizeof(unsigned));

	int repliesSize = comment.comments.getSize();
	ofs.write((const char*)&repliesSize, sizeof(unsigned));

	for (unsigned i = 0; i < repliesSize; i++)
		writeComment(ofs, comment.comments[i]);

}

void SocialNetwork::writePost(std::ofstream& ofs, const Post& post) {

	writeToFile(ofs, post.topic.c_str());
	writeToFile(ofs, post.content.c_str());

	ofs.write((const char*)&post.postCounter, sizeof(unsigned));
	ofs.write((const char*)&post.uniqueId, sizeof(unsigned));

	int commentsSize = post.comments.getSize();
	ofs.write((const char*)&commentsSize, sizeof(int));

	for (unsigned i = 0; i < commentsSize; i++)
		writeComment(ofs, post.comments[i]);
}

SocialNetwork::SocialNetwork() : users(), topics() {
	std::ifstream ifs("data.txt", std::ios::in | std::ios::binary);

	if (!ifs.is_open()) {
		std::cout << "Error" << std::endl;
	}

	ifs.read((char*)&id, sizeof(id));
	size_t usersCout = 0;
	ifs.read((char*)&usersCout, sizeof(size_t));
	for (size_t i = 0; i < usersCout; i++) {
		User user = readUser(ifs);
		users.pushBack(user);
	}

	size_t topicsCout = 0;
	ifs.read((char*)&topicsCout, sizeof(size_t));
	for (size_t i = 0; i < topicsCout; i++) {
		Topic topic = readTopic(ifs);
		topics.pushBack(topic);
	}

	/*int commentsCout = 0;
	ifs.read((char*)commentsCout, sizeof(int));
	for (int i = 0; i < commentsCout; i++) {
		Comment comment = readComment(ifs);
		comments.pushBack(comment);
	}

	int postsCout = 0;
	ifs.read((char*)postsCout, sizeof(int));
	for (int i = 0; i < postsCout; i++) {
		Post post = readPost(ifs);
		posts.pushBack(post);
	}*/

	ifs.close();
}

SocialNetwork::~SocialNetwork() {
	std::ofstream ofs("data.txt", std::ios::out | std::ios::binary);

	if (!ofs.is_open()) {
		std::cout << "Error" << std::endl;
	}

	ofs.write((const char*)&id, sizeof(id));

	size_t usersCout = users.getSize();
	ofs.write((const char*)&usersCout, sizeof(size_t));

	for (size_t i = 0; i < users.getSize(); i++) {
		const User& user = users[i];
		writeUser(ofs, user);
	}

	size_t topicsCout = topics.getSize();
	ofs.write((const char*)&topicsCout, sizeof(size_t));

	for (size_t i = 0; i < topics.getSize(); i++) {
		const Topic& topic = topics[i];
		writeTopic(ofs, topic);
	}

	/*int commentsCout = comments.getSize();
	ofs.write((const char*)commentsCout, sizeof(int));

	for (int i = 0; i < commentsCout; i++) {
		const Comment& comment = comments[i];
		writeComment(ofs, comment);
	}

	int postCout = post.getSize();
	ofs.write((const char*)postCout, sizeof(int));

	for (int i = 0; i < postCout; i++) {
		const Post& post = posts[i];
		writePost(ofs, post);
	}*/

	ofs.close();

}

