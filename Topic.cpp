#include "Topic.h"

Topic::Topic() :topic(""), creator(), content("") {};

//Topic::Topic() :topic(""),content("") {
//
//	/*uniqueID = counter++;*/
//    posts = Vector<Post>();
//}

//Добавя нов пост към вектора posts на темата. Постът се подава като константна референция и се добавя в края на вектора
void Topic::addPost(const Post& post)
{
    posts.pushBack(post);
}

//Изтрива пост по дадено ID
void Topic::deletePost(unsigned postId)
{
    for (size_t i = 0; i < posts.getSize(); i++)
    {
        if (posts[i].getUniqueID() == postId)
        {
            posts.popAt(i);
            return;
        }
    }

    throw std::exception("Post with this ID is not found");
}

//Връща вектора с всички постове в темата. Не променя състоянието на обекта Topic
Vector<Post> Topic::getPosts() const
{
    return posts;
}

Topic::Topic(const MyString& topic, const MyString& content, const User& creator) :topic(topic), content(content), 
                                                                                   creator(&creator), uniqueID(0) {};

Topic::Topic(const MyString& topic, const MyString& content, const User& creator, unsigned uniqueID, Vector<Post> posts) : topic(topic), 
                                                                content(content), creator(&creator), uniqueID(uniqueID),posts(posts) {};

void Topic::setTopic(const MyString& topic) {
    this->topic = topic;
}

void Topic::setCreator(const User& creator) {
    this->creator = &creator;
}

void Topic::setId(unsigned id) {
    uniqueID = id;
}

void Topic::setContent(const MyString& content) {
    this->content = content;
}

const MyString& Topic::getTopic() const {
    return this->topic;
}

unsigned Topic::getUniqueID() const {
    return this->uniqueID;
}

std::istream& operator>>(std::istream& is, Topic& topic) {
    std::cout << "Enter topic: ";
    is >> topic.topic;
    std::cout << std::endl;
    /*setFirstName(_first_name);*/


    std::cout << "Enter content: ";
    is >> topic.content;
    std::cout << std::endl;

    return is;
}

std::ostream& operator<<(std::ostream& os, const Topic& topic) {
    os << "Topic: " << topic.topic << std::endl;
    os << "Creator: " << std::endl;
    os << "-->" << * (topic.creator) << std::endl;
    os << "Content: " << topic.content << std::endl;
    os << "Posts: " << topic.posts.getSize() << std::endl;

    return os;
}