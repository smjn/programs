#include <iostream>
#include <bits/stdc++.h>
#include <iterator>
#include <functional>

using namespace std;

//code to solve nxn sudoku with box checking if
//the dimension is a perfect square
//ex: if 9x9 sudoku the box check done since dimension is 9
//ex: if 10x10 sudoku the box check is NOT done sice dimension is 10
//reads input from file puzzle.txt, with first line describing the characterset
//the sudoku grid follows
//the first line has all possible choices for each cell and all characters are allowed
//in the grid characters are separated by whitespace
//0 is taken to be uninitialized
//
//ex:
//1234
//0 0 0 0
//1 2 0 0
//0 3 1 0
//0 0 0 0

vector<vector<char> > grid;
int dim = 0;
bool shouldCheckBox = true;
string choices;

void printGrid(){
	for(int i=0; i<dim; i++){
		for(int j=0;j<dim;j++)
			cout<<grid[i][j]<<" ";
		cout<<endl;
	}

	cout << endl << endl;
}

bool checkBox(int x1, int y1, int x, int y, char choice){
	int temp = sqrt(dim);
	for(int i=x1;i<x1+temp;i++)
		for(int j=y1;j<y1+temp;j++)
			if(grid[i][j]==choice && i!=x && j!=y)
				return false;

	return true;
}

bool checkGrid(char choice,int x, int y){
	if(choice=='0')	return false;
	//check row
	for(int i=0;i<dim;i++)
		if(grid[x][i]==choice && i!=y) return false;
	//check col
	for(int i=0;i<dim;i++)
		if(grid[i][y]==choice && i!=x) return false;
	//check box only if dimension is perfect square
	if(shouldCheckBox){
		int temp = sqrt(dim);
		for(int i=0;i<dim;i+=temp){
			if(x>=i && x<=i+temp-1){
				for(int j=0;j<dim; j+=temp){
					if(y>=j && y<=j+temp-1)	
						return checkBox(i,j,x,y,choice);
				}
			}
		}
	}

	return true;	//incase box check is disabled
}

bool isAnyUnfilledLocation(int &r, int &c){
	for(int i=0;i<dim; i++){
		for(int j=0;j<dim; j++){
			if(grid[i][j] == '0'){
				r=i;
				c=j;
				return true;
			}
		}
	}
	return false;
}

bool solve(){
	int r,c;
	if(!isAnyUnfilledLocation(r, c))	return true;
	
	for(auto it=choices.begin(); it!=choices.end(); it++){
		if(checkGrid(*it,r,c)){
			grid[r][c]=*it;
			if(solve())	return true;
			grid[r][c]='0';
		}
	}
	return false;
}

int main(){
	fstream fh("puzzle.txt");
	string buffer;
	stringstream s;
	getline(fh,buffer,'\n');
	choices=buffer;
	s.clear();
		
	while(getline(fh,buffer,'\n')){
		vector<char> row;
		s<<buffer;
		while(!s.eof()){
			char temp;
			s>>temp;
			row.push_back(temp);
		}
		s.clear();
		grid.push_back(row);
	}
	dim = grid.size();
	int temp2 = sqrt(dim);
	if(temp2*temp2 != dim){
		shouldCheckBox = false;
		cout << endl << "Box check is disabled as grid dimension is not perfect square:" << dim << endl;
	}

	printGrid();
	if(solve())	printGrid();

	return 0;
}

