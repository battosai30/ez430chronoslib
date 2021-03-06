

// driver
#include "display_ez.h"

const char int_to_array_conversion_table[][4] = {
    "000", "001", "002", "003", "004", "005", "006", "007", "008", "009", "010", "011", "012",
    "013", "014", "015",
    "016", "017", "018", "019", "020", "021", "022", "023", "024", "025", "026", "027", "028",
    "029", "030", "031",
    "032", "033", "034", "035", "036", "037", "038", "039", "040", "041", "042", "043", "044",
    "045", "046", "047",
     "048", "049", "050", "051", "052", "053", "054", "055", "056", "057", "058", "059", "060",
    "061", "062", "063",
    "064", "065", "066", "067", "068", "069", "070", "071", "072", "073", "074", "075", "076",
    "077", "078", "079",
    "080", "081", "082", "083", "084", "085", "086", "087", "088", "089", "090", "091", "092",
    "093", "094", "095",
    "096", "097", "098", "099", "100", "101", "102", "103", "104", "105", "106", "107", "108",
    "109", "110", "111",
    "112", "113", "114", "115", "116", "117", "118", "119", "120", "121", "122", "123", "124",
    "125", "126", "127",
    "128", "129", "130", "131", "132", "133", "134", "135", "136", "137", "138", "139", "140",
    "141", "142", "143",
    "144", "145", "146", "147", "148", "149", "150", "151", "152", "153", "154", "155", "156",
    "157", "158", "159",
    "160", "161", "162", "163", "164", "165", "166", "167", "168", "169", "170", "171", "172",
    "173", "174", "175",
    "176", "177", "178", "179", "180", 
};

// *************************************************************************************************
// Defines section

// *************************************************************************************************
// Global Variable section

// Table with memory bit assignment for digits "0" to "9" and unsigned characters "A" to "Z"
const char lcd_font[] = {
    SEG_A + SEG_B + SEG_C + SEG_D + SEG_E + SEG_F,         // Displays "0"
    SEG_B + SEG_C,                                         // Displays "1"
    SEG_A + SEG_B + SEG_D + SEG_E + SEG_G,                 // Displays "2"
    SEG_A + SEG_B + SEG_C + SEG_D + SEG_G,                 // Displays "3"
    SEG_B + SEG_C + SEG_F + SEG_G,                         // Displays "4"
    SEG_A + SEG_C + SEG_D + SEG_F + SEG_G,                 // Displays "5"
    SEG_A + SEG_C + SEG_D + SEG_E + SEG_F + SEG_G,         // Displays "6"
    SEG_A + SEG_B + SEG_C,                                 // Displays "7"
    SEG_A + SEG_B + SEG_C + SEG_D + SEG_E + SEG_F + SEG_G, // Displays "8"
    SEG_A + SEG_B + SEG_C + SEG_D + SEG_F + SEG_G,         // Displays "9"
    0,                                                     // Displays " "
    0,                                                     // Displays " "
    0,                                                     // Displays " "
    0,                                                     // Displays " "
    0,                                                     // Displays " "
    SEG_D + SEG_E + SEG_G,                                 // Displays "c"
    0,                                                     // Displays " "
    SEG_A + SEG_B + SEG_C + SEG_E + SEG_F + SEG_G,         // Displays "A"
    SEG_C + SEG_D + SEG_E + SEG_F + SEG_G,                 // Displays "b"
    SEG_A + SEG_D + SEG_E + SEG_F,                         // Displays "C"
    SEG_B + SEG_C + SEG_D + SEG_E + SEG_G,                 // Displays "d"
    SEG_A + +SEG_D + SEG_E + SEG_F + SEG_G,                // Displays "E"
    SEG_A + SEG_E + SEG_F + SEG_G,                         // Displays "F"
    //  SEG_A+      SEG_C+SEG_D+SEG_E+SEG_F+SEG_G,       // Displays "G"
    SEG_A + SEG_B + SEG_C + SEG_D + SEG_F + SEG_G,         // Displays "g"
    SEG_B + SEG_C + SEG_E + SEG_F + SEG_G,                 // Displays "H"
    SEG_E + SEG_F,                                         // Displays "I"
    SEG_A + SEG_B + SEG_C + SEG_D,                         // Displays "J"
    //              SEG_B+SEG_C+      SEG_E+SEG_F+SEG_G,     // Displays "k"
    SEG_D + SEG_E + SEG_F + SEG_G,                         // Displays "k"
    SEG_D + SEG_E + SEG_F,                                 // Displays "L"
    SEG_A + SEG_B + SEG_C + SEG_E + SEG_F,                 // Displays "M"
    SEG_C + SEG_E + SEG_G,                                 // Displays "n"
    SEG_C + SEG_D + SEG_E + SEG_G,                         // Displays "o"
    SEG_A + SEG_B + SEG_E + SEG_F + SEG_G,                 // Displays "P"
    SEG_A + SEG_B + SEG_C + SEG_D + SEG_E + SEG_F,         // Displays "Q"
    SEG_E + SEG_G,                                         // Displays "r"
    SEG_A + SEG_C + SEG_D + SEG_F + SEG_G,                 // Displays "S"
    SEG_D + SEG_E + SEG_F + SEG_G,                         // Displays "t"
    SEG_C + SEG_D + SEG_E,                                 // Displays "u"
    SEG_C + SEG_D + SEG_E,                                 // Displays "u"
    SEG_G,                                                 // Displays "-"
    SEG_B + SEG_C + +SEG_E + SEG_F + SEG_G,                // Displays "X"
    SEG_B + SEG_C + SEG_D + SEG_F + SEG_G,                 // Displays "Y"
    SEG_A + SEG_B + SEG_D + SEG_E + SEG_G,                 // Displays "Z"
};

// Table with memory address for each display element
const unsigned char *segments_lcdmem[] = {
    LCD_SYMB_AM_MEM,
    LCD_SYMB_PM_MEM,
    LCD_SYMB_ARROW_UP_MEM,
    LCD_SYMB_ARROW_DOWN_MEM,
    LCD_SYMB_PERCENT_MEM,
    LCD_SYMB_TOTAL_MEM,
    LCD_SYMB_AVERAGE_MEM,
    LCD_SYMB_MAX_MEM,
    LCD_SYMB_BATTERY_MEM,
    LCD_UNIT_L1_FT_MEM,
    LCD_UNIT_L1_K_MEM,
    LCD_UNIT_L1_M_MEM,
    LCD_UNIT_L1_I_MEM,
    LCD_UNIT_L1_PER_S_MEM,
    LCD_UNIT_L1_PER_H_MEM,
    LCD_UNIT_L1_DEGREE_MEM,
    LCD_UNIT_L2_KCAL_MEM,
    LCD_UNIT_L2_KM_MEM,
    LCD_UNIT_L2_MI_MEM,
    LCD_ICON_HEART_MEM,
    LCD_ICON_STOPWATCH_MEM,
    LCD_ICON_RECORD_MEM,
    LCD_ICON_ALARM_MEM,
    LCD_ICON_BEEPER1_MEM,
    LCD_ICON_BEEPER2_MEM,
    LCD_ICON_BEEPER3_MEM,
    LCD_SEG_L1_3_MEM,
    LCD_SEG_L1_2_MEM,
    LCD_SEG_L1_1_MEM,
    LCD_SEG_L1_0_MEM,
    LCD_SEG_L1_COL_MEM,
    LCD_SEG_L1_DP1_MEM,
    LCD_SEG_L1_DP0_MEM,
    LCD_SEG_L2_5_MEM,
    LCD_SEG_L2_4_MEM,
    LCD_SEG_L2_3_MEM,
    LCD_SEG_L2_2_MEM,
    LCD_SEG_L2_1_MEM,
    LCD_SEG_L2_0_MEM,
    LCD_SEG_L2_COL1_MEM,
    LCD_SEG_L2_COL0_MEM,
    LCD_SEG_L2_DP_MEM,
};

// Table with bit mask for each display element
const char segments_bitmask[] = {
    LCD_SYMB_AM_MASK,
    LCD_SYMB_PM_MASK,
    LCD_SYMB_ARROW_UP_MASK,
    LCD_SYMB_ARROW_DOWN_MASK,
    LCD_SYMB_PERCENT_MASK,
    LCD_SYMB_TOTAL_MASK,
    LCD_SYMB_AVERAGE_MASK,
    LCD_SYMB_MAX_MASK,
    LCD_SYMB_BATTERY_MASK,
    LCD_UNIT_L1_FT_MASK,
    LCD_UNIT_L1_K_MASK,
    LCD_UNIT_L1_M_MASK,
    LCD_UNIT_L1_I_MASK,
    LCD_UNIT_L1_PER_S_MASK,
    LCD_UNIT_L1_PER_H_MASK,
    LCD_UNIT_L1_DEGREE_MASK,
    LCD_UNIT_L2_KCAL_MASK,
    LCD_UNIT_L2_KM_MASK,
    LCD_UNIT_L2_MI_MASK,
    LCD_ICON_HEART_MASK,
    LCD_ICON_STOPWATCH_MASK,
    LCD_ICON_RECORD_MASK,
    LCD_ICON_ALARM_MASK,
    LCD_ICON_BEEPER1_MASK,
    LCD_ICON_BEEPER2_MASK,
    LCD_ICON_BEEPER3_MASK,
    LCD_SEG_L1_3_MASK,
    LCD_SEG_L1_2_MASK,
    LCD_SEG_L1_1_MASK,
    LCD_SEG_L1_0_MASK,
    LCD_SEG_L1_COL_MASK,
    LCD_SEG_L1_DP1_MASK,
    LCD_SEG_L1_DP0_MASK,
    LCD_SEG_L2_5_MASK,
    LCD_SEG_L2_4_MASK,
    LCD_SEG_L2_3_MASK,
    LCD_SEG_L2_2_MASK,
    LCD_SEG_L2_1_MASK,
    LCD_SEG_L2_0_MASK,
    LCD_SEG_L2_COL1_MASK,
    LCD_SEG_L2_COL0_MASK,
    LCD_SEG_L2_DP_MASK,
};

// Global return string for int_to_array function
char int_to_array_str[8];

// *************************************************************************************************


// *************************************************************************************************
// @fn          lcd_init
// @brief       Erase LCD memory. Init LCD peripheral.
// @param       none
// @return      none
// *************************************************************************************************
void lcd_init(void)
{
    // Clear entire display memory
    LCDBMEMCTL |= LCDCLRBM + LCDCLRM;

    // LCD_FREQ = ACLK/16/8 = 256Hz
    // Frame frequency = 256Hz/4 = 64Hz, LCD mux 4, LCD on
    LCDBCTL0 = (LCDDIV0 + LCDDIV1 + LCDDIV2 + LCDDIV3) | (LCDPRE0 + LCDPRE1) | LCD4MUX | LCDON;

    // LCB_BLK_FREQ = ACLK/8/4096 = 1Hz
    LCDBBLKCTL = LCDBLKPRE0 | LCDBLKPRE1 | LCDBLKDIV0 | LCDBLKDIV1 | LCDBLKDIV2 | LCDBLKMOD0;

    // I/O to COM outputs
    P5SEL |= (BIT5 | BIT6 | BIT7);
    P5DIR |= (BIT5 | BIT6 | BIT7);

    // Activate LCD output
    LCDBPCTL0 = 0xFFFF;         // Select LCD segments S0-S15
    LCDBPCTL1 = 0x00FF;         // Select LCD segments S16-S22

#ifdef USE_LCD_unsigned charGE_PUMP
    // unsigned charge pump voltage generated internally, internal bias (V2-V4) generation
    LCDBVCTL = LCDCPEN | VLCD_2_72;
#endif
}

// *************************************************************************************************
// @fn          clear_display_all
// @brief       Erase LINE1 and LINE2 segments. Clear also function-specific content.
// @param       none
// @return      none
// *************************************************************************************************
void clear_display_all(void)
{
    // Clear generic content
    clear_line(LINE1);
    clear_line(LINE2);

}

// *************************************************************************************************
// @fn          clear_display
// @brief       Erase LINE1 and LINE2 segments. Keep icons.
// @param       none
// @return      none
// *************************************************************************************************
void clear_display(void)
{
    clear_line(LINE1);
    clear_line(LINE2);
}

// *************************************************************************************************
// @fn          clear_line
// @brief       Erase segments of a given line.
// @param       unsigned char line LINE1, LINE2
// @return      none
// *************************************************************************************************
void clear_line( char line)
{
    display_chars(switch_seg(line, LCD_SEG_L1_3_0, LCD_SEG_L2_5_0), NULL, SEG_OFF);
    if (line == LINE1)
    {
        display_symbol(LCD_SEG_L1_DP1, SEG_OFF);
        display_symbol(LCD_SEG_L1_DP0, SEG_OFF);
        display_symbol(LCD_SEG_L1_COL, SEG_OFF);
    }
    else                        // line == LINE2
    {
        display_symbol(LCD_SEG_L2_DP, SEG_OFF);
        display_symbol(LCD_SEG_L2_COL1, SEG_OFF);
        display_symbol(LCD_SEG_L2_COL0, SEG_OFF);
    }
}

// *************************************************************************************************
// @fn          write_segment
// @brief       Write to one or multiple LCD segments
// @param       lcdmem          Pointer to LCD byte memory
//                              bits            Segments to address
//                              bitmask         Bitmask for particular display item
//                              mode            On, off or blink segments
// @return
// *************************************************************************************************
void write_lcd_mem( char * lcdmem,  char bits, char bitmask,  char state)
{
    if (state == SEG_ON)
    {
        // Clear segments before writing
        *lcdmem = (char) (*lcdmem & ~bitmask);

        // Set visible segments
        *lcdmem = ( char) (*lcdmem | bits);
    }
    else if (state == SEG_OFF)
    {
        // Clear segments
        *lcdmem = ( char) (*lcdmem & ~bitmask);
    }
    else if (state == SEG_ON_BLINK_ON)
    {
        // Clear visible / blink segments before writing
        *lcdmem = ( char) (*lcdmem & ~bitmask);
        *(lcdmem + 0x20) = ( char) (*(lcdmem + 0x20) & ~bitmask);

        // Set visible / blink segments
        *lcdmem = (char) (*lcdmem | bits);
        *(lcdmem + 0x20) = ( char) (*(lcdmem + 0x20) | bits);
    }
    else if (state == SEG_ON_BLINK_OFF)
    {
        // Clear visible segments before writing
        *lcdmem = ( char) (*lcdmem & ~bitmask);

        // Set visible segments
        *lcdmem = (char) (*lcdmem | bits);

        // Clear blink segments
        *(lcdmem + 0x20) = ( char) (*(lcdmem + 0x20) & ~bitmask);
    }
    else if (state == SEG_OFF_BLINK_OFF)
    {
        // Clear segments
        *lcdmem = ( char) (*lcdmem & ~bitmask);

        // Clear blink segments
        *(lcdmem + 0x20) = (char) (*(lcdmem + 0x20) & ~bitmask);
    }
}

// *************************************************************************************************
// @fn          int_to_array
// @brief       Generic integer to array routine. Converts integer n to string.
//                              Default conversion result has leading zeros, e.g. "00123"
//                              Option to convert leading '0' into whitespace (blanks)
// @param       unsigned long n                   integer to convert
//                              unsigned char digits               number of digits
//                              unsigned char blanks               fill up result string with number of
// whitespaces instead of leading zeros
// @return      unsigned char                              string
// *************************************************************************************************
 char *int_to_array(uint32_t n, uint8_t digits, uint8_t blanks)
{
    char i;
   char digits1 = digits;

    // Preset result string
    memcpy(int_to_array_str, "0000000", 7);

    // Return empty string if number of digits is invalid (valid range for digits: 1-7)
    if ((digits == 0) || (digits > 7))
        return (int_to_array_str);

    // Numbers 0 .. 180 can be copied from int_to_array_conversion_table without conversion
    if (n <= 180)
    {
        if (digits >= 3)
        {
            memcpy(int_to_array_str + (digits - 3), int_to_array_conversion_table[n], 3);
        }
        else                    // digits == 1 || 2
        {
            memcpy(int_to_array_str, int_to_array_conversion_table[n] + (3 - digits), digits);
        }
    }
    else                        // For n > 180 need to calculate string content
    {
        // Calculate digits from least to most significant number
        do
        {
            int_to_array_str[digits - 1] = n % 10 + '0';
            n /= 10;
        }
        while (--digits > 0);
    }

    // Remove specified number of leading '0', always keep last one
    i = 0;
    while ((int_to_array_str[i] == '0') && (i < digits1 - 1))
    {
        if (blanks > 0)
        {
            // Convert only specified number of leading '0'
            int_to_array_str[i] = ' ';
            blanks--;
        }
        i++;
    }

    return (int_to_array_str);
}

// *************************************************************************************************
// @fn          display_value
// @brief       Generic decimal display routine. Used exclusively by set_value function.
// @param       unsigned char segments                     LCD segments where value is displayed
//                              unsigned long value                       Integer value to be displayed
//                              unsigned char digits                       Number of digits to convert
//                              unsigned char blanks                       Number of leadings blanks in
// int_to_array result string
// @return      none
// *************************************************************************************************
void display_value(char segments,  long value,  char digits,  char blanks)
{
    char *str;

    str = int_to_array(value, digits, blanks);

    // Display string in blink mode
    display_chars(segments, str, SEG_ON_BLINK_ON);
}




// *************************************************************************************************
// @fn          display_symbol
// @brief       Switch symbol on or off on LCD.
// @param       unsigned char symbol               A valid LCD symbol (index 0..42)
//                              unsigned char state                SEG_ON, SEG_OFF, SEG_BLINK
// @return      none
// *************************************************************************************************
void display_symbol( char symbol,  char mode)
{
    char *lcdmem;
     char bits;
     char bitmask;

    if (symbol <= LCD_SEG_L2_DP)
    {
        // Get LCD memory address for symbol from table
        lcdmem = (char *) segments_lcdmem[symbol];

        // Get bits for symbol from table
        bits = segments_bitmask[symbol];

        // Bitmask for symbols equals bits
        bitmask = bits;

        // Write LCD memory
        write_lcd_mem(lcdmem, bits, bitmask, mode);
    }
}

// *************************************************************************************************
// @fn          display_unsigned char
// @brief       Write to 7-segment unsigned characters.
// @param       unsigned char segment              A valid LCD segment
//                              unsigned char chr                  unsigned character to display
//                              unsigned char mode         SEG_ON, SEG_OFF, SEG_BLINK
// @return      none
// *************************************************************************************************
void display_char(char segment, char chr,  char mode)
{
    char *lcdmem;                 // Pointer to LCD memory
    char bitmask;                 // Bitmask for unsigned character
    char bits, bits1;             // Bits to write

    // Write to single 7-segment unsigned character
    if ((segment >= LCD_SEG_L1_3) && (segment <= LCD_SEG_L2_DP))
    {
        // Get LCD memory address for segment from table
        lcdmem = (char *) segments_lcdmem[segment];

        // Get bitmask for unsigned character from table
        bitmask = segments_bitmask[segment];

        // Get bits from font set
        if ((chr >= 0x30) && (chr <= 0x5A))
        {
            // Use font set
            bits = lcd_font[chr - 0x30];
        }
        else if (chr == 0x2D)
        {
            // '-' not in font set
            bits = BIT1;
        }
        else
        {
            // Other unsigned characters map to ' ' (blank)
            bits = 0;
        }

        // When addressing LINE2 7-segment unsigned characters need to swap high- and low-nibble,
        // because LCD COM/SEG assignment is mirrored against LINE1
        if (segment >= LCD_SEG_L2_5)
        {
            bits1 = ((bits << 4) & 0xF0) | ((bits >> 4) & 0x0F);
            bits = bits1;

            // When addressing LCD_SEG_L2_5, need to convert ASCII '1' and 'L' to 1 bit,
            // because LCD COM/SEG assignment is special for this incomplete unsigned character
            if (segment == LCD_SEG_L2_5)
            {
                if ((chr == '1') || (chr == 'L'))
                    bits = BIT7;
            }
        }

        // Physically write to LCD memory
        write_lcd_mem(lcdmem, bits, bitmask, mode);
    }
}

// *************************************************************************************************
// @fn          display_unsigned chars
// @brief       Write to consecutive 7-segment unsigned characters.
// @param       unsigned char segments     LCD segment array
//                              unsigned char * str                Pointer to a string
//                              unsigned char mode             SEG_ON, SEG_OFF, SEG_BLINK
// @return      none
// *************************************************************************************************
void display_chars(char segments, char * str,  char mode)
{
    char i;
     char length = 0;              // Write length
     char char_start;              // Starting point for consecutive write

    switch (segments)
    {
        // LINE1
        case LCD_SEG_L1_3_0:
            length = 4;
            char_start = LCD_SEG_L1_3;
            break;
        case LCD_SEG_L1_2_0:
            length = 3;
            char_start = LCD_SEG_L1_2;
            break;
        case LCD_SEG_L1_1_0:
            length = 2;
            char_start = LCD_SEG_L1_1;
            break;
        case LCD_SEG_L1_3_1:
            length = 3;
            char_start = LCD_SEG_L1_3;
            break;
        case LCD_SEG_L1_3_2:
            length = 2;
            char_start = LCD_SEG_L1_3;
            break;

        // LINE2
        case LCD_SEG_L2_5_0:
            length = 6;
            char_start = LCD_SEG_L2_5;
            break;
        case LCD_SEG_L2_4_0:
            length = 5;
             char_start = LCD_SEG_L2_4;
            break;
        case LCD_SEG_L2_3_0:
            length = 4;
            char_start = LCD_SEG_L2_3;
            break;
        case LCD_SEG_L2_2_0:
            length = 3;
            char_start = LCD_SEG_L2_2;
            break;
        case LCD_SEG_L2_1_0:
            length = 2;
            char_start = LCD_SEG_L2_1;
            break;
        case LCD_SEG_L2_5_4:
            length = 2;
            char_start = LCD_SEG_L2_5;
            break;
        case LCD_SEG_L2_5_2:
            length = 4;
            char_start = LCD_SEG_L2_5;
            break;
        case LCD_SEG_L2_3_2:
            length = 2;
            char_start = LCD_SEG_L2_3;
            break;
        case LCD_SEG_L2_4_2:
            length = 3;
            char_start = LCD_SEG_L2_4;
            break;
    }

    // Write to consecutive digits
    for (i = 0; i < length; i++)
    {
        // Use single unsigned character routine to write display memory
        display_char(char_start + i, *(str + i), mode);
    }
}

// *************************************************************************************************
// @fn          switch_seg
// @brief       Returns index of 7-segment unsigned character. Required for display routines that can draw
//                              information on both lines.
// @param       unsigned char line             LINE1 or LINE2
//                              unsigned char index1               Index of LINE1
//                              unsigned char index2               Index of LINE2
// @return      uint8
// *************************************************************************************************
char switch_seg( char line,  char index1, char index2)
{
    if (line == LINE1)
    {
        return index1;
    }
    else                        // line == LINE2
    {
        return index2;
    }
}

// *************************************************************************************************
// @fn          start_blink
// @brief       Start blinking.
// @param       none
// @return      none
// *************************************************************************************************
void start_blink(void)
{
    LCDBBLKCTL |= LCDBLKMOD0;
}

// *************************************************************************************************
// @fn          stop_blink
// @brief       Stop blinking.
// @param       none
// @return      none
// *************************************************************************************************
void stop_blink(void)
{
    LCDBBLKCTL &= ~LCDBLKMOD0;
}

// *************************************************************************************************
// @fn          stop_blink
// @brief       Clear blinking memory.
// @param       none
// @return      none
// *************************************************************************************************
void clear_blink_mem(void)
{
    LCDBMEMCTL |= LCDCLRBM;
}

// *************************************************************************************************
// @fn          set_blink_rate
// @brief       Set blink rate register bits.
// @param       none
// @return      none
// *************************************************************************************************
void set_blink_rate(char bits)
{
    LCDBBLKCTL &= ~(BIT7 | BIT6 | BIT5);
    LCDBBLKCTL |= bits;
}

