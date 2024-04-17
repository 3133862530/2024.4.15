#pragma once

#define MAX_ROWS 40
#define MAX_COLS 6


struct seat_information
{
    bool booked;          //����λ�Ƿ�Ԥ��
    int price;  //����λ�ȼ����۸�
    //Passenger Infor;  //����λ�˿���Ϣ
};

struct Flight//������Ϣ
{
    char flightnumber[10];//�����
    char departure[20];//��ɵ�
    char destination[20];//Ŀ�ĵ�

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

    

    int  mile;//����
    int  headseat;//ͷ�Ȳ�����
    int  business;//���������
    int  economyseat;//���ò�����
    int availableSeats;//ʣ�������λ
    struct seat_information seats[MAX_ROWS][MAX_COLS] ;//�üܴκ�����λ��Ϣ  һ��6λ ��40��//�ݶ�����ͷ�Ȳ� ��������� ʣ��Ϊ���ò�

    struct Flight* next;
};    //������Ϣ     this is the basic part

int appendFlightNode(struct Flight** headRef);
void printFlightList(struct Flight* head);
void freeFlightList(struct Flight* head);
void FlightWriteListToFile(struct Flight** head, const char* filename);
void FlightReadListFromFile(struct Flight** head, const char* filename);
void FlightWriteListToNode(struct Flight** head, int number);


int appendFlightNode(struct Flight** headRef)//�����֮ 
{//���������ͷָ�� ��Ҫ����Ľṹ�弴�� ���ɴ���n������
    printf("������Ӻ���������");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        struct Flight* newFlight = (struct Flight*)malloc(sizeof(struct Flight));
        newFlight->next = NULL;
        if (*headRef == NULL)//��鴫�ݽ���������ͷָ���Ƿ�Ϊ�� ���� 
        {
            *headRef = newFlight;//������һ���ڵ�
            continue;//��ֹ
        }
        struct Flight* current = *headRef;
        while (current->next != NULL)//һ·��ͨ����ȥ��ͷ
        {
            current = current->next;
        }
        current->next = newFlight;//����ͷ�� �ӵ�β����
    }



    return n;
}
void printFlightList(struct Flight* head) //���������Ϣ�ĺ���
{
    struct Flight* current = head;
    current = current->next;//������һ��ʾ������
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
        printf("Mile: %d (����)\n", current->mile);
        Sleep(TIME_DELAY);
        printf("Headseat : %d (λ)\n", current->headseat);
        Sleep(TIME_DELAY);
        printf("Economyseat : %d (λ)\n", current->economyseat);
        Sleep(TIME_DELAY);
        printf("Business : %d (λ)\n", current->business);
        Sleep(TIME_DELAY);
        printf("AvailableSeats : %d (λ)\n", current->availableSeats);
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
void FlightWriteListToFile(struct Flight** head, const char* filename)//����һ������ ���������ݶ�д���ļ���
{
    
    //FILE* file = fopen(filename, "w");//��д
    FILE* file = fopen(filename, "w");//׷��
    struct Flight* temp = *head;
    while (temp != NULL)//ûд���һֱд
    {
        fwrite(temp, sizeof(struct Flight), 1, file);
        temp = temp->next;
    }
    fclose(file);
}
void FlightReadListFromFile(struct Flight** head, const char* filename)
{//����һ��ͷָ�� Ȼ����ļ����ݶ�����������
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
    printf("ʾ����\n");
    Sleep(TIME_DELAY);
    printf("Flightnumber: AF1740\n");
    Sleep(TIME_DELAY);
    printf("Departure: ����\n");
    Sleep(TIME_DELAY);
    printf("Destination: ����\n");
    Sleep(TIME_DELAY);
    printf("DepartureTime: 2023-12-1 17:50:30\n");
    Sleep(TIME_DELAY);
    printf("ArrivalTime: 2023-12-1 19:20:50\n");
    Sleep(TIME_DELAY);
    printf("Mile(����): 649\n");
    Sleep(TIME_DELAY);
    printf("Headseat(λ): 24\n");
    Sleep(TIME_DELAY);
    printf("Economyseat(λ): 24\n");
    Sleep(TIME_DELAY);
    printf("Business(λ): 192\n");
    Sleep(TIME_DELAY);
    printf("AvailableSeats(λ): 240\n");
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


void Initialization(struct Flight** head);//��ʼ����λ��Ϣ
void Initialization(struct Flight** head)
{
    struct Flight* current = *head;
    while (current != NULL)
    {
        for (int i = 0; i < 4; i++)//ͷ��
        {
            for (int j = 0; j < MAX_COLS; j++)
            {
                current->seats[i][j].booked = 0;
                current->seats[i][j].price = current->mile * 4;
            }
        }
        for (int i = 4; i < 8; i++)//����
        {
            for (int j = 0; j < MAX_COLS; j++)
            {
                current->seats[i][j].booked = 0;
                current->seats[i][j].price = current->mile * 2;
            }
        }
        for (int i = 8; i < MAX_ROWS; i++)//����
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
    int number = appendFlightNode(&WNEU);//��������
    FlightWriteListToNode(&WNEU, number);//����������д������
    Initialization(&WNEU);
    FlightWriteListToFile(&WNEU, "��������.txt");//������д���ļ�
    system("cls");
    //freeFlightList(WNEU);
}
void check_flight(void)
{
    system("cls");
    struct Flight** RNEU = NULL;
    FlightReadListFromFile(&RNEU, "��������.txt");
    printFlightList(RNEU);
    //freeFlightList(RNEU);
}


struct Flight* search(struct Flight** head, const char* number);

struct Flight* search(struct Flight** head, const char* number)//���뺽���Ѱ�Һ��ಢ���ظú���ָ��
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

struct Flight* Delectsearch(struct Flight** head, const char* number)//���뺽���Ѱ�Һ��ಢ����ǰһ����ָ��
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

void FlightSearch(void)//��ѯ������ú�����Ϣ
{
    system("cls");
    printf("�����ѯ�ĺ���ţ�\n");
    char number[10];
    scanf("%s", number);
    struct Flight** RNEU = NULL;
    FlightReadListFromFile(&RNEU, "��������.txt");
    struct Flight* result = search(&RNEU, number);

    if (result == NULL)
    {
        printf("δ�ҵ�ƥ��ĺ��ࡣ\n");
        return;
    }
    Sleep(TIME_DELAY);
    printf("�����: %s\n", result->flightnumber);
    Sleep(TIME_DELAY);
    printf("����: %s\n", result->departure);
    Sleep(TIME_DELAY);
    printf("����: %s\n", result->destination);
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
    printf("���: %d (����)\n", result->mile);
    Sleep(TIME_DELAY);
    printf("ͷ�Ȳ����� : %d (λ)\n", result->headseat);
    Sleep(TIME_DELAY);
    printf("��������� : %d (λ)\n", result->business);
    Sleep(TIME_DELAY);
    printf("���ò����� : %d (λ)\n", result->economyseat);
    Sleep(TIME_DELAY);
    printf("ʣ����� : %d (λ)\n", result->availableSeats);
    printf("\n");
}

void delectFlight(void);
void delectFlight(void)
{
    system("cls");
    printf("����ɾ���ĺ���ţ�\n");
    char number[10];
    scanf("%s", number);
    struct Flight** RNEU = NULL;
    FlightReadListFromFile(&RNEU, "��������.txt");

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


    FlightWriteListToFile(&RNEU, "��������.txt");//������д���ļ�
}