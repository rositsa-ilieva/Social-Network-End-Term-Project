#include "Comment.h"

Comment::Comment() : user(), content(""){
	/*uniqueID = counter++;*/
};

Comment::Comment(const User& user, const MyString& content) :user(&user), content(content) {};

Comment::Comment(const User& user, const MyString& content, unsigned uniqueID, Vector<Comment> comments) :
                                 user(&user), content(content), uniqueID(uniqueID), comments(comments) {};
//
//void Comment::clearComments() {
//	comments.clear();
//}


//void Comment::setContent(const MyString& content) {
//	this->content = content;
//}
//void Comment::setUsers(const Users& users) {
//	this->users = users;
//}
//
//const MyString& Comment::getContent() const {
//	return content;
//}
//const Users& Comment::getUsers() const {
//	return users;
//}

unsigned Comment::getUniqueID() const {
	return uniqueID;
}

std::istream& operator>>(std::istream& is, Comment& comment) {
	is >> comment.content;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Comment& comment) {
	os << comment.content << " id: {" << comment.uniqueID << "}   " << "upvotes: " << comment.upvotes << "   downvotes: " << comment.downvotes << std::endl;
	return os;
}