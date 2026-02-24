int main(){
    
    int input;                  
    while((input = getchar()) != EOF){
        if( input != '\t' && c != '\b' && c != '\\')        
            putchar(c);                             
            
        else{
            if(input == '\t'){          
                putchar('\\');
                putchar('t');
                }
            
            if(input == '\b'){           
                putchar('\\');
                putchar('b');
                }
                
            if(input == '\\'){          
                putchar('\\');
                putchar('\\');
                }       
        }
        
    }

}
