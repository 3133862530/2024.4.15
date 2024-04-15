#pragma once

struct Passenger //�˿͸�����Ϣ
{
    char name[20];//����
    char idcard[19];//18λ���֤
    char contact_information[12];//��ϵ��ʽ
    char password[20];//����
    char Registration_number[20];//ע���� UID
    char fancy[100];//�ÿ�ƫ��
    //char seat[2][3];//��λ ����13 A
    struct Passenger* next;
};

int appendPassengerNode(struct Passenger** headRef);
void printPassengerList(struct Passenger* head);
void freePassengerList(struct Passenger* head);
void PassengerWriteListToFile(struct Passenger** head, const char* filename);
void PassengerReadListFromFile(struct Passenger** head, const char* filename);
void PassengerWriteListToNode(struct Passenger** head, int number);


int appendPassengerNode(struct Passenger** headRef)//�����֮ 
{//���������ͷָ�� ��Ҫ����Ľṹ�弴�� ���ɴ���n������
    printf("������ӳ˿�������");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        struct Passenger* newPassenger = (struct Passenger*)malloc(sizeof(struct Passenger));
        newPassenger->next = NULL;
        if (*headRef == NULL)//��鴫�ݽ���������ͷָ���Ƿ�Ϊ�� ���� 
        {
            *headRef = newPassenger;//������һ���ڵ�
            continue;//��ֹ
        }
        struct Passenger* current = *headRef;
        while (current->next != NULL)//һ·��ͨ����ȥ��ͷ
        {
            current = current->next;
        }
        current->next = newPassenger;//����ͷ�� �ӵ�β����
    }

    return n;
}
void printPassengerList(struct Passenger* head) //����˿���Ϣ�ĺ���
{
    struct Passenger* current = head;
    while (current != NULL)
    {
        Sleep(TIME_DELAY);
        printf("Name: %s\n", current->name);
        Sleep(TIME_DELAY);
        printf("ID Card: %s\n", current->idcard);
        Sleep(TIME_DELAY);
        printf("Contact Information: %s\n", current->contact_information);
        Sleep(TIME_DELAY);
        printf("Password: %s\n", current->password);
        Sleep(TIME_DELAY);
        printf("Registration_number: %s\n", current->Registration_number);
        Sleep(TIME_DELAY);
        printf("Fancy: %s\n", current->fancy);
       // printf("Seat: %s %s\n", current->seat[0], current->seat[1]);
        printf("\n");
        current = current->next;
    }
}
void freePassengerList(struct Passenger* head)
{
    struct Passenger* current = head;
    while (current != NULL)
    {
        struct Passenger* temp = current;
        current = current->next;
        free(temp->name);
        free(temp->idcard);
        free(temp->contact_information);
        free(temp->password);
        //free(temp->seat);
        free(temp->Registration_number);
        free(temp->fancy);
        free(temp);
    }
}
void PassengerWriteListToFile(struct Passenger** head, const char* filename)
{
    //����һ������ ���������ݶ�д���ļ���
    FILE* file = fopen(filename, "wb");
    struct Passenger* temp = *head;
    while (temp != NULL)//ûд���һֱд
    {
        fwrite(temp, sizeof(struct Passenger), 1, file);
        temp = temp->next;
    }
    fclose(file);
}
void PassengerReadListFromFile(struct Passenger** head, const char* filename)
{//����һ��ͷָ�� Ȼ����ļ����ݶ�����������
    FILE* file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    struct Passenger temp;
    while (fread(&temp, sizeof(struct Passenger), 1, file) != 0)
    {
        struct Passenger* newPassenger = (struct Passenger*)malloc(sizeof(struct Passenger));
        if (newPassenger == NULL)
        {
            printf("Memory allocation failed.\n");
            //fclose(file);
            return;
        }

        *newPassenger = temp;
        newPassenger->next = NULL;
        if (*head == NULL)
        {
            *head = newPassenger;
        }
        else
        {
            struct Passenger* current = *head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newPassenger;
        }

    }
    fclose(file);
}
void PassengerWriteListToNode(struct Passenger** head, int number)
{
    struct Passenger* current = *head;

    printf("\n");
    printf("ʾ����\n");
    Sleep(TIME_DELAY);
    printf("Name: Wang Yili\n");
    Sleep(TIME_DELAY);
    printf("ID Card: 33032420041004105X\n");
    Sleep(TIME_DELAY);
    printf("Contact Information: 13587953759\n");
    Sleep(TIME_DELAY);
    printf("Password: 123123123\n");
    Sleep(TIME_DELAY);
    printf("Registration_number: 121241230\n");
    Sleep(TIME_DELAY);
    printf("Fancy: ˯���˲�Ҫ���ҳԷ�\n");
    //printf("Seat: 13 A\n");
    printf("\n");


    for (int i = 0; i < number; i++)
    {
        scanf("%s", current->name);
        //fgets(current->name, 21, stdin);
        scanf("%s", current->idcard);
        //fgets(current->idcard, 20, stdin);
        scanf("%s", current->contact_information);
        //fgets(current->contact_information, 13, stdin);
        scanf("%s", current->password);
        //fgets(current->password, 21, stdin);
        scanf("%s", current->Registration_number);
        //fgets(current->Registration_number, 21, stdin);
        scanf("%s", current->fancy);
        //fgets(current->fancy, 101, stdin);
        //scanf("%s %s", current->seat[0], current->seat[1]);
        current = current->next;
    }

}



void input_passenger(void);
void check_passenger(void);

void input_passenger()
{
    struct Passenger** WNEUer = NULL;
    int number = appendPassengerNode(&WNEUer);//��������
    PassengerWriteListToNode(&WNEUer, number);//���˿�����д������
    PassengerWriteListToFile(&WNEUer, "�˿�����.txt");//������д���ļ�
    system("cls");
    //freePassengerList(WNEUer);//�ͷŹ��̻������� ��δ���
}
void check_passenger()
{
    system("cls");
    struct Passenger** RNEUer = NULL;
    PassengerReadListFromFile(&RNEUer, "�˿�����.txt");
    printPassengerList(RNEUer);
    //freePassengerList(RNEUer);
}