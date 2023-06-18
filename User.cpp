#include "User.h"

//unsigned User::_counter = 0;

User::User() : first_name(""), second_name(""),
               password(""), unique_ID(0), points(0) {};

User::User(const MyString& first_name, const MyString& second_name,
	       const MyString& password, unsigned unique_ID, unsigned points) : 
	       first_name(first_name), second_name(second_name),
           password(password), unique_ID(unique_ID), points(points) {};

std::istream& operator>>(std::istream& is, User& user) {
	std::cout << "Enter first name: ";
	is >> user.first_name;
	std::cout << std::endl;
	/*setFirstName(_first_name);*/


	std::cout << "Enter second name: ";
	is >> user.second_name;
	std::cout << std::endl;
	/*setSecondName(_second_name);*/


	std::cout << "Enter your password: ";
	is >> user.password;
	std::cout << std::endl;

	return is;

}

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "~~> First name: " << user.first_name << std::endl;
	os << "~~> Last name: " << user.second_name << std::endl;
	os << "~~> Points: " << user.points << std::endl;
    return os;
}
//
//void User::setFirstName(const MyString& first_name) {
//	_first_name = first_name;
//}
//
//void User::setSecondName(const MyString& second_name) {
//	_second_name = second_name;
//}
//
//void User::setPassword(const MyString& password) {
//	_password = password;
//}
//
//User::User(const MyString& first_name, const MyString& second_name,
//	const MyString& password/* unsigned int unique_ID,*/ /*unsigned int points*/) {
//	setFirstName(first_name);
//	setSecondName(second_name);
//	setPassword(password);
//	/*setUniqueID(unique_ID);*//*
//	setPoints(points);*/
//
//}