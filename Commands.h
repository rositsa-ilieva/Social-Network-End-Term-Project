#pragma once

class Commands {
protected:
	virtual void execute() = 0;
};

class SignUp : public Commands {
	void execute() override;
};

class LogIn : public Commands {
	void execute() override;
};

class LogOut : public Commands {
	void execute() override;
};

class SearchInText : public Commands {
	void execute() override;
};

class Post : public Commands {
	void execute() override;
};

class Comment : public Commands {
	void execute() override;
};

class Comments : public Commands {
	void execute() override;
};