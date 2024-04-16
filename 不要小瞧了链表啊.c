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
		printf("                 @@@@@***************************欢迎使用航班订票系统***************************@@@@@\n");//分类 管理员类与乘客类
		printf("                 ###                              1 管 理 员 登 陆                                ###\n");	
        printf("                 @@@                              2 录 入 乘 客 信 息                             @@@\n");
		printf("                 ###                              3 查 看 全 部 乘 客 信 息                       ###\n");
		printf("                 @@@                              4 订 票                                         @@@\n");//加可视化
		printf("                 ###                              5 退 出                                         ###\n");
		printf("                 #####!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!#####\n");
		printf("请选择: ");
		scanf("%d",&i);
		switch(i){
		
		    case 1:conductor(); break;
			case 2:input_passenger(); break;
			case 3:check_passenger(); break;
			case 4:bookingTicket(); break;
			case 5:return;
			default:break;
		}
	}
}



