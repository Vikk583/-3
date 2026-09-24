#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

struct node
{
    char inf[256];
    int priority;
    struct node* next;
};

struct node* head = NULL;
struct node* last = NULL;


struct node* get_struct(void)
{
    struct node* p = NULL;

    p = (struct node*)malloc(sizeof(struct node));

    if (p == NULL)
    {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }

    printf("Введите название объекта: ");
    scanf("%255s", p->inf);

    printf("Введите приоритет объекта: ");
    scanf("%d", &p->priority);

    p->next = NULL;

    return p;
}


void spstore(void)
{
    struct node* p = get_struct();
    struct node* current;

    if (head == NULL)
    {
        head = p;
        last = p;
        return;
    }

    if (p->priority > head->priority)
    {
        p->next = head;
        head = p;
        return;
    }

    if (p->priority <= last->priority)
    {
        last->next = p;
        last = p;
        return;
    }

    current = head;

    while (current->next != NULL &&
        current->next->priority >= p->priority)
    {
        current = current->next;
    }

    p->next = current->next;
    current->next = p;
}


void review(void)
{
    struct node* current = head;

    if (head == NULL)
    {
        printf("Список пуст\n");
        return;
    }

    printf("\nСодержимое списка:\n");

    while (current != NULL)
    {
        printf("Название: %s | Приоритет: %d\n",
            current->inf,
            current->priority);

        current = current->next;
    }
}


void del_first(void)
{
    struct node* temp;

    if (head == NULL)
    {
        printf("Список пуст\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);

    if (head == NULL)
    {
        last = NULL;
    }

    printf("Первый элемент удалён\n");
}


void clear_list(void)
{
    struct node* temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    last = NULL;
}


int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    int choice;

    do
    {
        printf("\nПриоритетная очередь\n");
        printf("1. Добавить элемент\n");
        printf("2. Просмотреть список\n");
        printf("3. Удалить первый элемент\n");
        printf("0. Выход\n");
        printf("Ваш выбор: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            spstore();
            break;

        case 2:
            review();
            break;

        case 3:
            del_first();
            break;

        case 0:
            clear_list();
            printf("Выход из программы\n");
            break;

        default:
            printf("Неверный выбор\n");
        }

    } while (choice != 0);

    return 0;
}