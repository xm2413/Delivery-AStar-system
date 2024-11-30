#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<time.h>

#include "ui.h"
#include "data.h"

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

		if (id == 1) User();
		else if (id == 2) Option();
		else if (id == 3) break;
		else printf("请输入1-3之间的数字！");
	}
}

void Option() {

}

void MainMenu() {
	while (1) {
		Clear();
		PrintTitle("主菜单");
		char* selections[] = {"进入配送系统", "设置", "退出程序"};
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
