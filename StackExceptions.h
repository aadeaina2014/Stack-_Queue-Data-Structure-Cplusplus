

/****************************************************************************
                   Florida Institute Of Technology
                   College of Engineering
                   Electrical and Computer Engineering Department
                   ECE 2552 : Software Hardware Integration
                   Stack Exception 

*****************************************************************************/

#ifndef STACKEXCEPTIONS_H
#define STACKEXCEPTIONS_H
#include <string>

class RuntimeException {
	// generic run-time exception private:   
	std::string errorMsg;
public:
	RuntimeException(const std::string& err) { errorMsg = err; }
	std::string getMessage() const { return errorMsg; }
};


class StackFull : public RuntimeException {
public:
	StackFull(const std::string& err) : RuntimeException(err) {}
};

class StackEmpty : public RuntimeException {
public:
	StackEmpty(const std::string& err) : RuntimeException(err) {}
};
/*
class StackFull{
// generic run-time exception private:
std::string errorMsg;
public:
StackFull(const std::string& err) { errorMsg = err; }
std::string getMessage() const { return errorMsg; }
};



class StackEmpty {
// generic run-time exception private:
std::string errorMsg;
public:
StackEmpty(const std::string& err) { errorMsg = err; }
std::string getMessage() const { return errorMsg; }
};
*/


# endif 