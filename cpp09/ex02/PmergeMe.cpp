#include "PmergeMe.hpp"
#include <ctime>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <stdexcept>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **tab) {
	std::string	str;

	if (tab == NULL || *tab == NULL)
		throw (std::invalid_argument("Invalid argument"));
	for (int i = 0; tab[i] != NULL; i++) {
		str = tab[i];
		if (str.find_first_not_of("0123456789+-") != std::string::npos)
			throw (std::invalid_argument("Invalid argument"));
		else if (str.size() == 1 && !std::isdigit(str[0]))
			throw (std::invalid_argument("Invalid argument"));
		else if (str.size() < 1 && str[0] != '+' && str[0] != '-' && !std::isdigit(str[0]))
			throw (std::invalid_argument("Invalid argument"));
		else if (str.size() < 1 && (str[0] == '+' || str[0] == '-' || std::isdigit(str[0]))
			&& str.find_first_not_of("0123456789") != std::string::npos)
			throw (std::invalid_argument("Invalid argument"));
		else if (std::atol(str.c_str()) < -2147483648 || std::atol(str.c_str()) > 2147483647)
			throw (std::invalid_argument("Invalid argument"));
		_vec_tab.push_back(std::atoi(str.c_str()));
		_list_tab.push_back(std::atoi(str.c_str()));
	}
}

PmergeMe::PmergeMe(const PmergeMe &new_rpn) {
	*this = new_rpn;
}

PmergeMe::~PmergeMe() {}

PmergeMe	&PmergeMe::operator=(const PmergeMe &new_rpn) {
	if (this == &new_rpn)
		return (*this);
	this->_vec_tab = new_rpn._vec_tab;
	this->_vec_pairs = new_rpn._vec_pairs;
	this->_vec_result = new_rpn._vec_result;
	this->_vec_smallest = new_rpn._vec_smallest;
	this->_list_tab = new_rpn._list_tab;
	this->_list_pairs = new_rpn._list_pairs;
	this->_list_result = new_rpn._list_result;
	this->_list_smallest = new_rpn._list_smallest;
	return (*this);
}

void PmergeMe::sort() {
	std::cout << "Before:\t";
	for (t_list::iterator iter = this->_list_tab.begin(); iter != this->_list_tab.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
	double	vec_time = this->vectorSort();
	double	list_time = this->listSort();
	std::cout << "After:\t";
	for (t_list::iterator iter = this->_list_result.begin(); iter != this->_list_result.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << this->_vec_result.size() << " with std::vector:\t" << vec_time << " ms." << std::endl;
	std::cout << "Time to process a range of " << this->_list_result.size() << " with std::list: \t" << list_time << " ms." << std::endl;
}

double PmergeMe::vectorSort() {
	clock_t	start;
	clock_t	end;

	start = clock();
	this->createVecPairs();
	this->sortVecPairs();
	this->makeBiggestVecLst();
	this->makeSmallestVecLst();
	this->finalVecMerge();
	end = clock();
	return (static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000));
}

void	PmergeMe::createVecPairs() {
	for (t_vec::iterator iter = this->_vec_tab.begin(); iter != this->_vec_tab.end(); iter++) {
		if (iter + 1 == this->_vec_tab.end())
			break;
		this->_vec_pairs.push_back(std::make_pair(*iter, *(iter + 1)));
		iter += 1;
	}
	if (this->_vec_tab.size() % 2 != 0)
		this->_vec_smallest.push_back(*(this->_vec_tab.end() - 1));
	this->_vec_tab.clear();
}

void PmergeMe::sortVecPairs() {
	for (t_vec_pairs::iterator iter = this->_vec_pairs.begin(); iter != this->_vec_pairs.end(); iter++) {
		if (iter->first < iter->second)
			std::swap(iter->first, iter->second);
	}
}

void PmergeMe::makeBiggestVecLst() {
	for (t_vec_pairs::iterator iter = this->_vec_pairs.begin(); iter != this->_vec_pairs.end(); iter++)
		this->_vec_result.push_back(iter->first);
	std::sort(_vec_result.begin(), _vec_result.end());
	for (t_vec_pairs::iterator iter = this->_vec_pairs.begin(); iter != this->_vec_pairs.end(); iter++) {
		if (iter->first == (*this->_vec_result.begin())) {
			this->_vec_result.insert(this->_vec_result.begin(), iter->second);
			this->_vec_pairs.erase(iter);
			break ;
		}
	}
}

void PmergeMe::makeSmallestVecLst() {
	for (t_vec_pairs::iterator iter = this->_vec_pairs.begin(); iter != this->_vec_pairs.end(); iter++)
		this->_vec_smallest.push_back(iter->second);
}

t_vec::iterator	PmergeMe::findVecPairs(int value) {
	for (t_vec_pairs::iterator iter = this->_vec_pairs.begin(); iter != this->_vec_pairs.end(); iter++) {
		if (iter->second == value)
			return (std::find(this->_vec_result.begin(), this->_vec_result.end(), iter->first));
	}
	return (this->_vec_result.end());
}

void PmergeMe::finalVecMerge() {
	for (t_vec::iterator iter = this->_vec_smallest.begin(); iter != this->_vec_smallest.end(); iter++) {
		t_vec::iterator it = this->vecBinarySearch(this->_vec_result.begin(), this->findVecPairs(*iter), *iter);
		this->_vec_result.insert(it, *iter);
	}
}

t_vec::iterator	PmergeMe::vecBinarySearch(t_vec::iterator begin, t_vec::iterator end, int value) {
	t_vec::iterator mid;

	while (begin < end) {
		mid = begin + (end - begin) / 2;
		if (*mid == value)
			return (mid);
		if (*mid < value)
			begin = mid + 1;
		else
			end = mid;
	}
	return (begin);
}

double PmergeMe::listSort() {
	clock_t	start;
	clock_t	end;

	start = clock();
	this->createListPairs();
	this->sortListPairs();
	this->makeBiggestListLst();
	this->makeSmallestListLst();
	this->finalListMerge();
	end = clock();
	return (static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000));
}

void	PmergeMe::createListPairs() {
	for (t_list::iterator iter = this->_list_tab.begin(); iter != this->_list_tab.end(); iter++) {
		t_list::iterator	tmp = iter;
		++tmp;
		if (tmp == this->_list_tab.end())
			break;
		this->_list_pairs.push_back(std::make_pair(*iter, *tmp));
		iter = tmp;
	}
	if (this->_list_tab.size() % 2 != 0)
		this->_list_smallest.push_back(_list_tab.back());
	this->_list_tab.clear();
}

void PmergeMe::sortListPairs() {
	for (t_list_pairs::iterator iter = this->_list_pairs.begin(); iter != this->_list_pairs.end(); iter++) {
		if (iter->first < iter->second)
			std::swap(iter->first, iter->second);
	}
}

void PmergeMe::makeBiggestListLst() {
	for (t_list_pairs::iterator iter = this->_list_pairs.begin(); iter != this->_list_pairs.end(); iter++)
		this->_list_result.push_back(iter->first);
	this->_list_result.sort();
	for (t_list_pairs::iterator iter = this->_list_pairs.begin(); iter != this->_list_pairs.end(); iter++) {
		if (iter->first == (*this->_list_result.begin())) {
			this->_list_result.push_front(iter->second);
			this->_list_pairs.erase(iter);
			break ;
		}
	}
}

void PmergeMe::makeSmallestListLst() {
	for (t_list_pairs::iterator iter = this->_list_pairs.begin(); iter != this->_list_pairs.end(); iter++)
		this->_list_smallest.push_back(iter->second);
}

t_list::iterator	PmergeMe::findListPairs(int value) {
	for (t_list_pairs::iterator iter = this->_list_pairs.begin(); iter != this->_list_pairs.end(); iter++) {
		if (iter->second == value)
			return (std::find(this->_list_result.begin(), this->_list_result.end(), iter->first));
	}
	return (this->_list_result.end());
}

void PmergeMe::finalListMerge() {
	for (t_list::iterator iter = this->_list_smallest.begin(); iter != this->_list_smallest.end(); iter++) {
		t_list::iterator it = this->listBinarySearch(this->_list_result.begin(), this->findListPairs(*iter), *iter);
		this->_list_result.insert(it, *iter);
	}
}

size_t	PmergeMe::getDist(t_list::iterator start, t_list::iterator end) {
	size_t	dist = 0;

	while (start != end) {
		++dist;
		++start;
	}
	return (dist);
}

t_list::iterator	PmergeMe::getMiddle(t_list::iterator begin, t_list::iterator end) {
	size_t	i = 0;
	size_t	middle_dist = getDist(begin, end) / 2;

	while (i < middle_dist) {
		++begin;
		++i;
	}
	return (begin);
}

t_list::iterator	PmergeMe::listBinarySearch(t_list::iterator begin, t_list::iterator end, int value) {
	t_list::iterator mid;

	while (getDist(this->_list_result.begin(), begin) < getDist(this->_list_result.begin(), end)) {
		mid = getMiddle(begin, end);
		if (*mid == value)
			return (mid);
		if (*mid < value)
			begin = ++mid;
		else
			end = mid;
	}
	return (begin);
}
