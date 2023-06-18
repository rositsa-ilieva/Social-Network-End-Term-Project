//#include "UserCommands.h"
//
//unsigned UserCommands::id = 0;
//
//bool UserCommands::userExists(const User& user) {
//	for (unsigned i = 0; i < users.getSize(); i++)
//	{
//		if (users[i].first_name == user.first_name &&
//			users[i].second_name == user.second_name &&
//			users[i].unique_ID == user.unique_ID) {
//
//			return true;
//		}
//	}
//	return false;
//}
//
//bool UserCommands::userExists(const MyString& username, const MyString& password) {
//	for (unsigned i = 0; i < users.getSize(); i++)
//	{
//		if (users[i].first_name == username && users[i].password == password) {
//			return true;
//		}
//	}
//	return false;
//}
//
//bool UserCommands::logIn() {
//	MyString name;
//	MyString password;
//	std::cout << "User name: ";
//	std::cin >> name;
//	std::cout << std::endl;
//	std::cout << "Password: ";
//	std::cin >> password;
//	std::cout << std::endl;
//
//
//	if (userExists(name, password)) {
//		for (unsigned i = 0; i < users.getSize(); i++)
//		{
//			if (users[i].first_name == name && users[i].password == password) {
//				loggedUser = &users[i];
//				return true;
//			}
//
//		}
//
//	}
//	std::cout << "There is no such user! Try again." << std::endl;
//	/*if (userExists(name, password) == true) {
//		for (unsigned i = 0; i < users.getSize(); i++)
//		{
//			if (name == users[i].first_name && password == users[i].password) {
//				if (loggedUser[i] == '1') {
//					std::cout << "Already logged user." << std::endl;
//					return false;
//				}
//				unsigned indexOfID = users[i].unique_ID;
//				loggedUser[i] = '1';
//				return true;
//			}
//		}
//	}*/
//
//	return false;
//}
//
//void UserCommands::logOut() {
//	loggedUser = nullptr;
//
//}
//
//
//bool UserCommands::signUp() {
//	User user;
//	std::cin >> user;
//	if (!userExists(user)) {
//		return false;
//	}
//	users.pushBack(user);
//	return true;
//}
//
//void UserCommands::whoami() {
//	if (loggedUser != nullptr) {
//		std::cout << *(loggedUser);
//	}
//
//	else {
//		std::cout << "Error." << std::endl;
//	}
//}
//
//unsigned UserCommands::userIndex() const {
//	for (unsigned i = 0; i < users.getSize(); i++)
//	{
//		if (&users[i] == loggedUser) {
//			return i;
//		}
//	}
//	return -1;
//}