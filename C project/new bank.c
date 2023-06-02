#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


void newAccount(void);
void accountcreated(void);
void login(void);
void loginsu(void);
void display(char username1[]);
void deposit();
void depositload(void);
void withdrawload(void);
void withdraw(void);
void logout(void);
void menu();
void updateAccount();
void updateload(void);
void transfer();
void viewAccount();
void administration();
void deleteAccount();
void viewstaff(void);
int validateEmail(char email[]);
int validatePassword(char password[]);
void reset_password();

struct Account{
	char username[50];
	int date, month, year;
	char pnumber[15];
	int age;
	char pannum[20];
	char fname[20];
	char lname[20];
	char fathname[20];
	char mothname[20];
	char address[50];
	char nati[20];
	char email[50];
	char occup[50];
	char password[50];
	int marital; 
	float amount;
	float deposit;
	float withdraw;
	char type[20];
	char account_number[50];
}acc, acc1;

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main(){
	gotoxy(40, 10);
	printf(".....WELCOME TO BANKING MANAGEMENT SYSTEM.....");
	gotoxy(50, 14);
	printf("Coded By AMISH MAN JOSHI (SEMESTER 1)");
	gotoxy(40, 12);
	printf("............C-PROGRAMMING PROJECT............");
	gotoxy(50, 16);
	printf("SUBMITTED TO ANIMESH REGMI");
	gotoxy(10, 25);
	printf("Press enter to continue.....");
    getch();
	menu();
}
void menu(){
	int choice;
	system("cls");
	printf("Welcome to Bank management system\n\n");
		gotoxy(20, 10);
	printf("1.... CREATE A BANK ACCOUNT");

	gotoxy(20, 12);
	printf("2.... ALREADY A USER? SIGN IN");
	gotoxy(20, 14);
	printf("3.... EXIT\n\n");

	printf("\n\nENTER YOUR CHOICE..");

	scanf("%d", &choice);

	switch (choice) {
	case 1:
		system("cls");
		printf("\n\n USERNAME 50 CHARACTERS MAX!!");
		printf("\n\n PASSWORD 50 CHARACTERS MAX!!");
		newAccount();
		break;

	case 2:
		login();
		break;

	case 3:
		printf("\nThank you for using the Banking System!\n");
		exit(0);
		break;

		getch();
	}
}

void newAccount(void)
{
	char password[20];
	int i;
	char ch;

	system("cls");
	printf("\n\n!!!!!CREATE ACCOUNT!!!!!");

	printf("\n\nFIRST NAME:  ");
	scanf("%s", &acc.fname);
	
	printf("\n\nLAST NAME:  ");
	scanf("%s", &acc.lname);
	
	printf("\n\nFATHER's NAME:  ");
	scanf("%s", &acc.fathname);

	printf("\n\nMOTHER's NAME:  ");
	scanf("%s", &acc.mothname);

	printf("\n\nADDRESS:  ");
	scanf("%s", &acc.address);
	
	printf("\n\nNATIONALITY:  ");  
    scanf("%s", &acc.nati); 

	printf("\n\nDATE OF BIRTH.. (yyyy/mm/dd)\n ");
	scanf(" %d  %d  %d", &acc.year, &acc.month, &acc.date);
	
	system("cls");
	
	printf("\n\nPAN NUMBER:  ");
	scanf("%s", acc.pannum);

	printf("\n\nPHONE NUMBER:   ");
	scanf("%s", acc.pnumber);
	
	mail:
	printf("\n\nEMAIL.. \t Email should contain an '@' and '.' in the 4rd last character\n");
	scanf("%s", acc.email);
	if (validateEmail(acc.email)== 0){
		printf("Invalid email try again\n Email should be at least 6 characters\n");
		getch();
		goto mail;
	}
    
    printf("\n\nOCCUPATION:  ");  
    scanf("%s", &acc.occup);
    
    printf("\n\nMARITAL STATUS.. (1.MARRIED \t2.UNMARRIED \t3.DIVORCE)\n");
    scanf("%d",&acc.marital);
    
    system("cls");
    
    printf("\n\nDEPOSIT AMOUNT: ");
    scanf("%f",&acc.amount);
	
	printf("\n\nUSERNAME:   ");
	scanf("%s", &acc.username);
    
    pass:
	printf("\n\nPASSWORD:  \t Password should contain atleast 1 uppercase, 1 special character and 3 numbers \n");
	scanf("%s",&acc.password);
	if(validatePassword(acc.password) == 0){
		printf("Password should be at least 8 characters \t try again\n");
		getch();
		goto pass;
	} 
	strcpy(acc.account_number,acc.username);
	strcat(acc.account_number,acc.pnumber);
	char fileName[30];
	strcmp(acc.password,password);
    strcpy(fileName, acc.username);
    strcat(fileName, ".dat");
    FILE* fp = fopen(fileName, "rb");
    if(fp != NULL) {
        printf("\nAccount with that username already exists!\n");
        fclose(fp);
        getch();
        menu();
    }
    fp = fopen(fileName, "wb");
    if(fp == NULL) {
        printf("\nUnable to create account!\n");
        getch();
        menu();
    }
	fwrite(&acc, sizeof(acc),1, fp);
	fclose(fp);
	
	accountcreated();
}

void accountcreated(void)
{
	int i;
	char ch;
	system("cls");
	printf(
		"PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
	for (i = 0; i < 200000000; i++) {
		i++;
		i--;
	}

	gotoxy(30, 10);

	printf("ACCOUNT CREATED SUCCESSFULLY....");
	gotoxy(0, 20);

	printf("Press enter to login");

	getch();
	login();
}

void login(void)
{
    system("cls");

    char username[50];
    char password[50];
    char ch;
    int i = 0;
    int j, k;

    gotoxy(34, 2);
    printf(" ACCOUNT LOGIN ");
    gotoxy(7, 5);
    printf("***********************************************"
        "********************************");

    gotoxy(35, 10);
    printf("==== LOG IN ====");
	
    gotoxy(35, 12);
    printf("USERNAME..");
    scanf("%s", username);

    gotoxy(35, 14);
    printf("PASSWORD..");
    while(ch!=13)
    {
        ch=getch();
        if(ch!=13 && ch!=8){
            putch('*');
            password[i] = ch;
            i++;
        }
    }
    password[i]   = '\0';
    
    if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0) {
        administration();
    }
    else {
        char fileName[30];
        strcpy(fileName, username);
        strcat(fileName, ".dat");
        FILE* fp = fopen(fileName, "rb");
        if(fp == NULL) {
            printf("\nAccount with that username does not exist!\n");
            getch();
            menu();
        }
        else {
            fread(&acc, sizeof(struct Account), 1, fp);
            fclose(fp);

            if(strcmp(username, acc.username)==0 && strcmp(password, acc.password)==0) {
                loginsu();
                display(acc.username);
            }
            else {
                printf("\n\n\n\t\t\aWarning!! \n\t   Incorrect Password");
                getch();
                login();
            }
        }
    }
}


void loginsu(void)
{
	int i;
	system("cls");
	printf("Fetching account details.....\n");
	for (i = 0; i < 20000; i++) {
		i++;
		i--;
	}

	gotoxy(30, 10);
	printf("LOGIN SUCCESSFUL....");
	gotoxy(0, 20);
	printf("Press enter to continue");
	getch();
}


void display(char username1[]){
system("cls");
	FILE* fp;
	int choice, i;
	char fileName[30];
    strcpy(fileName, acc.username);
    strcat(fileName, ".dat");
	fp = fopen(fileName, "rb");
	

	if (fp == NULL) {
		printf("error in opening file");
		getch();
		login();
	}

	while (fread(&acc, sizeof(acc),1, fp)) {
		if (strcmp(username1,acc.username)== 0) {
			
			gotoxy(30, 1);
			printf("WELCOME, %s %s\n",acc.fname,acc.lname);
			
			gotoxy(28, 2);
			printf("..........................");
			gotoxy(55, 4);
			printf("==== YOUR ACCOUNT INFO ====");
			gotoxy(55, 6);
    		printf("ACCOUNT NUMBER: %s",acc.account_number);
			gotoxy(55, 7);
			printf("***************************");
			gotoxy(55, 10);
			printf("NAME: %s %s", acc.fname, acc.lname);

			gotoxy(55, 12);
			printf("FATHER's NAME: %s %s",acc.fathname, acc.lname);

			gotoxy(55, 14);
			printf("MOTHER's NAME: %s %s",acc.mothname, acc.lname);

			gotoxy(55, 16);
			printf("PAN NUMBER: %s",acc.pannum);

			gotoxy(55, 18);
			printf("MOBILE NUMBER: %s",acc.pnumber);

			gotoxy(55, 20);
			printf("DATE OF BIRTH:  %d-%d-%d",
				acc.date, acc.month, acc.year);

			gotoxy(55, 22);
			printf("ADDRESS: %s", acc.address);

			gotoxy(55, 24);
			printf("OCCUPATION: %s",acc.occup);
			
		}
	}

	fclose(fp);

    gotoxy(0, 4);
	printf("Current Balance: $ %.2f",acc.amount);	
	gotoxy(0, 6);
	printf(" HOME ");
	gotoxy(0, 7);
	printf("******");
	gotoxy(0, 9);
	printf(" 1. DEPOSIT FUNDS");
	gotoxy(0, 11);
	printf(" 2. WITHDRAW FUNDS");
	gotoxy(0, 13);
	printf(" 3. TRANSFER FUNDS\n\n");
	gotoxy(0, 15);
	printf(" 4. VIEW TRANSACTIONS\n\n");
	gotoxy(0, 17);
	printf(" 5. UPDATE ACCOUNT INFORMATION\n\n");
	gotoxy(0, 19);
	printf(" 6. LOG OUT\n\n");

	printf(" ENTER YOUR CHOICES..");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		deposit();
		break;

	case 2:
		withdraw();
		break;

	case 3:
       transfer();
		break;
		
	case 4:	
	    viewAccount();
	    break;

    case 5:
    	updateAccount();
    	break;
    	
    	
	case 6:
		logout();
		system("cls");
		menu();
		break;
		
	default: {
        printf("\nInvalid choice!\n");
        break;
        }
	}
}

void deposit() {
	system("cls");
    float amount, amt;
    strcpy(acc.type,"Deposit");
    printf("\nEnter the amount to deposit: ");
    scanf("%f", &amount);
    amt = amount;
    if (amount <= 0) {
        printf("Error: Invalid amount\n");
        getch();
        deposit();
    }
    acc.amount += amount;
    
    char fileName[30],transaction[30];
    strcpy(fileName, acc.username);
    strcpy(transaction,acc.username);
    strcat(fileName, ".dat");
    strcat(transaction,"t.dat");
    
    FILE *fc = fopen(transaction, "a");
    fprintf(fc, "%s %s +%.2f\n", acc.username, acc.type, amt);
    fclose(fc);
    
    FILE* fp = fopen(fileName, "wb");
    if(fp == NULL) {
        printf("\nUnable to deposit money!\n");
        getch();
        display(acc.username);
    }
    fwrite(&acc, sizeof(struct Account), 1, fp);
    fclose(fp);
    depositload();
    display(acc.username);
}

void depositload(void)
{
	int i;
	system("cls");
	printf(
		"PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
	for (i = 0; i < 200000000; i++) {
		i++;
		i--;
	}
	gotoxy(30, 10);
	printf("\nDeposit successful! New balance: $%.2f\n", acc.amount);
	gotoxy(0, 20);
	printf("Press enter to continue");
	getch();
}


void withdraw() {
	system("cls");
	strcpy(acc.type,"Withdrawl");
    float amount, amt;
    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);
    amt = amount;
    
    if(amount > acc.amount) {
        printf("\nInsufficient balance! Please try again.\n");
        getch();
        withdraw();
    }
    acc.amount -= amount;
    char fileName[30],transaction[30];
    strcpy(fileName, acc.username);
    strcpy(transaction,acc.username);
    strcat(fileName, ".dat");
    strcat(transaction,"t.dat");
    
    FILE *fc = fopen(transaction, "a");
    fprintf(fc, "%s %s -%.2f\n", acc.username, acc.type, amt);
    fclose(fc);
    
    FILE* fp = fopen(fileName, "wb");
    if(fp == NULL) {
        printf("\nUnable to withdraw money!\n");
        getch();
        display(acc.username);
    }
    fwrite(&acc, sizeof(struct Account), 1, fp);
    fclose(fp);
    withdrawload();
    display(acc.username);
}
void withdrawload(void)
{
	int i;
	system("cls");
	printf(
		"PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
	for (i = 0; i < 200000000; i++) {
		i++;
		i--;
	}
	gotoxy(30, 10);
	printf("\nWithdrawal successful! New balance: $%.2f\n", acc.amount);
	gotoxy(0, 20);
	printf("Press enter to continue");
	getch();
}

void logout(void)
{
	int i, j;
	system("cls");
	printf("please wait, logging out");

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 25000000; j++) {
			i++;
			i--;
		}
		printf(".");
	}

	gotoxy(30, 10);
	printf("Sign out successfully..\n");

	gotoxy(0, 20);
	printf("press any key to continue..");

	getch();
}

void updateAccount() {
	system("cls");
	char password[30];
	gotoxy(0, 2);
    printf("\nUpdate Account\n");
    printf("***********************************************"
        "********************************");
    gotoxy(0, 6);
    printf("1. Change Name\n");
    gotoxy(0, 8);
    printf("2. Change Address\n");
    gotoxy(0, 10);
    printf("3. Change Phone Number\n");
    gotoxy(0, 12);
    printf("4. Change Password\n");
    gotoxy(0, 14);
    printf("5. Go back to menu\n");
    int choice;
    gotoxy(0, 16);
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            printf("Enter your new first name: ");
            scanf("%s",acc.fname);
            printf("Enter your new last name");
            scanf("%s", acc.lname);
            break;
        }
        case 2: {
            printf("Enter your new address: ");
            scanf("%s",acc.address);
            break;
        }
        case 3: {
            printf("Enter your new phone number: ");
            scanf("%s",acc.pnumber);
            break;
        }
        case 4: {
        	try:
        	system("cls");
            printf("Enter your new password: ");
            scanf("%s",&password);
		if (validatePassword(password) == 1){
		 strcpy(acc.password,password);
	    printf("\n New Password has been set!\n");
	}
		else{
			printf("Invalid password, Try again");
			getch();
			goto try;
		}
            break;
        }
        case 5: {
            display(acc.username);
        }
        default: {
            printf("\nInvalid choice!\n");
            getch();
            updateAccount();
        }
    }

    char fileName[30];
    strcpy(fileName, acc.username);
    strcat(fileName, ".dat");
    FILE* fp = fopen(fileName, "wb");
    fwrite(&acc, sizeof(struct Account), 1, fp);
    fclose(fp);
    updateload();
    display(acc.username);
    
}

void updateload(void)
{
	int i;
	system("cls");
	printf(
		"PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
	for (i = 0; i < 200000000; i++) {
		i++;
		i--;
	}
	gotoxy(30, 10);
	printf("\nAccount updated successfully!\n");
	gotoxy(0, 20);
	printf("Press enter to continue");
	getch();
}



void transfer() {
    system("cls");
    printf("\nTransfer Funds\n");
    printf("Enter username of recipient: ");
    char recipient[30], transaction[30], type[30];
    scanf("%s", recipient);

    char fileName[30];
    strcpy(fileName, recipient);
    strcat(fileName, ".dat");
    strcpy(transaction, recipient);
    strcat(transaction, "t.dat");
    FILE* fp = fopen(fileName, "rb");
    if(fp == NULL) {
        printf("\nRecipient account not found!\n");
        getch();
        transfer();
    }
    fread(&acc1, sizeof(struct Account), 1, fp);
    fclose(fp);
    printf("Enter amount to transfer: $");
    float amount, amt;
    scanf("%f", &amount);
    amt = amount;
    if(amount > acc.amount) {
        printf("\nInsufficient funds!\n");
        getch();
        menu();
    }
    acc.amount -= amount;
    acc1.amount += amount;

    // Store transaction history in sender's transaction file
    strcpy(type,"Transferred:");
    strcat(type,recipient);
    strcpy(acc.type,type);
    strcpy(fileName, acc.username);
    strcat(fileName, ".dat");
    strcpy(transaction, acc.username);
    strcat(transaction, "t.dat");
    fp = fopen(fileName, "wb");
    if(fp == NULL) {
        printf("\nUnable to transfer funds!\n");
        getch();
        login();
    }
    fwrite(&acc, sizeof(struct Account), 1, fp);
    fclose(fp);
    FILE *fc = fopen(transaction, "a");
    fprintf(fc, "%s %s \n-%.2f  \n", acc.username, acc.type, amt);
    fclose(fc);

    // Store transaction history in recipient's transaction file
    strcpy(type,"Received:");
    strcat(type,acc.username);
    strcpy(acc1.type,type);
    strcpy(fileName, recipient);
    strcat(fileName, ".dat");
    strcpy(transaction, recipient);
    strcat(transaction, "t.dat");
    fp = fopen(fileName, "wb");
    if(fp == NULL) {
        printf("\nUnable to transfer funds!\n");
        getch();
        login();
    }
    fwrite(&acc1, sizeof(struct Account), 1, fp);
    fclose(fp);
    FILE *ft = fopen(transaction, "a");
    fprintf(ft, "%s %s \n+%.2f  \n", recipient, acc1.type, amt);
    fclose(ft);

    int i;
    system("cls");
    printf(
        "PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
    for (i = 0; i < 200000000; i++) {
        i++;
        i--;
    }
    gotoxy(30, 10);
    printf("\n$%.2f transferred to %s successfully!\n", amount, recipient);
    gotoxy(0, 20);
    printf("Press enter to continue");
    getch();
    display(acc.username);
}


void viewAccount()
{
	system("cls");
    char transaction[30];
    strcpy(transaction, acc.username);
    strcat(transaction, "t.dat");
    FILE *fc = fopen(transaction, "rb");
    if(fc == NULL)
    {
        printf("Error opening file!");
        menu();
    }
    printf("\nTransaction History\n\n");
    printf("***********************************************"
        "********************************\n\n");
    printf(" Type | Current Balance\n\n");
    char temp[30];
    
    while (fgets(temp,sizeof(temp),fc)!=NULL){
    	fputs(temp,stdout);
    	fputs("\n",stdout);
	}
    printf("\n");
    fclose(fc);
	getch();
	system("cls");
	display(acc.username);
}


int validateEmail(char email[]) {
    int at = -1, dot = -1, len, i;
    char c;
    len = strlen(email);
    if (len < 6) { // email should be at least 6 characters
        return 0;
    }

    for (i = 0; i < len; i++) {   // Check for @ and .
      c = email[i];
      if (c == '@') {
        at = i;
      } else if (c == '.') {
        dot = i;
      }
    }
    
    // Check if the email contains both @ and .
    if (at > 0 && dot > at && len - dot > 3) {
      return 1;
    } else {
      return 0;
    }
}

int validatePassword(char password[]) {
    int numCount = 0, upperCount = 0, specialCount = 0,i;
    int len = strlen(password);
    if (len < 7) { // password should be at least 8 characters
        return 0;
    }
    for (i = 0; i < len; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            numCount++;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            upperCount++;
        } else if (password[i] == '@' || password[i] == '!' || password[i] == '#' || password[i] == '$' || password[i] == '.' || password[i] == '*'|| password[i] == '+'|| password[i] == '-'|| password[i] == '/'){
            specialCount++;
        }
    }
    return (numCount >= 3 && upperCount >= 1 && specialCount >= 1);
}

void administration(){
    char admin_username[20], admin_password[20],name[20];
    int choice, i;
    
    do {
    	system("cls");
    	gotoxy(0, 2);
        printf("\nAdministration Menu\n\n");
	    printf("***********************************************"
        "********************************");
        gotoxy(0, 8);
        printf("1. View all accounts\n");
        gotoxy(0, 10);
        printf("2. Reset user's password\n");
        gotoxy(0, 12);
        printf("3. Delete account\n");
        gotoxy(0, 14);
        printf("4. Logout\n");
        gotoxy(0, 16);
		printf("Enter choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewstaff();
                break;
            case 2:
                reset_password();
                break;
            case 3:
            	printf("Enter the username you want to delete: ");
            	scanf("%s",&name);
                deleteAccount(name);
                break;
            case 4:
                logout();
                menu();
                break;
            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
                getch();
                administration();
        }
    } while (choice != 4);
}

void deleteAccount(char username[]) {
	system("cls");
    char fileName[30], transaction[30];
    strcpy(fileName, username);
    strcpy(transaction, username);
    strcat(fileName, ".dat");
    strcat(transaction, "t.dat");

    if(remove(fileName) != 0 || remove(transaction) != 0) {
        printf("\nUnable to delete account!\n");
    }
    else {
        printf("\nAccount deleted successfully!\n");
    }
    getch();
    administration();
}

void viewstaff() {
	system("cls");
    printf("\nAll Accounts\n");

    // Set the file name pattern
    char fileNamePattern[30] = "*.dat";

    // Open the directory and read all file names that match the pattern
    WIN32_FIND_DATA fileData;
    HANDLE hFind = FindFirstFile(fileNamePattern, &fileData);

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            // Extract the username from the file name
            char* username = strtok(fileData.cFileName, ".");
            printf("- %s\n", username);
        } while (FindNextFile(hFind, &fileData) != 0);
        FindClose(hFind);
    }
    else {
        printf("No accounts found.\n");
    }
    printf("Press enter to continue");
    getch();
    administration();
}

void reset_password(){
	char password[30],username[30];
	try:
	system("cls");
	printf("Enter the your username of the account you want to reset: \n");
	scanf("%s",&username);
	char fileName[30];
    strcpy(fileName,username);
    strcat(fileName, ".dat");
    FILE* fp = fopen(fileName, "wb");
	if(fp == NULL) {
        printf("\n Account not found!\n");
        getch();
        reset_password();
    }
    
	printf("Enter new password: ");
	scanf("%s",&password);
	
	if (validatePassword(password) == 1){
	 strcpy(acc.password,password);
    fwrite(&acc, sizeof(struct Account), 1, fp);
    fclose(fp);
    printf("\n New Password has been set!\n");
	}
	else{
		printf("Invalid password, Try again");
		getch();
		goto try;
	}
	printf("Press enter to continue");
	getch();
}


