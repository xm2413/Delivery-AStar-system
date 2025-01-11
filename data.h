#ifndef DATA_H
#define DATA_H
#include"ui.h"
#include<bits/stdc++.h>
using namespace std;
const int MAXNAMELEN = 10;
const int MAXLEN = 11;
//节点
struct Node {
	int x, y;//x,y坐标
	float g, h;//g当前代价,h预估代价
	Node *parent;
	//构造函数
	Node(int x, int y) : x(x), y(y), g(0), h(0), parent(nullptr) {}
	//返回一个A*代价
	float getF() const {
		return g + h;
	}
};

//A*
class AStar {
	public:
		vector<vector<int>> grid;//存地图
		int rows, cols;//长宽
		//构造函数，传地图进来
		AStar(const vector<vector<int>>& grid) : grid(grid) {
			rows = grid.size();
			cols = grid[0].size();
		}
		//核心决策
		float heuristic(Node* a, Node* b) {
			return abs(a->x - b->x) + abs(a->y - b->y);
		}
		//搜索
		vector<Node*> getNeighbors(Node* node) {
			vector<Node*> neighbors;
			int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
			for (auto& dir : directions) {
				int newX = node->x + dir[0];
				int newY = node->y + dir[1];
				if (newX >= 0 && newX < rows && newY >= 0 && newY < cols ) {
					neighbors.push_back(new Node(newX, newY));
				}
			}
			return neighbors;
		}
		//构建路径
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
		//寻路
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

					float tentativeG = current->g + grid[current->x][current->y]; // Assuming cost between nodes is 1
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
//地图
class Map {
	public:
		// 创建一个 i 行 j 列的二维 vector，初始值为0
		vector<vector<int>> createGrid(int i, int j) {
			vector<vector<int>> grid(i, vector<int>(j, 0));
			return grid;
		}
		//填充地图
		void fillGrid(vector<vector<int>>& grid,FILE *pf) {
			for (int r = 0; r < grid.size(); ++r) {
				for (int c = 0; c < grid[r].size(); ++c) {
					fscanf(pf, "%d", grid[r][c]);
				}
			}
		}
		//设初始值
		vector<vector<int> > grid = {
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		};
		//打印地图
		void PrintMap() {
			uiManager.PrintTitle("      地图");
			printf("   ");
			for (int i = 0; i < grid[0].size(); ++i) {
				printf("%2d",i);
			}cout<<endl<<endl;
			for (int i = 0; i < grid.size(); ++i) {
				
				for (int j = 0; j < grid[i].size(); ++j) {
					if(j==0)printf("%2d ",i);
					
					printf("%2d",grid[i][j]);
				}
				printf("\n");
			}
		}
		//修改地图
		void ModifyMap(int i,int j,int k) {
			grid[i][j]=k;
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
		//导入外部文件
		void ImportLoadFile(char* result) {
			FILE *pf = fopen(result, "r");
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
				cout<<"导入成功！"<<endl;
			} else cout<<"未找到文件"<<endl;
		}
		vector<Node*> goals;
		//vector<vector<Node*> > path;
		//打印路径点
		void Printgoals() {
			if (goals.size()<=0) {
				cout<<"暂无目标点"<<endl;
			} else {
				for (int i = 0; i < goals.size(); ++i) {
					cout<<"第"<<i<<"个目标点"<<endl<< goals[i]->x << ", " << goals[i]->y <<endl;
				}
			}
		}
		//增加路径点
		void Addgoals(int i1,int i2,int i3) {

			auto it = goals.begin() + i1; // 指向第二个位置

			Node* node1 = new Node(i2,i3);

			goals.insert(it,node1);
		}
		//找一个点
		void Find1(Node start,Node goal) {

			AStar astar(grid);
			vector<Node*> path = astar.findPath(&start, &goal);
			for (Node* node : path) {
				cout << "(" << node->x << ", " << node->y << ") -> ";
			}
			cout << "End" << endl;
		}
		//找所有的路径
		void FindALL() {
			for (int i = 0; i < goals.size()-1; ++i) {
				Find1(*goals[i],*goals[i+1]);
			}
		}
};
Map map1;
//在读取的时候执行
void OnLoad() {
	map1.LoadFile();
}
#endif
