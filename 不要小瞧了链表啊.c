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








int main(void)
{
    int i;

	while(1)
	{
		printf("                 @@@@@***************************��ӭʹ�ú��ඩƱϵͳ***************************@@@@@\n");//���� ����Ա����˿���
		printf("                 ###                              1 ¼ �� �� �� �� Ϣ                             ###\n");//�Ӹ��ǻ���
        printf("                 @@@                              2 �� ʾ ȫ �� �� �� �� Ϣ                       @@@\n");
		printf("                 ###                              3 �� ѯ �� �� �� �� �� Ϣ                       ###\n");
        printf("                 @@@                              4 ¼ �� �� �� �� Ϣ                             @@@\n");
		printf("                 ###                              5 �� �� ȫ �� �� �� �� Ϣ                       ###\n");
		printf("                 @@@                              6 �� Ʊ                                         @@@\n");//�ӿ��ӻ�
		printf("                 #####!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!#####\n");
		printf("��ѡ��: ");
		scanf("%d",&i);
		switch(i){
			case 1:input_flight();break;
            case 2:check_flight(); break; 
			case 3:FlightSearch(); break;
			case 4:input_passenger(); break;
			case 5:check_passenger(); break;
			case 6:bookingTicket(); break;
			default:break;
		}
	}
}



