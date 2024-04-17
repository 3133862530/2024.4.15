#pragma once

struct administrator//����Ա������Ϣ
{
	char ID[20];//����Ա���
	char PASSWORD[10];//���룬�涨һ�³���
	struct administrator* next;
};

int appendConductorNode(struct administrator** headRef);

int appendConductorNode(struct administrator** headRef)//�����֮ 
{//���������ͷָ�� ��Ҫ����Ľṹ�弴�� ���ɴ���n������
	printf("����ע�����Ա������");
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		struct administrator* newadministrator = (struct administrator*)malloc(sizeof(struct administrator));
		newadministrator->next = NULL;
		if (*headRef == NULL)//��鴫�ݽ���������ͷָ���Ƿ�Ϊ�� ���� 
		{
			*headRef = newadministrator;//������һ���ڵ�
			continue;//��ֹ
		}
		struct administrator* current = *headRef;
		while (current->next != NULL)//һ·��ͨ����ȥ��ͷ
		{
			current = current->next;
		}
		current->next = newadministrator;//����ͷ�� �ӵ�β����
	}

	return n;
}
void ConductWriteListToNode(struct administrator** head, int number);
void ConductWriteListToNode(struct administrator** head, int number)
{
	struct administrator* current = *head;

	printf("\n");
	printf("ʾ����\n");
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
	//����һ������ ���������ݶ�д���ļ���
	FILE* file = fopen(filename, "w");//��д
	//FILE* file = fopen(filename, "w");//׷��
	struct administrator* temp = *head;
	while (temp != NULL)//ûд���һֱд
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
{//����һ��ͷָ�� Ȼ����ļ����ݶ�����������
	FILE* file = fopen(filename, "r");
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
void input_administrator(void)//����Աע��
{
	struct administrator** Conductor = NULL;
	int number = appendConductorNode(&Conductor);
	ConductWriteListToNode(&Conductor, number);
	ConductorWriteListToFile(&Conductor, "����Ա����.txt");
	//freePassengerList(Conductor);
}

struct administrator* searchAd(struct administrator** head, const char* id, const char* password);
struct administrator* searchAd(struct administrator** head, const char* id, const char* password)//�������Ա��Ϣ��¼
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

void Modify(void);

void Modify(void)
{
	system("cls");
	printf("�����޸ĵĺ���ţ�\n");
	char number[10];
	scanf("%s", number);
	struct Flight** RNEU = NULL;
	FlightReadListFromFile(&RNEU, "��������.txt");
	struct Flight* result = search(&RNEU, number);
	if (result == NULL)
	{
		printf("δ�ҵ�ƥ��ĺ��ࡣ\n");
		return;
	}

	while (1)
	{

		printf("                 @@@@@***************************�޸ĺ�����Ϣ***********************************@@@@@\n");//���� ����Ա����˿���//�㶨
		printf("                 ###                              1 �� �� ��                                     ###\n");
		printf("                 @@@                              2 Ŀ �� ��                                     @@@\n");
		printf("                 ###                              3 �� �� ʱ ��                                  ###\n");
		printf("                 @@@                              4 �� �� ʱ ��                                  @@@\n");
		printf("                 ###                              5 �� ��                                        ###\n");
		printf("                 @@@                              6 �� �� �� ��                                  @@@\n");
		printf("                 #####!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!#####\n");
		int i;
		scanf("%d", &i);
		switch (i)
		{

		case 1:printf("ʾ����\nDeparture: ����\n"); scanf("%s", result->departure); break;
		case 2:printf("ʾ����\nDestination: ����\n"); scanf("%s", result->destination); break;
		case 3:printf("ʾ����\nDepartureTime: 2023-12-1 17:50:30\n"); scanf("%d-%d-%d %d:%d:%d",
			&result->departureTimeYear,
			&result->departureTimeMonth,
			&result->departureTimeDay,
			&result->departureTimeHour,
			&result->departureTimeMinute,
			&result->departureTimeSecond); break;
		case 4:printf("ʾ����\nArrivalTime: 2023-12-1 19:20:50\n"); scanf("%d-%d-%d %d:%d:%d",
			&result->arrivalTimeYear,
			&result->arrivalTimeMonth,
			&result->arrivalTimeDay,
			&result->arrivalTimeHour,
			&result->arrivalTimeMinute,
			&result->arrivalTimeSecond); break;
		case 5:printf("ʾ����\nMile(����): 649\n"); scanf("%d", &result->mile); break;
		case 6:return;
		default:break;
		}
		printf("�޸ĳɹ���\n");
		FlightWriteListToFile(&RNEU, "��������.txt");//������д���ļ�
	}

}

void conductor(void);

void conductor(void)
{
	char ID[20];
	char PASSWORD[10];
	printf("�������Ա�˺ţ�\n");
	scanf("%s", ID);
	printf("�������Ա���룺\n");
	scanf("%s", PASSWORD);
	struct administrator** Conductor = NULL;
	ConductorReadListFromFile(&Conductor, "����Ա����.txt");
	struct administrator* result = searchAd(&Conductor, ID, PASSWORD);


	if (result == NULL)
	{
		printf("�˺Ż��������\n");
		return;
	}
	while (1)
	{
		printf("                 @@@@@***************************����Աϵͳ����*********************************@@@@@\n");
		printf("                 @@@                              1 ¼ �� �� �� �� Ϣ                             @@@\n");//�Ӹ��ǻ���
		printf("                 ###                              2 �� ѯ �� �� �� �� �� Ϣ                       ###\n");
		printf("                 @@@                              3 �� �� ȫ �� �� �� �� Ϣ                       @@@\n");
		printf("                 ###                              4 �� �� ȫ �� �� �� �� Ϣ                       ###\n");
		printf("                 @@@                              5 �� �� �� �� �� Ϣ                             @@@\n");
		printf("                 ###                              6 ɾ �� �� �� �� Ϣ                             ###\n");
		printf("                 @@@                              7 �� ��                                         @@@\n");
		printf("                 #####!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!#####\n");
		int i;
		printf("��ѡ��: ");
		scanf("%d", &i);
		switch (i) {

		case 1:input_flight(); break;
		case 2:FlightSearch(); break;
		case 3:check_flight(); break;
		case 4:check_passenger(); break;
		case 5:Modify(); break;
		case 6:delectFlight(); break;
			
		case 7:system("cls"); return;
		
		default:break;
		}

	}
}
