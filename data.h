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

		vector<Node*> findPath(Node* start, Node* goals) {
			priority_queue<pair<float, Node*>, vector<pair<float, Node*>>, greater<pair<float, Node*>>> openSet;
			openSet.emplace(start->getF(), start);
			vector<vector<bool>> closedSet(rows, vector<bool>(cols, false));

			while (!openSet.empty()) {
				Node* current = openSet.top().second;
				openSet.pop();

				if (current->x == goals->x && current->y == goals->y) {
					return reconstructPath(current);
				}

				closedSet[current->x][current->y] = true;

				for (Node* neighbor : getNeighbors(current)) {
					if (closedSet[neighbor->x][neighbor->y]) continue;

					float tentativeG = current->g + 1; // Assuming cost between nodes is 1
					if (tentativeG < neighbor->g || neighbor->g == 0) {
						neighbor->parent = current;
						neighbor->g = tentativeG;
						neighbor->h = heuristic(neighbor, goals);
						openSet.emplace(neighbor->getF(), neighbor);
					}
				}
			}
			return {}; // Return empty path if no path found
		}
};
class Map {
	public:
		// 创建一个 i 行 j 列的二维 vector，初始值为0
		vector<vector<int>> createGrid(int i, int j) {
			vector<vector<int>> grid(i, vector<int>(j, 0));
			return grid;
		}
		void fillGrid(vector<vector<int>>& grid,FILE *pf) {
			for (int r = 0; r < grid.size(); ++r) {
				for (int c = 0; c < grid[r].size(); ++c) {
					fscanf(pf, "%d", grid[r][c]);
				}
			}
		}
		vector<vector<int> > grid = {
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		};
		void PrintMap() {
			for (int i = 0; i < grid.size(); ++i) {
				for (int j = 0; j < grid[i].size(); ++j) {
					printf("%2d",grid[i][j]);
				}
				printf("\n");
			}

		}
		void ModifyMap(int i,int j,int k) {
			grid[i-1][j-1]=k;
		}
		//输出到文件
		void SaveFile() {
			FILE *pf = fopen("MapData.sav", "w");
			fprintf(pf,"%d ",grid.size());
			fprintf(pf,"%d\n",grid[0].size());
			if (pf == NULL)cout<<"未找到文件2"<<endl;

			for (int i = 0; i < grid.size(); ++i) {
				for (int j = 0; j < grid[i].size(); ++j) {
					fprintf(pf,"%d ",grid[i][j]);
				}
				fprintf(pf,"\n");
			}
		}
		//从文件中读取
		void LoadFile() {
			FILE *pf = fopen("MapData.sav", "r");
			if (pf != NULL) {
				int rows, cols;
				fscanf(pf, "%d", &rows);
				fscanf(pf, "%d", &cols);
				grid=createGrid(rows,cols);
				//vector<vector<int> > temp;
				for (int r = 0; r < grid.size(); ++r) {
					for (int c = 0; c < grid[r].size(); ++c) {
						fscanf(pf, "%d", &grid[r][c]);
					}
				}
			} else cout<<"未找到文件"<<endl;
		}
		vector<Node*> goals;
		//vector<vector<Node*> > path;
		void Printgoals() {
			if (goals.size()<=0) {
				cout<<"暂无目标点"<<endl;
			} else {
				for (int i = 0; i < goals.size(); ++i) {
					cout<<"第"<<i<<"个目标点"<<endl<< goals[i]->x << ", " << goals[i]->y <<endl;
				}
			}
		}
		void Addgoals(int i1,int i2,int i3) {

			auto it = goals.begin() + i1; // 指向第二个位置

			Node* node1 = new Node(i2,i3);

			goals.insert(it,node1);
		}
		void Find1(Node start,Node goal) {

			AStar astar(grid);
			vector<Node*> path = astar.findPath(&start, &goal);
			for (Node* node : path) {
				cout << "(" << node->x << ", " << node->y << ") -> ";
			}
			cout << "End" << endl;
		}
		void FindALL() {
			for (int i = 0; i < goals.size()-1; ++i) {
				Find1(*goals[i],*goals[i+1]);
			}
		}
};
Map map1;
void OnLoad() {
	map1.LoadFile();
}

void find1(vector<vector<int>> grid,Node start,Node goals) {

	AStar astar(grid);
	vector<Node*> path = astar.findPath(&start, &goals);
	for (Node* node : path) {
		cout << "(" << node->x << ", " << node->y << ") -> ";
	}
	cout << "End" << endl;
}
