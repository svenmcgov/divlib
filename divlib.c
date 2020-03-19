#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};
struct digit *create_digit(int dig);
struct digit * append(struct digit * end, struct digit * newDigptr);
void print_num(struct digit *start);
void free_num(struct digit *start);
struct digit *read_num(void);
int div_by_3(struct digit *start);

int main(void) {
    struct digit *start;
    start = read_num();
    printf("The number ");
    print_num(start);
    if (div_by_3(start))
        printf("is divisible by 3.\n");
    else
        printf("is not divisible by 3.\n");
    free_num(start);
    return 0;
}

struct digit *create_digit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}

void print_num(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void free_num(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

struct digit *read_num(void) {
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c != '\n') {
        d = c-'0';
        newptr = create_digit(d);
        if (start == NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return(start);
}

int div_by_3(struct digit *start){
    int sum = 0;
    while(start != NULL){
        sum += start->num;
        start = start->next;
    }
    if(sum % 3 == 0){
        return 1;
    }
    return 0;
}
