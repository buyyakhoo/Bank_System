 /* ดูเงิน, ฝากเงิน , ถอนเงิน , สกุลเงิน , เวลาผ่านไป (ปี)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "banksys.h"

int main(void) {
  char name[99], legitname[99] = "comcamp33"; //ประกาศตัวแปรประเภท char
  double money, interest, year, amount; //ประกาศตัวแปรประเภท double
  int loop = 1 , withdraw, deposit, account_no, choice ,Choice; //ประกาศตัวแปรประเภท int
  int exit = 0; //ประกาศตัวแปรประเภท int

  FILE *file = fopen("memo.txt" , "r"); //เปิดไฟล์ memo.txt เป็นแบบ read
  fscanf(file ,"%lf" , &money); //ดึงข้อมูลเงินของ money จากไฟล์ memo.txt
  fclose(file); //ปิดไฟล์ memo.txt
  
  printf("Enter your name: ");
  scanf("%s", name); //กรอกชื่อบัญชีผู้ใช้
  printf("Enter your account number (6 letters): "); 
  scanf("%d", &account_no); // กรอกเลขบัญชี
  
  while ((account_no != 165936 || strcmp(name, legitname)!=0) && loop <= 3) { //จะทำการเช็ค 3 ครั้งถ้ายังใส่ชื่อและหมายเลขบัญชีไม่ถูกต้อง
    system("@cls||clear"); //clear หน้าจอ
    printf("\n\n_____________Please enter your password again._____________\n\n");
    printf("Please enter your name and valid account number\n");
    
    printf("Enter your name: ");
    scanf("%s", name); //กรอกชื่อบัญชีผู้ใช้
  
    printf("Enter your account number (6 letters): "); 
    scanf("%d", &account_no);//กรอกเลขบัญชี 
    loop += 1; //loop + 1
  }
  
  while (account_no == 165936 && strcmp(name, legitname) == 0 && exit != 1) { //ถ้าหมายเลขและชื่อถูกต้อง จะทำการเข้าในส่วนของระบบ atm จนกว่าค่า exit เป็น 1 นั่นคือกด quit หมายเลข 5
    loop = 1;
    Choice = 0;

    //system("@cls||clear");
    printf("\nBalance: %.2lf\n", money); //
    printf("\n\n_______________#Welcome to ComCamp33 Mini ATM#_______________\n\n");
    printf("1. Withdraw Cash\n"); //ถอนเงิน
    printf("2. Deposit Cash\n"); //ฝากเงิน
    printf("3. Exchange the currency\n"); //แลกเปลี่ยนสกุลเงิน
    printf("4. Future interest (year) \n"); //ดอกเบี้ยในอนาคต
    printf("5. Quit\n"); //ยกเลิก 
    printf("________________________________________________________\n");
	  printf("\n\n________________________________________________________\n\n\n");

		printf("Enter your choice: "); //เลือกรายการที่จะทำ
    scanf("%d", &choice);//เลือกรายการที่จะทำ
      
    if (choice == 1) {
      system("@cls||clear");
      printf("\nBalance: %.2lf\n", money);
      printf("\n\n___________________Withdraw___________________\n");
      printf("\n Enter the amount to withdraw: "); 
			scanf("%d", &withdraw); //กรอกจำนวนเงินที่ถอน
      withDraw(&withdraw, &money);     
      printf("\n\n________________________________________________________\n\n");
    }

    else if (choice == 2) {
      system("@cls||clear");
      printf("\nBalance: %.2lf\n", money);
      printf("\n\n___________________Deposit______________________________\n\n");
      printf("\n Enter the amount to deposit: ");
			scanf("%d", &deposit); //ระบุจำนวนเงินฝาก
      Deposit(&deposit, &money);
      printf("\n\n________________________________________________________\n\n");
    }
      
    else if (choice == 3) {
      system("@cls||clear");
      printf("\nBalance: %.2lf\n", money);
      printf("\n\n___________________Exchange the currency___________________\n");
      printf("Following are the Choices:"); //เลือกสกุลเงินที่อยากแปลง
      printf("\nEnter 1: Rupee");
      printf("\nEnter 2: Dollar");
      printf("\nEnter 3: Pound");
      printf("\nEnter 4: Euro");
      printf("\nEnter 5: Yuan");
      printf("\nEnter 6: Yen");
 
      printf("\nEnter your choice: ");
      scanf("%d", &Choice);
      amount = money;
      bahttocur(amount, Choice);
      printf("\n\n________________________________________________________\n\n");
      
    }
      
    else if (choice == 4) {
      system("@cls||clear");
      printf("\nBalance: %.2lf\n", money);
      printf("\n\n___________________Future interest___________________\n");
      printf("Enter year: ");
      scanf("%lf", &year);//ระบุจำนวนปีในอนาคตเพื่อคิดดอกเบี้ย
      interest = money * (pow(1+0.0025 , year));
      printf("\nFuture interest is %.2lf Baht(interest rate 0.25%%)\n", interest);
      printf("\n\n________________________________________________________\n\n");
    }
      
    else if (choice == 5) {
      system("@cls||clear");
      exit = 1;
    }
    
  }
  if (loop > 3) {
    system("@cls||clear");
    printf("Your bank account is locked. \n");
  }

  if (account_no == 165936 && !strcmp(name, legitname) && exit == 1){
    system("@cls||clear");
    FILE *file = fopen("memo.txt" , "w");
    fprintf(file ,"%lf" , money);
    fclose(file);   
    printf("Thank you for using Mini ATM.\n");
  }//จบการทำงาน

  return 0;
}