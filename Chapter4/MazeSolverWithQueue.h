#pragma once

#include <queue>
using namespace std;
const int MAZE_SIZE = 6;

struct Location2D {
	int row;
	int col;

	Location2D() :row(0), col(0) {}
	Location2D(int row, int col) :row(row), col(col) {}

	bool isNeighbor(Location2D& p) {
		return	(row - p.row + col - p.col == 1 || row - p.row + col - p.col == -1);
	}

	bool operator==(Location2D& p) { return row == p.row && col == p.col; }

};

char map[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'}
};

bool isValidloc(int r, int c) {
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE)
	{
		return false;
	}
	else
	{
		return map[r][c] == '0' || map[r][c] == 'x';
	}
}

void mazeSolverwithQueue() {
	queue<Location2D> locQueue;
	Location2D entry(1, 0);
	locQueue.push(entry);

	while (locQueue.empty() == false)
	{
		Location2D here = locQueue.front();
		locQueue.pop();

		int r = here.row;
		int c = here.col;
		printf("(%d,%d)", r, c);

		if (map[r][c] == 'x')
		{
			printf("미로 탐색 성공\n");
			return;
		}
		else
		{
			map[r][c] = '.';
			// 상하좌우 순서로 가능한 길 탐색
			if (isValidloc(r - 1, c))
			{
				locQueue.push(Location2D(r - 1, c));
			}
			if (isValidloc(r + 1, c))
			{
				locQueue.push(Location2D(r + 1, c));
			}
			if (isValidloc(r, c - 1))
			{
				locQueue.push(Location2D(r, c - 1));
			}
			if (isValidloc(r, c + 1))
			{
				locQueue.push(Location2D(r, c + 1));
			}
		}
	}
	printf("미로 탐색 실패\n");
}