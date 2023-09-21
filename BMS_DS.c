//BMS
/* Nodes:
    # customer id : 11 digits
    # customer name
    # account number : 14 digits
    # type of account : current, savings, salary, fixed deposit
    # total balance
    # Loan taken or not: Yes or No, if Yes take loan details' input else skip
    # loan id : 3 digits
    # loan type : home loan, gold loan, vehicle loan, property loan
    # loan status : paid, unpaid
    # payment due date : if unpaid display, else say nil
*/

/* Queries:
    # Print cust and acc details of customers whose total balance is > 1,00,000
    # Print acc and loan details of customers who haven't cleared their loan
    # Print cust and acc details of customers whose acc type is savings
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i=0;

struct link
{
    char cID[12]; //customer id
    char cName[100]; //customer name
    char AcNo[15]; //account
    char TOA[60]; //type of account
    int TotBal; //total balance
    char l[4];
    char lID[4]; //loan id
    char TOL[25]; //type of loan
    char lstatus[10]; //loan status
    char DueDate[15]; //payment due date
    struct link *next;
};

struct link *start;

void create(struct link *);
void display(struct link *);
void G1L(struct link *);
void PendingL(struct link *);
void SavingsTOA(struct link *);

int main()
{
    int c;
    struct link *node;
    node = (struct link *)malloc(sizeof(struct link));
    start = node;
    if (node == NULL)
    {
        printf("No info\n");
        return 1;
    }
    else
    {
        printf("Press 1 to create/input data.\n");
        printf("Press 2 to print Customer and Account Details of the customers whose total balance is greater than 1 lakh.\n");
        printf("Press 3 to print Account and Loan details of the customers who haven't clear their loans.\n");
        printf("Press 4 to print Customer and Account details of the customers whose account type is Savings.\n");
        printf("Press 5 to display full details.\n");
        printf("Press 6 to exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        int ch = 1;
        while (ch)
        {
            switch (c)
            {
            case 1:
                create(start);
                break;
            case 2:
                G1L(start);
                break;
            case 3:
                PendingL(start);
                break;
            case 4:
                SavingsTOA(start);
                break;
            case 5:
                display(start);
                break;
            case 6:
                ch = 0;
                break;
            default:
                printf("Wrong choice. Try again.\n");
                break;
            }
            if (ch)
            {
                printf("Press 1 to create/input data.\n");
                printf("Press 2 to print Customer and Account Details of the customers whose total balance is greater than 1 lakh.\n");
                printf("Press 3 to print Account and Loan details of the customers who haven't clear their loans.\n");
                printf("Press 4 to print Customer and Account details of the customers whose account type is Savings.\n");
                printf("Press 5 to display full details.\n");
                printf("Press 6 to exit.\n");
                printf("Enter your choice: ");
                scanf("%d", &c);
            }
        }
    }
}

void create(struct link *node)
{
    char ch;
    printf("Enter ID of customer: ");
    fflush(stdin);
    scanf("%[^\n]s",node->cID);

    printf("Enter name of customer: ");
    fflush(stdin);
    scanf("%[^\n]s",node->cName);

    printf("Enter account number of customer: ");
    fflush(stdin);
    scanf("%[^\n]s",node->AcNo);

    printf("Enter type of account: ");
    fflush(stdin);
    scanf("%[^\n]s",node->TOA);

    printf("Enter total balance: ");
    scanf("%d",&node->TotBal);

    printf("Loan requested? Type 'Yes' or 'No': ");
    fflush(stdin);
    scanf("%[^\n]s",node->l);

    if(strcmp(node->l,"Yes")==0)
    {
        printf("Enter loan id of customer: ");
        fflush(stdin);
        scanf("%[^\n]s",node->lID);

        printf("Enter type of loan: ");
        fflush(stdin);
        scanf("%[^\n]s",node->TOL);

        printf("Enter status of loan (Paid or Unpaid): ");
        fflush(stdin);
        scanf("%[^\n]s",node->lstatus);
        if(strcmp(node->lstatus,"Unpaid")==0)
        {
            printf("Enter due date of loan payment: ");
            fflush(stdin);
            scanf("%[^\n]s",node->DueDate);
        }
    }
    node->next = NULL;

    printf("Enter 's' to stop: ");
    scanf(" %c", &ch);
    while (ch != 's')
    {
        node->next = (struct link *)malloc(sizeof(struct link));
        node = node->next;

        printf("Enter ID of customer: ");
        fflush(stdin);
        scanf("%[^\n]s",node->cID);

        printf("Enter name of customer: ");
        fflush(stdin);
        scanf("%[^\n]s",node->cName);

        printf("Enter account number of customer: ");
        fflush(stdin);
        scanf("%[^\n]s",node->AcNo);

        printf("Enter type of account: ");
        fflush(stdin);
        scanf("%[^\n]s",node->TOA);

        printf("Enter total balance: ");
        scanf("%d",&node->TotBal);

        printf("Loan requested? Type 'Yes' or 'No': ");
        fflush(stdin);
        scanf("%[^\n]s",node->l);

        if(strcmp(node->l,"Yes")==0)
    {
        printf("Enter loan id of customer: ");
        fflush(stdin);
        scanf("%[^\n]s",node->lID);

        printf("Enter type of loan: ");
        fflush(stdin);
        scanf("%[^\n]s",node->TOL);

        printf("Enter status of loan (Paid or Unpaid): ");
        fflush(stdin);
        scanf("%[^\n]s",node->lstatus);

        if(strcmp(node->lstatus,"Unpaid")==0)
        {
            printf("Enter due date of loan payment: ");
            fflush(stdin);
            scanf("%[^\n]s",node->DueDate);
        }
    }
        node->next = NULL;
        printf("Enter 's' to stop: ");
        scanf(" %c", &ch);
    }
}

void display(struct link *node)
{
    int i=1;
    while (node != NULL)
    {
        printf("\n===========================================\n");
        printf("\nCustomer Details %d.:\n",i);
        printf("Customer ID: %s\n",node->cID);
        printf("Customer's Name: %s\n",node->cName);

        printf("-------------------------------------");
        printf("\nAccount Details %d.:\n",i);
        printf("Account number: %s\n",node->AcNo);
        printf("Type of account: %s\n",node->TOA);
        printf("Total balance in the account: %d\n",node->TotBal);

        printf("-------------------------------------");
        printf("\nLoan Details %d.:\n",i);
        if(strcmp(node->l,"Yes")==0)
        {
            printf("Loan id of customer: %s\n",node->lID);
            printf("Type of loan taken: %s\n",node->TOL);
            printf("Status of loan: %s\n",node->lstatus);
            if(strcmp(node->lstatus,"Unpaid")==0)
        {
            printf("Due date of loan payment: %s\n",node->DueDate);
        }
        else
        {
            printf("Due date of loan payment: NIL\n");
        }
        }
        else
        {
            printf("No loan taken.\n");
        }

        node = node->next;
        i++;
    }
    printf("\n===========================================\n");
}

void G1L(struct link *node)
{
    int i=1;
    printf("\n------------TOTAL BALANCE > 1 LAKH--------------------\n");
    while (node != NULL)
    {
        if(node->TotBal>100000)
        {
            printf("%d. ",i);
            printf("\nCustomer Details:\n",i);
            printf("Customer ID: %s\n",node->cID);
            printf("Customer's Name: %s\n",node->cName);

            printf("-------------------------------------");
            printf("\nAccount Details:\n",i);
            printf("Account number: %s\n",node->AcNo);
            printf("Type of account: %s\n",node->TOA);
            printf("Total balance in the account: %d\n",node->TotBal);
            printf("\n****************************************\n");
        }
        node = node->next;
        i++;
    }
}

void PendingL(struct link *node)
{
    int i=1;
    printf("\n--------------CUSTOMERS WITH PENDING LOAN-------------\n");
    while (node != NULL)
    {
        if(strcmp(node->lstatus,"Unpaid")==0)
        {
            printf("%d. ",i);
            printf("\nAccount Details:\n",i);
            printf("Account number: %s\n",node->AcNo);
            printf("Type of account: %s\n",node->TOA);
            printf("Total balance in the account: %d\n",node->TotBal);

            printf("-------------------------------------");
            printf("\nLoan Details:\n",i);
            printf("Loan id of customer: %s\n",node->lID);
            printf("Type of loan taken: %s\n",node->TOL);
            printf("Status of loan: %s\n",node->lstatus);
            printf("Due date of loan payment: %s\n",node->DueDate);
            printf("\n****************************************\n");
        }
        node = node->next;
        i++;
    }
}

void SavingsTOA(struct link *node)
{
    int i=1;
    printf("\n------------SAVINGS ACCOUNT TYPE----------------\n");
    while(node != NULL)
    {
        if(strcmp(node->TOA,"Savings")==0)
        {
            printf("%d. ",i);
            printf("\nCustomer Details:\n",i);
            printf("Customer ID: %s\n",node->cID);
            printf("Customer's Name: %s\n",node->cName);

            printf("-------------------------------------");
            printf("\nAccount Details:\n",i);
            printf("Account number: %s\n",node->AcNo);
            printf("Type of account: %s\n",node->TOA);
            printf("Total balance in the account: %d\n",node->TotBal);
            printf("\n****************************************\n");
        }
        node = node->next;
        i++;
    }
}
