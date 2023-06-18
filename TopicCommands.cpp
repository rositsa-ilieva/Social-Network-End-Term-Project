//#include "TopicCommands.h"
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
//
//void TopicCommands::search(const MyString& name) {
//	if (loggedUser != nullptr) {
//		for (unsigned i = 0; i < topics.getSize(); i++)
//		{
//			if (searchInText(topics[i].topic.c_str(), name.c_str())) {
//				std::cout << topics[i].topic << " {id:" << topics[i].uniqueID << "}" << std::endl;
//			}
//		}
//	}
//	else {
//		std::cout << "Error." << std::endl;
//	}
//
//}
//
//void TopicCommands::open(const MyString& name)
//{
//	///////////////////////////////////samo ako e lognat shte se izpulnqt!!!
//	if (loggedUser != nullptr) {
//		for (unsigned i = 0; i < topics.getSize(); i++)
//		{
//			if (searchInText(topics[i].topic.c_str(), name.c_str())) {
//				std::cout << "Welcome to " << topics[i].topic << "!" << std::endl;
//				openedTopic = &topics[i];
//				break;
//			}
//		}
//	}
//
//	else {
//		std::cout << "Error." << std::endl;
//	}
//
//}
//
//void TopicCommands::open(unsigned id)
//{
//	///////////////////////////////////samo ako e lognat shte se izpulnqt!!!
//	if (loggedUser != nullptr) {
//		for (unsigned i = 0; i < topics.getSize(); i++)
//		{
//			if (topics[i].uniqueID = id) {
//				std::cout << "Welcome to " << topics[i].topic << "!" << std::endl;
//				openedTopic = &topics[i];
//				break;
//			}
//		}
//	}
//
//	else {
//		std::cout << "Error." << std::endl;
//	}
//}
//
//
//void TopicCommands::create() {
//	if (loggedUser != nullptr) {
//		Topic topic;
//		std::cin >> topic;
//
//		topic.setId(id++);
//		topic.setCreator(*loggedUser);
//		topic.indexOfCreator = userIndex();
//
//		topics.pushBack(topic);
//
//	}
//
//	else {
//		std::cout << "Error." << std::endl;
//	}
//}
//
//void TopicCommands::quit() {
//	if (openedTopic != nullptr && loggedUser != nullptr) {
//		openedTopic = nullptr;
//	}
//
//	else {
//		std::cout << "Error." << std::endl;
//	}
//}
//
//unsigned TopicCommands::topicIndex(unsigned ind) {
//
//	for (unsigned i = 0; i < topics.getSize(); i++) {
//		if (topics[i].uniqueID == ind) {
//			return i;
//		}
//	}
//	return -1;
//}
//
//
//void TopicCommands::about(unsigned id) {
//	if (topicIndex(id) != -1 && loggedUser != nullptr) {
//		std::cout << topics[topicIndex(id)];
//	}
//
//	else {
//		std::cout << "Error." << std::endl;
//	}
//}