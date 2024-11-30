#include<bits/stdc++.h>
using namespace std;
#include "ui.h"
#include "data.h"
void ShowRoadMenu() {
	Clear();
	PrintTitle("当前路径");

	map1.PrintMap();
	SetWait();
}

void ModifyRoadMenu() {
	Clear();
	PrintTitle("修改路径信息");
	int i1,i2,i3;
	InputInt(&i1,"请输入待修改路段x坐标");
	InputInt(&i2,"请输入待修改路段y坐标");
	InputInt(&i3,"请输入待修改路段通过时长");
	map1.ModifyMap(i1,i2,i3);
	SetWait();
}
void User() {
	while (1) {
		Clear();
		PrintTitle("配送系统");
		char* selections[] = {"查看当前路径", "修改路径信息", "回到主菜单"};
		ShowSelect(3, selections);
		int id = -1;
		InputInt(&id, "选择选项：");

		if (id <= 0 || id >= 4) {
			Print("未找到该选项，请重试");
			Fenge();
			SetWait();
			continue;
		}

		if (id == 1) ShowRoadMenu();
		else if (id == 2) ModifyRoadMenu();
		else if (id == 3) break;
		else printf("请输入1-3之间的数字！");
	}
}

void Option() {
	while (1) {
		Clear();
		PrintTitle("地图配置");
		char* selections[] = {"查看当前地图", "修改地图信息", "回到主菜单"};
		ShowSelect(3, selections);
		int id = -1;
		InputInt(&id, "选择选项：");

		if (id <= 0 || id >= 4) {
			Print("未找到该选项，请重试");
			Fenge();
			SetWait();
			continue;
		}

		if (id == 1) ShowRoadMenu();
		else if (id == 2) ModifyRoadMenu();
		else if (id == 3) break;
		else printf("请输入1-3之间的数字！");
	}
}

void MainMenu() {
	while (1) {
		Clear();
		PrintTitle("主菜单");
		char* selections[] = {"配送系统", "地图配置", "退出程序"};
		ShowSelect(3, selections);
		int id = -1;
		InputInt(&id, "选择选项：");

		if (id <= 0 || id >= 4) {
			Print("未找到该选项，请重试");
			Fenge();
			SetWait();
			continue;
		}

		if (id == 1) User();
		else if (id == 2) Option();
		else if (id == 3) ExitPage();
		else printf("请输入1-3之间的数字！");
	}
}
int main() {
	PrintTitle("欢迎使用外卖配送系统");
	SetWait();
	MainMenu();
	return 0;
}
