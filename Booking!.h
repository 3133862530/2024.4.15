#pragma once
void Book(struct Flight** head, int row, int line, const char* number);

void Book(struct Flight** head, int row, int line, const char* number)//���뺽���Ѱ�Һ���
{
	struct Flight* current = *head;
	while (current != NULL)
	{
		if (strcmp(current->flightnumber, number) == 0)
		{
			if (current->seats[row][line].booked == 0)
			{
				current->seats[row][line].booked = 1;
				printf("��Ʊ�ɹ���\n");
				//printf("%d", current->seats[row][line].booked);//�������
				printf("%d %c\n", row, line + 65);
				printf("����������ز˵���\n");
				int c;
				c = getchar();
				return;
			}
			else
			{
				printf("��Ʊʧ�ܣ�����λ�ѱ�Ԥ����\n");
				printf("����������ز˵���\n");
				int c;
				c = getchar();
				return;
			}
		}
		else
		{
			printf("����Ŵ���\n");
			printf("����������ز˵���\n");
			int c;
			c = getchar();
			return;
		}

		current = current->next;
	}
	printf("��Ʊʧ��\n");
	printf("����������ز˵���\n");
	int c;
	c = getchar();
	return;
}




void bookingTicket(void);

void bookingTicket(void)
{
	printf("����Ԥ������ţ�");
	char number[10];
	scanf("%s", number);
	printf("����Ԥ����λ��");
	int row;
	char Line;
	scanf("%d %c", &row, &Line);
	system("cls");
	int line = Line - 65;
	struct Flight** RNEU = NULL;
	FlightReadListFromFile(&RNEU, "��������.txt");
	
	Book(&RNEU, row, line, number);
	FlightWriteListToFile(&RNEU, "��������.txt");
}
