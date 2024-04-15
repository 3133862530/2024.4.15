#pragma once
struct Flight//航班信息
{
    char flightnumber[10];//航班号
    char departure[20];//起飞地
    char destination[20];//目的地

    int departureTimeHour;
    int departureTimeMinute;
    int departureTimeSecond;

    

    int arrivalTimeHour;
    int arrivalTimeMinute;
    int arrivalTimeSecond;

    

    int  mile;//距离
    int  headseat;//头等舱数量
    int  economyseat;//经济舱数量
    int  business;//商务舱数量
    int availableSeats;//剩余可用座位
    //seat_information seats[MAX_ROWS][MAX_COLS] = {0}；//该架次航班座位信息  一排6位 共40排//暂定四排头等舱 八排商务舱 剩余为经济舱

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
    while (current != NULL)
    {
        printf("Flightnumber: %s\n", current->flightnumber);
        printf("Departure: %s\n", current->departure);
        printf("Destination: %s\n", current->destination);
        printf("DepartureTime: %d:%d:%d\n",
            current->departureTimeHour,
            current->departureTimeMinute, 
            current->departureTimeSecond);
        printf("DepartureTime: %d:%d:%d\n", 
            current->arrivalTimeHour, 
            current->arrivalTimeMinute, 
            current->arrivalTimeSecond);
        printf("Mile: %d (公里)\n", current->mile);
        printf("Headseat : %d (位)\n", current->headseat);
        printf("Economyseat : %d (位)\n", current->economyseat);
        printf("Business : %d (位)\n", current->business);
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
void FlightWriteListToFile(struct Flight** head, const char* filename)
{
    //输入一个链表 把链表数据都写到文件中
    FILE* file = fopen(filename, "wb");
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
    FILE* file = fopen(filename, "rb");
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
    printf("Flightnumber: AF1740\n");
    printf("Departure: 沈阳\n");
    printf("Destination: 北京\n");
    printf("DepartureTime: 17:50:30\n");
    printf("ArrivalTime: 19:20:50\n");
    printf("Mile(公里): 649\n");
    printf("Headseat(位): 24\n");
    printf("Economyseat(位): 24\n");
    printf("Business(位): 192\n");
    printf("AvailableSeats(位): 240\n");
    printf("\n");


    for (int i = 0; i < number; i++)
    {
        scanf("%s", current->flightnumber);
        scanf("%s", current->departure);
        scanf("%s", current->destination);
        scanf("%d:%d:%d", &current->departureTimeHour, &current->departureTimeMinute, &current->departureTimeSecond);
        scanf("%d:%d:%d", &current->arrivalTimeHour, &current->arrivalTimeMinute, &current->arrivalTimeSecond);
        scanf("%d", &current->mile);
        scanf("%d", &current->headseat);
        scanf("%d", &current->economyseat);
        scanf("%d", &current->business);
        scanf("%d", &current->availableSeats);
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

struct Flight* search(struct Flight** head, const char* number)//输入航班号寻找航班
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

void FlightSearch(void)
{
    system("cls");
    printf("输入查询的航班号：");
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

    printf("Flightnumber: %s\n", result->flightnumber);
    printf("Departure: %s\n", result->departure);
    printf("Destination: %s\n", result->destination);
    printf("DepartureTime: %d:%d:%d\n",
        result->departureTimeHour,
        result->departureTimeMinute,
        result->departureTimeSecond);
    printf("DepartureTime: %d:%d:%d\n",
        result->arrivalTimeHour,
        result->arrivalTimeMinute,
        result->arrivalTimeSecond);
    printf("Mile: %d (公里)\n", result->mile);
    printf("Headseat : %d (位)\n", result->headseat);
    printf("Economyseat : %d (位)\n", result->economyseat);
    printf("Business : %d (位)\n", result->business);
    printf("AvailableSeats : %d (位)\n", result->availableSeats);
    printf("\n");
}