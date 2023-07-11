//Bank Management system
#include<stdio.h>
#include<string.h>
void BD();
void CD();
void TD();
void LD();
void n();
struct Bdetails
{
 char Bname[100];
 char Bbranch[100];
 char Badd[100];
 char IFSC[12];
}BDet;
struct CDetails
{
 char cID[12];//customer id
 char Accno[15];//account no.
 char Cname[100];//customer name
 char TOA[20];//type of account
 char cadd[100];//customer address
 char phno[10];//customer ph no.
 int TotBal;//total balance
}CDet[10];
struct TrDetails
{
 char cID[12];//copy from CDetails
 char Accno[15];//copy from Cdetails
 int Debamt; //debited amount
 int Credamt;//credited amt
 int TotBal;
}TDet[10];
struct LDetails
{
 char Accno[15];
 int Lamt;//loan amt
 int Ramt;//repaid amt
 int Damt;//due amt
 int roi;//rate of interest
}LDet[10];
struct NEFT
{
 char NEFTno[12];
 char Cname[100];
 int Debamt;
 int Credamt;
 char IFSC[12];
 char B2name[100];
}neft[10];
int main()
{
 BD();
 CD();
 TD();
 LD();
 n();
 return 0;
}
void BD()
{
 printf("Bank Details: \n");
 printf("\nEnter the name of the bank: ");
 scanf("\n");
 scanf("%[^\n]s",BDet.Bname);
 printf("Enter the branch of the bank: ");
 scanf("%s",BDet.Bbranch);
 printf("Enter the address of the bank: ");
 scanf("\n");
 scanf("%[^\n]s",BDet.Badd);
 printf("Enter the IFSC code of the bank: ");
 scanf("%s",BDet.IFSC);
 printf("\n");
 printf("-------------------------------------------------------------\n");
 printf("Name of the Bank: %s\n",BDet.Bname);
 printf("Branch of the Bank: %s\n",BDet.Bbranch);
 printf("Address of the Bank: %s\n",BDet.Badd);
 printf("IFSC code of the Bank: %s\n",BDet.IFSC);
 printf("-------------------------------------------------------------\n");
}
void CD(){
 printf("\nCustomer Details: \n");
 int i;
 for(i=1;i<=10;i++)
 {
 printf("\nEnter customer ID of %d: ",i);
 scanf("\n");
 scanf("%[^\n]s",CDet[i].cID);
 printf("Enter the account no. of %d: ",i);
 scanf("\n");
 scanf("%[^\n]s",CDet[i].Accno);
 printf("Name of customer %d: ",i);
 scanf("\n");
 scanf("%[^\n]s",CDet[i].Cname);
 printf("Enter the type of account of %d: ",i);
 scanf("\n");
 scanf("%[^\n]s",CDet[i].TOA);
 printf("Enter the address of %d: ",i);
 scanf("\n");
 scanf("%[^\n]s",CDet[i].cadd);
 printf("Enter phone number of %d: ",i);
 scanf("%s",CDet[i].phno);
 printf("Enter the total balance of %d: ",i);
 scanf("%d",&CDet[i].TotBal);
 printf("\n");
 }
 printf("\n-------------------------------------------------------------\n");
 for(i=1;i<=10;i++)
 {
 printf("%d. ",i);
 printf("Customer ID %d: %s\n",i,CDet[i].cID);
 printf("Account no. %d: %s\n",i,CDet[i].Accno);
 printf("Customer's name %d: %s\n",i,CDet[i].Cname);
 printf("Type of account %d: %s\n",i,CDet[i].TOA);
 printf("Address %d: %s\n",i,CDet[i].cadd);
 printf("Phone number %d: %s\n",i,CDet[i].phno);
 printf("Total balance %d: %d\n",i,CDet[i].TotBal);
 printf("\n");
 }
 printf("-------------------------------------------------------------\n");
}
void TD()
{
 printf("Transaction Details: \n");
 int i;
 for(i=1;i<=10;i++)
 {
 strcpy(TDet[i].cID,CDet[i].cID);
 strcpy(TDet[i].Accno,CDet[i].Accno);
 printf("\nEnter Debited amount of %d: ",i);
 scanf("%d",&TDet[i].Debamt);
 printf("Enter Credited amount of %d: ",i);
 scanf("%d",&TDet[i].Credamt);
 TDet[i].TotBal=CDet[i].TotBal-TDet[i].Debamt+TDet[i].Credamt;
 printf("\n");
 }
 printf("\n-------------------------------------------------------------\n");
 for(i=1;i<=10;i++)
 {
 printf("%d. ",i);
 printf("Customer ID %d: %s\n",i,TDet[i].cID);
 printf("Account no. %d: %s\n",i,TDet[i].Accno);
 printf("Debited amount %d: %d\n",i,TDet[i].Debamt);
 printf("Credited amount %d: %d\n",i,TDet[i].Credamt);
 printf("Current balance %d: %d\n",i,TDet[i].TotBal);
 printf("\n");
 }
 printf("-------------------------------------------------------------\n");
}
void LD()
{
 printf("Loan Details: \n");
 int i;
 float si;
 for(i=1;i<=10;i++)
 {
 int t,p;
 strcpy(LDet[i].Accno,CDet[i].Accno);
 printf("\nEnter the rate of interest of %d: ",i);
 scanf("%d",&LDet[i].roi);
 printf("Enter the principle amount of %d: ",i);
 scanf("%d",&p);
 printf("Enter the time period of %d: ",i);
 scanf("%d",&t);
 si = (p*t*LDet[i].roi)/100;
 LDet[i].Lamt = p + si;
 printf("Enter repaid amount of %d: ",i);
 scanf("%d",&LDet[i].Ramt);
 LDet[i].Damt = LDet[i].Lamt - LDet[i].Ramt;
 printf("\n");
 }
 printf("\n-------------------------------------------------------------\n");
 for(i=1;i<=10;i++)
 {
 printf("%d. ",i);
 printf("Account no. %d: %s\n",i,LDet[i].Accno);
 printf("Interest %d: %.2f\n",i,si);
 printf("Loan amount %d: %d\n",i,LDet[i].Lamt);
 printf("Repaid amount %d: %d\n",i,LDet[i].Ramt);
 printf("Due amount %d: %d\n",i,LDet[i].Damt);
 printf("\n");
 }
 printf("-------------------------------------------------------------\n");
}
void n()
{
 printf("NEFT Details: \n");
 int i;
 for(i=1;i<=10;i++)
 {
 printf("\nEnter NEFT number of %d: ",i);
 scanf("%s",neft[i].NEFTno);
 strcpy(neft[i].Cname,CDet[i].Cname);
 neft[i].Debamt=TDet[i].Debamt;
 neft[i].Credamt=TDet[i].Credamt;
 printf("Enter the name of the beneficiary bank of %d: ",i);
 scanf("\n%[^\n]s",neft[i].B2name);
 printf("Enter beneficiary bank's IFSC code of %d: ",i);
 scanf("%s",neft[i].IFSC);
 printf("\n");
 }
 printf("\n-------------------------------------------------------------\n");
 for(i=1;i<=10;i++)
 {
 printf("%d. ",i);
 printf("NEFT number %d: %s\n",i,neft[i].NEFTno);
 printf("Customer's name %d: %s\n",i,neft[i].Cname);
 printf("Debited amount %d: %d\n",i,neft[i].Debamt);
 printf("Credited amount %d: %d\n",i,neft[i].Credamt);
 printf("IFSC code %d: %s\n",i,neft[i].IFSC);
 printf("Name of the beneficiary bank %d: %s\n",i,neft[i].B2name);
 printf("\n");
 }
 printf("-------------------------------------------------------------\n");
}
