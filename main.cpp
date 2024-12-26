#include<bits/stdc++.h>
using namespace std;
#include "ui.h"
#include "data.h"
void PathMenu() {

	uiManager.Clear();
	map1.PrintMap();
	if (map1.goals.size()<=0) {
		uiManager.PrintTitle("����·����");
	} else {
		uiManager.PrintTitle("·����");
		map1.Printgoals();
		uiManager.PrintTitle("·��");
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
		uiManager.PrintTitle("������ʼĩ��");
		uiManager.InputInt(&i2,"���������x����");
		if (i2<0||i2>=map1.grid[0].size()) {
			uiManager.Print("�뱣֤�����ڷ�Χ�ڣ�");
			uiManager.SetWait();
			return;
		}
		uiManager.InputInt(&i3,"���������y����");
		if (i3<0||i3>=map1.grid.size()) {
			uiManager.Print("�뱣֤�����ڷ�Χ�ڣ�");
			uiManager.SetWait();
			return;
		}
		map1.Addgoals(0,i2,i3);
		uiManager.InputInt(&i2,"�����������x����");
		if (i2<0||i2>=map1.grid[0].size()) {
			uiManager.Print("�뱣֤�����ڷ�Χ�ڣ�");
			uiManager.SetWait();
			return;
		}
		uiManager.InputInt(&i3,"�����������y����");
		if (i3<0||i3>=map1.grid.size()) {
			uiManager.Print("�뱣֤�����ڷ�Χ�ڣ�");
			uiManager.SetWait();
			return;
		}
		map1.Addgoals(1,i2,i3);
		uiManager.PrintTitle("��ӳɹ�");
	} else {
		uiManager.PrintTitle("����Ŀ���");

		uiManager.InputInt(&i1,"����������λ�ã�������ڸ�λ��ǰ��");
		if (i1<0||i1>map1.goals.size()) {
			uiManager.PrintTitle("������Χ��");
			uiManager.SetWait();
			return;
		}
		uiManager.InputInt(&i2,"������Ŀ���x����");
		if (i2<0||i2>=map1.grid[0].size()) {
			uiManager.Print("�뱣֤�����ڷ�Χ�ڣ�");
			uiManager.SetWait();
			return;
		}
		uiManager.InputInt(&i3,"������Ŀ���y����");
		if (i3<0||i3>=map1.grid.size()) {
			uiManager.Print("�뱣֤�����ڷ�Χ�ڣ�");
			uiManager.SetWait();
			return;
		}
		map1.Addgoals(i1,i2,i3);
		uiManager.PrintTitle("��ӳɹ�");
	}
	uiManager.SetWait();
}
void ShowRoadMenu() {
	uiManager.Clear();
	uiManager.PrintTitle("��ǰ·��");

	map1.PrintMap();
	uiManager.SetWait();
}

void ModifyRoadMenu() {
	uiManager.Clear();
	uiManager.PrintTitle("�޸�·����Ϣ");
	int i1,i2,i3;
	uiManager.InputInt(&i1,"��������޸�·��x����");
	uiManager.InputInt(&i2,"��������޸�·��y����");
	uiManager.InputInt(&i3,"��������޸�·��ͨ��ʱ��");
	map1.ModifyMap(i1,i2,i3);
	map1.SaveFile();
	uiManager.SetWait();
}
void InportFile() {
	uiManager.Clear();
	uiManager.PrintTitle("�����ⲿ��ͼ");
	char s[MAXLEN];
	uiManager.InputString(s,"�������ͼ�ļ�·��");
	map1.ImportLoadFile(s);
	uiManager.SetWait();
}
void User() {
	while (1) {
		uiManager.Clear();
		uiManager.PrintTitle("����ϵͳ");
		char* selections[] = {"�鿴��ǰ·��", "�޸Ľڵ���Ϣ", "�ص����˵�"};
		uiManager.ShowSelect(3, selections);
		int id = -1;
		uiManager.InputInt(&id, "ѡ��ѡ�");

		if (id <= 0 || id >= 4) {
			uiManager.Print("δ�ҵ���ѡ�������");
			uiManager.Fenge();
			uiManager.SetWait();
			continue;
		}

		if (id == 1) PathMenu();
		else if (id == 2) ModifygoalsMenu();
		else if (id == 3) break;
		else printf("������1-3֮������֣�");
	}
}

void Option() {
	while (1) {
		uiManager.Clear();
		uiManager.PrintTitle("��ͼ����");
		char* selections[] = {"�鿴��ǰ��ͼ", "�޸ĵ�ͼ��Ϣ","�����ⲿ��ͼ","�ص����˵�"};
		uiManager.ShowSelect(4, selections);
		int id = -1;
		uiManager.InputInt(&id, "ѡ��ѡ�");

		if (id <= 0 || id >= 5) {
			uiManager.Print("δ�ҵ���ѡ�������");
			uiManager.Fenge();
			uiManager.SetWait();
			continue;
		}

		if (id == 1) ShowRoadMenu();
		else if (id == 2) ModifyRoadMenu();
		else if (id == 3) InportFile();
		else if (id == 4) break;
		else printf("������1-3֮������֣�");
	}
}

void MainMenu() {
	while (1) {
		uiManager.Clear();
		uiManager.PrintTitle("���˵�");
		char* selections[] = {"����ϵͳ", "��ͼ����", "�˳�����"};
		uiManager.ShowSelect(3, selections);
		int id = -1;
		uiManager.InputInt(&id, "ѡ��ѡ�");

		if (id <= 0 || id >= 4) {
			uiManager.Print("δ�ҵ���ѡ�������");
			uiManager.Fenge();
			uiManager.SetWait();
			continue;
		}

		if (id == 1) User();
		else if (id == 2) Option();
		else if (id == 3) uiManager.ExitPage();
		else printf("������1-3֮������֣�");
	}
}
int main() {
	//��������ִ��
	OnLoad();
	//
	uiManager.PrintTitle("��ӭʹ����������ϵͳ");
	uiManager.SetWait();
	MainMenu();
	return 0;
}
