#define _CRT_SECURE_NO_WARNINGS
#define TIME_DELAY 25
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<windows.h>

#include"PassStatement.h"
#include"FlightStatement.h"
#include"Booking!.h"
#include"Conductor.h"
void BookSearch(struct Flight** head, const char* UID);

void BookSearch(struct Flight** head, const char* UID)//寻找所定航班
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
	int i = 0;
	int j = 0;
	while (current != NULL)
	{
		for (; i < MAX_ROWS; i++)
		{
			for (; j < MAX_COLS; j++)
			{
				if (strcmp(current->seats[i][j].BookerID, UID) == 0)
					break;
			}
			if (strcmp(current->seats[i][j].BookerID, UID) == 0)
				break;
		}
		if (strcmp(current->seats[i][j].BookerID, UID) == 0)
			break;
		
		current = current->next;
	}
	current->seats[i][j].booked = 0;
	strcpy(current->seats[i][j].BookerID, "");
	Booker->Total -= current->mile;
	Booker->cost -= current->seats[i][j].price;
	if (i >= 0 && i < 4)
	{
		current->headseat += 1;
	}
	else if (i >= 4 && i < 8)
	{
		current->business += 1;
	}
	else
	{
		current->economyseat += 1;
	}
	current->availableSeats += 1;
	printf("退订成功！\n");
	printf("返还机票：%d（元）\n", current->seats[i][j].price);
	
}
void Unsubscribe(void);
void Unsubscribe(void)
{
	struct Flight** RNEU = NULL;
	FlightReadListFromFile(&RNEU, "航班数据.txt");
	//printFlightList(RNEU);

	printf("输入用户身份证：");
	char UID[20];
	scanf("%s", UID);
	BookSearch(&RNEU, UID);
	FlightWriteListToFile(&RNEU, "航班数据.txt");
}




int main(void)
{
    int i;
	//input_administrator();//管理员注册

	while(1)
	{
		printf("\n");
		printf("                 @@@@@***************************欢迎使用航班订票系统***************************@@@@@\n");//分类 管理员类与乘客类//搞定
		printf("                 ###                              1 管 理 员 登 陆                                ###\n");	
        printf("                 @@@                              2 进 入 乘 客 系 统                             @@@\n");
		printf("                 ###                              3 票 务 系 统                                   ###\n");//加可视化//搞定
		printf("                 @@@                              4 退 票                                         @@@\n");
		printf("                 ###                              5 退 出 程 序                                   ###\n");
		printf("                 #####!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!#####\n");
		printf("请选择: ");
		scanf("%d",&i);
		switch(i){
		
		    case 1:conductor(); break;
			case 2:passenger(); break;
			
			case 3:bookingTicket(); break;
			case 4:Unsubscribe(); break;
				
			case 5:return;
			default:break;
		}
	}
}

