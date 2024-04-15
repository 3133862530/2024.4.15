#pragma once

struct administrator//管理员个人信息
{
	char ID[20];//管理员编号
	char PASSWORD[10];//密码，规定一下长度
	struct administrator* next;
};

int appendConductorNode(struct administrator** headRef);

int appendConductorNode(struct administrator** headRef)//简而言之 
{//输入链表的头指针 和要加入的结构体即可 即可创建n个链表
	printf("输入注册管理员数量：");
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		struct administrator* newadministrator = (struct administrator*)malloc(sizeof(struct administrator));
		newadministrator->next = NULL;
		if (*headRef == NULL)//检查传递进来的链表头指针是否为零 若是 
		{
			*headRef = newadministrator;//则建立第一个节点
			continue;//终止
		}
		struct administrator* current = *headRef;
		while (current->next != NULL)//一路畅通拉下去到头
		{
			current = current->next;
		}
		current->next = newadministrator;//拉到头了 加到尾巴上
	}

	return n;
}
void ConductWriteListToNode(struct administrator** head, int number);
void ConductWriteListToNode(struct administrator** head, int number)
{
	struct administrator* current = *head;

	printf("\n");
	printf("示例：\n");
	Sleep(TIME_DELAY);
	printf("ID: 174044503\n");
	Sleep(TIME_DELAY);
	printf("PASSWORD: a121241250\n");


	printf("\n");


	for (int i = 0; i < number; i++)
	{
		scanf("%s", current->ID);

		scanf("%s", current->PASSWORD);

		current = current->next;
	}

}

void ConductorWriteListToFile(struct administrator** head, const char* filename);
void ConductorWriteListToFile(struct administrator** head, const char* filename)
{
	//输入一个链表 把链表数据都写到文件中
	FILE* file = fopen(filename, "wb");
	struct administrator* temp = *head;
	while (temp != NULL)//没写完就一直写
	{
		fwrite(temp, sizeof(struct administrator), 1, file);
		temp = temp->next;
	}
	fclose(file);
}

void freeConductorList(struct administrator* head);
void freeConductorList(struct administrator* head)
{
	struct administrator* current = head;
	while (current != NULL)
	{
		struct administrator* temp = current;
		current = current->next;
		free(temp->ID);
		free(temp->PASSWORD);
		free(temp);
	}
}

void ConductorReadListFromFile(struct administrator** head, const char* filename);
void ConductorReadListFromFile(struct administrator** head, const char* filename)
{//输入一个头指针 然后把文件数据都读到链表中
	FILE* file = fopen(filename, "rb");
	if (file == NULL)
	{
		printf("Error opening file.\n");
		return;
	}
	struct administrator temp;
	while (fread(&temp, sizeof(struct administrator), 1, file) != 0)
	{
		struct administrator* newadministrator = (struct administrator*)malloc(sizeof(struct administrator));
		if (newadministrator == NULL)
		{
			printf("Memory allocation failed.\n");
			//fclose(file);
			return;
		}

		*newadministrator = temp;
		newadministrator->next = NULL;
		if (*head == NULL)
		{
			*head = newadministrator;
		}
		else
		{
			struct administrator* current = *head;
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = newadministrator;
		}

	}
	fclose(file);
}

void input_administrator(void);
void input_administrator(void)//管理员注册
{
	struct administrator** Conductor = NULL;
	int number = appendConductorNode(&Conductor);
	ConductWriteListToNode(&Conductor, number);
	ConductorWriteListToFile(&Conductor, "管理员数据.txt");
	//freePassengerList(Conductor);
}

struct administrator* searchAd(struct administrator** head, const char* id, const char* password);
struct administrator* searchAd(struct administrator** head, const char* id, const char* password)//输入管理员信息登录
{
	struct administrator* current = *head;
	while (current != NULL)
	{
		if (strcmp(current->ID, id) == 0 && strcmp(current->PASSWORD, password) == 0)
			return current;
		current = current->next;
	}
	return NULL;
}

void conductor(void);

void conductor(void)
{
	char ID[20];
	char PASSWORD[10];
	printf("输入管理员账号：\n");
	scanf("%s", ID);
	printf("输入管理员密码：\n");
	scanf("%s", PASSWORD);
	struct administrator** Conductor = NULL;
	ConductorReadListFromFile(&Conductor, "管理员数据.txt");
	struct administrator* result = searchAd(&Conductor, ID, PASSWORD);


	if (result == NULL)
	{
		printf("账号或密码错误！\n");
		return;
	}
	printf("                 @@@@@***************************管理员系统界面*********************************@@@@@\n");
	printf("                 ###                              1 录 入 航 班 信 息                             ###\n");//加个登机口
	printf("                 @@@                              2 显 示 全 部 航 班 信 息                       @@@\n");
	printf("                 ###                              3 退 出                                         ###\n");
	printf("                 #####!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!#####\n");
	int i;
	printf("请选择: ");
	scanf("%d", &i);
	switch (i) {

	case 1:input_flight(); break;
	case 2:check_flight(); break;
	case 3:break;
	default:break;

	}
}
