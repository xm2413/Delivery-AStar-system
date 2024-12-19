#include<bits/stdc++.h>
using namespace std;
#include "ui.h"
#include "data.h"
void PathMenu() {
	Clear();
	if (map1.goals.size()<=0) {
		PrintTitle("暂无路径点");
	} else {
		PrintTitle("路径点");
		map1.Printgoals();
		PrintTitle("路径");
		map1.FindALL();
	}

	SetWait();
}
void ModifygoalsMenu() {
	Clear();
	map1.Printgoals();
	int i1,i2,i3;
	if (map1.goals.size()<=0) {
		PrintTitle("请输入始末点");
		InputInt(&i2,"请输入起点x坐标");
		InputInt(&i3,"请输入起点y坐标");
		map1.Addgoals(0,i2,i3);
		InputInt(&i2,"请输入结束点x坐标");
		InputInt(&i3,"请输入结束点y坐标");
		map1.Addgoals(1,i2,i3);
		PrintTitle("添加成功");
	} else {
		PrintTitle("增加目标点");

		InputInt(&i1,"请输入增加位置");
		if (i1<0||i1>=map1.goals.size()) {
			PrintTitle("超出范围！");
			SetWait();
			return;
		}
		InputInt(&i2,"请输入目标点x坐标");
		InputInt(&i3,"请输入目标点y坐标");
		map1.Addgoals(i1,i2,i3);
		PrintTitle("添加成功");
	}
	SetWait();
}
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
	map1.SaveFile();
	SetWait();
}
void User() {
	while (1) {
		Clear();
		PrintTitle("配送系统");
		char* selections[] = {"查看当前路径", "修改节点信息", "回到主菜单"};
		ShowSelect(3, selections);
		int id = -1;
		InputInt(&id, "选择选项：");

		if (id <= 0 || id >= 4) {
			Print("未找到该选项，请重试");
			Fenge();
			SetWait();
			continue;
		}

		if (id == 1) PathMenu();
		else if (id == 2) ModifygoalsMenu();
		else if (id == 3) break;
		else printf("请输入1-3之间的数字！");
	}
}

void Option() {
	while (1) {
		Clear();
		PrintTitle("地图配置");
		char* selections[] = {"查看当前地图", "修改地图信息","导入外部地图","回到主菜单"};
		ShowSelect(4, selections);
		int id = -1;
		InputInt(&id, "选择选项：");

		if (id <= 0 || id >= 5) {
			Print("未找到该选项，请重试");
			Fenge();
			SetWait();
			continue;
		}

		if (id == 1) ShowRoadMenu();
		else if (id == 2) ModifyRoadMenu();
		else if (id == 3) tbd();
		else if (id == 4) break;
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
	//程序启动执行
	OnLoad();
	//
	PrintTitle("欢迎使用外卖配送系统");
	SetWait();
	MainMenu();
	return 0;
}
