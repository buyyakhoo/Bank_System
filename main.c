// replit
/* ดูเงิน, ฝากเงิน , ถอนเงิน , สกุลเงิน , เวลาผ่านไป (ปี)*/
#include "banksys.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char name[99], legitname[99] = "comcamp33"; //ประกาศตัวแปรประเภท char
  double money, interest, year, amount; //ประกาศตัวแปรประเภท double
  int loop = 1, withdraw, deposit, account_no, choice,
      Choice;   //ประกาศตัวแปรประเภท int
  int exit = 0, q=0; //; //ประกาศตัวแปรประเภท int

  
  FILE *file = fopen("memo.txt", "r"); //เปิดไฟล์ memo.txt เป็นแบบ read
  fscanf(file, "%lf", &money); //ดึงข้อมูลเงินของ money จากไฟล์ memo.txt
  fclose(file); //ปิดไฟล์ memo.txt
  
  printf("Enter your name: ");
  scanf("%s", name); //กรอกชื่อบัญชีผู้ใช้
  printf("Enter your account number (6 letters): ");
  scanf("%d", &account_no); // กรอกเลขบัญชี

  while ((account_no != 165936 || strcmp(name, legitname) != 0) && loop <= 3) {
    //จะทำการเช็ค 3 ครั้งถ้ายังใส่ชื่อและหมายเลขบัญชีไม่ถูกต้อง
    system("@cls||clear"); // clear หน้าจอ
    printf(
        "\n\n_____________Please enter your password again._____________\n\n");
    printf("Please enter your name and valid account number\n");

    printf("Enter your name: ");
    scanf("%s", name); //กรอกชื่อบัญชีผู้ใช้

    printf("Enter your account number (6 letters): ");
    scanf("%d", &account_no); //กรอกเลขบัญชี
    loop += 1;                // loop + 1
  }

  while (account_no == 165936 && strcmp(name, legitname) == 0 && exit != 1) {
    //ถ้าหมายเลขและชื่อถูกต้อง จะทำการเข้าในส่วนของระบบ atm จนกว่าค่า exit เป็น 1 นั่นคือกด
    // quit หมายเลข 5

    Choice = 0;
    system("@cls||clear"); //clear  หน้าจอ
    FILE *file = fopen("memo.txt", "w");
    fprintf(file, "%lf", money); //อัพเดทเงินเก็บไว้บน memo.txt
    fclose(file);
    
    printf("\n\n_______________#Welcome to ComCamp33 Mini "
           "ATM#_______________\n\n");
    printf("\nBalance: %.2lf\n", money); //แสดงจำนวนเงินที่เหลือ
    printf("1. Withdraw Cash\n"); //ถอนเงิน
    printf("2. Deposit Cash\n");  //ฝากเงิน
    printf("3. Compare the currency\n"); //เปรียบเทียบสกุลเงิน
    printf("4. Future interest (year) \n"); //ดอกเบี้ยในอนาคต
    printf("5. Quit\n");                    //ยกเลิก
    printf("________________________________________________________\n");
    printf(
        "\n\n________________________________________________________\n\n\n");

    printf("Enter your choice: "); //เลือกรายการที่จะทำ
    scanf("%d", &choice); //เลือกรายการที่จะทำ

    if (choice == 1 ) {
      while (q==0) {
        system("@cls||clear");               // clear หน้าจอ
        printf("\n\n___________________Withdraw___________________\n");
        printf("\nBalance: %.2lf\n", money); //แสดงจำนวนเงิน
        printf("\n Enter the amount to withdraw: ");
        scanf("%d", &withdraw); //กรอกจำนวนเงินที่ถอน
        withDraw(&withdraw, &money); //ดำเนินการถอนเงิน
        printf("\n\n________________________________________________________\n\n");
        printf("Do you want to quit withdraw? (1:yes, 0:no): ");
        scanf("%d", &q); //ให้เลือกว่าจะออกจากหน้าถอนเงินหรือไม่
      }
      q = 0; 
    }

    else if (choice == 2) {
      while (q==0) { 
        system("@cls||clear"); //clear  หน้าจอ
        
        printf(
            "\n\n___________________Deposit______________________________\n\n");
        printf("\nBalance: %.2lf\n", money); //แสดงจำนวนเงิน
        printf("\n Enter the amount to deposit: ");
        scanf("%d", &deposit); //กรอกจำนวนเงินฝาก
        Deposit(&deposit, &money); //ดำเนินการฝากเงิน
        printf(
            "\n\n________________________________________________________\n\n");

        printf("Do you want to quit deposit? (1:yes, 0:no): ");
        scanf("%d", &q); //ให้เลือกว่าจะออกจากหน้าฝากเงินหรือไม่
      }
      q = 0;
    }

    else if (choice == 3) {
      while (q==0) {
        system("@cls||clear"); //clear หน้าจอ
        printf("\n\n___________________Exchange the currency___________________\n");
        printf("\nBalance: %.2lf\n", money); //แสดงจำนวนเงิน
        printf("Following are the Choices:"); //แสดงสกุลเงินที่อยากเปรียบเทียบ
        printf("\nEnter 1: Rupee");
        printf("\nEnter 2: Dollar");
        printf("\nEnter 3: Pound");
        printf("\nEnter 4: Euro");
        printf("\nEnter 5: Yuan");
        printf("\nEnter 6: Yen");
  
        printf("\nEnter your choice: ");
        scanf("%d", &Choice); //กรอกสกุลเงินที่อยากเปรียบเทียบเป็นตัวเลข 
        amount = money; //กำหนดค่า amount เท่ากับ money
        bahttocur(amount, Choice); //ดำเนินการคำนวณสกุลเงินที่เลือก
        printf(
            "\n\n________________________________________________________\n\n");
        printf("Do you want to quit exchange the currency? (1:yes, 0:no): ");
        scanf("%d", &q); //ให้เลือกว่าจะออกจากหน้าคำนวนสกุลเงินหรือไม่
      }
      q = 0;
    }

    else if (choice == 4) {
      while (q==0) {
        system("@cls||clear");
        printf("\n\n___________________Future interest___________________\n");
        printf("\nBalance: %.2lf\n", money); //แสดงจำนวนเงิน
        printf("Enter year: "); 
        scanf("%lf", &year); //กรอกจำนวนปีในอนาคตเพื่อคิดดอกเบี้ย
        interest = money * (pow(1 + 0.0025, year)); //คำนวณดอกเบี้ย
        printf("\nFuture interest is %.2lf Baht(interest rate 0.25%%)\n", interest); //แสดงจำนวนเงินในอนาคต
        printf("\n\n________________________________________________________\n\n");
        printf("Do you want to quit future interest? (1:yes, 0:no): ");
        scanf("%d", &q); //ให้เลือกว่าจะออกจากหน้าคำนวนดอกเบี้ยหรือไม่
      }
      q=0;
    }

    else if (choice == 5) {
      system("@cls||clear"); //ทำการ clear หน้าจอ
      exit = 1; //กำหนดค่า exit เป็น 1 เพื่อออกจาก loop
        
    }
  }
  if ((account_no != 165936 || strcmp(name, legitname) != 0) && loop > 3) { 
    //ถ้าชื่อและหมายเลขบัญชียังไม่ถูกต้อง
    system("@cls||clear"); //clear หน้าจอ
    printf("Your bank account is locked. \n"); //แสดงข้อความ
  }
  if (account_no == 165936 && !strcmp(name, legitname) && exit == 1) {
    //ถ้าชื่อและหมายเลขบัญชีถูกต้อง และออกจากระบบธนาคารแล้ว
    system("@cls||clear"); //ทำการ clear หน้าจอ
    FILE *file = fopen("memo.txt", "w"); //เปิดไฟล์ memo.txt เป็นแบบ write
    fprintf(file, "%lf", money); //อัพเดทจำนวนเงิน
    fclose(file); //ปิดไฟล์ memo.txt
    printf("Thank you for using Mini ATM.\n"); //แสดงข้อความ
    
  } //จบการทำงาน

  return 0;
}