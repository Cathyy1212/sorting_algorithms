#include "sort.h"

/**
 * sw_nd - Swap two nodes in a listint_t doubly-linked list.
 * @h: A parameter pointer to the head of the doubly-linked list.
 * @nd1: A pointer to the first node of the doubly-linked list
 * @nd2: The node parameter
 */
void sw_nd(listint_t **h, listint_t **nd1, listint_t *nd2)
{
        (*nd1)->next = nd2->next;
        if (nd2->next != NULL)
                nd2->next->prev = *nd1;
        nd2->prev = (*nd1)->prev;
        nd2->next = *nd1;
        if ((*nd1)->prev != NULL)
                (*nd1)->prev->next = nd2;
        else
                *h = nd2;
        (*nd1)->prev = nd2;
        *nd1 = nd2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * @list: A pointer parameter to the head of a doubly-linked list
 * Description: Prints the list at the end
 */
void insertion_sort_list(listint_t **list)
{
        listint_t *a, *b, *k;

        if (list == NULL || *list == NULL || (*list)->next == NULL)
                return;

        for (a = (*list)->next; a != NULL; a = k)
        {
                k = a->next;
                b = a->prev;
                while (b != NULL && a->n < b->n)
                {
                        sw_nd(list, &b, a);
                        print_list((const listint_t *)*list);
                }
        }
}
