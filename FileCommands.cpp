//#include "FileCommands.h"
//
//namespace {
//	MyString readFromFile(std::ifstream& ifs) {
//		int stringLength;
//		ifs.read((char*)&stringLength, sizeof(int));
//		char* str = new char[stringLength + 1];
//		ifs.read(str, stringLength);
//		str[stringLength] = '\0';
//	
//		return str;
//	}
//}
//
//User FileCommands::readUser(std::ifstream& ifs) {
//	User user;
//	user.first_name = readFromFile(ifs);
//	user.second_name = readFromFile(ifs);
//	user.password = readFromFile(ifs);
//
//	unsigned id, points;
//	ifs.read((char*)&id, sizeof(unsigned));
//	ifs.read((char*)&points, sizeof(unsigned));
//	user.unique_ID = id;
//	user.points = points;
//	////////////////////////////////////
//
//	return user;
//}
//
//Topic FileCommands::readTopic(std::ifstream& ifs) {
//	Topic topic;
//	topic.topic = readFromFile(ifs);
//
//	unsigned ind, id;
//	ifs.read((char*)&ind, sizeof(unsigned));
//	topic.indexOfCreator = ind;
//
//	topic.content = readFromFile(ifs);
//
//	ifs.read((char*)&id, sizeof(unsigned));
//	topic.uniqueID = id;
//
//	int postCount;
//	ifs.read((char*)&postCount, sizeof(unsigned));
//
//	for (unsigned i = 0; i < postCount; i++) {
//		topic.posts.pushBack(readPost(ifs));
//	}
//
//	return topic;
//}
//
//Comment FileCommands::readComment(std::ifstream& ifs) {
//	Comment comment;
//
//	unsigned index, countUpvotes, countDownvotes, id;
//	ifs.read((char*)&index, sizeof(unsigned));
//	/*comment.user = &users[index];*/
//	comment.indexOfCreator = index;
//
//	ifs.read((char*)&countUpvotes, sizeof(unsigned));
//	comment.upvotes = countUpvotes;
//
//	ifs.read((char*)&countDownvotes, sizeof(unsigned));
//	comment.downvotes = countDownvotes;
//
//	ifs.read((char*)&id, sizeof(unsigned));
//	comment.uniqueID = id;
//
//	int repliesCount;
//	ifs.read((char*)&repliesCount, sizeof(unsigned));
//
//	for (unsigned i = 0; i < repliesCount; i++)
//		comment.comments.pushBack(readComment(ifs));
//
//	return comment;
//}
//
//Post FileCommands::readPost(std::ifstream& ifs) {
//	Post post;
//
//	post.topic = readFromFile(ifs);
//	post.content = readFromFile(ifs);
//
//	unsigned counter, id;
//	static unsigned size = sizeof(unsigned);
//	ifs.read((char*)&counter, size);
//	post.postCounter = counter;
//
//	ifs.read((char*)&id, size);
//	post.uniqueId = id;
//
//	int post_count;
//	ifs.read((char*)&post_count, sizeof(unsigned));
//
//	for (size_t i = 0; i < post_count; i++)
//		post.comments.pushBack(readComment(ifs));
//
//	return post;
//}
//
//namespace {
//	void writeToFile(std::ofstream& ofs, const char* text) {
//		unsigned stringLength = strlen(text);
//		ofs.write((const char*)&stringLength, sizeof(unsigned));
//		ofs.write(text, stringLength);
//	}
//}
//
//void FileCommands::writeUser(std::ofstream& ofs, const User& user) {
//	writeToFile(ofs, user.first_name.c_str());
//	writeToFile(ofs, user.second_name.c_str());
//	writeToFile(ofs, user.password.c_str());
//	ofs.write((const char*)&user.unique_ID, sizeof(unsigned));
//	ofs.write((const char*)&user.points, sizeof(unsigned));
//	//ofs.write((const char*)&us.voted, sizeof(user.voted));
//}
//
//void FileCommands::writeTopic(std::ofstream& ofs, const Topic& topic) {
//	writeToFile(ofs, topic.topic.c_str());
//	ofs.write((const char*)&topic.indexOfCreator, sizeof(unsigned));
//	writeToFile(ofs, topic.content.c_str());
//	ofs.write((const char*)&topic.uniqueID, sizeof(unsigned));
//	int postsSize = topic.posts.getSize();
//	ofs.write((const char*)&postsSize, sizeof(unsigned));
//
//	for (size_t i = 0; i < postsSize; i++)
//		(ofs, topic.posts[i]);
//}
//
//void FileCommands::writeComment(std::ofstream& ofs, const Comment& comment) {
//
//	ofs.write((const char*)&comment.indexOfCreator, sizeof(unsigned));
//
//	writeToFile(ofs, comment.content.c_str());
//
//	ofs.write((const char*)&comment.upvotes, sizeof(unsigned));
//	ofs.write((const char*)&comment.downvotes, sizeof(unsigned));
//	ofs.write((const char*)&comment.uniqueID, sizeof(unsigned));
//
//	int repliesSize = comment.comments.getSize();
//	ofs.write((const char*)&repliesSize, sizeof(unsigned));
//
//	for (unsigned i = 0; i < repliesSize; i++)
//		writeComment(ofs, comment.comments[i]);
//
//}
//
//void FileCommands::writePost(std::ofstream& ofs, const Post& post) {
//
//	writeToFile(ofs, post.topic.c_str());
//	writeToFile(ofs, post.content.c_str());
//
//	ofs.write((const char*)&post.postCounter, sizeof(unsigned));
//	ofs.write((const char*)&post.uniqueId, sizeof(unsigned));
//
//	int commentsSize = post.comments.getSize();
//	ofs.write((const char*)&commentsSize, sizeof(int));
//
//	for (unsigned i = 0; i < commentsSize; i++)
//		writeComment(ofs, post.comments[i]);
//}
