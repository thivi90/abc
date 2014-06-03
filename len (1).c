
node_ptr build_list();
void traverse_list(node_ptr head);
int remove_item(int accountNo, node_ptr head);
node_ptr add_item(int accountNo, float balance, node_ptr head );
int length(node_ptr head);

int main()
{
node_ptr accounts = build_list();
traverse_list(accounts);
int value;
float balan;
printf("Enter remove accountNo :");
scanf("%d",&value);
int val = remove_item(value,accounts);
traverse_list(accounts);
printf("Enter add accountNo :");
scanf("%d",&value);
printf("Enter add balance :");
scanf("%f",&balan);
accounts = add_item(value,balan,accounts);
traverse_list(accounts);
printf("No of nodes in the list is :%d\n",length(accounts));
}

node_ptr build_list()
{
node_ptr head;
node_ptr current;
head =malloc(sizeof(Node));

node_ptr tmp = malloc(sizeof(Node));
current = head;
do
{
printf("Enter new account no(if End list press 0) :");
scanf("%d",&current->rec.accountNum);
printf("Enter balance :");
scanf("%f",&current->rec.balance);
tmp = current;
current = malloc(sizeof(Node));
tmp -> next = current;
}
while(tmp ->rec. accountNum != 0);
free(current);
if(head->rec.accountNum == 0)
{
printf("Empty list\n");
exit(0);
}
return head;
}

void traverse_list(node_ptr head)
{
node_ptr current = malloc(sizeof(Node));
current = head;
while(current != NULL && current ->rec.balance !=0)
{
printf("The account account no : %d \n",current ->rec. accountNum);
printf("The account balance    : %.2f \n",current ->rec. balance);
current = current -> next;
}
}

int remove_item(int accountNo,node_ptr head)
{
node_ptr temp,current;
current = head;
temp = NULL;
while (current -> next != NULL)
{
if(current -> rec.accountNum == accountNo)
{
if (temp == NULL)
{
head = current->next;
free(current);
return 1;
}
else
{
temp -> next = current -> next;
free(current);
return 1;
} 
}     
temp = current;
current = current -> next;
}	
printf("Account is not here");
return 0;
}


node_ptr add_item(int accountNo, float balance, node_ptr head )
{
node_ptr newnode = malloc(sizeof(Node));
newnode ->rec. accountNum = accountNo;
newnode ->rec. balance = balance; 
newnode -> next = head;
head =newnode;
return head;
}


int length(node_ptr head)
{
node_ptr current = head;
int count = 0;
while(current != NULL && current ->rec. accountNum !=0)
{
count ++;
current = current -> next;
}
return count;
}

