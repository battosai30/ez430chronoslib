#ifndef __DISPLAY_H
#define __DISPLAY_H

#include "Energia.h"
#include <msp430.h>

// *************************************************************************************************
// Extern section

// Constants defined in library
extern const unsigned char *segments_lcdmem[];
extern const  char segments_bitmask[];
extern const char int_to_array_conversion_table[][4];
extern const  char lcd_font[];

// *************************************************************************************************
// Global Variable section



// *************************************************************************************************
// Defines section

// Display function modes
#define DISPLAY_LINE_UPDATE_FULL                (BIT0)
#define DISPLAY_LINE_UPDATE_PARTIAL             (BIT1)
#define DISPLAY_LINE_CLEAR                              (BIT2)

// Definitions for line view style
#define DISPLAY_DEFAULT_VIEW                    (0u)
#define DISPLAY_ALTERNATIVE_VIEW                (1u)

// Definitions for line access
#define LINE1                                                   (1u)
#define LINE2                                                   (2u)

// LCD display modes
#define SEG_OFF                                 (0u)
#define SEG_ON                                  (1u)
#define SEG_ON_BLINK_ON                 (2u)
#define SEG_ON_BLINK_OFF                (3u)
#define SEG_OFF_BLINK_OFF               (4u)

// 7-segment unsigned character bit assignments
#define SEG_A                   (BIT4)
#define SEG_B                   (BIT5)
#define SEG_C                   (BIT6)
#define SEG_D                   (BIT7)
#define SEG_E                   (BIT2)
#define SEG_F                   (BIT0)
#define SEG_G                   (BIT1)

// ------------------------------------------
// LCD symbols for easier access
//
// xxx_SEG_xxx          = Seven-segment unsigned character (sequence 5-4-3-2-1-0)
// xxx_SYMB_xxx         = Display symbol, e.g. "AM" for ante meridiem
// xxx_UNIT_xxx         = Display unit, e.g. "km/h" for kilometers per hour
// xxx_ICON_xxx         = Display icon, e.g. heart to indicate reception of heart rate data
// xxx_L1_xxx           = Item is part of Line1 information
// xxx_L2_xxx           = Item is part of Line2 information

// Symbols for Line1
#define LCD_SYMB_AM                                     0
#define LCD_SYMB_PM                                     1
#define LCD_SYMB_ARROW_UP                       2
#define LCD_SYMB_ARROW_DOWN                     3
#define LCD_SYMB_PERCENT                        4

// Symbols for Line2
#define LCD_SYMB_TOTAL                          5
#define LCD_SYMB_AVERAGE                        6
#define LCD_SYMB_MAX                            7
#define LCD_SYMB_BATTERY                        8

// Units for Line1
#define LCD_UNIT_L1_FT                          9
#define LCD_UNIT_L1_K                           10
#define LCD_UNIT_L1_M                           11
#define LCD_UNIT_L1_I                           12
#define LCD_UNIT_L1_PER_S                       13
#define LCD_UNIT_L1_PER_H                       14
#define LCD_UNIT_L1_DEGREE                      15

// Units for Line2
#define LCD_UNIT_L2_KCAL                        16
#define LCD_UNIT_L2_KM                          17
#define LCD_UNIT_L2_MI                          18

// Icons
#define LCD_ICON_HEART                          19
#define LCD_ICON_STOPWATCH                      20
#define LCD_ICON_RECORD                         21
#define LCD_ICON_ALARM                          22
#define LCD_ICON_BEEPER1                        23
#define LCD_ICON_BEEPER2                        24
#define LCD_ICON_BEEPER3                        25

// Line1 7-segments
#define LCD_SEG_L1_3                            26
#define LCD_SEG_L1_2                            27
#define LCD_SEG_L1_1                            28
#define LCD_SEG_L1_0                            29
#define LCD_SEG_L1_COL                          30
#define LCD_SEG_L1_DP1                          31
#define LCD_SEG_L1_DP0                          32

// Line2 7-segments
#define LCD_SEG_L2_5                            33
#define LCD_SEG_L2_4                            34
#define LCD_SEG_L2_3                            35
#define LCD_SEG_L2_2                            36
#define LCD_SEG_L2_1                            37
#define LCD_SEG_L2_0                            38
#define LCD_SEG_L2_COL1                         39
#define LCD_SEG_L2_COL0                         40
#define LCD_SEG_L2_DP                           41

// Line1 7-segment arrays
#define LCD_SEG_L1_3_0                          70
#define LCD_SEG_L1_2_0                          71
#define LCD_SEG_L1_1_0                          72
#define LCD_SEG_L1_3_1                          73
#define LCD_SEG_L1_3_2                          74

// Line2 7-segment arrays
#define LCD_SEG_L2_5_0                          90
#define LCD_SEG_L2_4_0                          91
#define LCD_SEG_L2_3_0                          92
#define LCD_SEG_L2_2_0                          93
#define LCD_SEG_L2_1_0                          94
#define LCD_SEG_L2_5_2                          95
#define LCD_SEG_L2_3_2                          96
#define LCD_SEG_L2_5_4                          97
#define LCD_SEG_L2_4_2                          98

// LCD controller memory map
#define LCD_MEM_1                               ((unsigned char*)0x0A20)
#define LCD_MEM_2                               ((unsigned char*)0x0A21)
#define LCD_MEM_3                               ((unsigned char*)0x0A22)
#define LCD_MEM_4                               ((unsigned char*)0x0A23)
#define LCD_MEM_5                               ((unsigned char*)0x0A24)
#define LCD_MEM_6                               ((unsigned char*)0x0A25)
#define LCD_MEM_7                               ((unsigned char*)0x0A26)
#define LCD_MEM_8                               ((unsigned char*)0x0A27)
#define LCD_MEM_9                               ((unsigned char*)0x0A28)
#define LCD_MEM_10                              ((unsigned char*)0x0A29)
#define LCD_MEM_11                              ((unsigned char*)0x0A2A)
#define LCD_MEM_12                              ((unsigned char*)0x0A2B)

// Memory assignment
#define LCD_SEG_L1_0_MEM                        (LCD_MEM_6)
#define LCD_SEG_L1_1_MEM                        (LCD_MEM_4)
#define LCD_SEG_L1_2_MEM                        (LCD_MEM_3)
#define LCD_SEG_L1_3_MEM                        (LCD_MEM_2)
#define LCD_SEG_L1_COL_MEM                      (LCD_MEM_1)
#define LCD_SEG_L1_DP1_MEM                      (LCD_MEM_1)
#define LCD_SEG_L1_DP0_MEM                      (LCD_MEM_5)
#define LCD_SEG_L2_0_MEM                        (LCD_MEM_8)
#define LCD_SEG_L2_1_MEM                        (LCD_MEM_9)
#define LCD_SEG_L2_2_MEM                        (LCD_MEM_10)
#define LCD_SEG_L2_3_MEM                        (LCD_MEM_11)
#define LCD_SEG_L2_4_MEM                        (LCD_MEM_12)
#define LCD_SEG_L2_5_MEM                        (LCD_MEM_12)
#define LCD_SEG_L2_COL1_MEM                     (LCD_MEM_1)
#define LCD_SEG_L2_COL0_MEM                     (LCD_MEM_5)
#define LCD_SEG_L2_DP_MEM                       (LCD_MEM_9)
#define LCD_SYMB_AM_MEM                         (LCD_MEM_1)
#define LCD_SYMB_PM_MEM                         (LCD_MEM_1)
#define LCD_SYMB_ARROW_UP_MEM           (LCD_MEM_1)
#define LCD_SYMB_ARROW_DOWN_MEM         (LCD_MEM_1)
#define LCD_SYMB_PERCENT_MEM            (LCD_MEM_5)
#define LCD_SYMB_TOTAL_MEM                      (LCD_MEM_11)
#define LCD_SYMB_AVERAGE_MEM            (LCD_MEM_10)
#define LCD_SYMB_MAX_MEM                        (LCD_MEM_8)
#define LCD_SYMB_BATTERY_MEM            (LCD_MEM_7)
#define LCD_UNIT_L1_FT_MEM                      (LCD_MEM_5)
#define LCD_UNIT_L1_K_MEM                       (LCD_MEM_5)
#define LCD_UNIT_L1_M_MEM                       (LCD_MEM_7)
#define LCD_UNIT_L1_I_MEM                       (LCD_MEM_7)
#define LCD_UNIT_L1_PER_S_MEM           (LCD_MEM_5)
#define LCD_UNIT_L1_PER_H_MEM           (LCD_MEM_7)
#define LCD_UNIT_L1_DEGREE_MEM          (LCD_MEM_5)
#define LCD_UNIT_L2_KCAL_MEM            (LCD_MEM_7)
#define LCD_UNIT_L2_KM_MEM                      (LCD_MEM_7)
#define LCD_UNIT_L2_MI_MEM                      (LCD_MEM_7)
#define LCD_ICON_HEART_MEM                      (LCD_MEM_2)
#define LCD_ICON_STOPWATCH_MEM          (LCD_MEM_3)
#define LCD_ICON_RECORD_MEM                     (LCD_MEM_1)
#define LCD_ICON_ALARM_MEM                      (LCD_MEM_4)
#define LCD_ICON_BEEPER1_MEM            (LCD_MEM_5)
#define LCD_ICON_BEEPER2_MEM            (LCD_MEM_6)
#define LCD_ICON_BEEPER3_MEM            (LCD_MEM_7)

// Bit masks for write access
#define LCD_SEG_L1_0_MASK                       (BIT2 + BIT1 + BIT0 + BIT7 + BIT6 + BIT5 + BIT4)
#define LCD_SEG_L1_1_MASK                       (BIT2 + BIT1 + BIT0 + BIT7 + BIT6 + BIT5 + BIT4)
#define LCD_SEG_L1_2_MASK                       (BIT2 + BIT1 + BIT0 + BIT7 + BIT6 + BIT5 + BIT4)
#define LCD_SEG_L1_3_MASK                       (BIT2 + BIT1 + BIT0 + BIT7 + BIT6 + BIT5 + BIT4)
#define LCD_SEG_L1_COL_MASK                     (BIT5)
#define LCD_SEG_L1_DP1_MASK                     (BIT6)
#define LCD_SEG_L1_DP0_MASK                     (BIT2)
#define LCD_SEG_L2_0_MASK                       (BIT3 + BIT2 + BIT1 + BIT0 + BIT6 + BIT5 + BIT4)
#define LCD_SEG_L2_1_MASK                       (BIT3 + BIT2 + BIT1 + BIT0 + BIT6 + BIT5 + BIT4)
#define LCD_SEG_L2_2_MASK                       (BIT3 + BIT2 + BIT1 + BIT0 + BIT6 + BIT5 + BIT4)
#define LCD_SEG_L2_3_MASK                       (BIT3 + BIT2 + BIT1 + BIT0 + BIT6 + BIT5 + BIT4)
#define LCD_SEG_L2_4_MASK                       (BIT3 + BIT2 + BIT1 + BIT0 + BIT6 + BIT5 + BIT4)
#define LCD_SEG_L2_5_MASK                       (BIT7)
#define LCD_SEG_L2_COL1_MASK            (BIT4)
#define LCD_SEG_L2_COL0_MASK            (BIT0)
#define LCD_SEG_L2_DP_MASK                      (BIT7)
#define LCD_SYMB_AM_MASK                        (BIT1 + BIT0)
#define LCD_SYMB_PM_MASK                        (BIT0)
#define LCD_SYMB_ARROW_UP_MASK          (BIT2)
#define LCD_SYMB_ARROW_DOWN_MASK        (BIT3)
#define LCD_SYMB_PERCENT_MASK           (BIT4)
#define LCD_SYMB_TOTAL_MASK                     (BIT7)
#define LCD_SYMB_AVERAGE_MASK           (BIT7)
#define LCD_SYMB_MAX_MASK                       (BIT7)
#define LCD_SYMB_BATTERY_MASK           (BIT7)
#define LCD_UNIT_L1_FT_MASK                     (BIT5)
#define LCD_UNIT_L1_K_MASK                      (BIT6)
#define LCD_UNIT_L1_M_MASK                      (BIT1)
#define LCD_UNIT_L1_I_MASK                      (BIT0)
#define LCD_UNIT_L1_PER_S_MASK          (BIT7)
#define LCD_UNIT_L1_PER_H_MASK          (BIT2)
#define LCD_UNIT_L1_DEGREE_MASK         (BIT1)
#define LCD_UNIT_L2_KCAL_MASK           (BIT4)
#define LCD_UNIT_L2_KM_MASK                     (BIT5)
#define LCD_UNIT_L2_MI_MASK                     (BIT6)
#define LCD_ICON_HEART_MASK                     (BIT3)
#define LCD_ICON_STOPWATCH_MASK         (BIT3)
#define LCD_ICON_RECORD_MASK            (BIT7)
#define LCD_ICON_ALARM_MASK                     (BIT3)
#define LCD_ICON_BEEPER1_MASK           (BIT3)
#define LCD_ICON_BEEPER2_MASK           (BIT3)
#define LCD_ICON_BEEPER3_MASK           (BIT3)

// *************************************************************************************************
// // API section

// Physical LCD memory write
void write_lcd_mem( char * lcdmem, char bits, char bitmask,  char state);

// Display init / clear
void lcd_init(void);
void clear_display_all(void);
void clear_line(char line);

// Blinking function
void start_blink(void);
void stop_blink(void);
void clear_blink_mem(void);
void set_blink_rate(char bits);

// unsigned character / symbol draw functions
void display_char(char segment,  char chr,  char mode);
void display_chars(char segments,  char * str,  char mode);
void display_symbol(char symbol, char mode);



// Set_value display functions
void display_value( char segments, unsigned long value,  char digits, char blanks);


// Integer to string conversion
char *int_to_array(uint32_t n, uint8_t digits, uint8_t blanks);

// Segment index helper function
 char switch_seg(char line,  char index1,  char index2);

#endif     /*DISPLAY_H_ */
