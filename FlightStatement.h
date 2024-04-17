#pragma once

#define MAX_ROWS 40
#define MAX_COLS 6


struct seat_information
{
    bool booked;          //该座位是否被预定
    int price;  //该座位等级及价格
    //Passenger Infor;  //该座位乘客信息
};

struct Flight//航班信息
{
    char flightnumber[10];//航班号
    char departure[20];//起飞地
    char destination[20];//目的地

    int departureTimeYear;
    int departureTimeMonth;
    int departureTimeDay;

    int departureTimeHour;
    int departureTimeMinute;
    int departureTimeSecond;

    int arrivalTimeYear;
    int arrivalTimeMonth;
    int arrivalTimeDay;

    int arrivalTimeHour;
    int arrivalTimeMinute;
    int arrivalTimeSecond;

    

    int  mile;//距离
    int  headseat;//头等舱数量
    int  business;//商务舱数量
    int  economyseat;//经济舱数量
    int availableSeats;//剩余可用座位
    struct seat_information seats[MAX_ROWS][MAX_COLS] ;//该架次航班座位信息  一排6位 共40排//暂定四排头等舱 八排商务舱 剩余为经济舱

    struct Flight* next;
};    //航班信息     this is the basic part

int appendFlightNode(struct Flight** headRef);
void printFlightList(struct Flight* head);
void freeFlightList(struct Flight* head);
void FlightWriteListToFile(struct Flight** head, const char* filename);
void FlightReadListFromFile(struct Flight** head, const char* filename);
void FlightWriteListToNode(struct Flight** head, int number);


int appendFlightNode(struct Flight** headRef)//简而言之 
{//输入链表的头指针 和要加入的结构体即可 即可创建n个链表
    printf("输入添加航班数量：");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        struct Flight* newFlight = (struct Flight*)malloc(sizeof(struct Flight));
        newFlight->next = NULL;
        if (*headRef == NULL)//检查传递进来的链表头指针是否为零 若是 
        {
            *headRef = newFlight;//则建立第一个节点
            continue;//终止
        }
        struct Flight* current = *headRef;
        while (current->next != NULL)//一路畅通拉下去到头
        {
            current = current->next;
        }
        current->next = newFlight;//拉到头了 加到尾巴上
    }



    return n;
}
void printFlightList(struct Flight* head) //输出航班信息的函数
{
    struct Flight* current = head;
    current = current->next;//跳过第一个示例航班
    while (current != NULL)
    {
        
        printf("Flightnumber: %s\n", current->flightnumber);
        Sleep(TIME_DELAY);
        printf("Departure: %s\n", current->departure);
        Sleep(TIME_DELAY);
        printf("Destination: %s\n", current->destination);
        Sleep(TIME_DELAY);
        printf("DepartureTime: %d-%d-%d %d:%d:%d\n",
            current->departureTimeYear,
            current->departureTimeYear,
            current->departureTimeDay,
            current->departureTimeHour,
            current->departureTimeMinute, 
            current->departureTimeSecond);
        Sleep(TIME_DELAY);
        printf("ArrivalTime: %d-%d-%d %d:%d:%d\n", 
            current->arrivalTimeYear,
            current->arrivalTimeMonth,
            current->arrivalTimeDay,
            current->arrivalTimeHour, 
            current->arrivalTimeMinute, 
            current->arrivalTimeSecond);
        Sleep(TIME_DELAY);
        printf("Mile: %d (公里)\n", current->mile);
        Sleep(TIME_DELAY);
        printf("Headseat : %d (位)\n", current->headseat);
        Sleep(TIME_DELAY);
        printf("Economyseat : %d (位)\n", current->economyseat);
        Sleep(TIME_DELAY);
        printf("Business : %d (位)\n", current->business);
        Sleep(TIME_DELAY);
        printf("AvailableSeats : %d (位)\n", current->availableSeats);
        printf("\n");
        current = current->next;
    }
}
void freeFlightList(struct Flight* head)
{
    struct Flight* current = head;
    while (current != NULL)
    {
        struct Flight* temp = current;
        current = current->next;
        free(temp->flightnumber);
        free(temp->departure);
        free(temp->destination);
        free(temp->departureTimeHour);
        free(temp->departureTimeMinute);
        free(temp->departureTimeSecond);
        free(temp->arrivalTimeSecond);
        free(temp->arrivalTimeMinute);
        free(temp->arrivalTimeHour);
        free(temp->mile);
        free(temp->headseat);
        free(temp->economyseat);
        free(temp->business);
        free(temp->availableSeats);
        free(temp);
    }
}
void FlightWriteListToFile(struct Flight** head, const char* filename)//输入一个链表 把链表数据都写到文件中
{
    
    //FILE* file = fopen(filename, "w");//重写
    FILE* file = fopen(filename, "w");//追加
    struct Flight* temp = *head;
    while (temp != NULL)//没写完就一直写
    {
        fwrite(temp, sizeof(struct Flight), 1, file);
        temp = temp->next;
    }
    fclose(file);
}
void FlightReadListFromFile(struct Flight** head, const char* filename)
{//输入一个头指针 然后把文件数据都读到链表中
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    struct Flight temp;
    while (fread(&temp, sizeof(struct Flight), 1, file) != 0)
    {
        struct Flight* newFlight = (struct Flight*)malloc(sizeof(struct Flight));
        if (newFlight == NULL)
        {
            printf("Memory allocation failed.\n");
            //fclose(file);
            return;
        }

        *newFlight = temp;
        newFlight->next = NULL;
        if (*head == NULL)
        {
            *head = newFlight;
        }
        else
        {
            struct Flight* current = *head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newFlight;
        }

    }
    fclose(file);

}
void FlightWriteListToNode(struct Flight** head, int number)
{
    struct Flight* current = *head;

    printf("\n");
    printf("示例：\n");
    Sleep(TIME_DELAY);
    printf("Flightnumber: AF1740\n");
    Sleep(TIME_DELAY);
    printf("Departure: 沈阳\n");
    Sleep(TIME_DELAY);
    printf("Destination: 北京\n");
    Sleep(TIME_DELAY);
    printf("DepartureTime: 2023-12-1 17:50:30\n");
    Sleep(TIME_DELAY);
    printf("ArrivalTime: 2023-12-1 19:20:50\n");
    Sleep(TIME_DELAY);
    printf("Mile(公里): 649\n");
    Sleep(TIME_DELAY);
    printf("Headseat(位): 24\n");
    Sleep(TIME_DELAY);
    printf("Economyseat(位): 24\n");
    Sleep(TIME_DELAY);
    printf("Business(位): 192\n");
    Sleep(TIME_DELAY);
    printf("AvailableSeats(位): 240\n");
    printf("\n");


    for (int i = 0; i < number; i++)
    {
        scanf("%s", current->flightnumber);
        scanf("%s", current->departure);
        scanf("%s", current->destination);
        char c;
        c=getchar();
        scanf("%d-%d-%d %d:%d:%d", 
            &current->departureTimeYear, 
            &current->departureTimeMonth,
            &current->departureTimeDay, 
            &current->departureTimeHour, 
            &current->departureTimeMinute,
            &current->departureTimeSecond);
        scanf("%d-%d-%d %d:%d:%d", 
            &current->arrivalTimeYear,
            &current->arrivalTimeMonth,
            &current->arrivalTimeDay,
            &current->arrivalTimeHour,
            &current->arrivalTimeMinute,
            &current->arrivalTimeSecond);
        scanf("%d", &current->mile);
        scanf("%d", &current->headseat);
        scanf("%d", &current->business);
        scanf("%d", &current->economyseat);
        scanf("%d", &current->availableSeats);
        current = current->next;
    }

}


void Initialization(struct Flight** head);//初始化座位信息
void Initialization(struct Flight** head)
{
    struct Flight* current = *head;
    while (current != NULL)
    {
        for (int i = 0; i < 4; i++)//头等
        {
            for (int j = 0; j < MAX_COLS; j++)
            {
                current->seats[i][j].booked = 0;
                current->seats[i][j].price = current->mile * 4;
            }
        }
        for (int i = 4; i < 8; i++)//商务
        {
            for (int j = 0; j < MAX_COLS; j++)
            {
                current->seats[i][j].booked = 0;
                current->seats[i][j].price = current->mile * 2;
            }
        }
        for (int i = 8; i < MAX_ROWS; i++)//经济
        {
            for (int j = 0; j < MAX_COLS; j++)
            {
                current->seats[i][j].booked = 0;
                current->seats[i][j].price = current->mile * 1;
            }
        }
        
        current = current->next;
    }
}

void input_flight(void);
void check_flight(void);

void input_flight(void)
{
    struct Flight** WNEU = NULL;
    int number = appendFlightNode(&WNEU);//创建链表
    FlightWriteListToNode(&WNEU, number);//将航班数据写入链表
    Initialization(&WNEU);
    FlightWriteListToFile(&WNEU, "航班数据.txt");//将链表写入文件
    system("cls");
    //freeFlightList(WNEU);
}
void check_flight(void)
{
    system("cls");
    struct Flight** RNEU = NULL;
    FlightReadListFromFile(&RNEU, "航班数据.txt");
    printFlightList(RNEU);
    //freeFlightList(RNEU);
}


struct Flight* search(struct Flight** head, const char* number);

struct Flight* search(struct Flight** head, const char* number)//输入航班号寻找航班并返回该航班指针
{
    struct Flight* current = *head;
    while (current != NULL)
    {
        if (strcmp(current->flightnumber, number) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}
struct Flight* search(struct Flight** head, const char* number);

struct Flight* Delectsearch(struct Flight** head, const char* number)//输入航班号寻找航班并返回前一航班指针
{
    struct Flight* current = *head;
    while (current != NULL)
    {
        if (strcmp(current->next->flightnumber, number) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}

void FlightSearch(void);

void FlightSearch(void)//查询并输出该航班信息
{
    system("cls");
    printf("输入查询的航班号：\n");
    char number[10];
    scanf("%s", number);
    struct Flight** RNEU = NULL;
    FlightReadListFromFile(&RNEU, "航班数据.txt");
    struct Flight* result = search(&RNEU, number);

    if (result == NULL)
    {
        printf("未找到匹配的航班。\n");
        return;
    }
    Sleep(TIME_DELAY);
    printf("航班号: %s\n", result->flightnumber);
    Sleep(TIME_DELAY);
    printf("出发: %s\n", result->departure);
    Sleep(TIME_DELAY);
    printf("到达: %s\n", result->destination);
    Sleep(TIME_DELAY);
    printf("DepartureTime: %d-%d-%d %d:%d:%d\n",
        result->departureTimeYear,
        result->departureTimeYear,
        result->departureTimeDay,
        result->departureTimeHour,
        result->departureTimeMinute,
        result->departureTimeSecond);
    Sleep(TIME_DELAY);
    printf("ArrivalTime: %d-%d-%d %d:%d:%d\n",
        result->arrivalTimeYear,
        result->arrivalTimeMonth,
        result->arrivalTimeDay,
        result->arrivalTimeHour,
        result->arrivalTimeMinute,
        result->arrivalTimeSecond);
    Sleep(TIME_DELAY);
    printf("里程: %d (公里)\n", result->mile);
    Sleep(TIME_DELAY);
    printf("头等舱数量 : %d (位)\n", result->headseat);
    Sleep(TIME_DELAY);
    printf("商务舱数量 : %d (位)\n", result->business);
    Sleep(TIME_DELAY);
    printf("经济舱数量 : %d (位)\n", result->economyseat);
    Sleep(TIME_DELAY);
    printf("剩余空座 : %d (位)\n", result->availableSeats);
    printf("\n");
}

void delectFlight(void);
void delectFlight(void)
{
    system("cls");
    printf("输入删除的航班号：\n");
    char number[10];
    scanf("%s", number);
    struct Flight** RNEU = NULL;
    FlightReadListFromFile(&RNEU, "航班数据.txt");

    struct Flight* temp = search(&RNEU, number);
    struct Flight* result = Delectsearch(&RNEU, number);

    result->next = result->next->next;
    /*	free(temp->flightnumber);
        free(temp->departure);
        free(temp->destination);
        free(temp->departureTimeYear);
        free(temp->departureTimeMonth);
        free(temp->departureTimeDay);
        free(temp->departureTimeHour);
        free(temp->departureTimeMinute);
        free(temp->departureTimeSecond);
        free(temp->arrivalTimeYear);
        free(temp->arrivalTimeMonth);
        free(temp->arrivalTimeDay);
        free(temp->arrivalTimeHour);
        free(temp->arrivalTimeMinute);
        free(temp->arrivalTimeSecond);
        free(temp->mile);
        free(temp->headseat);
        free(temp->business);
        free(temp->economyseat);
        free(temp->availableSeats);
        for (int i = 0; i < MAX_ROWS; i++)
        {
            for (int j = 0; j < MAX_COLS; j++)
            {
                free(temp->seats[i][j].booked);
                free(temp->seats[i][j].price);
            }
        }*/
    free(temp);


    FlightWriteListToFile(&RNEU, "航班数据.txt");//将链表写入文件
}