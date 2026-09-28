#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void divide (struct ListNode* origem, struct ListNode** esq, struct ListNode** dir) {
    struct ListNode* fast;
    struct ListNode* slow;
    
    slow = origem;
    fast = origem->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *esq = origem;
    *dir = slow->next;
    slow->next = NULL;
}

struct ListNode* merge (struct ListNode* lista1, struct ListNode* lista2) {
    struct ListNode* resultado = NULL;

    if (lista1 == NULL) return (lista2);
    if (lista2 == NULL) return (lista1);

    if (lista1->val <= lista2->val) {
        resultado = lista1;
        resultado->next = merge(lista1->next, lista2);
    } else {
        resultado = lista2;
        resultado->next = merge(lista1, lista2->next);
    }
    return (resultado);
}

void mergeSort (struct ListNode** lista) {
    struct ListNode* inicio = *lista;
    struct ListNode* esq;
    struct ListNode* dir;

    if (inicio == NULL || inicio->next == NULL) return;

    divide(inicio, &esq, &dir);

    mergeSort(&esq);
    mergeSort(&dir);

    *lista = merge(esq, dir);
}

struct ListNode * mergeTwoLists(struct ListNode * list1, struct ListNode * list2) {

    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct ListNode * nav = list1;

    while(nav->next != NULL) {
        nav = nav->next;
    }

    nav->next = list2;

    mergeSort(&list1);

    return list1;

}