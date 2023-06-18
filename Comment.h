#pragma once 
#include "User.h"
#include "MyString.h"
#include "Vector.hpp"

class Comment {
private:
	const User* user;
	MyString content;
	unsigned uniqueID;
	Vector<Comment> comments;
	friend class SocialNetwork;
	int upvotes;
	int downvotes;
	unsigned indexOfCreator;
	friend class PostCommands;
	friend class FileCommands;


public:
	Comment();
	Comment(const User& user, const MyString& content);
	Comment(const User& user, const MyString& content, unsigned uniqueID, Vector<Comment> comments);

	void setContent(const MyString& content);
	void setUsers(const User& user);

	const MyString& getContent() const;
	const User& getUsers() const;

	unsigned getUniqueID() const;
	void clearComments();



	friend std::istream& operator>>(std::istream& is, Comment& comment);
	friend std::ostream& operator<<(std::ostream& os, const Comment& comment);
};

std::istream& operator>>(std::istream& is, Comment& comment);
std::ostream& operator<<(std::ostream& os, const Comment& comment);