#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>   
#include <locale.h>    

struct node
{
    char inf[256];
    struct node* next;
};

struct node* head = NULL;

struct node* get_struct(void)
{
    struct node* p;

    p = (struct node*)malloc(sizeof(struct node));

    if (p == NULL)
    {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }

    printf("Введите название объекта: ");
    scanf("%255s", p->inf);

    p->next = NULL;

    return p;
}

void push(void)
{
    struct node* p = get_struct();

    p->next = head;
    head = p;

    printf("Элемент добавлен в стек\n");
}

void pop(void)
{
    struct node* temp;

    if (head == NULL)
    {
        printf("Стек пуст\n");
        return;
    }

    temp = head;
    head = head->next;

    printf("Удалённый элемент: %s\n", temp->inf);

    free(temp);
}

void review(void)
{
    struct node* current = head;

    if (head == NULL)
    {
        printf("Стек пуст\n");
        return;
    }

    while (current != NULL)
    {
        printf("%s\n", current->inf);
        current = current->next;
    }
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
}

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    int choice;

    do
    {
        printf("\n Стек \n");
        printf("1. Добавить элемент\n");
        printf("2. Удалить элемент\n");
        printf("3. Просмотреть стек\n");
        printf("0. Выход\n");
        printf("Ваш выбор: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            review();
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