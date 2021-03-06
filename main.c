#include <stdio.h> //printf()函数头文件
// stdio "standard buffered input & output
// 带缓冲区的标准输入输出，用到标准输入输出函数时，就要包含这个头文件！
#include <Windows.h>
#include <conio.h>
#include "menu.h"

/****************************************************
[函数名称] main
[函数功能] 程序主函数，即入口函数
[函数参数] 无
[返 回 值] int: 说明程序的退出状态
****************************************************/
int main(void)
{
	// 玩家选项
	int nSelect;
	
	// 加载玩家排名
	InitRanks();
	
	do
	{
		//输出欢迎界面
		intiApplication();
		
		// 通过方向键选择功能
		nSelect = printMainMenu();

		switch (nSelect)
		{
			
		case 0:// 退出
			continue;

		case 1:// 多人模式
			//参数为选择游戏模式：加载还是新建
			PlayGame(nSelect);			
			break;

		case 2:// 单人模式
			gotoxy(33, 25);
			printf("人机对战\n");
			gotoxy(24, 27);
			system("pause");
			break;

		case 3:// 加载棋局 
			PlayGame(nSelect);
			break;

		case 4:// 排行榜
			PrintRanklist();
			break;

		case 5:// 查看规则
			PrintGameRule();
			break;

		case 6:// 关于我们
			PrintAboutUs();
			break;

		default:
			printf("出bug啦！");
		}

	} while (nSelect != 0);

	// 退出程序，并保存排名，输出退出界面
	exitApplication();
	
	// 如果返回0，则代表程序正常退出；
	return 0;
}

