# zcu104_base_io
base project for ZCU104 dev board

Zynq programs do not store code in block RAM normally, so either a BIF has to be loaded to flash, or the program must be executed from the dev environment (SDK or Vitis).  We will load from dev environment.

Instructions to create SDK 2019.1 project from this base
1) Launch SDK 2019.1 (installed with Vivado 2019.1)
2) Select new directory for the project
3) Click Create application project from main screen
   a. give project name e.g. hello
   b. New Hardware Project -> click 'New..'
   c. give name e.g. hello_hw
   d. Browse to .hdf file (it is in /sources from git)
   e. Finish (wait until helper returns Application Project)
   f. Finish
4) Open hello_bsp/system.mss file
   a. Modify BSP settings
   b. standalone section in left pane
   c. stdin/stdout select one :
	* axi_uartlite_0 - COM port on PC
	* psu_uart_0 - COM port on PC
	* psu_uart_1 - COM port on PC
	* psu_coresight_0 - Console win debug Coretex-A53#0 in SDK
5) Copy/Paste over hello/src/helloworld.c with (/sources git)
	* Project->Build all
6) Xilinx->Program FPGA (should be set up from .hdf file)
7) Right click on hello/Binaries/hello.elf
	a. Run As -> Launch on Hardware (System Debugger)


On load the Zynq should execute the following peripherals:
1) Binary counter with 4 LEDs
2) 4 push-buttons report to UART (hold down to register)
3) UART broadcast to COM port / Debug terminal as specified in
	stdout from BSP configuration above
	PC COM port settings: 115200 N-8-1 (use app like Putty)