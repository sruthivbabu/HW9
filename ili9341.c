#include<xc.h>           // processor SFR definitions
#include<sys/attribs.h>  // __ISR macro
#include "ili9341.h" //lcd library
#include<stdio.h> //sprintf
#include<stdlib.h>

void LCD_init() {
    int time = 0;
    
    CS = 0; // CS
   
    LCD_command(ILI9341_SWRESET);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 7200000) {} // 300ms

    LCD_command(0xEF);
  	LCD_data(0x03);
	LCD_data(0x80);
	LCD_data(0x02);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
    
    LCD_command(0xCF);
  	LCD_data(0x00);
	LCD_data(0xC1);
	LCD_data(0x30);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
    
    LCD_command(0xED);
  	LCD_data(0x64);
	LCD_data(0x03);
	LCD_data(0x12);
    LCD_data(0x81);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
    
    LCD_command(0xE8);
  	LCD_data(0x85);
	LCD_data(0x00);
	LCD_data(0x78);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
    
    LCD_command(0xCB);
  	LCD_data(0x39);
	LCD_data(0x2C);
	LCD_data(0x00);
    LCD_data(0x34);
    LCD_data(0x02);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
    
    LCD_command(0xF7);
  	LCD_data(0x20);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
    
    LCD_command(0xEA);
  	LCD_data(0x00);
	LCD_data(0x00);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
    
    LCD_command(ILI9341_PWCTR1);
  	LCD_data(0x23);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
    
    LCD_command(ILI9341_PWCTR2);
  	LCD_data(0x10);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
    
    LCD_command(ILI9341_VMCTR1 );
  	LCD_data(0x3e);
    LCD_data(0x28);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
    
    LCD_command(ILI9341_VMCTR2);
  	LCD_data(0x86);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
    
    LCD_command(ILI9341_MADCTL);
  	LCD_data(0x48);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
/*    
    LCD_command(ILI9341_VSCRSADD);
  	LCD_data(0x00);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
 */   
    LCD_command(ILI9341_PIXFMT);
  	LCD_data(0x55);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
    
    LCD_command(ILI9341_FRMCTR1);
  	LCD_data(0x00);
    LCD_data(0x18);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
    
    LCD_command( ILI9341_DFUNCTR);
  	LCD_data(0x08);
    LCD_data(0x82);
    LCD_data(0x27);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
    
    LCD_command(0xF2);
  	LCD_data(0); // 1
    LCD_data(0x00);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
    
    LCD_command(ILI9341_GAMMASET);
  	LCD_data(0x01);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
    
    LCD_command(ILI9341_GMCTRP1);
  	LCD_data(0x0F);
    LCD_data(0x31);
    LCD_data(0x2B);
    LCD_data(0x0C);
    LCD_data(0x0E);
    LCD_data(0x08);
    LCD_data(0x4E);
    LCD_data(0xF1);
    LCD_data(0x37);
    LCD_data(0x07);
    LCD_data(0x10);
    LCD_data(0x03);
    LCD_data(0x0E);
    LCD_data(0x09);
    LCD_data(0x00);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
    
    LCD_command(ILI9341_GMCTRN1);
  	LCD_data(0x00);
    LCD_data(0x0E);
    LCD_data(0x14);
    LCD_data(0x03);
    LCD_data(0x11);
    LCD_data(0x07);
    LCD_data(0x31);
    LCD_data(0xC1);
    LCD_data(0x48);
    LCD_data(0x08);
    LCD_data(0x0F);
    LCD_data(0x0C);
    LCD_data(0x31);
    LCD_data(0x36);
    LCD_data(0x0F);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
    
    LCD_command(0xB1);
  	LCD_data(0x00);
    LCD_data(0x10);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
    
    LCD_command(ILI9341_SLPOUT);
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
    
    LCD_command(ILI9341_DISPON);
    
    CS = 1; // CS
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
    
    
    CS = 0; // CS
    
    LCD_command(ILI9341_MADCTL);
    LCD_data(MADCTL_MX | MADCTL_BGR); // rotation
    time = _CP0_GET_COUNT();
    while (_CP0_GET_COUNT() < time + 3600000) {} // 150ms
    
    CS = 1; // CS
}

void SPI1_init() {
  SDI1Rbits.SDI1R = 0b0100; // B8 is SDI1 
  TRISAbits.TRISA0 = 0; // set up the chip select pin as an output
  CS = 1; //no communication
  RPA1Rbits.RPA1R = 0b0011; //set pin A1 as output SDO1
  TRISBbits.TRISB9 = 0; // DC pin
  DC = 1;
  SPI1CON = 0;              // turn off the spi module and reset it
  SPI1BUF;                  // clear the rx buffer by reading from it
  SPI1BRG = 3;             // baud rate to 10 MHz [SPI1BRG = (80000000/(2*desired))-1]
  SPI1STATbits.SPIROV = 0;  // clear the overflow bit
  SPI1CONbits.CKE = 1;      // data changes when clock goes from hi to lo (since CKP is 0)
  SPI1CONbits.MSTEN = 1;    // master operation
  SPI1CONbits.ON = 1;       // turn on spi 1
}


void SPI2_init() {
  SDI2Rbits.SDI2R = 0b0011; // B13 is SDI2
  RPB11Rbits.RPB11R = 0b0100; // B11 is SDO2
  TRISBbits.TRISB10 = 0; // CS is B10
  TCS = 1; // CS starts high
  ANSELBbits.ANSB13 = 0;
  
  SPI2CON = 0; // turn off the spi2 module and reset it
  SPI2BUF; // clear the rx buffer by reading from it
  SPI2BRG = 3; // baud rate to 12 MHz [SPI1BRG = (48000000/(2*desired))-1]
  SPI2STATbits.SPIROV = 0; // clear the overflow bit
  SPI2CONbits.CKE = 1; // data changes when clock goes from hi to lo (since CKP is 0)
  SPI2CONbits.MSTEN = 1; // master operation
  SPI2CONbits.ON = 1; // turn on spi2
}

unsigned char spi_io(unsigned char o) {
  SPI1BUF = o;
  while(!SPI1STATbits.SPIRBF) { // wait to receive the byte
    ;
  }
  return SPI1BUF;
}

unsigned char spi2_io(unsigned char o) {
  SPI2BUF = o;
  while(!SPI2STATbits.SPIRBF) { // wait to receive the byte
    ;
  }
  return SPI2BUF;
}

void LCD_command(unsigned char com) {
    DC = 0; // DC
    spi_io(com);
    DC = 1; // DC
}

void LCD_data(unsigned char dat) {
    spi_io(dat);
}

void LCD_data16(unsigned short dat) {
    spi_io(dat>>8);
    spi_io(dat);
}

void LCD_setAddr(unsigned short x, unsigned short y, unsigned short w, unsigned short h) {
    LCD_command(ILI9341_CASET); // Column
    LCD_data16(x);
	LCD_data16(x+w-1);

	LCD_command(ILI9341_PASET); // Page
	LCD_data16(y);
	LCD_data16(y+h-1);

	LCD_command(ILI9341_RAMWR); // Into RAM
}

void LCD_drawPixel(unsigned short x, unsigned short y, unsigned short color) {
  // check boundary
    
    CS = 0; // CS
    
    LCD_setAddr(x,y,1,1);
    LCD_data16(color);
    
    CS = 1; // CS
}

void LCD_clearScreen(unsigned short color) {
    int i;
    
    CS = 0; // CS
    
    LCD_setAddr(0,0,ILI9341_TFTWIDTH,ILI9341_TFTHEIGHT);
	for (i = 0;i < ILI9341_TFTWIDTH*ILI9341_TFTHEIGHT; i++){
		LCD_data16(color);
	}
    
    CS = 1; // CS
}

void LCD_drawchar(char c, int a, int b, unsigned short charcolor, unsigned short bgcolor)
{ 
    int i,j;
    int cbit=0;
    int casc=c;
    for (i=0;i<5;i++)
    {
    char chk=ASCII[casc-32][i];
        for (j=0;j<7;j++)
        {
            cbit=chk>>j&1;
            if(cbit==1)
                LCD_drawPixel(a+i,b+j,charcolor);
            if(cbit==0)
                LCD_drawPixel(a+i,b+j,bgcolor);
        }
    }
}

void LCD_drawstring(char*m,int x, int y,unsigned short charcolor, unsigned short bgcolor)
{
    int t=0;
    while(m[t])
    {
        LCD_drawchar(m[t],x+(t*5),y,charcolor,bgcolor);
        t++;
    }
}

void drawBarH(unsigned short x, unsigned short y, signed short n1o, unsigned short color_on, unsigned short color_off, unsigned int width, unsigned int length, signed short n1max){
       
        unsigned short ni1=0;
        unsigned short ni2=0;
        unsigned short yi=0;
        signed short length_max_v = length/2;
        signed short n1 = n1o/n1max;
        
        for(yi=0; yi<=width; yi++){ //loop over length of the bar
            
            if(n1>0){
                 for (ni2=0; ni2<=length_max_v ; ni2++){ //if acceleration is negative, turn off the positive side
                     LCD_drawPixel(x-ni2, y+yi, color_off);
                      }  
                if (n1<=length_max_v){
                    for (ni1=0; ni1<=n1 ; ni1++){ //color the bar up to the value of the acceleration
                     LCD_drawPixel(x+ni1, y+yi, color_on);
                    }
                     for (ni2=n1; ni2<=length_max_v ; ni2++){ //turn off the pixels that are greater than the acceleration
                     LCD_drawPixel(x+ni2, y+yi, color_off);
                      }     
                     }
                 
                else{
                     for (ni1=0; ni1<=length_max_v ; ni1++){ //turn on whole bar if acceleration is greater than the length
                     LCD_drawPixel(x+ni1, y+yi, color_on);
                    }
                    }
                
            }
            
           
            if(n1<0){
                for (ni2=0; ni2<=length_max_v ; ni2++){ //turn off the positive side of the bar 
                     LCD_drawPixel(x+ni2, y+yi, color_off);
                      } 
                if (-n1<=length_max_v){
                    for (ni1=0; ni1<=-n1 ; ni1++){ //turn on the part of the bar that matches the acceleration
                     LCD_drawPixel(x-ni1, y+yi, color_on);
                    }
                     for (ni2=-n1; ni2<=length_max_v ; ni2++){ //turn off the parts greater than the acceleration
                     LCD_drawPixel(x-ni2, y+yi, color_off);
                     }
                     }
                 
                else{
                     for (ni1=0; ni1<=length_max_v ; ni1++){ //loop over n1 values of n (color on of the bar)
                     LCD_drawPixel(x-ni1, y+yi, color_on);
                    }
                 }
            }
            
        
        
        }
    }
    
    void drawBarV(unsigned short x, unsigned short y, signed short n1o, unsigned short color_on, unsigned short color_off, unsigned int width, unsigned int length, signed short n1max){
       
        unsigned short ni1=0;
        unsigned short ni2=0;
        unsigned short xi=0;
        signed short length_max_v = length/2;
        signed short n1 = n1o/n1max;
        
        for(xi=0; xi<=width; xi++){ //loop over width of the bar
            
            if(n1>0){
                 for (ni2=0; ni2<=length_max_v ; ni2++){ //loop over n2 values of n (color off of the bar background)
                     LCD_drawPixel(x+xi, y-ni2, color_off);
                      }  
                if (n1<length_max_v){
                    for (ni1=0; ni1<=n1 ; ni1++){ //loop over n1 values of n (color on of the bar)
                     LCD_drawPixel(x+xi, y+ni1, color_on);
                    }
                     for (ni2=n1; ni2<=length_max_v ; ni2++){ //loop over n2 values of n (color off of the bar background)
                     LCD_drawPixel(x+xi, y+ni2, color_off);
                      }     
                     }
                 
                else{
                     for (ni1=0; ni1<=length_max_v ; ni1++){ //loop over n1 values of n (color on of the bar)
                     LCD_drawPixel(x+xi, y+ni1, color_on);
                    }
                    }
                
            }
            
           
            if(n1<0){
                for (ni2=0; ni2<=length_max_v ; ni2++){ //loop over n2 values of n (color off of the bar background)
                     LCD_drawPixel(x+xi, y+ni2, color_off);
                      } 
                if (-n1<=length_max_v){
                    for (ni1=0; ni1<=-n1 ; ni1++){ //loop over n1 values of n (color on of the bar)
                     LCD_drawPixel(x+xi, y-ni1, color_on);
                    }
                     for (ni2=-n1; ni2<=length_max_v ; ni2++){ //loop over n2 values of n (color off of the bar background)
                     LCD_drawPixel(x+xi, y-ni2, color_off);
                     }
                     }
                 
                else{
                     for (ni1=0; ni1<=length_max_v ; ni1++){ //loop over n1 values of n (color on of the bar)
                     LCD_drawPixel(x+xi, y-ni1, color_on);
                    }
                 }
            }
            
        
        
        }
    }
    

void LCD_button(unsigned short x_cor, unsigned short y_cor, int wid, int len ,unsigned short color_on)
{
    int i;
    int k;
     for(i=0; i<=wid; i++)
     {
         
         for (k =0; k<=len; k++)
         {
         LCD_drawPixel(x_cor+i, y_cor+k,color_on);
         }
     }
    
}

void setgui()
{
    unsigned short bg=0x780F; // background color
    LCD_clearScreen(bg);   
}


void drawbutton(unsigned short x_p, unsigned short y,int len_y, int wid_x, unsigned short color, unsigned short textcolor,char *buttontype)
{
    unsigned char str_sign [20];
    LCD_button(x_p, y, wid_x, len_y ,color);
    //sprintf(str_sign, "+");
    LCD_drawstring(buttontype,((x_p+(wid_x/2))-2),((y+(len_y/2))-2),textcolor,color);
    //sprintf(str_sign, "-");
    //LCD_drawstring(str_sign,((x_m+(wid_x/2))-2),((y+(len_y/2))-2),color,textcolor);
    
}

void XPT2046_read(unsigned short *x, unsigned short *y, unsigned int *z)
{
    
    unsigned char zero_byte = 0x00;
    unsigned char low_byte;
    unsigned char high_byte;
    unsigned char cmd_byte;
    
    short x_comb=0;
    short y_comb=0;
    short z1_comb=0;
    short z2_comb=0;
  
    
    // X Value
    // Start (1), address (101), Mode(0), SER(0), PD (01)
    cmd_byte = 0b11010011;
    
    TCS =0; //ready to talk
    //1st transaction
    spi2_io(cmd_byte);
    //2nd transaction 
    high_byte = spi2_io(zero_byte);
    //3rd transaction
    low_byte = spi2_io(zero_byte);
    
    TCS = 1; // done talking
    
    x_comb= (high_byte << 8) | low_byte ;
    *x = x_comb >> 3;
    
     // Y Value
    // Start (1), address (001), Mode(0), SER(0), PD (01)
    cmd_byte = 0b10010001;
    
    TCS =0; //ready to talk
    //1st transaction
    spi2_io(cmd_byte);
    //2nd transaction 
    high_byte = spi2_io(zero_byte);
    //3rd transaction
    low_byte = spi2_io(zero_byte);
    
    TCS = 1; // done talking
    
    y_comb= (high_byte << 8) | low_byte;
    *y = y_comb >> 3;
    
    
     // Z1 Value
    // Start (1), address (011), Mode(0), SER(0), PD (01)
    cmd_byte = 0b10110001;
    
    TCS =0; //ready to talk
    //1st transaction
    spi2_io(cmd_byte);
    //2nd transaction 
    high_byte = spi2_io(zero_byte);
    //3rd transaction
    low_byte = spi2_io(zero_byte);
    
    TCS = 1; // done talking
    
    z1_comb = (high_byte << 8) | low_byte;
    z1_comb = z1_comb >> 3;
    
    
    // Z2 Value
    // Start (1), address (100), Mode(0), SER(0), PD (01)
    cmd_byte = 0b11000001;
    
    TCS =0; //ready to talk
    //1st transaction
    spi2_io(cmd_byte);
    //2nd transaction 
    high_byte = spi2_io(zero_byte);
    //3rd transaction
    low_byte = spi2_io(zero_byte);
    
    TCS = 1; // done talking
    
    z2_comb = (high_byte << 8) | low_byte;
    z2_comb = z2_comb >> 3;
    
    *z = z1_comb - z2_comb + 4095;
       
    
}