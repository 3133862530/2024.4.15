#pragma once
void Book(struct Flight** head, int row, int line, const char* number, const char* UID);

void Book(struct Flight** head, int row, int line, const char* number, const char* UID)//���뺽���Ѱ�Һ���
{
	struct Passenger** RNEUer = NULL;
	PassengerReadListFromFile(&RNEUer, "�˿�����.txt");
	struct Passenger* Booker = RNEUer;
	while (Booker != NULL)
	{
		if (strcmp(Booker->idcard, UID) == 0)
			break;
		Booker = Booker->next;
	}



	struct Flight* current = *head;
	
	while (current != NULL)
	{
		if (strcmp(current->flightnumber, number) == 0)
		{
			if (current->seats[row-1][line].booked == 0)
			{
				current->seats[row-1][line].booked = true;
				Booker->Total += current->mile;
				Booker->cost += current->seats[row - 1][line].price;
				printf("��Ʊ�ɹ���\n");
				//for (int i = 0; i < 18; i++)
				//{
				//	current->seats[row - 1][line].BookerID[i] = UID[i];
				//}
				//current->seats[row - 1][line].BookerID[18] = '\0';
				strcpy(current->seats[row - 1][line].BookerID, UID);//������//����û��
				
				printf("��Ʊ�۸�%d\n", current->seats[row - 1][line].price);
				printf("����ǰ��ʮ����ֵ����ף����;��죡");
				//PassengerWriteListToFile(&RNEUer, "�˿�����.txt");
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
				//printf("%d %c\n", row, line + 65);
				//printf("����������ز˵���\n");
				PassengerWriteListToFile(&RNEUer, "�˿�����.txt");//������д���ļ�
				return;
			}
			else
			{
				printf("��Ʊʧ�ܣ�����λ�ѱ�Ԥ����\n");
			
				return;
			}
		}
		current = current->next;
	}
	printf("��Ʊʧ��\n");
	printf("����������ز˵���\n");
	int c;
	c = getchar();
	return;
}

int ShowSeats(struct Flight** head, const char* number);
int ShowSeats(struct Flight** head, const char* number)//��ʾ����Ʊ�ĺ�����λ
{
	int p = 1;
	struct Flight* current = *head;
	while (current != NULL)
	{
		if (strcmp(current->flightnumber, number) == 0)
		{
			printf("         A   B   C   D   E   F\n");
			for (int i = 0; i < 7; i++)
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
			return p;
		}
		current = current->next;
	}
	printf("����Ŵ���\n");
	p = 0;
	return p;
}




void bookingTicket(void);

void bookingTicket(void)
{
	printf("\n�����Ǻ�����Ϣ:\n\n");
	struct Flight** RNEU = NULL;
	FlightReadListFromFile(&RNEU, "��������.txt");
	printFlightList(RNEU);

	printf("�����û����֤��");
	char UID[20];
	scanf("%s", UID);
	
	

	printf("����Ԥ������ţ�");
	char number[10];
	scanf("%s", number);
	

	if (ShowSeats(&RNEU, number) == 0)
		return;

	printf("����Ԥ����λ��");
	int row;
	char Line;
	scanf("%d %c", &row, &Line);
	system("cls");
	int line = Line - 65;
	
	
	Book(&RNEU, row, line, number,UID);
	FlightWriteListToFile(&RNEU, "��������.txt");
}



