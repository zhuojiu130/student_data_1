#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>			// ���� Sleep() ����
#define MAX_STUDENT_NUM 100		//���ѧ������

//����ȫ�ֱ���
int students[MAX_STUDENT_NUM][2] = { {11,77}, {12,88}, {13,99} };
int student_count = 3; //ʵ��¼��ѧ������

//��������
int menu(); 			//���ò˵�����
void body_1();			//���ù���ѡ����
void input_score();		//���óɼ�¼�뺯��
void modify_score();	//���óɼ��޸ĺ���
void delete_score();	//���óɼ�ɾ������
void search_score();	//���óɼ���ѯ����
void print_score();		//���óɼ���ӡ����
void save_score();		//���óɼ����溯��
void load_score();		//���óɼ����뺯��

//main���������
int main()
{
	load_score();		//����֮ǰ����ĳɼ�
	body_1();			// ���ù���ѡ����
	return 0;
}

// ����ѡ����
void body_1()
{
	int choose = -1; 		// ��ʼ��ѡ��Ϊ -1��ȷ������ѭ��	����scanf���������

	while (choose != 0)
	{
		choose = menu();	// ���ò˵�������������ѡ����
		switch (choose)
		{
		case 1:
			printf("����ʹ�ã�ѧ���ɼ�¼��\n");
			input_score(); 	//���óɼ�¼�뺯��
			save_score(); 	//�ɼ����溯��
			break;
		case 2:
			printf("����ʹ�ã�ѧ���ɼ��޸�\n");
			modify_score();	//���óɼ��޸ĺ���
			break;
		case 3:
			printf("����ʹ�ã�ѧ���ɼ�ɾ��\n");
			delete_score();	//���óɼ�ɾ������
			break;
		case 4:
			printf("����ʹ�ã�ѧ���ɼ���ѯ\n");
			search_score();	//���ò�ѯ�ɼ�����
			break;
		case 5:
			printf("����ʹ�ã�ѧ���ɼ���ӡ\n");
			print_score();	//���ô�ӡ����
			break;
		case 6:
			printf("����ʹ�ã�ѧ���ɼ�����\n");
			save_score();	//���óɼ����溯��
			break;
		case 0:
			printf("ллʹ�ã��ټ���\n");
			break;
		default:
			printf("�Բ���û������˵�����������롣\n");
			break;
		}

		Sleep(2000); 	   // ��ͣ 2 �룬���ڲ鿴���
		system("cls");    // ������������ʾ�˵�
	}
}

// �˵�����
int menu() {
	int choose;
	printf("===== ѧ���ɼ�����ϵͳ =====\n");
	printf("1. ѧ���ɼ�¼��\n");
	printf("2. ѧ���ɼ��޸�\n");
	printf("3. ѧ���ɼ�ɾ��\n");
	printf("4. ѧ���ɼ���ѯ\n");
	printf("5. ѧ���ɼ���ӡ\n");
	printf("6. ѧ���ɼ�����\n");
	printf("0. �˳�ϵͳ\n");
	printf("===========================\n");
	printf("���������ѡ�� (0-5):> ");
	scanf("%d", &choose);

	if (choose < 0 || choose > 6)	//����0����6֮�����	//  || ��ʾ�߼���(or)ֻҪ��һ��Ϊ�漴Ϊ��
	{
		printf("������Ч��������ѡ��\n");
		return menu();	//��Ч���֣��������ز˵�ѡ��
	}
	return choose;
}

//�ɼ�¼�뺯��
void input_score()
{
	printf("׼���ɼ�¼��......\n");

	for (int i = 0; i < student_count; i++)		// ������¼���ѧ������
	{
		do	//��ִ��ѭ���壬�ټ�������Ƿ�����
		{
			printf("�������%d���˵�ѧ��: ", i + 1);	//ѭ����
			scanf("%d", &students[i][0]);

		} while (students[i][0] <= 0);  // ѧ��ӦΪ����		//whileΪ����

		do
		{
			printf("�������%d���˵ĳɼ� (0-100): ", i + 1);
			scanf("%d", &students[i][1]);

		} while (students[i][1] < 0 || students[i][1] > 100);  // �ɼ��� 0-100 ��Χ��	���벻��ȷ����ֵ�����½���ѭ��
	}

	//��ӡ�ɼ�
	for (int i = 0; i < student_count; i++)
	{
		printf("��%d��ѧ����ѧ��-�ɼ�:%d-%d\n", i + 1, students[i][0], students[i][1]);
	}

	Sleep(2000);  // ��ͣ 2 �룬���ڲ鿴���

}


// �ɼ��޸ĺ���
void modify_score()
{
	int id;		//���ڽ��������ѧ��ѧ��
	printf("������Ҫ�޸ĳɼ���ѧ��ѧ��: ");
	scanf("%d", &id);	//scanf����Ҫ��ѯ��ѧ��

	int found = 0;	//found��־������������¼�Ƿ��ҵ��˶�Ӧ��ѧ�ţ���ʼ��Ϊ 0����δ�ҵ���
	for (int i = 0; i < student_count; i++)
	{
		if (students[i][0] == id)
		{
			printf("�������µĳɼ�: ");
			scanf("%d", &students[i][1]);
			printf("�ɼ����޸ģ�\n");
			found = 1;	//foundΪ1��Ϊ�ҵ�
			break;	//break ��ֹѭ�������ⲻ��Ҫ�ļ�������
		}
	}

	if (!found)		//����������� found ��ȻΪ 0����ʾ��ѧ�Ų����ڻ�δ�ҵ�
	{
		printf("δ�ҵ���ѧ�ŵ�ѧ����\n");
	}

	Sleep(2000);  // ��ͣ 2 �룬���ڲ鿴���
}

// �ɼ�ɾ������
void delete_score()
{
	int id;
	printf("������Ҫɾ���ɼ���ѧ��ѧ��: ");
	scanf("%d", &id);

	int found = 0;	//found��־������������¼�Ƿ��ҵ��˶�Ӧ��ѧ�ţ���ʼ��Ϊ 0����δ�ҵ���	
	for (int i = 0; i < student_count; i++)
	{
		if (students[i][0] == id)
		{
			students[i][0] = 0;  // ��ѧ�źͳɼ�����Ϊ 0����ʾɾ��
			students[i][1] = 0;
			printf("�ɼ���ɾ����\n");
			found = 1;	//foundΪ1��Ϊ�ҵ�
			break;
		}
	}

	if (!found)		//����������� found ��ȻΪ 0����ʾ��ѧ�Ų����ڻ�δ�ҵ�
	{
		printf("δ�ҵ���ѧ�ŵ�ѧ����\n");
	}

	Sleep(2000);  // ��ͣ 2 �룬���ڲ鿴���
}

// �ɼ���ѯ����
void search_score()
{
	int id;
	printf("������Ҫ��ѯ��ѧ��ѧ��: ");
	scanf("%d", &id);

	int found = 0;	//��־������������¼�Ƿ��ҵ��˶�Ӧ��ѧ�ţ���ʼ��Ϊ 0����δ�ҵ���	
	for (int i = 0; i < student_count; i++)
	{
		if (students[i][0] == id)	//����ҵ�students���id(ѧ����)�ͽ�found����Ϊ1 
		{
			printf("ѧ��: %d, �ɼ�: %d\n", students[i][0], students[i][1]);
			found = 1;	//foundΪ1��Ϊ�ҵ�
			break;
		}
	}


	//����ѭ����foundֵ����û�иı��ʼֵ(0)������ʾû���ҵ�ѧ��
	if (!found)		//����������� found ��ȻΪ 0����ʾ��ѧ�Ų����ڻ�δ�ҵ�	//��ȡ��  ��1 = 0�� ��0 = 1��	//0ȡ����Ϊ1��Ϊtrue ִ��if���
	{
		printf("δ�ҵ���ѧ�ŵ�ѧ����\n");
	}

	Sleep(2000);  // ��ͣ 2 �룬���ڲ鿴���
}

//�ɼ���ӡ����
void print_score()
{
	printf("׼���ɼ���ӡ......\n");
	printf("ѧ��\t-\t�ɼ�\n");	//��ʽΪ "ѧ�� - �ɼ�"��ʹ�� \t �Ʊ��������"ѧ��"��"�ɼ�"������
	for (int i = 0; i < student_count; i++)
	{
		printf("%d\t-\t%d\n", students[i][0], students[i][1]);	//ʹ�� printf ���ѧ�źͳɼ������� \t �Ʊ�������еĶ���
	}

	Sleep(2000); // ��ͣ 2 �룬���ڲ鿴���
}

//�ɼ����溯��
void save_score()
{
	FILE* fp = fopen("D:\\Dev c wenjian\\student_data\\score.txt", "w");	// *fpΪָ������ָ��򿪵��ļ�  fopen�������ڴ򿪻򴴽�һ���ļ�		����w��ʾ��д��ģʽ���ļ���if�ļ��Ѵ��ڣ������ԭ���ݣ�if�ļ������ڣ����������ļ�

	if (fp == NULL)		//����ļ���ʧ�ܣ���������Ϊ·�������ڻ���Ȩ��д�룩������ NULL
	{
		printf("�ļ���ʧ�ܣ��޷�����ɼ���\n");
		return;
	}

	for (int i = 0; i < student_count; i++)
	{
		if (students[i][0] != 0)
			fprintf(fp, "ѧ��: %d, �ɼ�: %d\n", students[i][0], students[i][1]);
	}

	if (fclose(fp) == 0)
	{
		printf("�ɼ��ѳɹ��������ļ� %s��\n", "D:\\Dev c wenjian\\student_data\\score.txt");
	}
	else {
		printf("�ļ�����ʱ�������⣬�����ԡ�\n");
	}
}

// �ɼ����غ���
void load_score()
{
	FILE* fp = fopen("D:\\Dev c wenjian\\student_data\\score.txt", "r");
	if (fp == NULL) {
		printf("δ�ҵ��ɼ���¼�ļ�������ͷ��ʼ��\n");
		return;
	}

	int i = 0;
	while (fscanf(fp, "ѧ��: %d, �ɼ�: %d\n", &students[i][0], &students[i][1]) == 2 && i < MAX_STUDENT_NUM)	//i < MAX_STUDENT_NUM ��֤��ȡ�����������������󳤶� MAX_STUDENT_NUM����ֹ����Խ��
	{
		i++;	//ÿ�ζ�ȡ�ɹ���i ��������ʾ�ɹ�������һ����¼��
	}
	student_count = i;	//����ȡ��ѧ������ i ��ֵ��ȫ�ֱ��� student_count����ʾ��ǰ���ص�ѧ����

	fclose(fp);
	printf("�Ѽ��� %d ��ѧ���ɼ���¼��\n", student_count);
}