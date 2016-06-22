#include <iostream>
#include <vector>
using namespace std;

const int move[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution{
public:
	bool exist(vector<vector<char> > &board, string word){
		int m = board.size(), n = board[0].size();
		vector<vector<bool> > flag(m, vector<bool>(n, 0));
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (dfs(board, flag, i, j, 0, word)) return true;
		return false;
	}
	
	bool dfs(vector<vector<char> > &board, vector<vector<bool> > &flag, int x, int y, int idx, string &word){
		if (idx >= word.size()) return false;
		if (board[x][y] == word[idx]) {
			if (idx == word.size() - 1) {
				for (int i = 0; i < board.size(); ++i){
					for (int j = 0; j < board[0].size(); ++j)
						cout << flag[i][j] << ' ';
					cout << endl;
				}
				return true;
			}
			flag[x][y] = 1;
			for (int i = 0; i < 4; ++i) {
				int xx = x + move[i][0], yy = y + move[i][1];
				if (!(0 <= xx && xx < board.size() && 0 <= yy && yy < board[0].size())) continue;
				if (!flag[xx][yy]){
					if (dfs(board, flag, xx, yy, idx+1, word)) return true; 
				}
			}
			flag[x][y] = 0;
		}
		return false;
	}
};

int main(){
	int n, m;
	char ch;
	string word;
	vector<vector<char> > board;
	cin >> n >> m >> word;
	for (int i = 0; i < n; ++i){
		vector<char> row;
		for (int j = 0; j < m; ++j) {
			cin >> ch;
			while (!(('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z'))) cin >> ch;
			row.push_back(ch);
		}
		board.push_back(row);
	}
	Solution sc;
	if (sc.exist(board, word)) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}