#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>			// 调用 Sleep() 函数
#define MAX_STUDENT_NUM 100		//最大学生人数

//定义全局变量
int students[MAX_STUDENT_NUM][2];
int student_count = 6; //实际录入学生人数

//函数声明
int menu(); 			//调用菜单函数
void body_1();			//调用功能选择函数
void input_score();		//调用成绩录入函数
void modify_score();	//调用成绩修改函数
void delete_score();	//调用成绩删除函数
void search_score();	//调用成绩查询函数
void print_score();		//调用成绩打印函数
void save_score();		//调用成绩保存函数
void load_score();		//调用成绩载入函数
void bubble_sort();     //调用冒泡排序函数
void insertion_sort();  //调用插入排序函数
void selection_sort();  //调用选择排序函数

//main主函数入口
int main()
{
	load_score();		//加载之前保存的成绩
	body_1();			// 调用功能选择函数
	return 0;
}

// 功能选择函数
void body_1()
{
	int choose = -1; 		// 初始化选择为 -1，确保进入循环	接收scanf传入的数据

	while (choose != 0)
	{
		choose = menu();	// 调用菜单函数，并接收选择项
		switch (choose)
		{
		case 1:
			printf("正在使用：学生成绩录入\n");
			input_score(); 	//调用成绩录入函数
			save_score(); 	//成绩保存函数
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
		case 6:
			printf("正在使用：学生成绩保存\n");
			save_score();	//调用成绩保存函数
			break;
		case 7:
			printf("正在使用：学生成绩读取\n");
			load_score();	//调用成绩读取函数
			break;
		case 8:
			printf("正在使用：成绩排序（冒泡排序）\n");
			bubble_sort();
			break;
		case 9:
			printf("正在使用：成绩排序（插入排序）\n");
			break;
		case 10:
			printf("正在使用：成绩排序（选择排序）\n");
			break;
		case 0:
			printf("确定要退出吗？(1表示是, 0表示否): ");
			int confirm;
			scanf("%d", &confirm);
			if (confirm == 1)
			{
				printf("谢谢使用，再见！\n");
				exit(0);
			}
			break;
		default:
			printf("对不起，没有这个菜单项！请重新输入。\n");
			break;
		}

		Sleep(2000); 	   // 暂停 2 秒，便于查看输出
		system("cls");    // 清屏，重新显示菜单
	}
}

// 菜单函数
int menu() {
	int choose;
	printf("===== 学生成绩管理系统 =====\n");
	printf("1. 学生成绩录入\n");
	printf("2. 学生成绩修改\n");
	printf("3. 学生成绩删除\n");
	printf("4. 学生成绩查询\n");
	printf("5. 学生成绩打印\n");
	printf("6. 学生成绩保存\n");
	printf("7. 学生成绩读取\n");
	printf("8. 按成绩升序（冒泡排序）\n");
	printf("9. 按成绩升序（插入排序）\n");
	printf("10.按成绩升序（选择排序）\n");
	printf("0. 退出系统\n");
	printf("===========================\n");
	printf("请输入你的选择 (0-10):> ");
	scanf("%d", &choose);

	if (choose < 0 || choose > 10)	//输入0——6之间的数	//  || 表示逻辑或(or)只要有一方为真即为真
	{
		printf("输入无效，请重新选择！\n");
		return menu();	//无效数字，继续返回菜单选项
	}
	return choose;		//返回选择
}

//成绩录入函数
void input_score()
{
	printf("准备成绩录入......\n");
	int continue_input = 1;  // 控制是否继续录入
	while (continue_input && student_count < MAX_STUDENT_NUM)
	{
		int id, score;
		printf("请输入学号: ");
		scanf("%d", &id);
		printf("请输入成绩 (0-100): ");
		scanf("%d", &score);

		if (score < 0 || score > 100)
		{
			printf("成绩无效，请输入0到100之间的分数。\n");
			continue;
		}

		students[student_count][0] = id;
		students[student_count][1] = score;
		student_count++;
		printf("成绩录入成功！\n");

		// 显示所有已录入的学生成绩
		printf("当前所有学生成绩:\n");
		printf("学号\t-\t成绩\n");
		for (int i = 0; i < student_count; i++)
		{
			printf("%d\t-\t%d\n", students[i][0], students[i][1]);
		}
		printf("是否继续录入？ (1表示是, 0表示否): ");
		scanf("%d", &continue_input);
	}

	if (student_count >= MAX_STUDENT_NUM)
	{
		printf("学生人数已满，无法录入更多成绩。\n");
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
	for (int i = 0; i < student_count; i++)
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
	for (int i = 0; i < student_count; i++)
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

	save_score();
	load_score();

	Sleep(2000);  // 暂停 2 秒，便于查看输出
}

// 成绩查询函数
void search_score()
{
	int id;
	printf("请输入要查询的学生学号: ");
	scanf("%d", &id);

	int found = 0;	//标志变量，用来记录是否找到了对应的学号，初始化为 0（即未找到）	
	for (int i = 0; i < student_count; i++)
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
	for (int i = 0; i < student_count; i++)
	{
		printf("%d\t-\t%d\n", students[i][0], students[i][1]);	//使用 printf 输出学号和成绩，并用 \t 制表符保持列的对齐
	}

	Sleep(2000); // 暂停 2 秒，便于查看输出
}

//成绩保存函数
void save_score()
{
	FILE* fp = fopen("D:\\Dev c wenjian\\student_data\\score.txt", "w");	// *fp为指针用于指向打开的文件  fopen函数用于打开或创建一个文件		参数w表示以写入模式打开文件，if文件已存在，将清空原内容；if文件不存在，将创建新文件

	if (fp == NULL)		//如果文件打开失败（可能是因为路径不存在或无权限写入），返回 NULL
	{
		printf("文件打开失败，无法保存成绩。\n");
		return;
	}

	for (int i = 0; i < student_count; i++)
	{
		if (students[i][0] != 0)
			fprintf(fp, "学号: %d, 成绩: %d\n", students[i][0], students[i][1]);
	}

	if (fclose(fp) == 0)
	{
		printf("成绩已成功保存至文件 %s。\n", "D:\\Dev c wenjian\\student_data\\score.txt");
	}
	else {
		printf("文件保存时出现问题，请重试。\n");
	}
}

// 成绩加载函数
void load_score()
{
	FILE* fp = fopen("D:\\Dev c wenjian\\student_data\\score.txt", "r");
	if (fp == NULL) {
		printf("未找到成绩记录文件，将从头开始。\n");
		return;
	}

	int i = 0;
	while (fscanf(fp, "学号: %d, 成绩: %d\n", &students[i][0], &students[i][1]) == 2 && i < MAX_STUDENT_NUM)	//i < MAX_STUDENT_NUM 保证读取数量不超过数组的最大长度 MAX_STUDENT_NUM，防止数组越界
	{
		i++;	//每次读取成功，i 自增，表示成功加载了一条记录。
	}
	student_count = i;	//将读取的学生数量 i 赋值给全局变量 student_count，表示当前加载的学生数

	fclose(fp);
	printf("已加载 %d 条学生成绩记录。\n", student_count);
}

//冒泡排序
void bubble_sort()
{
	for (int i = 0; i < student_count - 1; i++)
	{  // 遍历学生列表
		for (int j = 0; j < student_count - i - 1; j++) 	// 从0到未排序部分的末尾
		{
			if (students[j][1] > students[j + 1][1]) 	// 如果前一个成绩大于后一个
			{
				int temp_id = students[j][0];			// 交换学号和成绩
				int temp_score = students[j][1];
				students[j][0] = students[j + 1][0];
				students[j][1] = students[j + 1][1];
				students[j + 1][0] = temp_id;
				students[j + 1][1] = temp_score;
			}
		}
	}

	printf("学号\t-\t成绩\n");	//格式为 "学号 - 成绩"，使用 \t 制表符来对齐"学号"和"成绩"这两列
	for (int i = 0; i < student_count; i++)
	{
		printf("%d\t-\t%d\n", students[i][0], students[i][1]);	//使用 printf 输出学号和成绩，并用 \t 制表符保持列的对齐
	}
	save_score();
	load_score();
}

//插入排序
void insertion_sort()
{


	save_score();
	load_score();
}
