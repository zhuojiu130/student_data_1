#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>	// 调用 Sleep() 函数

//定义全局变量
//int students[3][2];	//接收三个人的学号和成绩

//测试数据
int students[3][2] = { {101,77}, {102,88}, {103,99} };

//函数声明
void input_score();		//调用成绩录入函数
void modify_score();	//调用成绩修改函数
void delete_score();	//调用成绩删除函数
void search_score();	//调用成绩查询函数
void print_score();		//调用成绩打印函数
void menu(); 			//调用菜单函数
void body_1();			//调用功能选择函数
void save_score();		//调用成绩保存函数

//main主函数入口
int main()
{
	body_1(); // 调用功能选择函数
	return 0;
}

// 功能选择函数
void body_1()
{
	int choose = -1; // 初始化选择为 -1，确保进入循环	接收scanf传入的数据

	while (choose != 0)
	{
		menu(); // 调用菜单函数
		printf("请输入你的选择 (0-5):> ");
		scanf("%d", &choose);	//输入选择数据

		switch (choose)
		{
		case 1:
			printf("正在使用：学生成绩录入\n");
			input_score();//调用成绩录入函数
			save_score();//成绩保存函数
			break;
		case 2:
			printf("正在使用：学生成绩修改\n");
			modify_score();	//调用成绩修改函数
			break;
		case 3:
			printf("正在使用：学生成绩删除\n");
			delete_score();	//调用成绩删除函数
			break;
		case 4:
			printf("正在使用：学生成绩查询\n");
			search_score();	//调用查询成绩函数
			break;
		case 5:
			printf("正在使用：学生成绩打印\n");
			print_score();	//调用打印函数
			break;
		case 0:
			printf("谢谢使用，再见！\n");
			break;
		default:
			printf("对不起，没有这个菜单项！请重新输入。\n");
			break;
		}

		Sleep(2000); // 暂停 2 秒，便于查看输出
		system("cls"); // 清屏，重新显示菜单
	}
}

// 显示菜单函数
void menu()
{
	printf("===== 学生成绩管理系统 =====\n");
	printf("1. 学生成绩录入\n");
	printf("2. 学生成绩修改\n");
	printf("3. 学生成绩删除\n");
	printf("4. 学生成绩查询\n");
	printf("5. 学生成绩打印\n");
	printf("0. 退出系统\n");
	printf("===========================\n");
}

//成绩录入函数
void input_score()
{
	printf("准备成绩录入......\n");
	for (int i = 0; i < 3; i++)
	{
		printf("请输入第%d个人的学号\n", i + 1);
		scanf("%d", &students[i][0]);

		printf("请输入第%d个人的成绩\n", i + 1);
		scanf("%d", &students[i][1]);
	}

	//打印成绩
	for (int i = 0; i < 3; i++)
	{
		printf("第%d个学生的学号-成绩:%d-%d\n", i + 1, students[i][0], students[i][1]);
	}

	Sleep(2000);  // 暂停 2 秒，便于查看输出

}

// 成绩修改函数
void modify_score()
{
	int id;		//用于接收输入的学生学号
	printf("请输入要修改成绩的学生学号: ");
	scanf("%d", &id);	//scanf输入要查询的学号

	int found = 0;	//found标志变量，用来记录是否找到了对应的学号，初始化为 0（即未找到）
	for (int i = 0; i < 3; i++)
	{
		if (students[i][0] == id)
		{
			printf("请输入新的成绩: ");
			scanf("%d", &students[i][1]);
			printf("成绩已修改！\n");
			found = 1;	//found为1即为找到
			break;	//break 终止循环，避免不必要的继续遍历
		}
	}

	if (!found)		//遍历完数组后 found 仍然为 0，提示该学号不存在或未找到
	{
		printf("未找到该学号的学生。\n");
	}

	Sleep(2000);  // 暂停 2 秒，便于查看输出
}

// 成绩删除函数
void delete_score()
{
	int id;
	printf("请输入要删除成绩的学生学号: ");
	scanf("%d", &id);

	int found = 0;	//found标志变量，用来记录是否找到了对应的学号，初始化为 0（即未找到）	
	for (int i = 0; i < 3; i++)
	{
		if (students[i][0] == id)
		{
			students[i][0] = 0;  // 将学号和成绩重置为 0，表示删除
			students[i][1] = 0;
			printf("成绩已删除！\n");
			found = 1;	//found为1即为找到
			break;
		}
	}

	if (!found)		//遍历完数组后 found 仍然为 0，提示该学号不存在或未找到
	{
		printf("未找到该学号的学生。\n");
	}

	Sleep(2000);  // 暂停 2 秒，便于查看输出
}

// 成绩查询函数
void search_score()
{
	int id;
	printf("请输入要查询的学生学号: ");
	scanf("%d", &id);

	int found = 0;	//标志变量，用来记录是否找到了对应的学号，初始化为 0（即未找到）	
	for (int i = 0; i < 3; i++)
	{
		if (students[i][0] == id)	//如果找到students里的id(学生号)就将found设置为1 
		{
			printf("学号: %d, 成绩: %d\n", students[i][0], students[i][1]);
			found = 1;	//found为1即为找到
			break;
		}
	}


	//跳出循环后，found值依旧没有改变初始值(0)，则提示没有找到学生
	if (!found)		//遍历完数组后 found 仍然为 0，提示该学号不存在或未找到	//！取反  ！1 = 0； ！0 = 1；	//0取反则为1；为true 执行if语句
	{
		printf("未找到该学号的学生。\n");
	}

	Sleep(2000);  // 暂停 2 秒，便于查看输出
}

//成绩打印函数
void print_score()
{
	printf("准备成绩打印......\n");
	printf("学号\t-\t成绩\n");	//格式为 "学号 - 成绩"，使用 \t 制表符来对齐"学号"和"成绩"这两列
	for (int i = 0; i < 3; i++)
	{
		printf("%d\t-\t%d\n", students[i][0], students[i][1]);	//使用 printf 输出学号和成绩，并用 \t 制表符保持列的对齐
	}

	Sleep(2000); // 暂停 2 秒，便于查看输出
}

//成绩保存函数
void save_score()
{
	FILE* fp = fopen("D:\\c xiangmu\\sudentent_data_1\\sudentent_data_score\\score.text", "w");

	if (fp == NULL)
	{
		printf("文件打开失败，无法保存成绩。\n");
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		if (students[i][0] != 0) // 只保存有效数据
			fprintf(fp, "学号: %d, 成绩: %d\n", students[i][0], students[i][1]);
	}

	fclose(fp);
	printf("成绩已保存至文件。\n");

}
