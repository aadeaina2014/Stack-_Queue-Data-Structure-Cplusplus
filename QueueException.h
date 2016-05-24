

/****************************************************************************
Florida Institute Of Technology
College of Engineering
Electrical and Computer Engineering Department
ECE 2552 : Software Hardware Integration
Stack Exception

*****************************************************************************/

#ifndef QUEUEEXCEPTIONS_H
#define QUEUEEXCEPTIONS_H

#include <string>

//shorter exception code through inheritance
class RuntimeException {
	// generic run-time exception private:   
	std::string errorMsg;
public:
	RuntimeException(const std::string& err) { errorMsg = err; }
	std::string getMessage() const { return errorMsg; }
};


class QueueFull : public RuntimeException {
public:
	QueueFull(const std::string& err) : RuntimeException(err) {}
};


class QueueEmpty : public RuntimeException {
public:
	QueueEmpty(const std:: string& err) : RuntimeException(err) {}
};
/*
class QueueFull{
// generic run-time exception private:
std::string errorMsg;
public:
QueueFull(const std::string& err) { errorMsg = err; }
std::string getMessage() const { return errorMsg; }
};



class QueueEmpty {
// generic run-time exception private:
std::string errorMsg;
public:
QueueEmpty(const std::string& err) { errorMsg = err; }
std::string getMessage() const { return errorMsg; }
};

*/

# endif 