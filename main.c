#include<xc.h>           // processor SFR definitions
#include<sys/attribs.h>  // __ISR macro
#include "ili9341.h" //lcd library
#include<stdio.h> //sprintf
#include<stdlib.h>

// DEVCFG0
#pragma config DEBUG = OFF // no debugging
#pragma config JTAGEN = OFF // no jtag
#pragma config ICESEL =  ICS_PGx1 // use PGED1 and PGEC1
#pragma config PWP = OFF // no write protect
#pragma config BWP = OFF // no boot write protect
#pragma config CP = OFF // no code protect

// DEVCFG1
#pragma config FNOSC = PRIPLL // use primary oscillator with pll
#pragma config FSOSCEN = OFF // turn off secondary oscillator
#pragma config IESO = OFF // no switching clocks
#pragma config POSCMOD = HS // high speed crystal mode
#pragma config OSCIOFNC = OFF // disable secondary osc
#pragma config FPBDIV = DIV_1 // divide sysclk freq by 1 for peripheral bus clock
#pragma config FCKSM = CSDCMD // do not enable clock switch
#pragma config WDTPS = PS1048576 // use slowest wdt
#pragma config WINDIS = OFF // wdt no window mode
#pragma config FWDTEN = OFF // wdt disabled
#pragma config FWDTWINSZ = WINSZ_25 // wdt window at 25%

// DEVCFG2 - get the sysclk clock to 48MHz from the 8MHz crystal
#pragma config FPLLIDIV = DIV_2 // divide input clock to be in range 4-5MHz
#pragma config FPLLMUL = MUL_24 // multiply clock after FPLLIDIV
#pragma config FPLLODIV = DIV_2 // divide clock after FPLLMUL to get 48MHz
#pragma config UPLLIDIV = DIV_2 // divider for the 8MHz input clock, then multiplied by 12 to get 48MHz for USB
#pragma config UPLLEN = ON // USB clock on

// DEVCFG3
#pragma config USERID = 00000000 // some 16bit userid, doesn't matter what
#pragma config PMDL1WAY = OFF // allow multiple reconfigurations
#pragma config IOL1WAY = OFF // allow multiple reconfigurations
#pragma config FUSBIDIO = ON // USB pins controlled by USB module
#pragma config FVBUSONIO = ON // USB BUSON controlled by USB module
  
    
    //function to draw bars on the LCD
    

int main() {

    __builtin_disable_interrupts();

    // set the CP0 CONFIG register to indicate that kseg0 is cacheable (0x3)
    __builtin_mtc0(_CP0_CONFIG, _CP0_CONFIG_SELECT, 0xa4210583);

    // 0 data RAM access wait states
    BMXCONbits.BMXWSDRM = 0x0;

    // enable multi vector interrupts
    INTCONbits.MVEC = 0x1;

    // disable JTAG to get pins back
    DDPCONbits.JTAGEN = 0;

    // set input and output pins
    TRISBbits.TRISB4=1; // B4 i an input
    TRISAbits.TRISA4=0; //A4 is an output
    LATAbits.LATA4=1; //A4 initially set to 3.3V
    SPI1_init();
    LCD_init();
    SPI2_init();
    
    __builtin_enable_interrupts(); 
    
    
    
    unsigned short bg=0x780F; // background color
    unsigned short charcolor=0x0000; //color of the text
    unsigned short offcolor=0xffff; // color for text background to distinguish b/w off and on pixels
    unsigned short pg_bar_p=0x0000; //progress indicator
    unsigned short pg_bar_n=0x07ff; //progress remaining indicator       
    LCD_clearScreen(bg);
    unsigned short x_corm =60;
    unsigned short y_corm = 100;
    int wid =50;
    int len =50;
    unsigned short x_corp =x_corm+10+wid;
    unsigned short y_corp = y_corm;
     
     char message[20]; 
     char buttonname1[20]; 
     char buttonname2[20]; 
     char buttonname3[20]; 
    sprintf(buttonname1,"+");
    drawbutton(x_corp,y_corp,len,wid,offcolor,charcolor,buttonname1);//plus and minus button
    sprintf(buttonname2,"-");
    drawbutton(x_corm,y_corp,len,wid,offcolor,charcolor,buttonname2);//plus and minus butto
    sprintf(buttonname3,"R");
    drawbutton(10,10,50,50,charcolor,offcolor,buttonname3);
    sprintf(message,"R is reset counter");
    LCD_drawstring(message,70,25,offcolor, charcolor);
    
    short x;
    short y;
    int z; 
    int I=0;
    int Release = 0;
    char I_val[15];
    char I_plus[10];
    char I_minus[10];
    char str[20];
    int i=0;
    int j=0;
    
        char x_val[10];
        char y_val[10];
        char z_val[10];
        _CP0_SET_COUNT(0);
        int pressed=0;
       while(1)
       {   
           //char test[10];
           //sprintf(test,"test");
           //LCD_drawstring(test,200,200,charcolor,offcolor);
        XPT2046_read(&x, &y, &z);
        x = (short) ( ((double)(x - 450)/((double)(3855 - 450))) * ILI9341_TFTWIDTH ); // conversion into pixels
        y = (short) ( (1- (double)(y - 466)/((double)(3880 - 466))) * ILI9341_TFTHEIGHT );
        sprintf(x_val,"X = %d", x);
        LCD_drawstring(x_val,28,200,ILI9341_WHITE, ILI9341_BLUE);
        
        sprintf(y_val,"Y = %d", y);
        LCD_drawstring(y_val,28,215,ILI9341_WHITE, ILI9341_BLUE);
        
        sprintf(z_val,"Z = %d", z);
        LCD_drawstring(z_val,28,230,ILI9341_WHITE, ILI9341_BLUE); 
        
        
        if ( (z > 500)  & (Release == 0) )
        { 
            Release = 1;
            
            if ( (y < y_corm+len) & (y> y_corm ))
                
            {
            
                if ( (x < x_corm+wid) & (x >x_corm ) )
                {   
                    if(I>0)
                    {
                    I--;
                    pressed++;
                    }
                    else
                    {
                       //  _CP0_SET_COUNT(0);
                         //while (_CP0_GET_COUNT()<4800000)
                         //{
                             sprintf(str,"error cannot go below zero");
                             LCD_drawstring(str,150,250,ILI9341_WHITE, ILI9341_BLACK);
                            while (_CP0_GET_COUNT()<(70000000)) //delay
                            {;}
                         //}
                             LCD_clearScreen(bg);
                             drawbutton(x_corp,y_corp,len,wid,offcolor,charcolor,buttonname1);//plus button
                             drawbutton(x_corm,y_corp,len,wid,offcolor,charcolor,buttonname2);//minus button
                             drawbutton(10,10,50,50,charcolor,offcolor,buttonname3);
                             LCD_drawstring(message,70,25,offcolor, charcolor);
                    }
                    
                }
                
                else if ( (x < x_corp+wid) & (x > x_corp ))
                { I++;
                pressed++;
                }
            }
                if ( (x < 40) & (x > 10 ))
                {   if(I>0){
                    j=I;
                    if((y>10) & (y<40))
                    for(i=0;i<j;i++)
                    {I--;}}
                }
            }          
        else if (z < 500)
        {Release = 0;}   
        if ((I==0)&(pressed>0))
        {
        LCD_clearScreen(bg);
        drawbutton(x_corp,y_corp,len,wid,offcolor,charcolor,buttonname1);//plus button
        drawbutton(x_corm,y_corp,len,wid,offcolor,charcolor,buttonname2);//minus button
        drawbutton(10,10,50,50,charcolor,offcolor,buttonname3);
        LCD_drawstring(message,70,25,offcolor, charcolor);
        pressed=0;
        }
        if(I>=0)
        sprintf(I_val,"I = %d", I);   
        //LCD_drawstring(I,150,250,ILI9341_WHITE, ILI9341_BLACK);
        LCD_drawstring(I_val,150,225,ILI9341_WHITE, ILI9341_BLACK);
       }
        }