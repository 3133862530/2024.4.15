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






int main(void)
{
    int i;
	//input_administrator();//����Աע��

	while(1)
	{
		printf("                 @@@@@***************************��ӭʹ�ú��ඩƱϵͳ***************************@@@@@\n");//���� ����Ա����˿���
		printf("                 ###                              1 �� �� Ա �� ½                                ###\n");
		printf("                 ###                              2 �� ѯ �� �� �� �� �� Ϣ                       ###\n");
        printf("                 @@@                              3 ¼ �� �� �� �� Ϣ                             @@@\n");
		printf("                 ###                              4 �� �� ȫ �� �� �� �� Ϣ                       ###\n");
		printf("                 @@@                              5 �� Ʊ                                         @@@\n");//�ӿ��ӻ�
		printf("                 #####!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!#####\n");
		printf("��ѡ��: ");
		scanf("%d",&i);
		switch(i){
		
		    case 1:conductor(); break;
			case 2:FlightSearch(); break;
			case 3:input_passenger(); break;
			case 4:check_passenger(); break;
			case 5:bookingTicket(); break;
			default:break;
		}
	}
}



