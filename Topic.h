#pragma once
#include "MyString.h"
#include "User.h"
#include "Post.h"

class Topic
{
public:
	MyString topic;
	/*MyString*/const User* creator;
	MyString content;
	unsigned uniqueID;
	//static unsigned counter;
	/*static unsigned topic_ID_generator();*/
	Vector<Post> posts;
	unsigned indexOfCreator = 0;
	unsigned postCounter = 0;
	friend class TopicCommands;
	friend class FileCommands;

public:
	Topic();
	Topic(const MyString& topic, const MyString& content, const User& creator/*, unsigned int unique_ID*/);
	Topic(const MyString& topic, const MyString& content, const User& creator, unsigned uniqueID, Vector<Post> posts);
	/*posts = Vector<Post>();*/
	



	void setTopic(const MyString& topic);
	void setCreator(const User& creator);
	void setContent(const MyString& content);
	void setId(unsigned id);

	unsigned getUniqueID() const;
	const MyString& getTopic() const;

	// Допълнителни методи за операции с темите
	void addPost(const Post& post);
	void deletePost(unsigned postId);

	Vector<Post> getPosts() const;

	friend class SocialNetwork;

	//operators
	friend std::istream& operator>>(std::istream& is, Topic& user);
	friend std::ostream& operator<<(std::ostream& os, const Topic& user);

	/*void setUniqueID(unsigned int unique_ID);*/

};