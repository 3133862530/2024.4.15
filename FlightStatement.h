#pragma once
struct Flight//������Ϣ
{
    char flightnumber[10];//�����
    char departure[20];//��ɵ�
    char destination[20];//Ŀ�ĵ�

    int departureTimeHour;
    int departureTimeMinute;
    int departureTimeSecond;

    

    int arrivalTimeHour;
    int arrivalTimeMinute;
    int arrivalTimeSecond;

    

    int  mile;//����
    int  headseat;//ͷ�Ȳ�����
    int  economyseat;//���ò�����
    int  business;//���������
    int availableSeats;//ʣ�������λ
    //seat_information seats[MAX_ROWS][MAX_COLS] = {0}��//�üܴκ�����λ��Ϣ  һ��6λ ��40��//�ݶ�����ͷ�Ȳ� ��������� ʣ��Ϊ���ò�

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
        printf("Mile: %d (����)\n", current->mile);
        printf("Headseat : %d (λ)\n", current->headseat);
        printf("Economyseat : %d (λ)\n", current->economyseat);
        printf("Business : %d (λ)\n", current->business);
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
void FlightWriteListToFile(struct Flight** head, const char* filename)
{
    //����һ������ ���������ݶ�д���ļ���
    FILE* file = fopen(filename, "wb");
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
    printf("ʾ����\n");
    printf("Flightnumber: AF1740\n");
    printf("Departure: ����\n");
    printf("Destination: ����\n");
    printf("DepartureTime: 17:50:30\n");
    printf("ArrivalTime: 19:20:50\n");
    printf("Mile(����): 649\n");
    printf("Headseat(λ): 24\n");
    printf("Economyseat(λ): 24\n");
    printf("Business(λ): 192\n");
    printf("AvailableSeats(λ): 240\n");
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
    int number = appendFlightNode(&WNEU);//��������
    FlightWriteListToNode(&WNEU, number);//����������д������
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

struct Flight* search(struct Flight** head, const char* number)//���뺽���Ѱ�Һ���
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
    printf("�����ѯ�ĺ���ţ�");
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
    printf("Mile: %d (����)\n", result->mile);
    printf("Headseat : %d (λ)\n", result->headseat);
    printf("Economyseat : %d (λ)\n", result->economyseat);
    printf("Business : %d (λ)\n", result->business);
    printf("AvailableSeats : %d (λ)\n", result->availableSeats);
    printf("\n");
}