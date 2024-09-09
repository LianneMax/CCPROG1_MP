/***************************************************************************************
This is to certify that this project is my own work, based on my personal efforts
in studying and applying the concepts learned. I have constructed the
functions and their respective algorithms and corresponding code by myself.
The program was run, tested, and debugged by my own efforts. I further
certify that I have not copied in part or whole or otherwise plagiarized the
work of other students and/or persons.
Lianne Maxene Balbastro, DLSU ID# 12205931
***************************************************************************************/

/*
Description: The application should allow to input purchases, make payments, use points, view
balance, view points, and generate the credit card bill with differe.

Programmed by: Lianne Maxene Balbastro S11
Last modified: July 30, 2023
Version: 3
*/


#include <stdio.h>


/* 
This function Displays the welcome message and holds the credit limit value

@param *fCreditLimit is the credit limit of the card
*/

void displayWelcomeMessage(float *fCreditLimit){
    printf("\n+==================================================================+");
    printf("\n|                                                                  |");
    printf("\n|            WELCOME TO MAX'S CREDIT CARD BILL GENERATOR           |");
    printf("\n|                                                                  |");
    printf("\n+==================================================================+");
    printf("\nInput Credit Card Limit: ");
    scanf(" %f", fCreditLimit); //holds fCreditLimit
}

/* 
This function Displays the Menu and holds the users action

@param *nMenuChoice is the users choice in the menu
*/

void displayMainMenu(int *nMenuChoice){
        
    printf("\n+==================================================================+");
    printf("\n|                                                                  |");
    printf("\n|                 WHAT WOULD YOU LIKE TO DO TODAY?                 |");
    printf("\n|                                                                  |");
    printf("\n|                [ 1 ] Add Purchase                                |");
    printf("\n|                [ 2 ] View Previous Statement                     |");
    printf("\n|                [ 3 ] Make Payment                                |");
    printf("\n|                [ 4 ] View Rewards Points                         |");
    printf("\n|                [ 5 ] Use Rewards Points                          |");
    printf("\n|                [ 6 ] End Billing Cycle                           |");
    printf("\n|                [ 7 ] Exit                                        |");
    printf("\n|                                                                  |");
    printf("\n+==================================================================+");

    printf("\nSelect Action: ");
    scanf("%d", nMenuChoice); //holds nMenuChoice
}

/* 
This function adds a purchase to the total bill and computes for the total points per purchase
declined if the amount is greater than or equal to twice the credit limit or greater than 0

@param fCreditLimit is the credit limit of the card
@param *fCurPurchase is the current purchases of the billing cycle
@param *nCurPoints is the current points of the billing cycle
@param *nTotalPoints is the total points  
*/

void AddPurchase(float fCreditLimit, float* fCurPurchase, int* nCurPoints, int* nTotalPoints) {
	
    int nCurPointsEarned;
    float fPurchaseAmt;

    do {

        printf("\n+========================= ADD PURCHASE ===========================+");
        printf("\nEnter the Amount of Purchase: ");
        scanf("%f", &fPurchaseAmt);

        if (fPurchaseAmt >= 2 * fCreditLimit) { // purchases must be greater than or equal to twice the current credit limit
            printf("Transaction Declined. Purchase Amount Exceeds Twice the Credit Limit.\n");
            printf("+==================================================================+\n\n");
        }
        else if (fPurchaseAmt < 0) { // purchases must be greater than 0
            printf("Invalid amount. Please enter a non-negative value.\n");
            printf("+==================================================================+\n\n");
        }
        else {
            *fCurPurchase += fPurchaseAmt;
            nCurPointsEarned = fPurchaseAmt / 30; // Computes for Points
            *nCurPoints += nCurPointsEarned;
            *nTotalPoints += nCurPointsEarned;
            printf("Purchase Added Successfully!\n");
            printf("+==================================================================+\n\n");
        }
    } while (fPurchaseAmt >= 2 * fCreditLimit || fPurchaseAmt < 0);
}

/* 
This function Displays the Previous Statement of the previous billing cycle
precondition: Bill Cycle is not 1

@param fPreBal is the previous total amount
@param fMinAmtDue is the minimum amount due based on the total amount
*/

void ViewPreviousStatement(float fPreBal, float fMinAmtDue) {
    printf("\n+================== VIEWING PREVIOUS STATEMENT ====================+");
    printf("\n|                                                                  |");
    printf("\n             Previous Balance: %.2f                               ", fPreBal);
    printf("\n             Previous Minimum Amount Due: %.2f                    ", fMinAmtDue);
    printf("\n|                                                                  |");   
    printf("\n+==================================================================+");

}

/* 
This function adds a payment to the current billing cycle
precondition: amount is not negative

@param *fCurPayment is the current payments of the billing cycle
@param *fCurPurchase is the current payment of the billing cycle
@param fOutBal is the current outstanding balance that has not been paid
*/

void MakePayment(float* fCurPayment, float* fCurPurchase, float fOutBal) {
    float fPaymentAmt;
    printf("\n+========================= MAKE PAYMENT ============================+\n\n");
    printf("Enter Amount of Payment: ");
    scanf("%f", &fPaymentAmt);

    if (fPaymentAmt < 0) {
        printf("Invalid Amount. Please Enter a Non-Negative Value.");
        printf("\n+==================================================================+\n\n");
    }

    else {
        *fCurPayment += fPaymentAmt;
        printf("Payment Made Successfully!");
        printf("\n+==================================================================+\n\n");
    }
}

/* 
This function Displays the the current and total rewards points

@param *nTotalPoints is the total points of the rewards
*/

void ViewRewardsPoints(int* nTotalPoints) {

    printf("\n+==================== VIEWING REWARD POINTS =======================+");
    printf("\n|                                                                  |");
    printf("\n|                     VIEWING REWARD POINTS                        |");
    printf("\n                  Total Rewards Points: %d                          ", *nTotalPoints);
    printf("\n|                                                                  |");   
    printf("\n+==================================================================+");


}

/* 
This function claims the reward points only if the total points is greater or equal to 1000
precondition: Points are not negative

@param *nTotalPoints is the total points of the rewards
@param *nPointsUsed is the used points of the user
@param *nCurPayment is the current payment of the billing cycle
@param *nCurPoints is the current points computed by the purchases of the current billing cycle
*/
void UseRewardPoints(int* nTotalPoints, int* nPointsUsed, float* fCurPayment, int* nCurPoints) {
    int Choice;

    if (*nTotalPoints >= 1000) {
    	
    	*nTotalPoints -= 1000; // updates the new Total Points
        printf("\n+==================================================================+");
        printf("\n|                                                                  |");
        printf("\n|                      REWARDS TO BE CLAIMED                       |");
        printf("\n|                                                                  |");
        printf("\n|              [ 1 ] Php 100 eGift Voucher for 1000pts             |");
        printf("\n|              [ 2 ] Php 100 credits for 1000 pts                  |");
        printf("\n|              [ 3 ] Cancel                                        |");
        printf("\n|                                                                  |");
        printf("\n+==================================================================+");
        printf("\nEnter your Choice: ");
        scanf("%d", &Choice);


        switch (Choice) {
        case 1:
            *nPointsUsed += 1000;
            printf("eGift voucher code sent to your registered mobile number.\n");
            break;
        case 2:
            *nPointsUsed += 1000;
            *fCurPayment += 100.0;
            printf("Php 100 credits claimed successfully.\n");
            break;
        case 3:
            printf("Claim canceled.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    else {
            printf("\n+==================================================================+");
            printf("\n|            Insufficient Points (1000) to Claim Rewards.          |");
            printf("\n                        Current Points: %d                         ", *nTotalPoints);
            printf("\n+==================================================================+\n");

    }
}

/* 
This function displays and computes the total bill of the billing cycle

@param *fPreBal is the previous total amount
@param *fMinAmtDue is the minimum amount due based on the total amount
@param *fOutBal is the current outstanding balance that has not been paid
@param *fCurPurchase is the current purchase of the billing cycle
@param *fCurPayment is the current payment of the billing cycle
@param *fFinChar is the total overlimit fee and unpaid balance fee
@param *fLatePay is the charge for not paying the at least the minimum amount
@param *nBillCycle is the number of billing cycle
@param *nCancelCount is counting how many cycles without payment
@param *nTotalPoints is the total of previous and current points minus the used points.
@param *nPointsUsed is the claimed points during the billing cycle
@param *nCurPoints is the current points of the current billing cycle
@param *nPrevPoints is the previous total points
@param *fCreditLimit is the credit limit of the card
@param *fTotalAmt is the total amount of the billing cycle
*/
void EndBillingCycle(float* fPreBal, float* fMinAmtDue, float* fOutBal, float* fCurPurchase, float* fCurPayment,
    float* fFinChar, float* fLatePay, int* nBillCycle, int* nCancelCount, int* nTotalPoints,
    int* nPointsUsed, int* nCurPoints, int* nPrevPoints, float* fCreditLimit, float* fTotalAmt) {
    	
    float fUnpaidBal;
	
    *fFinChar = 0.0;
    *fLatePay = 0.0;
    
    if (*fCurPayment == 0 && *fMinAmtDue > 0) //check if cancel
        *nCancelCount += 1;
    
    else
        *nCancelCount = 0;
    

   *fOutBal = *fPreBal + *fCurPurchase - *fCurPayment; //compute outstanding balance

	if (*fOutBal > *fCreditLimit) // condition for overlimit fee
        *fFinChar += 500.0;
    

    if (*fCurPayment < *fPreBal) { // condition for payement lower than previous balance
        fUnpaidBal = *fPreBal - *fCurPayment; // compute for unpaid balance
        *fFinChar += (fUnpaidBal * 0.03);
    }

    if (*fPreBal > 0 && *fCurPayment < *fMinAmtDue) { //condition for late payment
        if (*fMinAmtDue <= 850)
            *fLatePay = *fMinAmtDue - *fCurPayment; // compute late pay
        else
            *fLatePay = 850;
    }
 
    *fTotalAmt = *fOutBal + *fFinChar + *fLatePay;   //compute for the total amount

    if (*fTotalAmt <= 850) //condition for minimum amount due (less than 850)
        *fMinAmtDue = *fTotalAmt;

    else{
        *fMinAmtDue = *fTotalAmt * 0.0357; // condition
    	    if(*fMinAmtDue < 850)
                *fMinAmtDue = 850;                 
    }

	*nTotalPoints = *nPrevPoints + *nCurPoints - *nPointsUsed; //compute total points   
	

  printf("\n+==================================================================+");
    printf("\n                                                                  ");
    printf("\n                Credit Card Bill: Billing Cycle %-4d              ", *nBillCycle);
    printf("\n                                                                  ");
    printf("\n               Previous Balance:              %-10.2f             ", *fPreBal);
    printf("\n               (-) Payments/Credits:          %-10.2f             ", *fCurPayment);
    printf("\n               (+) Purchases:                 %-10.2f             ", *fCurPurchase);
    printf("\n               (+) Finance Charges:           %-10.2f             ", *fFinChar);
    printf("\n               (+) Late Payment Charge:       %-10.2f             ", *fLatePay);    
	printf("\n------------------------------------------------------------------");    
    printf("\n               Total Amount Due:              %-10.2f             ", *fTotalAmt);
    printf("\n               Minimum Amount Due:            %-10.2f             ", *fMinAmtDue);
    printf("\n                                                                  ");
    printf("\n               Previous Card Points Balance:  %-6d                ", *nPrevPoints);
    printf("\n               (+) Current Points Earned:     %-6d                ", *nCurPoints);
    printf("\n               (-) Points Used:               %-6d                ", *nPointsUsed);
    printf("\n               Total Credit Points:           %-6d                ", *nTotalPoints);
    printf("\n                                                                  ");   
    printf("\n+==================================================================+");

	
    //prepare for next billing cycle
    *fPreBal = *fTotalAmt;

    *nPrevPoints = *nTotalPoints;
    
    *nCurPoints = 0;
    *nPointsUsed = 0;
    *fFinChar = 0.0;
    *fLatePay = 0.0;
    *fCurPurchase = 0.0;
    *fCurPayment = 0.0;

	if (*nBillCycle % 12 == 0) //condition for adding 2000 every 12 billing cycles
        *fCurPurchase += 2000;
		  
	(*nBillCycle)++; //next billing cycle

}

/* 
This function checks if the credit card is going to be declined after 4 billing cycles
without making a payment

@param *nCancelCount is counting how many cycles without payment
@param *fMinAmtDue is the minimum amount due based on the total amount
@param *fTotalAmt is the total amount of the billing cycle
@param *nEnd ends the program
*/

void nEndProgram(int *nCancelCount, float *fMinAmtDue, float *fTotalAmt, int *nEnd){
	
	if (*nCancelCount >= 4 && *fMinAmtDue > 0) { //condition if 4 cycles without payment
        printf("\n+==================================================================+");
        printf("\n|                                                                  |");
        printf("\n     Credit Card Canceled. Demandable Amount: %.2f                 ", *fTotalAmt);
        printf("\n     Penalty: %.2f                                                 ", (*fTotalAmt * 0.25));
        printf("\n|                                                                  |");  
        printf("\n+==================================================================+");
 
 		*nEnd = 1; //ends the program
    }

}

/* 
This function initializes everything to 0 and displays the welcome message,
display the main menu and calls the functions as long as the input is valid
*/

int main() {
    int nMenu = 0;
    float fCreditLimit = 0.0;

    int nBillCycle = 1;
    int nCancelCount = 0;
    int nEnd = 0;

    float fPrebal = 0.0;
    float fMinAmtDue = 0.0;
    float fCurPurchase = 0.0;
    float fCurPayment = 0.0;
    float fOutBal = 0.0;
    float fTotalAmt = 0.0;

    float fFinChar = 0.0;
    float fLatePay = 0.0;

    int nPrevPoints = 0;
    int nTotalPoints = 0;
    int nCurPoints = 0;
    int nPointsUsed = 0;
    
	do {
		
    	displayWelcomeMessage(&fCreditLimit);
				
	}while (fCreditLimit <= 0); //credit limit always positive or not 0
	
    do {

        displayMainMenu(&nMenu); //call the main menu
        
        switch (nMenu){ //calls the function depending on input
        case 1:
            AddPurchase(fCreditLimit, &fCurPurchase, &nCurPoints, &nTotalPoints);
            break;
        case 2:
            ViewPreviousStatement(fPrebal, fMinAmtDue);
            break;
        case 3:
            MakePayment(&fCurPayment, &fCurPurchase, fOutBal);
            break;
        case 4:
            ViewRewardsPoints(&nTotalPoints);
            break;
        case 5:
            UseRewardPoints(&nTotalPoints, &nPointsUsed, &fCurPayment, &nCurPoints);
            break;
        case 6:
            EndBillingCycle(&fPrebal, &fMinAmtDue, &fOutBal, &fCurPurchase, &fCurPayment, &fFinChar,
                &fLatePay, &nBillCycle, &nCancelCount, &nTotalPoints, &nPointsUsed, &nCurPoints, &nPrevPoints, 
                &fCreditLimit, &fTotalAmt);
            nEndProgram(&nCancelCount, &fMinAmtDue, &fTotalAmt, &nEnd);
            break;
        case 7:
        	nEnd = 1;
            printf("\n+==================================================================+");
            printf("\n|                     Exiting Program...                           |");
            printf("\n+==================================================================+\n");

            break;
        default:
            printf("\n+==================================================================+");
            printf("\n|          Invalid Choice. Please Select a Valid Option.           |");
            printf("\n+==================================================================+\n");
            break;
    	}
    } while (nMenu != 7 && nEnd == 0); // will run until the program ends

    return 0;
}

