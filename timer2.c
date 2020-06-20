#include <16f877.h>
#use delay(clock=4000000)
#fuses XT,NOWDT,NOPUT,NOLVP,NOCPD,NOPROTECT,NODEBUG,NOBROWNOUT,NOWRT

#use fast_io(a)
#use fast_io(b)

#define use_portb_lcd TRUE
#include <lcd.c>

unsigned int8 kesme=0;

#int_timer2
void timer2_kesme(){
 set_timer2(5);
 kesme++;
if(input(pin_a0)){

output_b(kesme);
lcd_init();
printf(lcd_putc,"\f kesme=%u",kesme);
}

}

void main()
{
   setup_psp(PSP_DISABLED);
   setup_timer_1(T1_DISABLED);
   
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF);
   
   set_tris_a(0x01); //0b 0000 0001
   set_tris_b(0x00);
   
   output_b(0x00);
   
   setup_timer_2(T2_DIV_BY_4,249,10);
   set_timer2(5);
   
   enable_interrupts(INT_timer2);
   enable_interrupts(GLOBAL);

   while(TRUE);
}






