#pragma once
#include "MyString.h"
#include "Vector.hpp"
#include "Comment.h"

class Post {
private:
	MyString topic;
	MyString content;
	unsigned uniqueId;
	unsigned postCounter;
	Vector<Comment> comments;
	friend class PostCommands;
	friend class FileCommands;
	friend class SocialNetwork;

public:
	Post();
	Post(const MyString& topic, const MyString& content, unsigned uniqueId, const Vector<Comment>& comments);
	Post(const MyString& topic, const MyString& content);



	unsigned getUniqueID() const;
    const MyString& getContent() const;
	const MyString& getTopic() const;

	void setContent(const MyString& content);
	void setTopic(const MyString& topic);

	void addComment(const Comment& comment);
	void deleteComment(int commentId);

	Vector<Comment> getComments() const;

	friend std::istream& operator>>(std::istream& is, Post& post);
	friend std::ostream& operator<<(std::ostream& os, const Post& post);
};

std::istream& operator>>(std::istream& is, Post& post);
std::ostream& operator<<(std::ostream& os, const Post& post);