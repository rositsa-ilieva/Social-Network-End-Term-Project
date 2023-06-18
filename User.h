#pragma once
#include "MyString.h"
#include "Constants.h"
#include "Vector.hpp"

class User
{
protected:
	friend class SocialNetwork;
	MyString first_name;
	MyString second_name;
	MyString password;
	/*static*/ unsigned unique_ID;/*
	static unsigned _counter;*/
	unsigned points;
	friend class UserCommands;
	friend class PostCommands;
	friend class FileCommands;
	Vector<unsigned> upvoteIDs;
	Vector<unsigned> downvoteIDs;
	
	
	/*Vector <Topic> topics;*/

	/*bool _logged_in;*/

public:

	//constructors
	User();
	User(const MyString& first_name, const MyString& second_name, 
		 const MyString& password, unsigned unique_ID, unsigned points);


	//getters
	const MyString& getFirstName() const;
	const MyString& getSecondName() const;
	const MyString& getPassword() const;
	unsigned int getUniqueID() const;
	unsigned int getPoints() const;


	//operators
	friend std::istream& operator>>(std::istream& is, User& user);
	friend std::ostream& operator<<(std::ostream& os, const User& user);

	/*void setFirstName(const MyString& first_name);
	void setSecondName(const MyString& second_name);
	void setPassword(const MyString& password);*/


	//functions
	/*void signup();
	bool login();

	void create();
	void search(const MyString& searched_name);

	void open(const MyString& topic_name);
	void open(unsigned int topic_ID);*/


};

