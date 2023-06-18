#include "Post.h"

Post::Post() : topic(""), content(""), uniqueId(0) {};
    /*comments = Vector<Comment>()*/;


Post::Post(const MyString& topic, const MyString& content, unsigned uniqueId, const Vector<Comment>& comments) :
           topic(topic), content(content), uniqueId(uniqueId), comments(comments) {};


Post::Post(const MyString& topic, const MyString& content) : topic(topic), content(content) {};

const MyString& Post::getContent() const {
    return content;
}
          
const MyString& Post::getTopic() const {
    return topic;
}

unsigned Post::getUniqueID() const {
    return uniqueId;
}

void Post::setContent(const MyString& content) {
    this->content = content;
}

void Post::setTopic(const MyString& topic) {
    this->topic = topic;
}

void Post::addComment(const Comment& comment) {
    comments.pushBack(comment);
}
void Post::deleteComment(int commentId) {
    for (unsigned i = 0; i < comments.getSize(); i++) {
        if (comments[i].getUniqueID() == commentId) {
            comments.popAt(i);
            return;
        }
    }
}

Vector<Comment> Post::getComments() const {
    /*Vector<Comment> commentVector;
    for (size_t i = 0; i < comments.getSize(); i++) {
        commentVector.pushBack(comments[i]);
    }
    return commentVector;*/
    return comments;
}

std::istream& operator>>(std::istream& is, Post& post) {
    std::cout << "Enter title: ";
    is >> post.topic;
    std::cout << std::endl;
    /*setFirstName(_first_name);*/


    std::cout << "Enter content: ";
    is >> post.content;
    std::cout << std::endl;

    return is;
}

std::ostream& operator<<(std::ostream& os, const Post& post) {
    os << "Post name: " << post.topic << std::endl;
    os << "Post ID: {id:" << post.uniqueId << "}" << std::endl;

    return os;
}