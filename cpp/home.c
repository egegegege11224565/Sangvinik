#include <stdio.h>  

enum Currency {     
    RUB = 0,        
    USD = 1,        
    EUR = 2         
};

struct Transaction {        
    double amount;          // Сумма в валюте
    enum Currency type;     // Тип валюты
};

double naDenigi(struct Transaction train){  
    double Kursk[] = {1.0, 92.5, 100.0};    // Курс
    double Komissi_CRB[] = {0.0, 3.0, 5.0}; // Комиссии 
    
    double v_rublyah = train.amount * Kursk[train.type];  
    double komissiya = v_rublyah * (Komissi_CRB[train.type] / 100.0); 
    double RESULTAT = v_rublyah - komissiya;  
    
    return RESULTAT;  
}

int main(){
    struct Transaction train;
    
    printf("VVEDITE MONY:\n");     
    printf("0 – RUB\n");
    printf("1 – USD\n");
    printf("2 – EUR\n");
    scanf("%d", &train.type);      
    
    if(train.type == RUB) {        
        printf("VVEDITE SUMMU V RUBLYAH\n");
        scanf("%lf", &train.amount);
    }
    else if(train.type == USD) {   
        printf("VVEDITE SUMMU V DOLLARAH\n");
        scanf("%lf", &train.amount);
    }
    else if(train.type == EUR) {   
        printf("VVEDITE SUMMU V EVRO\n");
        scanf("%lf", &train.amount);
    }
    
    double RESULTAT = naDenigi(train);  
    
    printf("\nRESULTAT: %.3f RUB\n", RESULTAT); 
    
    return 0; 
}