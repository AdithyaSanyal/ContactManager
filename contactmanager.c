#include<stdio.h>
#include<string.h>
struct contact
{
    char name[100],lastname[100];
    long int phone;
    int length;
};
void main()
{
    FILE *fp;
    struct contact s1[100];
    int i,n=0,ch,choice,no,j;
    long int edittedno,tn;
    char t[100],search[100],delete[100],edit[100],editted[100];
    b:printf("\n\t-----WELCOME TO CONTACT MANAGER-----\t\n");
    printf("\tPRESS \n\t1)TO ADD CONTACT \n\t2)LIST ALL CONTACTS \n\t3)SEARCH A CONTACT \n\t4)EDIT A CONTACT \n\t5)DELETE A CONTACT \n\t6)EXIT \n");
    scanf("%d",&choice);
    if(choice==1)//TO ADD NEW CONTACT//
    {
    a:
    for(i=n;i<n+1;i++)
    {
       printf("Enter name and phone number of contact: ");
       scanf("%s %s %ld",&s1[i].name,&s1[i].lastname,&s1[i].phone);
    }
    
    printf("\nNAME\tPHONE-NUMBER\t\n");
    printf("\n------------------------\n");
    for(i=n;i<n+1;i++)
    {
        strcat(s1[i].name,s1[i].lastname);
        printf("\n%s\t%ld\t\n",s1[i].name,s1[i].phone);
        printf("THIS IS THE CONTACT WHICH IS SAVED");
    }
    printf("\nDo you want to add another contact?\nPress 1 if YES and 2 if NO\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        n=n+1;
        goto a;
    }
    else
    {
    printf("THANK YOU");
    goto b;
    }
    }
    
    if(choice==2)//TO LIST ALL CONTACTS//
    {
        for(i=1;i<=n+1;i++)
        {
            for(j=0;j<n+1-i;j++)
            {
            if(strcmp(s1[j+1].name,s1[j].name)<0)
            {
                tn=s1[j].phone;
                s1[j].phone=s1[j].phone;
                s1[j+1].phone=tn;
                strcpy(t,s1[j].name);
                strcpy(s1[j].name,s1[j+1].name);
                strcpy(s1[j+1].name,t);
            }
            }
        }
        printf("\n\tTHE LIST OF ALL CONTACTS ARE: \n");
        for(i=0;i<n+1;i++)
        {
            printf("\n%s\t%ld\t\n",s1[i].name,s1[i].phone);
        }
        goto b;
    }
    
    if(choice==3)//TO SEARCH A CONTACT
    {
        printf("Enter the name of the contact to be searched: ");
        scanf("%s",&search);
        for(i=0;i<n+1;i++)
        {
            if(strcmp(search,s1[i].name)==0)
            printf("\n%s\t%ld\n",s1[i].name,s1[i].phone);
            break;
            //else
            //printf("NO SUCH CONTACT EXISTS\nTRY AGAIN");
            
        }
        goto b;
    }
    
    if(choice==4)//TO EDIT A CONTACT
    {
        printf("\nEnter the contact which needs to be editted: ");
        scanf("%s",&edit);
        printf("\nEnter the editted contact: ");
        scanf("%s",&editted);
        printf("\nEnter the editted phone number: ");
        scanf("%ld",&edittedno);
        for(i=0;i<n+1;i++)
        {
            if(strcmp(edit,s1[i].name)==0)
            {
                strcpy(s1[i].name,editted);
                s1[i].phone=edittedno;
            }
        }
        goto b;
    }
    
    if(choice==5)//DELETE A CONTACT
    {
        printf("Enter the contact to be deleted: ");
        scanf("%s",&delete);
        for(i=0;i<n+1;i++)
        {
            if(strcmp(delete,s1[i].name)==0)
            {
                n--;
                for(i=0;i<n+1;i++)
                {
                strcpy(s1[i].name,s1[i+1].name);
                s1[i].phone=s1[i+1].phone;
                }
                    
            }
        }
        goto b;
    }
    
    if(choice==6)
    {
        printf("\n=============THANK YOU FOR USING CONTACT MANAGER============\n");
    }
}