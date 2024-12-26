#include<bits/stdc++.h>
using namespace std;
#include "ui.h"
#include "data.h"
void PathMenu() {

	uiManager.Clear();
	map1.PrintMap();
	if (map1.goals.size()<=0) {
		uiManager.PrintTitle("暂无路径点");
	} else {
		uiManager.PrintTitle("路径点");
		map1.Printgoals();
		uiManager.PrintTitle("路径");
		map1.FindALL();
	}

	uiManager.SetWait();
}
void ModifygoalsMenu() {
	uiManager.Clear();
	map1.PrintMap();
	map1.Printgoals();
	int i1,i2,i3;
	if (map1.goals.size()<=0) {
		uiManager.PrintTitle("请输入始末点");
		uiManager.InputInt(&i2,"请输入起点x坐标");
		if (i2<0||i2>=map1.grid[0].size()) {
			uiManager.Print("请保证输入在范围内！");
			uiManager.SetWait();
			return;
		}
		uiManager.InputInt(&i3,"请输入起点y坐标");
		if (i3<0||i3>=map1.grid.size()) {
			uiManager.Print("请保证输入在范围内！");
			uiManager.SetWait();
			return;
		}
		map1.Addgoals(0,i2,i3);
		uiManager.InputInt(&i2,"请输入结束点x坐标");
		if (i2<0||i2>=map1.grid[0].size()) {
			uiManager.Print("请保证输入在范围内！");
			uiManager.SetWait();
			return;
		}
		uiManager.InputInt(&i3,"请输入结束点y坐标");
		if (i3<0||i3>=map1.grid.size()) {
			uiManager.Print("请保证输入在范围内！");
			uiManager.SetWait();
			return;
		}
		map1.Addgoals(1,i2,i3);
		uiManager.PrintTitle("添加成功");
	} else {
		uiManager.PrintTitle("增加目标点");

		uiManager.InputInt(&i1,"请输入增加位置（将会插在该位置前）");
		if (i1<0||i1>map1.goals.size()) {
			uiManager.PrintTitle("超出范围！");
			uiManager.SetWait();
			return;
		}
		uiManager.InputInt(&i2,"请输入目标点x坐标");
		if (i2<0||i2>=map1.grid[0].size()) {
			uiManager.Print("请保证输入在范围内！");
			uiManager.SetWait();
			return;
		}
		uiManager.InputInt(&i3,"请输入目标点y坐标");
		if (i3<0||i3>=map1.grid.size()) {
			uiManager.Print("请保证输入在范围内！");
			uiManager.SetWait();
			return;
		}
		map1.Addgoals(i1,i2,i3);
		uiManager.PrintTitle("添加成功");
	}
	uiManager.SetWait();
}
void ShowRoadMenu() {
	uiManager.Clear();
	uiManager.PrintTitle("当前路径");

	map1.PrintMap();
	uiManager.SetWait();
}

void ModifyRoadMenu() {
	uiManager.Clear();
	uiManager.PrintTitle("修改路径信息");
	int i1,i2,i3;
	uiManager.InputInt(&i1,"请输入待修改路段x坐标");
	uiManager.InputInt(&i2,"请输入待修改路段y坐标");
	uiManager.InputInt(&i3,"请输入待修改路段通过时长");
	map1.ModifyMap(i1,i2,i3);
	map1.SaveFile();
	uiManager.SetWait();
}
void InportFile() {
	uiManager.Clear();
	uiManager.PrintTitle("导入外部地图");
	char s[MAXLEN];
	uiManager.InputString(s,"请输入地图文件路径");
	map1.ImportLoadFile(s);
	uiManager.SetWait();
}
void User() {
	while (1) {
		uiManager.Clear();
		uiManager.PrintTitle("配送系统");
		char* selections[] = {"查看当前路径", "修改节点信息", "回到主菜单"};
		uiManager.ShowSelect(3, selections);
		int id = -1;
		uiManager.InputInt(&id, "选择选项：");

		if (id <= 0 || id >= 4) {
			uiManager.Print("未找到该选项，请重试");
			uiManager.Fenge();
			uiManager.SetWait();
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
		uiManager.Clear();
		uiManager.PrintTitle("地图配置");
		char* selections[] = {"查看当前地图", "修改地图信息","导入外部地图","回到主菜单"};
		uiManager.ShowSelect(4, selections);
		int id = -1;
		uiManager.InputInt(&id, "选择选项：");

		if (id <= 0 || id >= 5) {
			uiManager.Print("未找到该选项，请重试");
			uiManager.Fenge();
			uiManager.SetWait();
			continue;
		}

		if (id == 1) ShowRoadMenu();
		else if (id == 2) ModifyRoadMenu();
		else if (id == 3) InportFile();
		else if (id == 4) break;
		else printf("请输入1-3之间的数字！");
	}
}

void MainMenu() {
	while (1) {
		uiManager.Clear();
		uiManager.PrintTitle("主菜单");
		char* selections[] = {"配送系统", "地图配置", "退出程序"};
		uiManager.ShowSelect(3, selections);
		int id = -1;
		uiManager.InputInt(&id, "选择选项：");

		if (id <= 0 || id >= 4) {
			uiManager.Print("未找到该选项，请重试");
			uiManager.Fenge();
			uiManager.SetWait();
			continue;
		}

		if (id == 1) User();
		else if (id == 2) Option();
		else if (id == 3) uiManager.ExitPage();
		else printf("请输入1-3之间的数字！");
	}
}
int main() {
	//程序启动执行
	OnLoad();
	//
	uiManager.PrintTitle("欢迎使用外卖配送系统");
	uiManager.SetWait();
	MainMenu();
	return 0;
}
