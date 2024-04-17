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
	//input_administrator();//管理员注册

	while(1)
	{
		printf("                 @@@@@***************************欢迎使用航班订票系统***************************@@@@@\n");//分类 管理员类与乘客类//搞定
		printf("                 ###                              1 管 理 员 登 陆                                ###\n");	
        printf("                 @@@                              2 进 入 乘 客 系 统                             @@@\n");
		
		printf("                 @@@                              3 订 票                                         @@@\n");//加可视化//搞定
		printf("                 ###                              4 退 出 程 序                                   ###\n");
		
		printf("                 #####!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!#####\n");
		printf("请选择: ");
		scanf("%d",&i);
		switch(i){
		
		    case 1:conductor(); break;
			case 2:passenger(); break;
			
			case 3:bookingTicket(); break;
			case 4:return;
			default:break;
		}
	}
}



