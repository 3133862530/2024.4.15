#pragma once

struct Passenger //乘客个人信息
{
    char name[20];//名字
    char idcard[19];//18位身份证
    char contact_information[12];//联系方式
    char password[20];//密码
    char Registration_number[20];//注册编号 UID
    char fancy[100];//旅客偏好
    long int Total;//总里程
    long int cost;
    //char seat[2][3];//座位 例：13 A
    struct Passenger* next;
};

int appendPassengerNode(struct Passenger** headRef);
void printPassengerList(struct Passenger* head);
void freePassengerList(struct Passenger* head);
void PassengerWriteListToFile(struct Passenger** head, const char* filename);
void PassengerReadListFromFile(struct Passenger** head, const char* filename);
void PassengerWriteListToNode(struct Passenger** head, int number);


int appendPassengerNode(struct Passenger** headRef)//简而言之 
{//输入链表的头指针 和要加入的结构体即可 即可创建n个链表
    //printf("输入添加乘客数量：");
    int n = 1;
    //scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        struct Passenger* newPassenger = (struct Passenger*)malloc(sizeof(struct Passenger));
        newPassenger->next = NULL;
        if (*headRef == NULL)//检查传递进来的链表头指针是否为零 若是 
        {
            *headRef = newPassenger;//则建立第一个节点
            continue;//终止
        }
        struct Passenger* current = *headRef;
        while (current->next != NULL)//一路畅通拉下去到头
        {
            current = current->next;
        }
        current->next = newPassenger;//拉到头了 加到尾巴上
    }

    return n;
}
void printPassengerList(struct Passenger* head) //输出乘客信息的函数
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
        Sleep(TIME_DELAY);
        printf("Total mile: %ld(km)\n", current->Total);
        Sleep(TIME_DELAY);
        printf("Whole cost: %ld(km)\n", current->cost);
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
        free(temp->Total);
        free(temp);
    }
}
void PassengerWriteListToFile(struct Passenger** head, const char* filename)
{
    //输入一个链表 把链表数据都写到文件中
    //FILE* file = fopen(filename, "w");//重写
    FILE* file = fopen(filename, "a");//追加
    struct Passenger* temp = *head;
    while (temp != NULL)//没写完就一直写
    {
        fwrite(temp, sizeof(struct Passenger), 1, file);
        temp = temp->next;
    }
    fclose(file);
}
void PassengerReadListFromFile(struct Passenger** head, const char* filename)
{//输入一个头指针 然后把文件数据都读到链表中
    FILE* file = fopen(filename, "r");
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
    printf("示例：\n");
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
    printf("Fancy: 睡着了不要叫我吃饭\n");
    //Sleep(TIME_DELAY);
    //printf("Total mile: 1400 km\n");
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
        current->Total = 0;
        current->cost = 0;
        //scanf("%ld", &current->Total);
        //fgets(current->fancy, 101, stdin);
        //scanf("%s %s", current->seat[0], current->seat[1]);
        current = current->next;
    }

}



void input_passenger(void);
void check_passenger(void);

void input_passenger()//乘客注册
{
    struct Passenger** WNEUer = NULL;
    int number = appendPassengerNode(&WNEUer);//创建链表
    PassengerWriteListToNode(&WNEUer, number);//将乘客数据写入链表
    PassengerWriteListToFile(&WNEUer, "乘客数据.txt");//将链表写入文件
    system("cls");
    //freePassengerList(WNEUer);//释放过程还有问题 暂未解决
}
void check_passenger()//显示全部struct乘客信息
{
    system("cls");
    struct Passenger** RNEUer = NULL;
    PassengerReadListFromFile(&RNEUer, "乘客数据.txt");
    printPassengerList(RNEUer);
    //freePassengerList(RNEUer);
}

struct Passenger* Passsearch(struct Passenger** head, const char* UID);

struct Passenger* Passsearch(struct Passenger** head, const char* UID)//输入UID寻找乘客并返回该乘客指针
{
    struct Passenger* current = *head;
    while (current != NULL)
    {
        if (strcmp(current->Registration_number, UID) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}

void PassengerSearch(void);

void PassengerSearch(void)//查询并输出乘客信息
{
    system("cls");
    printf("输入查询的乘客注册编号：\n");
    char Registration_number[20];
    scanf("%s", Registration_number);
    struct Passenger** RNEUer = NULL;
    PassengerReadListFromFile(&RNEUer, "乘客数据.txt");
    struct Passenger* result = Passsearch(&RNEUer, Registration_number);

    if (result == NULL)
    {
        printf("不存在改乘客或UID错误输入。\n");
        return;
    }
    Sleep(TIME_DELAY);
    printf("Name: %s\n", result->name);
    Sleep(TIME_DELAY);
    printf("ID Card: %s\n", result->idcard);
    Sleep(TIME_DELAY);
    printf("Contact Information: %s\n", result->contact_information);
    Sleep(TIME_DELAY);
    printf("Password: %s\n", result->password);
    Sleep(TIME_DELAY);
    printf("Registration_number: %s\n", result->Registration_number);
    Sleep(TIME_DELAY);
    printf("Fancy: %s\n", result->fancy);
    Sleep(TIME_DELAY);
    printf("Total mile: %ld(km)\n", result->Total);
    Sleep(TIME_DELAY);
    printf("Whole cost: %ld(km)\n", result->cost);
    printf("\n");
}


void passenger(void);
void passenger(void)
{
    system("cls");
    while (1)
    {
        int i;

        printf("                 @@@@@***************************欢迎使用乘客系统*******************************@@@@@\n");
        printf("                 ###                              1 乘 客 注 册                                   ###\n");
        printf("                 @@@                              2 查 看 乘 客 信 息                             @@@\n");       
        printf("                 #####!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!#####\n");

        printf("请选择: ");
        scanf("%d", &i);
        switch (i) {
        case 1:input_passenger(); break;
        case 2:PassengerSearch(); break;
        default:break;
        }
    }


}

