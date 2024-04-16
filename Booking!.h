#pragma once
void Book(struct Flight** head, int row, int line, const char* number);

void Book(struct Flight** head, int row, int line, const char* number)//���뺽���Ѱ�Һ���
{
	struct Flight* current = *head;

	
	while (current != NULL)
	{
		if (strcmp(current->flightnumber, number) == 0)
		{
			if (current->seats[row-1][line].booked == 0)
			{
				current->seats[row-1][line].booked = 1;
				printf("��Ʊ�ɹ���\n");
				printf("��Ʊ�۸�%d\n", current->seats[row - 1][line].price);
				printf("����ǰ��ʮ����ֵ����ף����;��죡");
				if (row-1 >= 0 && row-1 < 4)
				{
					current->headseat -= 1;
				}
				else if (row - 1 >= 4 && row - 1 < 8)
				{
					current->business -= 1;
				}
				else
				{
					current->economyseat -= 1;
				}
				current->availableSeats -= 1;
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

void ShowSeats(struct Flight** head, const char* number);
void ShowSeats(struct Flight** head, const char* number)//��ʾ����Ʊ�ĺ�����λ
{

	struct Flight* current = *head;
	while (current != NULL)
	{
		if (strcmp(current->flightnumber, number) == 0)
		{
			printf("         A   B   C   D   E   F\n");
			for (int i = 0; i < MAX_ROWS; i++)
			{
				printf("%d \t", i + 1);
				for (int j = 0; j < MAX_COLS; j++)
				{

					if (current->seats[i][j].booked == 0)
					{
						printf("[ ] ");
					}
					else
					{
						printf("[X] ");
					}

				}
				printf("\n");
			}
			return;
		}
		else
		{
			printf("����Ŵ���");
			return;
		}
		current = current->next;
	}

}




void bookingTicket(void);

void bookingTicket(void)
{
	struct Flight** RNEU = NULL;
	FlightReadListFromFile(&RNEU, "��������.txt");
	printFlightList(RNEU);

	
	
	

	printf("����Ԥ������ţ�");
	char number[10];
	scanf("%s", number);

	ShowSeats(&RNEU, number);

	printf("����Ԥ����λ��");
	int row;
	char Line;
	scanf("%d %c", &row, &Line);
	system("cls");
	int line = Line - 65;
	
	
	Book(&RNEU, row, line, number);
	FlightWriteListToFile(&RNEU, "��������.txt");
}



