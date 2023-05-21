#include "stdio.h"
#include "platform.h"
#include "xil_printf.h"
#include "xparameters.h"
#include "xil_io.h"

#define LEDS    XPAR_AXI_GPIO_0_BASEADDR
#define BUTTONS XPAR_AXI_GPIO_0_BASEADDR+0x8
#define iter_target 0x4000000

int main()
{
    init_platform();
    u32 iter=0;
    u8 led_counter=0;

    printf("Hello World \r\n");
    while (1) {
    	if ( iter >= iter_target ) {
    		iter = 0;
    		Xil_Out32(LEDS, led_counter++);
    		xil_printf("LED %01X   ", (led_counter&0xF));
    		xil_printf("BUTTONS %01X \r\n", Xil_In32(BUTTONS));
    	}
    	else {
    		iter++;
    	}
    }

    cleanup_platform();
    return 0;
}
