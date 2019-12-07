#pragma once
#include "Maze.h"
/*
* Maze Generator:
*   Made by Jaden Peterson in 2016
*/

/*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
* This program uses the Direct-First Search algorithm
*   You can learn more about it at:
*     https://en.wikipedia.org/wiki/Maze_generation_algorithm#Depth-first_search
*/
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

class MazeGenerator
{
private:
	static const int UP = 0;
	static const int DOWN = 1;
	static const int LEFT = 2;
	static const int RIGHT = 3;

	int maze_size[2];

	int start_axis;
	int start_side;

	std::vector< std::vector< int > > dfs_path; // 

	/*
	* Structure of the maze vector:
	*                     |--> Filled in?
	*   Row --> Collumn --|
	*                     |--> Has been visited?
	*/
	std::vector< std::vector< std::vector< bool > > > maze;

	// Select a random direction based on our options, append it to the current path, and move there
	bool randomMove(bool first_move) { 
		int random_neighbor;
		std::vector< std::vector< int > > unvisited_neighbors;

		for (int direction = 0; direction < 4; direction++) { 
			int possible_pmd[2] = { 0, 0 };

			if (direction == UP) {
				possible_pmd[1] = -1;
			}
			else if (direction == DOWN) {
				possible_pmd[1] = 1;
			}
			else if (direction == LEFT) {
				possible_pmd[0] = -1;
			}
			else {
				possible_pmd[0] = 1;
			}

			if (dfs_path.back()[0] + possible_pmd[0] * 2 > 0 &&
				dfs_path.back()[0] + possible_pmd[0] * 2 < maze_size[0] - 1 &&
				dfs_path.back()[1] + possible_pmd[1] * 2 > 0 &&
				dfs_path.back()[1] + possible_pmd[1] * 2 < maze_size[1] - 1) {
				if (!maze[dfs_path.back()[1] + possible_pmd[1] * 2]
					[dfs_path.back()[0] + possible_pmd[0] * 2][1]) {
					std::vector< int > possible_move_delta = { possible_pmd[0], possible_pmd[1] };

					unvisited_neighbors.push_back(possible_move_delta);
				}
			}
		}

		if (unvisited_neighbors.size() > 0) {
			random_neighbor = rand() % unvisited_neighbors.size();

			for (int a = 0; a < !first_move + 1; a++) {
				std::vector< int > new_location;

				new_location.push_back(dfs_path.back()[0] + unvisited_neighbors[random_neighbor][0]);
				new_location.push_back(dfs_path.back()[1] + unvisited_neighbors[random_neighbor][1]);

				dfs_path.push_back(new_location);

				maze[dfs_path.back()[1]][dfs_path.back()[0]][0] = false;
				maze[dfs_path.back()[1]][dfs_path.back()[0]][1] = true;
			}

			return true;
		}
		else {
			return false;
		}
	}

	bool validInteger(const char* cstr) {
		std::string str(cstr);

		for (char& c : str) {
			if (!isdigit(c)) {
				return false;
			}
		}

		return true;
	}

	// The fun part ;)
	void generateMaze() {
		bool first_move = true;
		bool success = true;

		while ((int)dfs_path.size() > 1 - first_move) {
			if (!success) {
				dfs_path.pop_back();

				if (!first_move && dfs_path.size() > 2) {
					dfs_path.pop_back();
				}
				else {
					break;
				}

				success = true;
			}

			while (success) {
				success = randomMove(first_move);

				if (first_move) {
					first_move = false;
				}
			}
		}
	}

	// Initialize the maze vector with a completely-filled grid with the size the user specified
	void initializeMaze() {
		for (int a = 0; a < maze_size[1]; a++) {
			for (int b = 0; b < maze_size[0]; b++) {
				bool is_border;

				if (a == 0 || a == maze_size[1] - 1 ||
					b == 0 || b == maze_size[0] - 1) {
					is_border = true;
				}
				else {
					is_border = false;
				}

				std::vector< bool > new_cell = { true, is_border };

				if ((unsigned int)a + 1 > maze.size()) {
					std::vector< std::vector< bool > > new_row = { new_cell };

					maze.push_back(new_row);
				}
				else {
					maze[a].push_back(new_cell);
				}
			}
		}
	}

	void parseArgs(int argc, const char* argv[]) {
		bool width_found = false;
		bool height_found = false;
		int processing_number = -1;

		for (int arg = 1; arg < argc; arg++) {
			if (processing_number > -1) {
				if (validInteger(argv[arg])) {
					maze_size[processing_number] = atoi(argv[arg]);

					processing_number = -1;
				}
				else {
					std::cerr << "'" << argv[arg] << "'" << " is not a valid integer." << std::endl;
					exit(1);
				}
			}
			else {
				if (!strcmp(argv[arg], "-w")) {
					processing_number = 0;
					width_found = true;
				}
				else if (!strcmp(argv[arg], "-h")) {
					processing_number = 1;
					height_found = true;
				}
				else {
					std::cerr << "'" << argv[arg] << "'" << " is not a valid argument." << std::endl;
					exit(1);
				}
			}
		}

		if (!width_found || !height_found) {
			std::cerr << "You must specify the width and height with '-w' and '-h'" << std::endl;
			exit(1);
		}
	}

	void printMaze() {
		for (unsigned int a = 0; a < maze.size(); a++) {
			for (unsigned int b = 0; b < maze[a].size(); b++) {
				if (maze[a][b][0]) {
					std::cout << "■";
				}
				else {
					std::cout << "  ";
				}
			}

			std::cout << std::endl;
		}
	}


	// Set a random point (start or end)
	void randomPoint(bool part) {
		int axis;
		int side;

		if (!part) {
			axis = rand() % 2;
			side = rand() % 2;

			start_axis = axis;
			start_side = side;
		}
		else {
			bool done = false;

			while (!done) {
				axis = rand() % 2;
				side = rand() % 2;

				if (axis != start_axis ||
					side != start_side) {
					done = true;
				}
			}
		}

		std::vector< int > location = { 0, 0 };

		if (!side) {
			location[!axis] = 0;
		}
		else {
			location[!axis] = maze_size[!axis] - 1;
		}

		location[axis] = 2 * (rand() % ((maze_size[axis] + 1) / 2 - 2)) + 1;

		if (!part) {
			dfs_path.push_back(location);
		}

		maze[location[1]][location[0]][0] = false;
		maze[location[1]][location[0]][1] = true;
	}

public:
	void generate(Cell * map, const int width, const int height) {
		srand(time(NULL));

		std::string w = std::to_string(width);
		std::string h = std::to_string(height);
		
		const char* asdf[] = { "maze", "-w", w.c_str(), "-h", h.c_str() };

		parseArgs(5, asdf);

		// The width and height must be greater than or equal to 5 or it won't work
		// The width and height must be odd or else we will have extra walls
		for (int a = 0; a < 2; a++) {
			if (maze_size[a] < 5) {
				maze_size[a] = 5;
			}
			else if (maze_size[a] % 2 == 0) {
				maze_size[a]--;
			}
		}

		initializeMaze();
		randomPoint(false);
		randomPoint(true);
		generateMaze();

		//printMaze();

		for (unsigned int a = 0; a < maze.size(); a++) {
			for (unsigned int b = 0; b < maze[a].size(); b++) {
				if (maze[a][b][0]) {
					map[a * width + b] = Cell::WALL;
				}
				else {
					map[a * width + b] = Cell::SPACE;
				}
			}
		}
	}

};