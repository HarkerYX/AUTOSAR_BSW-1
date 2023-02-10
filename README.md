# AUTOSAR BSW

### INTRODUCTION
The main purpose of this project is to implement CLASSIC AUTOSAR BSW STACK.

Simple and directly.

Nice docs, notes and pictures provided. 

### WORKING TARGET NOW
#### CAN communication stack
1. CanIf (WORKING)
2. CanTrcv

### HOW TO USE
1. After implementing the CAN communication stack, I will verify it on a development board.
2. Currently unavailable to run.

### FUTURE
In addition to AUTOSAR OS, I hope that several commonly used BSW modules can be implemented according to the standards 
as much as possible. It is expected that CAN, LIN and ETH communication and diagnosis can be implemented on a development 
board in the future. It also includes NVM-related modules.

### NOTE
Since the MCAL part must be linked to a specific ECU, I am still considering how to reduce the relevance of MCAL to BSW.

I am considering creating QEMU to simulate the development board for verification. But at present, I still choose a 
physical development board to ensure the success of protocol stack communication.
