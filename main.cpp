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

		if (id == 1) User();
		else if (id == 2) Option();
		else if (id == 3) break;
		else printf("������1-3֮������֣�");
	}
}

void Option() {

}

void MainMenu() {
	while (1) {
		Clear();
		PrintTitle("���˵�");
		char* selections[] = {"��������ϵͳ", "����", "�˳�����"};
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
