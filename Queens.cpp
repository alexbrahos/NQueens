#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <array>
#include "Queens.h"

Queens::Queens(){
	Queens::filled = 0;

	std::cout << "How many Queens? Please enter an integer: ";
	std::cin >> Queens::n;
	std::cin.ignore();

	int i;

	//set board size to nxn
	Queens::board.resize(n);
	for (i=0;i<n;i++){
		board[i].resize(n);
	}

	int j;

	//fill the board with 0s
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			Queens::board[i][j] = 0;
		} //end inside for
	} //end outside for

}

void Queens::printRow(int rowNum){

	//print the given row in the board
	int i;
	for (i=0;i<n;i++){
		std::cout << board[rowNum][i];
		std::cout << " ";
	}

	std::cout << "\n";

}

void Queens::printBoard(){

	//print every row
	int i;
	for (i=0;i<n;i++){
		printRow(i);
	} //end for

	std::cout << "\n";

}

bool Queens::isValid(int r, int c){

	int i;
	int j;

	//check the column
	for (i=r; i>=0; i--){
		if(board[i][c] == 1){
			return false;
		}
	} //done checking column

	//check left diagonal
	j=c;
	//loop ends when either i or j goes out of bounds
	for (i=r; i>=0; i--){
		if(board[i][j] == 1){
			return false;
		}
		j--;
		if (j<0){
			i=0;
		} //if we went too far left, stop the loop

	} //done checking left diagonal

	//check right diagonal
	j=c;
	//loop ends when either i or j goes out of bounds
	for (i=r; i>=0; i--){
		if(board[i][j] == 1){
			return false;
		}
		j++;
		if (j==n){
			i=0;
		} //if we went too far right, stop the loop

	} //done checking right diagonal

	//if all of these loops passed without returning false, it must be valid
	return true;
}

void Queens::start(){

	int currentCol=0;

	while(filled!=n){

		//if the current spot is valid, place the queen and move to the next row
		if (isValid(filled, currentCol)){

			s.push({filled, currentCol});
			board[filled][currentCol] = 1;
			filled ++;
			currentCol = 0;
			printBoard();

		//If it wasn't valid, move over a spot and test it
		} else if (currentCol != n-1){

			currentCol ++;
		//If we cant move over a spot, pop the stack as many times as we have to
		} else {

			filled -= 1;
			currentCol = s.top()[1] + 1;
			board[s.top()[0]][s.top()[1]] = 0;
			s.pop();
			while (currentCol == n){ //pop more rows until we can move a queen over
				filled -= 1;
				currentCol = s.top()[1] + 1;
				board[s.top()[0]][s.top()[1]] = 0;
				s.pop();
			} //end inside while

		} //end validity checker, check next spot/row

	} //end outside while, board should be complete

}
