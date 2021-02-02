# FPGA-Project

Create an AXI IP which is connected to the PS via AXI GP0/1 from one side, and from the other side is connected to the board slide switches. This IP reads the value of the slide switches (which can be changed by user) and keeps the value. The user can send an inquiry via UART to read this value.
A simple bare-metal code running on the arm processor which provides a text-based menu to the user and once the user asks for the value of the switch, it reads the data from the registers inside the IP and prints the value on the UART terminal.

 
