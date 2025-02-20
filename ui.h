#ifndef UI_H
#define UI_H

#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

class UIManager {
	public :

		void Clear() {
			system("cls");
		}
		void Fenge() {
			printf("---------------------------\n");
		}
		void PrintTitle(char *text) {
			printf("---------------------------\n");
			printf("      %s\n", text);
			printf("---------------------------\n");
		}
		void SetWait() {
			printf("> 按下任意键继续......\n");
			getch();
		}
		void tbd() {
			PrintTitle("功能敬请期待！");
			SetWait();
		}

		void InputString(char* result, char *text) {
			printf("> %s", text);
			scanf("%s", result);
		}
		void InputInt(int* result, char *text) {
			printf("> %s", text);
			scanf("%d", result);
		}
		void InputDouble(double *result, char *text) {
			printf("> %s", text);
			scanf("%lf", result);
		}
		void ShowSelect(int count, char* text[]) {
			for (int i = 0; i < count; i++) {
				printf("%d.%s\n", i + 1, text[i]);
			}
			Fenge();
		}
		void Print(char *text) {
			printf("> %s\n", text);
		}
		void printTutorial(){
			
			printf("方向键：选择菜单\n回车或空格：进入子菜单\n");
			Fenge();
		}
		void ExitPage() {

			exit(0);
		}

};
static UIManager uiManager;
#endif
