#include<bits/stdc++.h>
using namespace std;
#include "ui.h"
#include "data.h"
void PathMenu() {
	Clear();
	if (map1.goals.size()<=0) {
		PrintTitle("����·����");
	} else {
		PrintTitle("·����");
		map1.Printgoals();
		PrintTitle("·��");
		map1.FindALL();
	}

	SetWait();
}
void ModifygoalsMenu() {
	Clear();
	map1.Printgoals();
	int i1,i2,i3;
	if (map1.goals.size()<=0) {
		PrintTitle("������ʼĩ��");
		InputInt(&i2,"���������x����");
		InputInt(&i3,"���������y����");
		map1.Addgoals(0,i2,i3);
		InputInt(&i2,"�����������x����");
		InputInt(&i3,"�����������y����");
		map1.Addgoals(1,i2,i3);
		PrintTitle("��ӳɹ�");
	} else {
		PrintTitle("����Ŀ���");

		InputInt(&i1,"����������λ��");
		if (i1<0||i1>=map1.goals.size()) {
			PrintTitle("������Χ��");
			SetWait();
			return;
		}
		InputInt(&i2,"������Ŀ���x����");
		InputInt(&i3,"������Ŀ���y����");
		map1.Addgoals(i1,i2,i3);
		PrintTitle("��ӳɹ�");
	}
	SetWait();
}
void ShowRoadMenu() {
	Clear();
	PrintTitle("��ǰ·��");

	map1.PrintMap();
	SetWait();
}

void ModifyRoadMenu() {
	Clear();
	PrintTitle("�޸�·����Ϣ");
	int i1,i2,i3;
	InputInt(&i1,"��������޸�·��x����");
	InputInt(&i2,"��������޸�·��y����");
	InputInt(&i3,"��������޸�·��ͨ��ʱ��");
	map1.ModifyMap(i1,i2,i3);
	map1.SaveFile();
	SetWait();
}
void User() {
	while (1) {
		Clear();
		PrintTitle("����ϵͳ");
		char* selections[] = {"�鿴��ǰ·��", "�޸Ľڵ���Ϣ", "�ص����˵�"};
		ShowSelect(3, selections);
		int id = -1;
		InputInt(&id, "ѡ��ѡ�");

		if (id <= 0 || id >= 4) {
			Print("δ�ҵ���ѡ�������");
			Fenge();
			SetWait();
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
		Clear();
		PrintTitle("��ͼ����");
		char* selections[] = {"�鿴��ǰ��ͼ", "�޸ĵ�ͼ��Ϣ","�����ⲿ��ͼ","�ص����˵�"};
		ShowSelect(4, selections);
		int id = -1;
		InputInt(&id, "ѡ��ѡ�");

		if (id <= 0 || id >= 5) {
			Print("δ�ҵ���ѡ�������");
			Fenge();
			SetWait();
			continue;
		}

		if (id == 1) ShowRoadMenu();
		else if (id == 2) ModifyRoadMenu();
		else if (id == 3) tbd();
		else if (id == 4) break;
		else printf("������1-3֮������֣�");
	}
}

void MainMenu() {
	while (1) {
		Clear();
		PrintTitle("���˵�");
		char* selections[] = {"����ϵͳ", "��ͼ����", "�˳�����"};
		ShowSelect(3, selections);
		int id = -1;
		InputInt(&id, "ѡ��ѡ�");

		if (id <= 0 || id >= 4) {
			Print("δ�ҵ���ѡ�������");
			Fenge();
			SetWait();
			continue;
		}

		if (id == 1) User();
		else if (id == 2) Option();
		else if (id == 3) ExitPage();
		else printf("������1-3֮������֣�");
	}
}
int main() {
	//��������ִ��
	OnLoad();
	//
	PrintTitle("��ӭʹ����������ϵͳ");
	SetWait();
	MainMenu();
	return 0;
}
