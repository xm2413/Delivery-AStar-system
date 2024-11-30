#include<bits/stdc++.h>
using namespace std;
const int MAXNAMELEN = 10;
const int MAXLEN = 11;
struct Node {
	int x, y;
	float g, h;
	Node *parent;

	Node(int x, int y) : x(x), y(y), g(0), h(0), parent(nullptr) {}

	float getF() const {
		return g + h;
	}
};

class AStar {
	public:
		vector<vector<int>> grid;
		int rows, cols;

		AStar(const vector<vector<int>>& grid) : grid(grid) {
			rows = grid.size();
			cols = grid[0].size();
		}

		float heuristic(Node* a, Node* b) {
			return abs(a->x - b->x) + abs(a->y - b->y);
		}

		vector<Node*> getNeighbors(Node* node) {
			vector<Node*> neighbors;
			int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
			for (auto& dir : directions) {
				int newX = node->x + dir[0];
				int newY = node->y + dir[1];
				if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 0) {
					neighbors.push_back(new Node(newX, newY));
				}
			}
			return neighbors;
		}

		vector<Node*> reconstructPath(Node* end) {
			vector<Node*> path;
			Node* current = end;
			while (current != nullptr) {
				path.push_back(current);
				current = current->parent;
			}
			reverse(path.begin(), path.end());
			return path;
		}

		vector<Node*> findPath(Node* start, Node* goal) {
			priority_queue<pair<float, Node*>, vector<pair<float, Node*>>, greater<pair<float, Node*>>> openSet;
			openSet.emplace(start->getF(), start);
			vector<vector<bool>> closedSet(rows, vector<bool>(cols, false));

			while (!openSet.empty()) {
				Node* current = openSet.top().second;
				openSet.pop();

				if (current->x == goal->x && current->y == goal->y) {
					return reconstructPath(current);
				}

				closedSet[current->x][current->y] = true;

				for (Node* neighbor : getNeighbors(current)) {
					if (closedSet[neighbor->x][neighbor->y]) continue;

					float tentativeG = current->g + 1; // Assuming cost between nodes is 1
					if (tentativeG < neighbor->g || neighbor->g == 0) {
						neighbor->parent = current;
						neighbor->g = tentativeG;
						neighbor->h = heuristic(neighbor, goal);
						openSet.emplace(neighbor->getF(), neighbor);
					}
				}
			}
			return {}; // Return empty path if no path found
		}
};
vector<vector<int>> grid = {
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0}
};
