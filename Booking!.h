#pragma once
void Book(struct Flight** head, int row, int line, const char* number);

void Book(struct Flight** head, int row, int line, const char* number)//输入航班号寻找航班
{
	struct Flight* current = *head;
	while (current != NULL)
	{
		if (strcmp(current->flightnumber, number) == 0)
		{
			if (current->seats[row][line].booked == 0)
			{
				current->seats[row][line].booked = 1;
				printf("订票成功！\n");
				//printf("%d", current->seats[row][line].booked);//测试语句
				printf("%d %c\n", row, line + 65);
				printf("按任意键返回菜单：\n");
				int c;
				c = getchar();
				return;
			}
			else
			{
				printf("订票失败，该座位已被预订。\n");
				printf("按任意键返回菜单：\n");
				int c;
				c = getchar();
				return;
			}
		}
		else
		{
			printf("航班号错误！\n");
			printf("按任意键返回菜单：\n");
			int c;
			c = getchar();
			return;
		}

		current = current->next;
	}
	printf("订票失败\n");
	printf("按任意键返回菜单：\n");
	int c;
	c = getchar();
	return;
}




void bookingTicket(void);

void bookingTicket(void)
{
	printf("输入预定航班号：");
	char number[10];
	scanf("%s", number);
	printf("输入预定座位：");
	int row;
	char Line;
	scanf("%d %c", &row, &Line);
	system("cls");
	int line = Line - 65;
	struct Flight** RNEU = NULL;
	FlightReadListFromFile(&RNEU, "航班数据.txt");
	
	Book(&RNEU, row, line, number);
	FlightWriteListToFile(&RNEU, "航班数据.txt");
}
