#pragma once
void Book(struct Flight** head, int row, int line, const char* number, const char* UID);

void Book(struct Flight** head, int row, int line, const char* number, const char* UID)//输入航班号寻找航班
{
	struct Passenger** RNEUer = NULL;
	PassengerReadListFromFile(&RNEUer, "乘客数据.txt");
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
				printf("订票成功！\n");
				//for (int i = 0; i < 18; i++)
				//{
				//	current->seats[row - 1][line].BookerID[i] = UID[i];
				//}
				//current->seats[row - 1][line].BookerID[18] = '\0';
				strcpy(current->seats[row - 1][line].BookerID, UID);//有问题//现在没了
				
				printf("机票价格：%d\n", current->seats[row - 1][line].price);
				printf("请提前四十分钟值机。祝您旅途愉快！");
				//PassengerWriteListToFile(&RNEUer, "乘客数据.txt");
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
				//printf("%d", current->seats[row][line].booked);//测试语句
				//printf("%d %c\n", row, line + 65);
				//printf("按任意键返回菜单：\n");
				PassengerWriteListToFile(&RNEUer, "乘客数据.txt");//将链表写入文件
				return;
			}
			else
			{
				printf("订票失败，该座位已被预订。\n");
			
				return;
			}
		}
		current = current->next;
	}
	printf("订票失败\n");
	printf("按任意键返回菜单：\n");
	int c;
	c = getchar();
	return;
}

int ShowSeats(struct Flight** head, const char* number);
int ShowSeats(struct Flight** head, const char* number)//显示欲订票的航班座位
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
	printf("航班号错误！\n");
	p = 0;
	return p;
}




void bookingTicket(void);

void bookingTicket(void)
{
	printf("\n以下是航班信息:\n\n");
	struct Flight** RNEU = NULL;
	FlightReadListFromFile(&RNEU, "航班数据.txt");
	printFlightList(RNEU);

	printf("输入用户身份证：");
	char UID[20];
	scanf("%s", UID);
	
	

	printf("输入预定航班号：");
	char number[10];
	scanf("%s", number);
	

	if (ShowSeats(&RNEU, number) == 0)
		return;

	printf("输入预定座位：");
	int row;
	char Line;
	scanf("%d %c", &row, &Line);
	system("cls");
	int line = Line - 65;
	
	
	Book(&RNEU, row, line, number,UID);
	FlightWriteListToFile(&RNEU, "航班数据.txt");
}



