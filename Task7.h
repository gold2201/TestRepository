char* violation_type(void);
void remove_Transfer(void);
void save_Data(void);

struct Violation 
{
    char violationType[50];
    int violationsAmount;
};

struct Car
{
    char regNumber[5];
    char* model;
    struct Violation* violations;
    int numViolations;
};

typedef enum ViolationType {
    violation1,
    violation2,
    violation3,
    violation4,
};

int add_Car(int numCars,  struct Car** cars)
{
    system("cls");

    struct Car* new_car = (struct Car*)malloc(sizeof(struct Car));

    int choice = 0;
    char buf [128];

    printf("Введите регистрационный номер: ");
    scanf("%s", new_car->regNumber);  
    printf("Введите модель автомобиля: ");
    gets(buf);    
    gets(buf);    
    new_car->model = (char*)malloc(strlen(buf) + 1);
    strcpy(new_car->model, buf);
    printf("Введите количество штрафов: ");
    scanf("%d", &new_car->numViolations);

    new_car->violations = (struct Violation*)malloc(new_car->numViolations * sizeof(struct Violation));

    for (int i = 0; i < new_car->numViolations; i++) 
    {
        printf("Выберете нарушение для добавления: ");

        char* bufV = violation_type(violation_Choice());
        strcpy(new_car->violations[i].violationType, bufV);
        printf("Введите сумму штрафа: ");
        scanf("%d", &new_car->violations[i].violationsAmount);
    }

    cars[numCars++] = new_car;
    save_Data(numCars, cars);

    printf("Автомобиль успешно добавлен.\n");
    return numCars;
}

void print_Car(int numCars, struct Car** cars)
{
    system("cls");
   
    printf("Список автомобилей:\n\n");
    for (int i = 0; i < numCars; i++)
    {
        printf("Индекс - %d |Регистрационный номер: %s, Модель: %s\nШтрафы:\n", (i+1),cars[i]->regNumber, cars[i]->model);
        for (int j = 0; j < cars[i]->numViolations; j++) 
        {
            printf("- Тип: %s, Сумма: %d\n", cars[i]->violations[j].violationType, cars[i]->violations[j].violationsAmount);
        }
        printf("\n");
    }
    printf("\nДля продолжения нажмите любую клавишу...");

    _getch();
}

void violation_Sorted(int numCars, struct Car** cars)
{
    struct ViolationCount
    {
        char type[50];
        int count;
    } violationCounts[100];

    system("cls");
    int violationCount = 0;

    for (int i = 0; i < numCars; i++)
    {
        for (int j = 0; j < cars[i]->numViolations; j++)
        {
            int existingIndex = -1;
            for (int k = 0; k < violationCount; k++) 
            {
                if (strcmp(violationCounts[k].type, cars[i]->violations[j].violationType) == 0) 
                {
                    existingIndex = k;
                    break;
                }
            }
            if (existingIndex == -1) 
            {
                strcpy(violationCounts[violationCount].type, cars[i]->violations[j].violationType);
                violationCounts[violationCount].count = 1;
                violationCount++;
            }
            else 
                violationCounts[existingIndex].count++;
        }
    }

    for (int i = 0; i < violationCount - 1; i++)
    {
        for (int j = 0; j < violationCount - i - 1; j++)
        {
            if (violationCounts[j].count < violationCounts[j + 1].count)
            {
                struct ViolationCount temp = violationCounts[j];
                violationCounts[j] = violationCounts[j + 1];
                violationCounts[j + 1] = temp;
            }
        }
    }

        for (int i = 0; i < violationCount; i++)
            printf("%s: %d\n", violationCounts[i].type, violationCounts[i].count);

     printf("\nДля продолжения нажмите любую клавишу...");

    _getch();
}

int remove(int index, int numCars, struct Car** cars)
{
    if (index >= 0 && index < numCars)
    {
        free(cars[index]->violations);
        free(cars[index]);

        for (int i = index; i < numCars - 1; i++) 
        {
            cars[i] = cars[i + 1];
        }

        numCars--;
        printf("Автомобиль успешно удален.\n");
    }
    else
        printf("Индекс выходит за пределы массива.\n");

    return numCars;
}

int underlimit_Remove(int numCars, struct Car** cars)
{
    system("cls");

    int index = numCars, totalFine = 0, limit = 0;

    printf("Введите сумму оплаты штрафов, автомобиля превышающие которую, будут удалены: ");
    scanf("%d", &limit);

    for (int i = 0; i < numCars; i++)
    {
        totalFine = 0;
        for (int j = 0; j < cars[i]->numViolations; j++)
        {
            totalFine += cars[i]->violations[j].violationsAmount;
        }
        if (totalFine > limit)
        {
            numCars = remove(i, numCars, cars);
            i--;
        }
    }

    save_Data(numCars, cars);
    printf("Удаление прошло успешно. Для продолжения нажмите любую клавишу...");
    _getch();
    return numCars;
}

int task7() 
{ 
    int choice = 1, numCars = 0;
    struct Car* cars[100];
    numCars = load_Data(numCars, cars);

    while (choice != 0)
    {
        system("cls");
        printf("(Для выхода введите 0)\nВвод информации о машинах------------------------1\nПоказать всю введённую информацию----------------2\nОтсортировать нарушения--------------------------3\nУдалить машину из базы---------------------------4\nУдаление всех машин с превышенной суммой штрафа--5\nВаш выбор: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            while (1)
            {
                numCars = add_Car(numCars, cars);
                printf("Продолжить внесение информации | 1 - Да 2 - Нет|\nВыбор: ");
                scanf("%d", &choice);
                if (choice == 2)
                    break;
            }
            break;
        case 2:
            print_Car(numCars, cars);
             break;
        case 3:
            violation_Sorted(numCars, cars);
             break;
        case 4:
            numCars = remove_Car(numCars, cars);
             break;
        case 5:
            numCars = underlimit_Remove(500, numCars, cars);
             break;
        default:
            choice = 0;
            break;
        }
    }
    return 0;
}

int violation_Choice()
{
    int choice = 0;
    printf("\nПревышение Скорости-------1\n");
    printf("Непристёгнутый ремень-----2\n");
    printf("Просроченная страховка----3\n");
    printf("Алкогольное опьянение-----4\n***\nВаш выбор: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        return 1;
        break;

    case 2:
        return 2;
        break;

    case 3:
        return 3;
        break;

    case 4:
        return 4;
        break;

    default:
        printf("Ошибка! Под таким номер нарушений нет");
        return 0;
        break;
    }
}

char* violation_type(int type)
{
    char violationReturn[32];
    char* violations[] =
    {
        "Превышение Скорости","Непристёгнутый Ремень","Просроченная Страховка", "Алкогольное опьянение"
    };
    switch (type)
    {
    case 1:
        strcpy(violationReturn, violations[violation1]);
        return violationReturn;
        break;
    case 2:
        strcpy(violationReturn, violations[violation2]);
        return violationReturn;
        break;
    case 3:    
        strcpy(violationReturn, violations[violation3]);
        return violationReturn;
        break;
    case 4:
        strcpy(violationReturn, violations[violation4]);
        return violationReturn;
        break;
    }
}

void save_Data(int numCars, struct Car** cars) {
    FILE* file = fopen("car_data.txt", "w+");

    for (int i = 0; i < numCars; i++)
    {
        fprintf(file, "%s\n%s\n%d\n", cars[i]->regNumber, cars[i]->model, cars[i]->numViolations);
        for (int j = 0; j < cars[i]->numViolations; j++)
        {
            fprintf(file, "%s\n%d\n", cars[i]->violations[j].violationType, cars[i]->violations[j].violationsAmount);
        }
        if ((i + 1) == numCars)
        {
            fprintf(file, "\0");
            break;
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

int load_Data(int numCars, struct Car** cars) {
    FILE* file = fopen("car_data.txt", "r");

    while (1)
    {
        struct Car* new_car = (struct Car*)malloc(sizeof(struct Car));
        char buf[128], n[2];

        if(fscanf(file, "%s", new_car->regNumber) != 1)
            break;
        fgets(buf, 129, file);
        fgets(buf, 129, file);
        remove_Transfer(buf, strlen(buf));

        new_car->model = (char*)malloc(strlen(buf) + 1);
        strcpy(new_car->model, buf);
        fscanf(file, "%d", &new_car->numViolations);

        new_car->violations = (struct Violation*)malloc(new_car->numViolations * sizeof(struct Violation));

        for (int i = 0; i < new_car->numViolations; i++)
        {
            fgets(buf, 129, file);
            fgets(buf, 129, file);
            remove_Transfer(buf, strlen(buf));

            strcpy(new_car->violations[i].violationType, buf);
            fscanf(file, "%d", &new_car->violations[i].violationsAmount);
        }

        cars[numCars++] = new_car;
    }

    fclose(file);
    return numCars;
}

void remove_Transfer(char buf[], int size)
{
    int r = 0;
    r += size - 1;
    buf[r] = '\0';
}

int remove_Car(int numCars, struct Car** cars)
{
    system("cls");

    int index = 0;

    printf("Введите индекс машины: ");
    scanf("%d", &index);
    index--;

    if (index >= 0 && index < numCars)
    {
        numCars = remove(index, numCars, cars);
        printf("Автомобиль успешно удален.\n");
    }
    else
        printf("Индекс выходит за пределы массива.\n");
    

    save_Data(numCars, cars);
    printf("\nДля продолжения нажмите любую клавишу...");
    return numCars;
    _getch();
}
