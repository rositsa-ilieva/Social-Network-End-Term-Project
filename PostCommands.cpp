//#include "PostCommands.h"
//
//namespace {
//	bool isPrefix(const char* pattern, const char* text)
//	{
//		while (*text != '\0' && *pattern != '\0')
//		{
//			if (*text != *pattern)
//				return false;
//			text++;
//			pattern++;
//		}
//		return *pattern == '\0';
//	}
//}
//
//namespace {
//	bool searchInText(const char* text, const char* pattern)
//	{
//		size_t textLen = strlen(text);
//		size_t patternLen = strlen(pattern);
//		while (patternLen <= textLen)
//		{
//			if (isPrefix(pattern, text))
//				return true;
//			text++; //подминаваме първия символ
//			textLen--;
//		}
//		return false;
//	}
//}
//
//void PostCommands::list() const {
//	if (loggedUser != nullptr && openedTopic != nullptr) {
//		for (unsigned i = 0; i < openedTopic->getPosts().getSize(); i++) {
//			std::cout << ">> " << openedTopic->getPosts()[i];
//		}
//	}
//
//	else {
//		std::cout << "Error." << std::endl;
//	}
//}
//
//void PostCommands::p_open(const MyString& title) {
//	if (loggedUser != nullptr && openedTopic != nullptr) {
//		for (unsigned i = 0; i < openedTopic->getPosts().getSize(); i++) {
//			if (searchInText(openedTopic->getPosts()[i].getTopic().c_str(), title.c_str())) {
//				std::cout << "Q: " << openedTopic->getPosts()[i];
//				openedPost = &(openedTopic->posts[i]);
//				return;
//			}
//		}
//	}
//
//	else {
//		std::cout << "Error." << std::endl;
//	}
//}
//
//void PostCommands::p_open(unsigned id) {
//	if (loggedUser != nullptr && openedTopic != nullptr) {
//		for (unsigned i = 0; i < openedTopic->getPosts().getSize(); i++) {
//			if (openedTopic->getPosts()[i].getUniqueID() == id) {
//				std::cout << "Q: " << openedTopic->getPosts()[i];
//				openedPost = &(openedTopic->posts[i]);
//				return;
//			}
//		}
//	}
//
//	else {
//		std::cout << "Error." << std::endl;
//	}
//}
//
//void PostCommands::post() {
//	if (loggedUser != nullptr && openedTopic != nullptr) {
//		Post post;
//		std::cin >> post;
//		post.uniqueId = openedTopic->postCounter;
//		openedTopic->postCounter++;
//		openedTopic->posts.pushBack(post);
//
//	}
//
//	else {
//		std::cout << "Error." << std::endl;
//	}
//}
//
//void PostCommands::p_close() {
//	if (openedTopic != nullptr && loggedUser != nullptr && openedPost == nullptr) {
//		openedPost = nullptr;
//	}
//
//	else {
//		std::cout << "Error." << std::endl;
//	}
//}
//
//void PostCommands::reply(unsigned id) {
//	if (loggedUser != nullptr && openedTopic != nullptr && openedPost != nullptr) {
//		std::cout << COMMENT;
//
//		Comment reply;
//		std::cin >> reply;
//
//		reply.user = loggedUser;
//		reply.uniqueID = openedPost->postCounter++;
//
//		bool foundComment = false;
//
//		unsigned size = openedPost->comments.getSize();
//		for (unsigned i = 0; i < size; i++) {
//			if (openedPost->comments[i].uniqueID == id) {
//				openedPost->comments[i].comments.pushBack(reply);
//				foundComment = true;
//				break;
//			}
//			else {
//				unsigned subSize = openedPost->comments[i].comments.getSize();
//				for (unsigned j = 0; j < subSize; j++) {
//					if (openedPost->comments[i].comments[j].uniqueID == id) {
//						openedPost->comments[i].comments[j].comments.pushBack(reply);
//						foundComment = true;
//						break;
//					}
//				}
//				if (foundComment)
//					break;
//			}
//		}
//		if (foundComment) {
//			std::cout << "posted" << std::endl;
//			return;
//		}
//	}
//	std::cout << "error while repling" << std::endl;
//}
//
//void PostCommands::comment() {
//	
//		if (loggedUser != nullptr && openedTopic != nullptr && openedPost != nullptr) {
//			Comment comment;
//			std::cout << "Say something: ";
//			std::cin >> comment;
//			loggedUser->points++;
//			comment.uniqueID = openedPost->postCounter++;
//			openedPost->comments.pushBack(comment);
//		}
//	
//		else {
//			std::cout << "Error." << std::endl;
//		}
//}
//
//
//
//void PostCommands::upvote(unsigned id) {
//	if (loggedUser != nullptr && openedTopic != nullptr && openedPost != nullptr) {
//
//		for (unsigned i = 0; i < openedPost->comments.getSize(); i++)
//		{
//			/*if (openedPost->comments[i].getUniqueID() == id && loggedUser->voted == false) {
//				openedPost->comments[i].upvotes++;
//				loggedUser->voted = true;
//			}
//			else if (openedPost->comments[i].getUniqueID() == id && loggedUser->voted == true) {
//				openedPost->comments[i].upvotes--;
//				loggedUser->voted = false;
//			}
//			else {
//				if (searchCommentAndUpvote(id, openedPost->comments[i]))
//					break;
//			}*/
//		}
//	}
//
//	else {
//		std::cout << "Error." << std::endl;
//	}
//}
//
//void PostCommands::downvote(unsigned id) {
//
//	if (loggedUser != nullptr && openedTopic != nullptr && openedPost != nullptr) {
//
//		for (unsigned i = 0; i < openedPost->getComments().getSize(); i++) {
//			/*if (openedPost->getComments()[i].getUniqueID() == id && loggedUser->voted == true) {
//				openedPost->comments[i].downvotes--;
//				loggedUser->voted = false;
//			}
//			else if (openedPost->comments[i].getUniqueID() == id && loggedUser->voted == false) {
//				openedPost->comments[i].downvotes++;
//				loggedUser->voted = true;
//			}
//			else {
//				if (searchCommentAndDownvote(id, openedPost->comments[i]))
//					break;
//			}*/
//		}
//	}
//
//	else {
//		std::cout << "Error." << std::endl;
//	}
//}
//
//void PostCommands::printComment(const Comment& comment, int indentLevel) {
//	for (int i = 0; i < indentLevel; i++) {
//		std::cout << '\t';
//	}
//	std::cout << comment << std::endl;
//
//	unsigned size = comment.comments.getSize();
//	for (unsigned i = 0; i < size; i++) {
//		printComment(comment.comments[i], indentLevel + 1);
//	}
//}
//
//void PostCommands::comments() {
//	if (openedPost != nullptr) {
//		unsigned size = openedPost->comments.getSize();
//		for (unsigned i = 0; i < size; i++) {
//			printComment(openedPost->comments[i], 0);
//		}
//		return;
//	}
//	std::cout << "Error" << std::endl;
//}