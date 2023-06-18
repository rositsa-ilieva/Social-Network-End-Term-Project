#pragma once
#include "User.h"
#include "Vector.hpp"
#include "Topic.h"
#include "Post.h"
#include "PostCommands.h"

class SocialNetwork {
public:

	SocialNetwork();
	~SocialNetwork();
	void execute();

	Vector<User> users;
	Vector<Topic> topics;
	User* loggedUser;
	Topic* openedTopic;
	Post* openedPost;
	static unsigned id;

	bool userExists(const User& user);
	bool userExists(const MyString& username, const MyString& password);

	bool signUp();

	bool logIn();
	void logOut();

	void open(const MyString& name);
	void open(unsigned id);
	void search(const MyString& name);

	void create();

	void list() const;

	void p_open(const MyString& title);
	void p_open(unsigned id);

	void post();

	unsigned userIndex() const;

	void comment();
	void comments();

	void reply(unsigned id);

	void quit();
	void p_close();

    void whoami();

	unsigned topicIndex(unsigned ind);

	bool hasUpvoted(unsigned id);
	bool hasDownvoted(unsigned id);

	void upvote(unsigned id);
	void downvote(unsigned id);

	void about(unsigned id);

	bool isValidIndex(unsigned id);

	bool searchComments(Comment& searchedComment, const Comment& reply, unsigned id);
	void printComments(const Comment& comment, int indentLevel);

	User readUser(std::ifstream& ifs);
	Topic readTopic(std::ifstream& ifs);
	Comment readComment(std::ifstream& ifs);
	Post readPost(std::ifstream& ifs);


	void writeUser(std::ofstream& ofs, const User& user);
	void writeTopic(std::ofstream& ofs, const Topic& topic);
	void writeComment(std::ofstream& ofs, const Comment& comment);
	void writePost(std::ofstream& ofs, const Post& post);


	





}; 