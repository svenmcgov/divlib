#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};

struct digit *create_digit(int);
struct digit *append(struct digit *, struct digit *);
int pop(struct digit *);
void print_num(struct digit *);
void free_num(struct digit *);
struct digit *read_num(void);
struct digit *copy(struct digit *);
int last_digit(struct digit *start);

/* div checks -- return 1 if true, 0 if false */
int is_even(struct digit *);
int div_by_3(struct digit *);
int div_by_4(struct digit *);
int div_by_5(struct digit *);
int div_by_6(struct digit *);
int div_by_7(struct digit *);
int div_by_8(struct digit *);
int div_by_9(struct digit *);
int div_by_10(struct digit *);

int main(void) {
    struct digit *start, *copy;
    start = read_num();
    printf("The number ");
    print_num(start);
    if (div_by_6(start))
        printf("is divisible by 6.\n");
    else
        printf("is not divisible by 6.\n");
    free_num(start);

    int i = 0;
    for(i = 0; i < 5; i++){
      start = read_num();
      printf("Your number is: ");
      print_num(start);

      print_num(start);
    }

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
    return start;
}

struct digit *copy(struct digit *start){
  struct digit *copy_start = NULL;
  struct digit *copy_end = NULL;
  struct digit *new_digit = NULL;

  if(start != NULL){
    copy_start = create_digit(start->num);
    start = start->next;
  }else{
    return NULL;
  }

  new_digit = copy_start;
  copy_end = copy_start;

  while(start != NULL){
    new_digit = create_digit(start->num);
    copy_end = append(copy_end, new_digit);
    start = start->next;
  }

  return copy_start;
}

int last_digit(struct digit *start){
  while(start->next != NULL){
    start = start->next;
  }
  return start->num;
}

int pop(struct digit *start){
  if(start == NULL){
    return -1;
  }

  if(start->next == NULL){
    int last = start->num;
    free(start);
    return last;
  }

  while(start->next->next != NULL){
    start = start->next;
  }
  int last = start->next->num;
  free(start->next);
  start->next = NULL;
  return last;
}

int is_even(struct digit *start){
  while(start->next != NULL){
    start = start->next;
  }
  // printf("%d\n", start->num);
  if(start->num == 0 || start->num == 2 || start->num == 4 ||
     start->num == 6 || start->num == 8){
       return 1;
  }
  return 0;
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

int div_by_4(struct digit *start){
  while(start->next->next != NULL){
    start = start->next;
  }
  int last_two = start->num * 10 + start->next->num;
  if(last_two % 4 == 0)
    return 1;
  // printf("Last two: %d\n", last_two);

  return 0;
}

int div_by_5(struct digit *start){
  while(start->next != NULL){
    start = start->next;
  }

  if(start->num == 5 || start->num == 0)
    return 1;

  return 0;
}

int div_by_6(struct digit *start){
  if(is_even(start) && div_by_3(start))
    return 1;
  return 0;
}

int div_by_7(struct digit *start){
  int last = pop(start);

  return 0;
}
