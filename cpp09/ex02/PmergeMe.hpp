#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <algorithm>
#include <list>

typedef std::vector<int>					t_vec;
typedef std::vector<std::pair<int, int> >	t_vec_pairs;
typedef std::list<int>						t_list;
typedef std::list<std::pair<int, int> >		t_list_pairs;

class PmergeMe {
	public:
		PmergeMe(char **tab);
		~PmergeMe();
	public:
		PmergeMe	&operator=(const PmergeMe &new_rpn);
	public:
		void				sort();
	private:
		PmergeMe();
		PmergeMe(const PmergeMe &new_rpn);
	private:
	/* Vector sorting */
		double				vectorSort();
		void				createVecPairs();
		void				sortVecPairs();
		void				makeBiggestVecLst();
		void				makeSmallestVecLst();
		t_vec::iterator		findVecPairs(int value);
		void				finalVecMerge();
		t_vec::iterator		vecBinarySearch(t_vec::iterator begin, t_vec::iterator end, int value);
	private:
	/* List sorting */
	double					listSort();
	void					createListPairs();
	void					sortListPairs();
	void					makeBiggestListLst();
	void					makeSmallestListLst();
	t_list::iterator		findListPairs(int value);
	void					finalListMerge();
	size_t					getDist(t_list::iterator start, t_list::iterator end);
	size_t					getDist(t_list_pairs::iterator start, t_list_pairs::iterator end);
	t_list::iterator		getMiddle(t_list::iterator begin, t_list::iterator end);
	t_list::iterator		listBinarySearch(t_list::iterator begin, t_list::iterator end, int value);
	private:
		t_vec		_vec_tab;
		t_vec_pairs	_vec_pairs;
		t_vec		_vec_smallest;
		t_vec		_vec_result;
	private:
		t_list			_list_tab;
		t_list_pairs	_list_pairs;
		t_list			_list_smallest;
		t_list			_list_result;


};

#endif
