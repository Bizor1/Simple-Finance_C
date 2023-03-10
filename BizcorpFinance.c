#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 128







void statement_header(char name[50], char date[30])
{

    printf("\n\n");

    printf("\t BizCorp Finance");
    printf("\n\t ------------------------");
    printf("\nDate:%s", date);
    printf("\nStatement To:%s", name);
    printf("\n");
    printf("-----------------------------------------\n");
    // printf("Assets\t\t");
    // printf("Quantities\t\t");
    // printf("Account balance\t\t");
    printf("\n--------------------------------------");
    printf("\n\n");
}

void generate_all_transactions(char date[50], float amount)
{
    printf("\nDate:%s", date);
    printf("\n");
    printf("Amount:%.2f\t\t", amount);

    printf("\n");
};

void generate_statement_footer(float user_balance)
{
    printf("\n");
    printf("\n--------------------------------------");
    printf("\n Grand Total \t\t\t%.2f", user_balance);
    printf("\n-----------------------------\n");
}
void generate_deposit_transactions(float amount)
{
    printf("\n Amount Deposited:");
    printf("\n%.2f\t\t", amount);
    printf("\n");
};
void generate_withdrawal_transactions(float amount)
{
    printf("\n Amount Withdrawn:");
    printf("\n%.2f\t\t", amount);
    printf("\n");
};
struct deposits
{
    char depositor[50];
    float amt_deposited;
    char date[50];
};
struct withdrawals{
    char withdrawer[50];
    float amt_withdrawn;
    char date[50];
};



// struct asset{

// }

struct investments{
    char asset[100];
    int qty;
    float price;
    char date[50];


};

void write_to_withdraw(char withdrawer[50],float amt_withdrawn,char date[50]){
    FILE *fp;
    fp = fopen("Withdrawal.csv", "a+");
        if (fp == NULL)
        {
            printf("Error opening file");
            exit(1);
        }

        // fwrite(&dp, sizeof(dp), 1, fp);
        fprintf(fp,"%s,%.2f,%s\n",withdrawer,amt_withdrawn,date);
        fclose(fp);

       
        }




int users_balance(char name[50],char file[100],char file_[100]){
        float user_balance=0;
        FILE *fp;
        char *field;
        struct deposits dp;
        // struct investments inv;

        struct withdrawals wd;
        char line[MAX_FIELD_LENGTH];
        strcpy(dp.date, __DATE__);
        fp = fopen(file, "r");
        //  char ch;
        while(fgets(line,MAX_FIELD_LENGTH,fp)!=NULL){
            field=strtok(line,",");

            strcpy(wd.withdrawer,field);

            field=strtok(NULL,",");
            wd.amt_withdrawn=atoi(field);

            field=strtok(NULL,",");
            strcpy(wd.date,field);
            // statement_header(wd.withdrawer, wd.date);
            // generate_withdrawal_transactions(wd.amt_withdrawn);
            // generate_statement_footer(wd.amt_withdrawn);
            if (!strcmp(wd.withdrawer, name))
            {
                //    statement_header(wd.withdrawer, wd.date);
                //     generate_withdrawal_transactions(wd.amt_withdrawn);
                //     generate_statement_footer(wd.amt_withdrawn);
                    user_balance-=wd.amt_withdrawn;
                    // printf("user balance:%f",user_balance);

                // printf("Amount deposiiited:%d",dp.amt_deposited);
                // total_deposits += dp.amt_deposited;
                // generate_all_transactions(dp.date, dp.amt_deposited);
                // total_number += 1;
            }


            // printf("Withdrawer: %s, Amount: %f, Date: %s",wd.withdrawer,wd.amt_withdrawn,wd.date);

        }
         fp = fopen(file_, "r");
        //  char ch;

        while(fgets(line,MAX_FIELD_LENGTH,fp)!=NULL){
            field=strtok(line,",");

            strcpy(dp.depositor,field);

            field=strtok(NULL,",");
            dp.amt_deposited=atoi(field);

            field=strtok(NULL,",");
            strcpy(dp.date,field);
                if (!strcmp(dp.depositor, name)){
                // statement_header(dp.depositor, dp.date);
                // generate_withdrawal_transactions(dp.amt_deposited);
                // generate_statement_footer(dp.amt_deposited);
                user_balance+=dp.amt_deposited;
                // printf("user balance:%f",user_balance);
               
            }    
            // statement_header(dp.depositor, dp.date);

        // printf("Depositor%s",dp.depositor);
            // generate_deposit_transactions(dp.amt_deposited);
            // generate_statement_footer(dp.amt_deposited);


            // printf("Depositor: %s, Amount: %f, Date: %s",dp.depositor,dp.amt_deposited,dp.date);

        }
    
        fclose(fp);
        return user_balance;

}





int main()
{
    char name[50];
    int opt;
    char date[100];
    int size;
    struct deposits dp;
    struct withdrawals wd;
    // struct investments inv;


    FILE *fp;
    FILE *fh;
    float total_deposits;
    int total_number;
    int deposit;
    int withdraw;
    int transaction_type;
    // user_balance("Bizor","Withdrawal.csv","Deposits.csv");
    



    printf("\n\n\t\t==============Welcome to BizCorp FINANCE============");
   
    printf("\n\n Please Select your Opreation");
    printf("\n\n1. Create a Deposit or withdrawal");
    printf("\n2.Show all Statements");
    printf("\n3.Search Statement");
    printf("\n4.Buy an asset");
    printf("\n5.Make a Withdrawal");
    printf("\n6.Exit");
    printf("\n-----------------------------");
    printf("\n\nInput your operation please: ");
    scanf("%d", &opt);
    // printf("Your name is %s", dp.depositor);
    printf("\n\nYour option is %d", opt);
    strcpy(wd.date, __DATE__);
    strcpy(dp.date, __DATE__);

    // printf("%s",date);

    switch (opt)
    {
    case 1:
        
        printf("\n\nType 1 to deposit or 2 to withdraw:");
        
        scanf("%d", &transaction_type);
        if (transaction_type==1){
             printf("\nPlease input your name: ");
        scanf("%s", &dp.depositor);
        printf("\n\nHow much would you like to deposit:");
        scanf("%f", &dp.amt_deposited);
        statement_header(dp.depositor, date);

        // printf("Depositor%s",dp.depositor);
        generate_deposit_transactions(dp.amt_deposited);
        generate_statement_footer(dp.amt_deposited);

           fp = fopen("Deposits.csv", "a+");
        if (fp == NULL)
        {
            printf("Error opening file");
            exit(1);
        }

        // fwrite(&dp, sizeof(dp), 1, fp);
        fprintf(fp,"%s,%.2f,%s\n",dp.depositor,dp.amt_deposited,dp.date);
        fclose(fp);

       
       
        }
        else if (transaction_type==2)
        {
        printf("\nPlease input your name: ");
        scanf("%s", &wd.withdrawer);
        printf("\n\nHow much would you like to Withdraw:");

        scanf("%f", &wd.amt_withdrawn);
        statement_header(wd.withdrawer, date);
        generate_withdrawal_transactions(wd.amt_withdrawn);
        generate_statement_footer(wd.amt_withdrawn);
        fp = fopen("Withdrawal.csv", "a+");
        if (fp == NULL)
        {
            printf("Error opening file");
            exit(1);
        }

        // fwrite(&dp, sizeof(dp), 1, fp);
        fprintf(fp,"%s,%.2f,%s\n",wd.withdrawer,wd.amt_withdrawn,wd.date);
        fclose(fp);

       
        }

     
        break;


    case 2:
        char *field;
        char line[MAX_FIELD_LENGTH];
        strcpy(dp.date, __DATE__);

        fp = fopen("Withdrawal.csv", "r");
        //  char ch;

        while(fgets(line,MAX_FIELD_LENGTH,fp)!=NULL){
            field=strtok(line,",");

            strcpy(wd.withdrawer,field);

            field=strtok(NULL,",");
            wd.amt_withdrawn=atoi(field);

            field=strtok(NULL,",");
            strcpy(wd.date,field);
            statement_header(wd.withdrawer, wd.date);
            generate_withdrawal_transactions(wd.amt_withdrawn);
            generate_statement_footer(wd.amt_withdrawn);


            printf("Withdrawer: %s, Amount: %f, Date: %s",wd.withdrawer,wd.amt_withdrawn,wd.date);

        }

        fp = fopen("Deposits.csv", "r");
        //  char ch;

        while(fgets(line,MAX_FIELD_LENGTH,fp)!=NULL){
            field=strtok(line,",");

            strcpy(dp.depositor,field);

            field=strtok(NULL,",");
            dp.amt_deposited=atoi(field);

            field=strtok(NULL,",");
            strcpy(dp.date,field);
            statement_header(dp.depositor, dp.date);

        // printf("Depositor%s",dp.depositor);
            generate_deposit_transactions(dp.amt_deposited);
            generate_statement_footer(dp.amt_deposited);


            printf("Depositor: %s, Amount: %f, Date: %s",dp.depositor,dp.amt_deposited,dp.date);

        }
    
        fclose(fp);
        break;

    case 3:
    printf("\nWhat is your name:");
    float user_balance=0;
    scanf("%s",&name);

        strcpy(dp.date, __DATE__);

        fp = fopen("Withdrawal.csv", "r");

        while(fgets(line,MAX_FIELD_LENGTH,fp)!=NULL){
            field=strtok(line,",");

            strcpy(wd.withdrawer,field);

            field=strtok(NULL,",");
            wd.amt_withdrawn=atoi(field);

            field=strtok(NULL,",");
            strcpy(wd.date,field);
            if (!strcmp(wd.withdrawer, name))
            {
                   statement_header(wd.withdrawer, wd.date);
                    generate_withdrawal_transactions(wd.amt_withdrawn);
                    generate_statement_footer(wd.amt_withdrawn);
                    user_balance-=wd.amt_withdrawn;
             
            }
         



        }

   

        
        strcpy(dp.date, __DATE__);

        fp = fopen("Deposits.csv", "r");
        


     

        while (fgets(line,MAX_FIELD_LENGTH,fp)!=NULL)
        {
              field=strtok(line,",");

            strcpy(dp.depositor,field);

            field=strtok(NULL,",");
            dp.amt_deposited=atoi(field);

            field=strtok(NULL,",");
            strcpy(wd.date,field);
            field=strtok(line,",");

            if (!strcmp(dp.depositor, name)){
                statement_header(dp.depositor, dp.date);
                generate_withdrawal_transactions(dp.amt_deposited);
                generate_statement_footer(dp.amt_deposited);
                user_balance+=dp.amt_deposited;
                // printf("user balance:%f",user_balance);
               
            }

            // else{
            //     printf("g");

            // }
        }

        // // for(int i=0;i<total_number;i++){

        // // }

        // generate_statement_footer(total_deposits);

        fclose(fp);
        printf("user_balance%f",user_balance);

        break;


    case 4:
        int num_assets;
        float total_cost= 0.0;
        char name_of_investor[100];
        float balance;

        

        printf("\n\t\t==============Welcome to BizCorp Investments============");
        printf("\nPlease what is your name?");
        scanf("%s",& name_of_investor);
        printf("\nHow many assets do you want to invest in ?");
        scanf("%d",&num_assets);
        // int const NUM_ASSETS=num_assets;
        struct investments *inv=malloc(num_assets *sizeof(struct investments));
        strcpy(inv->date,__DATE__);
        if(inv==NULL){
            printf("Memmory allocation messed up");
        }
        
        
        printf("\nyou selected %d",num_assets);
        for(int i=0;i<num_assets;i++){
        printf("\n Please Type the name of the asset %d ?",i+1);
        scanf("%s",inv[i].asset);
        printf("\n Please Type the quantity  %d ?",i+1);
        scanf("%d",&inv[i].qty);
        printf("\n Please Type price of the asset %d ?",i+1);
        scanf("%f",&inv[i].price);
        total_cost+=(inv[i].price * inv[i].qty);





        };
        balance=users_balance(name_of_investor,"Withdrawal.csv","Deposits.csv");


    


        printf("%f",balance);


        printf("total cost %f",total_cost);
        if(balance>total_cost){
               FILE *fp;
            fp=fopen("Asset_purchases.csv","a+");

            if(fp==NULL){
                printf("error opening file");
                exit(1);
            }
            

            fprintf(fp,"%s,%s,%s,%d,%f,%f\n",name_of_investor,inv->date,inv->asset,inv->qty,inv->price,total_cost);
            fclose(fp);


        }else{
            printf("Insufficeint_balance please make a deposit");
        }
        balance=balance-total_cost;
         write_to_withdraw(name_of_investor,total_cost,inv->date);
        
        
         

            
        
        
        
        


        free(inv);
       


            









        


        

    
    

  
    };

    return 0;
}