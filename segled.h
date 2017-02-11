#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define  NODE_EXP                  "/dev/7seg_led"

#define  SEG_7_LED_ON              1
#define  SEG_7_LED_WRITE           2
#define  SEG_7_LED_CLEAR           3
#define  SEG_7_LED_OFF             4

int exp_dev;
int i,res = 0;

void segmentled_open() {
	exp_dev =  open(NODE_EXP, O_RDWR);
	if (exp_dev < 0) {
		fprintf(stderr, "Open error: %s\n", NODE_EXP);
		close(exp_dev);
		//return 1;
	}
	if (res = ioctl(exp_dev, SEG_7_LED_ON, NULL) < 0) {
		printf("%d---> Error in switching ON the LED \r\n", res);
		close(exp_dev);
		//return 1;
	}
}
	/* open as blocking mode */
	//clear the exising no
void segmentled() {
	if (res = ioctl(exp_dev, SEG_7_LED_CLEAR, NULL) < 0) {
		printf("%d---> Error in Clearing the LED \r\n", res);
		close(exp_dev);

	}
	
	//Conter Delay for Glucose
for(i=50;i>=0;i--)
	{
	
	if (res = ioctl(exp_dev, SEG_7_LED_WRITE, i) < 0) {
		printf("%d---> Error in writing to the 7-Seg LED \r\n", res);
	
	}
	
}
}
void segmentled_close()
{
	if (res = ioctl(exp_dev, SEG_7_LED_OFF, NULL) < 0) {
		printf("%d---> Error in switching off  the LED \r\n", res);
		close(exp_dev);

	}
close(exp_dev);
}
