#include<bits/stdc++.h>
using namespace std;
#include "ui.h"
#include "data.h"
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
	SetWait();
}
void User() {
	while (1) {
		Clear();
		PrintTitle("����ϵͳ");
		char* selections[] = {"�鿴��ǰ·��", "�޸�·����Ϣ", "�ص����˵�"};
		ShowSelect(3, selections);
		int id = -1;
		InputInt(&id, "ѡ��ѡ�");

		if (id <= 0 || id >= 4) {
			Print("δ�ҵ���ѡ�������");
			Fenge();
			SetWait();
			continue;
		}

		if (id == 1) ShowRoadMenu();
		else if (id == 2) ModifyRoadMenu();
		else if (id == 3) break;
		else printf("������1-3֮������֣�");
	}
}

void Option() {
	while (1) {
		Clear();
		PrintTitle("��ͼ����");
		char* selections[] = {"�鿴��ǰ��ͼ", "�޸ĵ�ͼ��Ϣ", "�ص����˵�"};
		ShowSelect(3, selections);
		int id = -1;
		InputInt(&id, "ѡ��ѡ�");

		if (id <= 0 || id >= 4) {
			Print("δ�ҵ���ѡ�������");
			Fenge();
			SetWait();
			continue;
		}

		if (id == 1) ShowRoadMenu();
		else if (id == 2) ModifyRoadMenu();
		else if (id == 3) break;
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
	PrintTitle("��ӭʹ����������ϵͳ");
	SetWait();
	MainMenu();
	return 0;
}
