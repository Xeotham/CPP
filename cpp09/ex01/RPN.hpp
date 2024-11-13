#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <cstdlib>

class RPN {
	public:
		RPN(const std::string &str);
		~RPN();
	public:
		RPN	&operator=(const RPN &new_rpn);
	private:
		RPN();
		RPN(const RPN &new_rpn);
	private:
		void	computeData(char c);
		double	doOperation(char c, double first_value, double second_value);
	private:
		std::stack<double>	_stack;
};

#endif
