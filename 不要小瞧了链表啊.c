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
		printf("                 @@@@@***************************欢迎使用航班订票系统***************************@@@@@\n");//分类 管理员类与乘客类
		printf("                 ###                              1 录 入 航 班 信 息                             ###\n");//加个登机口
        printf("                 @@@                              2 显 示 全 部 航 班 信 息                       @@@\n");
		printf("                 ###                              3 查 询 具 体 航 班 信 息                       ###\n");
        printf("                 @@@                              4 录 入 乘 客 信 息                             @@@\n");
		printf("                 ###                              5 查 看 全 部 乘 客 信 息                       ###\n");
		printf("                 @@@                              6 订 票                                         @@@\n");//加可视化
		printf("                 #####!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!#####\n");
		printf("请选择: ");
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



