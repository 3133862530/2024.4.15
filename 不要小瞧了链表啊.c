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

void BookSearch(struct Flight** head, const char* UID)//Ѱ����������
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
	printf("�˶��ɹ���\n");
	printf("������Ʊ��%d��Ԫ��\n", current->seats[i][j].price);
	
}
void Unsubscribe(void);
void Unsubscribe(void)
{
	struct Flight** RNEU = NULL;
	FlightReadListFromFile(&RNEU, "��������.txt");
	//printFlightList(RNEU);

	printf("�����û����֤��");
	char UID[20];
	scanf("%s", UID);
	BookSearch(&RNEU, UID);
	FlightWriteListToFile(&RNEU, "��������.txt");
}




int main(void)
{
    int i;
	//input_administrator();//����Աע��

	while(1)
	{
		printf("\n");
		printf("                 @@@@@***************************��ӭʹ�ú��ඩƱϵͳ***************************@@@@@\n");//���� ����Ա����˿���//�㶨
		printf("                 ###                              1 �� �� Ա �� ½                                ###\n");	
        printf("                 @@@                              2 �� �� �� �� ϵ ͳ                             @@@\n");
		printf("                 ###                              3 Ʊ �� ϵ ͳ                                   ###\n");//�ӿ��ӻ�//�㶨
		printf("                 @@@                              4 �� Ʊ                                         @@@\n");
		printf("                 ###                              5 �� �� �� ��                                   ###\n");
		printf("                 #####!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!#####\n");
		printf("��ѡ��: ");
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

