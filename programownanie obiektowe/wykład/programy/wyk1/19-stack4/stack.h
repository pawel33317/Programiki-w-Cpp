#define STACKSIZE 20

struct stack_handle
{
int top; /* pierwsze wolne miejsce na stosie */
int dane[STACKSIZE];
};

void push(struct stack_handle* s,int a);
int pop(struct stack_handle* s);
void clear(struct stack_handle* s);
void init(struct stack_handle* s);
void finalize(struct stack_handle* s);

