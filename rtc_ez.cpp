#include "rtc_ez.h"

void RTC_init() {

#include <msp430.h>

// Enable 32kHz ACLK
    P5SEL |= 0x03;              // Select XIN, XOUT on P5.0 and P5.1
    UCSCTL6 &= ~XT1OFF;         // XT1 On, Highest drive strength
    UCSCTL6 |= XCAP_3;          // Internal load cap

	RTCCTL1 = BIT5;
    //RTCCTL1 = RTCMODE + RTCHOLD ;
	//RTCCTL01 &= ~RTCHOLD;  
	//RTCCTL1&= ~RTCHOLD;
}

byte GetSecond() {

return RTCSEC;

}