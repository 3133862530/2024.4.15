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
		printf("                 @@@@@***************************��ӭʹ�ú��ඩƱϵͳ***************************@@@@@\n");//���� ����Ա����˿���//�㶨
		printf("                 ###                              1 �� �� Ա �� ½                                ###\n");	
        printf("                 @@@                              2 �� �� �� �� ϵ ͳ                             @@@\n");
		
		printf("                 @@@                              4 �� Ʊ                                         @@@\n");//�ӿ��ӻ�//�㶨
		printf("                 ###                              5 �� ��                                         ###\n");
		
		printf("                 #####!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!#####\n");
		printf("��ѡ��: ");
		scanf("%d",&i);
		switch(i){
		
		    case 1:conductor(); break;
			case 2:passenger(); break;
			
			case 4:bookingTicket(); break;
			case 5:return;
			default:break;
		}
	}
}



