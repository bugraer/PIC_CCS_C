#include <16f877.h>
#device ADC=10
#use delay(clock=4000000)
#fuses XT,NOWDT,NOPUT,NOLVP,NOCPD,NOPROTECT,NODEBUG,NOBROWNOUT,NOWRT

#use fast_io(a)
#use fast_io(b)

#define use_portb_lcd TRUE
#include <lcd.c>

unsigned long int deger;
float gerilim;


void main()
{
   setup_psp(PSP_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF);
   
   set_tris_a(0x20); //0b 0010 0000
   set_tris_b(0x00);
   
   
   setup_adc(adc_clock_div_32);
   setup_adc_ports(ALL_ANALOG);
   
   lcd_init();
   
   while(true){
   set_adc_channel(4);
   delay_us(20);
   
   deger=read_adc();
   gerilim=deger/204.6;
   
   printf(lcd_putc,"\f%lu",deger);
   printf(lcd_putc,"\n Volt=%f V",gerilim);
   delay_ms(100);
   }


}






