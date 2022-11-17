ใน
void withDraw(int *withdraw, double *money) {
  

  if (*withdraw > *money) {
          printf("\n Insufficent Balance"); //แสดงข้อความต่อเมื่อเงินในบัญชีไม่พอ
        } 
        
        else if (*withdraw % 20 == 0 || *withdraw % 50 == 0) {
          *money -= *withdraw;
          printf("\n\n Please collect cash");
          printf("\n Your current balance is %.2lf", *money); //แสดงจำนวนเงินที่เหลือในบัญชี
        } else {
          printf("\n Please enter the amount in multiple of 20 baht");
        }
  }


void Deposit(int *deposit, double *money) {
  
        
  if (*deposit % 20 == 0 || *deposit % 50 == 0) {
    *money += *deposit;
    printf("\n Your current balance is %.2lf", *money); //แสดงจำนวนเงินที่เหลือในบัญชี
  } else {
    printf("\n Please enter the amount in multiple of 20 baht and 50 baht.");
        }
  }






void bahttocur(double baht, int choice){
  double money_cur;
  switch (choice) {
    
        case 1: // Rupee Conversion
            money_cur = baht * 2.27;
            printf("%.2lf Baht =  %.2lf Rupee", baht, money_cur);
            break;
 
        case 2: // Dollar Conversion
            money_cur = baht / 33.69;
            printf("\n%.2lf Baht =  %.2lf Dollar", baht, money_cur);
            break;
 
        case 3: // Pound Conversion
            money_cur = baht / 44.04;
            printf("\n%.2lf Baht =  %.2lf Pound", baht, money_cur);
            break;
 
        case 4: // Euro Conversion
            money_cur = baht / 36.41;
            printf("\n%.2lf Baht =  %.2lf Euro", baht, money_cur);
            break;

        case 5: // Yuan Conversion
            money_cur = baht / 5.29;
            printf("\n%.2lf Baht =  %.2lf Yuan", baht, money_cur);
            break;

        case 6: // Yen Conversion
            money_cur = baht * 3.75;
            printf("\n%.2lf Baht =  %.2lf Yen", baht, money_cur);
            break;

        default://Default case
            printf("\nInvalid Input");

    }
  
}

