#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define  NODE_EXP_LCD	"/dev/fpga_char_lcd"

#define  LCD_ON              1
#define  LCD_CLEAR           2
#define  LCD_SET_HOME        3
#define  LCD_CURSOR_BLINK    4
#define  LCD_DATA_WRITE      5
#define  LCD_OFF	     6

int exp_dev_lcd;

void init_lcdopen()
{
	exp_dev_lcd = open(NODE_EXP_LCD, O_RDWR);
	if (exp_dev_lcd < 0) {
		fprintf(stderr, "Open error: %s\n", NODE_EXP);
		close(exp_dev_lcd);
	}
	if (ioctl(exp_dev_lcd, LCD_ON, NULL) < 0) {
		printf("Error in swithcing on the LCD \r\n");
		close(exp_dev_lcd);

	}
}
void init_clcd(char s[]) {
	if (ioctl(exp_dev_lcd, LCD_CLEAR, NULL) < 0) {
			printf("Error in Clearing the LCD \r\n");
			close(exp_dev_lcd);

		}

	if (ioctl(exp_dev_lcd, LCD_SET_HOME, NULL) < 0) {
		printf("Error in setting the cursor in home\
			position \r\n");
		close(exp_dev_lcd);

	}

	if (ioctl(exp_dev_lcd, LCD_CURSOR_BLINK, NULL) < 0) {
		printf("Error in Curosr blinking \r\n");
		close(exp_dev_lcd);

	}

	
		if (ioctl(exp_dev_lcd, LCD_DATA_WRITE, s) < 0) {
			printf("Error in writing the LCD \r\n");
			close(exp_dev_lcd);

		}
}	
void init_lcdclose()
{	
	if (ioctl(exp_dev_lcd, LCD_OFF, NULL) < 0) {
		printf("Error in Switching OFF the LCD \r\n");
		close(exp_dev_lcd);

	}
	close(exp_dev_lcd);
}

