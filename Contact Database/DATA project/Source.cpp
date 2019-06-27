#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct list
{
	int serial;
	char name[20], email[30];
	char number[15];
	struct list *next;
};

typedef struct list node;

void ShowMenu ()
{
	printf("\n\nWelcome To The Contact Database\n-- -----------------------------\n1 - Add a new contact\n2 - Delete contact\n3 - List all contacts\n4 - Modify contact\n5 - Find a contact by name\n-- -----------------------------\nQ - Save and quit\n\n\tYour choice: ");
}

void print(node *start)
{
	node *temp;
	printf("\n\n Acct#  Name\t\t\tPhone\t\tEmail\n------ ----------------------- ------------- -------------------\n");
	temp = start;
	while(temp != NULL)
	{
		fflush(stdin);
		printf("    %d:  ", temp->serial);
		fflush(stdin);
		printf("%s", temp->name);
		fflush(stdin);
		if(strlen(temp->name) >= 8 && strlen(temp->name) <= 15)
			printf("\t\t%s", temp->number);
		else if(strlen(temp->name) >= 16)
			printf("\t%s", temp->number);
		else
			printf("\t\t\t%s", temp->number);
		fflush(stdin);
		if(strlen(temp->number) < 8)
			printf("\t\t%s\n", temp->email);
		else
			printf("\t%s\n", temp->email);
		fflush(stdin);
		temp=temp->next;
	}
}

void main (void)
{
	node *start, *temp, *prev, *temp1;
	start=NULL;
	char choice;
	int i=1, key1=1, key2, key4;
	char key5[20];
	char upname, upnumber, upemail;

	while(i=1)
	{
		ShowMenu();
		fflush(stdin);
		scanf("%c", &choice);
		fflush(stdin);
		if(choice=='1')
		{
			printf("\nAdd a new contact");
			printf("\n\n\t\tContact number: \t%d", key1);
			if(start==NULL)
			{
				start=new node();
				start->next=NULL;
				printf("\n\t    Enter contact name: ");
				fflush(stdin);
				gets(start->name);
				fflush(stdin);
				fflush(stdin);
				printf("    Enter contact phone number: ");
				fflush(stdin);
				gets(start->number);
				fflush(stdin);
				printf("           Enter contact email: ");
				fflush(stdin);
				gets(start->email);
				fflush(stdin);
				start->serial = key1;
				prev=start;
			}
			else
			{
				temp=new node();
				temp->next=NULL;
				printf("\n\t    Enter contact name: ");
				fflush(stdin);
				gets(temp->name);
				fflush(stdin);
				printf("    Enter contact phone number: ");
				fflush(stdin);
				gets(temp->number);
				fflush(stdin);
				printf("           Enter contact email: ");
				fflush(stdin);
				gets(temp->email);
				fflush(stdin);
				temp->serial = key1;
				prev->next=temp;
				prev=temp;
			}
			printf("\ncontact added!");
			key1++;
		}

		else if(choice=='2')
		{
			printf("\nDelete a contact");
			if(start==NULL)
				printf("\n\nThere are no contacts to delete!");
			else
			{
				print(start);

				printf("\n\nEnter contact account number to delete: ");
				scanf("%d", &key2);

				if(start->serial == key2)
				{
					start = start->next;
					delete(temp);
					printf("\n\ncontact %d deleted!", key2);
				}
				else
				{
					temp=start;
					while(temp->next!=NULL && temp->next->serial != key2)
						temp=temp->next;
					if(temp->next==NULL)
						printf("Contact %d not found!", key2);
					else
					{
						if(temp->next->next == NULL)
						{
							temp1 = temp->next;
							temp->next = NULL;
							prev = temp;
							delete(temp1);
						}
						else
						{
							temp1 = temp->next;
							temp->next = temp1->next;
							delete(temp1);
						}


						printf("\n\ncontact %d deleted!", key2);
					}
				}
			}
		}

		else if(choice=='3')
		{
			printf("\nList all contacts");
			if(start==NULL)
				printf("\n\nThere are no contacts to display!");

			else
			{
				print(start);
			}

		}

		else if(choice=='4')
		{
			printf("\nModify a contact");
			if(start==NULL)
				printf("\n\nThere are no contacts to modify!");
			else
			{
				print(start);

				printf("Enter contact account number to modify or change: ");
				scanf("%d", &key4);
				
				temp = start;
				while(temp!=NULL && key4!= temp->serial)
					temp=temp->next;

				if(temp==NULL)
					printf("\nContact %d was not found!", key4);
				else
				{
					printf("\nContact %d:", key4);
					printf("\nName: %s", temp->name);
					printf("\nUpdate? (Y to update any other key to not) ");
					fflush(stdin);
					scanf("%c", &upname);
					fflush(stdin);
					if(upname == 'Y' || upname == 'y')
					{
						printf("\nEnter new value: ");
						fflush(stdin);
						scanf("%s", temp->name);
						fflush(stdin);
					}
					printf("\nPhone: %s", temp->number);
					printf("\nUpdate? (Y to update any other key to not) ");
					fflush(stdin);
					scanf("%c", &upnumber);
					fflush(stdin);
					if(upnumber == 'Y' || upnumber == 'y')
					{
						printf("\nEnter new value: ");
						fflush(stdin);
						scanf("%s", temp->number);
						fflush(stdin);
					}
					printf("\nEmail: %s", temp->email);
					printf("\nUpdate? (Y to update any other key to not) ");
					fflush(stdin);
					scanf("%c", &upemail);
					fflush(stdin);
					if(upemail == 'Y'|| upemail == 'y')
					{
						printf("\nEnter new value: ");
						fflush(stdin);
						scanf("%s", temp->email);
						fflush(stdin);
					}
				}
			}
		}

		else if(choice=='5')
		{
			int a=1;
			printf("\nFind a contact by name");
			if(start==NULL)
				printf("\n\nThere are no contacts to find!");
			else
			{
				printf("\n\nEnter contact name: ");
				fflush(stdin);
				scanf("%s", key5);
				fflush(stdin);
				temp = start;
				while(temp!=NULL)
				{
					if ((strcmp(key5,temp->name) == 0))
					{
						printf("\n\n Acct#  Name\t\t\tPhone\t\tEmail\n------ ----------------------- ------------- -------------------\n");
						fflush(stdin);
						printf("    %d:  ", temp->serial);
						fflush(stdin);
						printf("%s", temp->name);
						fflush(stdin);
						if(strlen(temp->name) >= 8 && strlen(temp->name) <= 15)
							printf("\t\t%s", temp->number);
						else if(strlen(temp->name) >= 16)
							printf("\t%s", temp->name);
						else
							printf("\t\t\t%s", temp->number);
						fflush(stdin);
						if(strlen(temp->number) < 8)
							printf("\t\t%s\n", temp->email);
						else
							printf("\t%s\n", temp->email);
						a=0;
					}
					temp=temp->next;
				}
				if(a==1)
				printf("Contact %s was not found!", key5);
			}
		}

		else if (choice == 'Q' || choice == 'q')
			exit(0);

		else
		{
			i=1;
		}
	}

	_getch();
}