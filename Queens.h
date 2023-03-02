#ifndef QUEENS_H_EXISTS
#define QUEENS_H_EXISTS

#include <iostream>
#include <vector>
#include <stack>
#include <array>

class Queens {
	private:
		int filled;
		int n;
		std::vector<std::vector<int>> board;
		std::stack<std::array<int, 2>> s;
	public:
		Queens();
		bool isValid(int r, int c);
		void printRow(int rowNum);
		void printBoard();
		void start();
};


#endif
