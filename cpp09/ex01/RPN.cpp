#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &new_rpn) {
	*this = new_rpn;
}

RPN::RPN(const std::string &str) {
	if (str.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw (std::invalid_argument("Invalid character in the string."));
	for (std::string::const_iterator iter = str.begin(); iter != str.end(); iter++) {
		if (*iter == ' ')
			continue ;
		this->computeData(*iter);
	}
	if (this->_stack.size() != 1)
		throw (std::invalid_argument("Invalid expression."));
	std::cout << this->_stack.top() << std::endl;
}

RPN::~RPN() {}

RPN	&RPN::operator=(const RPN &new_rpn) {
	if (this == &new_rpn)
		return (*this);
	this->_stack = new_rpn._stack;
	return (*this);
}

double	RPN::doOperation(char c, double first_value, double second_value) {
	switch (c) {
		case '+':
			return (second_value + first_value);
		case '-':
			return (second_value - first_value);
		case '*':
			return (second_value * first_value);
		case '/':
			if (first_value == 0)
				throw (std::invalid_argument("Division by zero."));
			return (second_value / first_value);
		default:
			throw (std::invalid_argument("Invalid operator."));
	}
}

void RPN::computeData(char c) {
	const std::string	operators = "+-*/";
	if (operators.find(c) != std::string::npos) {
		if (this->_stack.size() < 2)
			throw (std::invalid_argument("Invalid operation."));
		double	first_value = this->_stack.top();
		this->_stack.pop();
		double	second_value = this->_stack.top();
		this->_stack.pop();
		this->_stack.push(doOperation(c, first_value, second_value));
	}
	else if (c >= '0' && c <= '9')
		this->_stack.push(c - '0');

}
