# zcu104_base_io
* base project for ZCU104 dev board


## Note
Zynq programs do not store code in block RAM normally, so either a BIF has to be loaded to flash, or the program must be executed from the dev environment (SDK or Vitis).  We will load from dev environment.


## Vivado + SDK 2019.1
Instructions to create SDK 2019.1 project from this base
1) Launch SDK 2019.1 (installed with Vivado 2019.1)
2) Select new directory for the project
3) Click Create application project from main screen
   - give project name e.g. hello
   - New Hardware Project -> click 'New..'
   - give name e.g. hello_hw
   - Browse to .hdf file (it is in /sources from git)
   - Finish (wait until helper returns Application Project)
   - Finish
4) Open hello_bsp/system.mss file
   - Modify BSP settings
   - standalone section in left tree
   - stdin/stdout select one :
     * axi_uartlite_0 - COM port on PC
     * psu_uart_0 - COM port on PC
     * psu_uart_1 - COM port on PC
     * psu_coresight_0 - Console win debug Coretex-A53#0 in SDK
5) Copy/Paste over hello/src/helloworld.c with (/sources git)
   - Project->Build all
6) Xilinx->Program FPGA (should be set up from .hdf file)
7) Right click on hello/Binaries/hello.elf
   - Run As -> Launch on Hardware (System Debugger)


## Vivado + Vitis 2023.1
Instructions to create Vitis 2023.1 project from this base
1) Launch Vitis 2023.1
2) Select new directory for this project
3) Click 'Create Application Project' from launch screen
   - If you get welcome page click next
4) Switch tab to 'Create a new platform from hardware (XSA)
   - Browse to (/sources git)
   - Select design_1_wrapper_2023p1.xsa
5) Click Next
6) Name application (e.g. Hello_app)
7) Click Next, then click Finish
8) Expand desing_1_wrapper_2023p1 tree, open platform.spr
   - In edit area expand design_1_wrapper_2023p1->psu_cortexa53_0->standalone_psu_coretexa53_0
   - Select 'Board Support Package'
   - Click 'Modify BSP Settings...'
   - Select 'standalone' in left tree
   - stdin/stdout select one :
     * axi_uartlite_0 - COM port on PC
     * psu_uart_0 - COM port on PC
     * psu_uart_1 - COM port on PC
     * psu_coresight_0 - Console win debug Coretex-A53#0 in SDK
   - click 'OK'
9) Copy/Paste over Hello_app_system->Hello_app->/src/helloworld.c with (/sources git) and save
10) Right click Hello_app, 'Build project' (takes a min or so)
11) Right click Hello_app, 'Run as'->'Launch Hardware'(Single Application Debug)
    - should program FPGA and launch 
    - if using Console for uart, click drop-down next to monitor icon in lower 'Console' window, select 'TCF Debug Virtual Terminal - Cortex A53#0'


## Project result
On load the Zynq should execute the following peripherals:
1) Binary counter with 4 LEDs
2) 4 push-buttons report to UART (hold down to register)
   - they are the 4 buttons beside the 4 LEDs reporting binary counter
3) UART broadcast to COM port / Debug terminal as specified in stdout from BSP configuration above
   - PC COM port settings: 115200 N-8-1 (use app like Putty)
