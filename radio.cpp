#include "radio.h"
#include "Energia.h"
#include "rf1a.h"


// *************************************************************************************************
// @fn          radio_reset
// @brief       Reset radio core.
// @param       none
// @return      none
// *************************************************************************************************
void radio_reset(void)
{
    volatile unsigned int i;
    unsigned char x;

    // Reset radio core
    Strobe(RF_SRES);
    // Wait before checking IDLE
    for (i = 0; i < 100; i++) ;
    do
    {
        x = Strobe(RF_SIDLE);
    }
    while ((x & 0x70) != 0x00);

    // Clear radio error register
    RF1AIFERR = 0;
}


// *************************************************************************************************
// @fn          radio_powerdown
// @brief       Put radio to SLEEP mode.
// @param       none
// @return      none
// *************************************************************************************************
void radio_powerdown(void)
{
    // Chip bug: Radio does not come out of this SLEEP when put to sleep
    // using the SPWD cmd. However, it does wakes up if SXOFF was used to
    // put it to sleep.

    // Powerdown radio
    Strobe(RF_SIDLE);
    Strobe(RF_SPWD);
}

// *************************************************************************************************
// @fn          radio_sxoff
// @brief       Put radio to SLEEP mode (XTAL off only).
// @param       none
// @return      none
// *************************************************************************************************
void radio_sxoff(void)
{
    // Chip bug: Radio does not come out of this SLEEP when put to sleep
    // using the SPWD cmd. However, it does wakes up if SXOFF was used to
    // put it to sleep.

    // Powerdown radio
    Strobe(RF_SIDLE);
    Strobe(RF_SXOFF);
}

// *************************************************************************************************
// @fn          open_radio
// @brief       Prepare radio for RF communication.
// @param       none
// @return      none
// *************************************************************************************************
void open_radio(void)
{
    // Reset radio core
    radio_reset();

    // Enable radio IRQ
    RF1AIFG &= ~BIT4;           // Clear a pending interrupt
    RF1AIE |= BIT4;             // Enable the interrupt
}

// *************************************************************************************************
// @fn          close_radio
// @brief       Shutdown radio for RF communication.
// @param       none
// @return      none
// *************************************************************************************************
void close_radio(void)
{
    // Disable radio IRQ
    RF1AIFG = 0;
    RF1AIE = 0;

    // Reset radio core
    radio_reset();

    // Put radio to sleep
    radio_powerdown();
}

// *************************************************************************************************
// @fn          GDOx_ISR
// @brief       GDO0/2 ISR to detect received packet.
//                              In BlueRobin mode:  capture packet end time and decode received
// packet
//                              In SimpliciTI mode: go to SimpliciTI handler
// @param       none
// @return      none
// *************************************************************************************************
#pragma vector=CC1101_VECTOR
__interrupt void radio_ISR(void)
{
    unsigned char rf1aivec = RF1AIV;

    // Forward to SimpliciTI interrupt service routine
    //if (is_rf())
	if(1)
    {
        //MRFI_RadioIsr();
    }
    else                                  // BlueRobin packet end interrupt service routine
    {
        if (rf1aivec == RF1AIV_RFIFG9)
        {
           // if ((sBlueRobin.state == BLUEROBIN_SEARCHING) ||
            //    (sBlueRobin.state == BLUEROBIN_CONNECTED))
            {
            //    BlueRobin_RadioISR_v();
            }
        }
        else if (rf1aivec == RF1AIV_NONE) // RF1A interface interrupt (error etc.)
        {
            asm ("	nop"); // break here
        }
    }
}


