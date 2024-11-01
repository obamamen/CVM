#include <stdio.h>
#include "vm/vm.h"
#include "instruction/instruction.h"

int main(int argc, char **argv) {
    vm machine;
    setupVM(&machine);
    machine.instructions[0] = (instruction){LOAD,{0,10}};
    machine.instructions[1] = (instruction){LOAD,{1,20}};

    machine.instructions[2] = (instruction){MOVEM,{2,0}};
    machine.instructions[3] = (instruction){MOVEM,{1,1}};

    machine.instructions[4] = (instruction){ADD,{1,2}};
    machine.instructions[5] = (instruction){MOVER,{registerA,5}};

    executeInstruction(&machine.instructions[0], &machine);
    executeInstruction(&machine.instructions[1], &machine);
    executeInstruction(&machine.instructions[2], &machine);
    executeInstruction(&machine.instructions[3], &machine);
    executeInstruction(&machine.instructions[4], &machine);
    executeInstruction(&machine.instructions[5], &machine);

    printf("\nInstructions: \n");
    for (int i = 0; i < instructionSize; i++) {
        printInstruction(&machine.instructions[i]);
    }

    printf("\nRegisters: \n");
    for (int i = 0; i < registerCount; i++) {
         printf("%d:  %d\n",i, machine.registers[i]);
    }

    printf("\nMemory: \n");
    for (int i = 0; i < ramSize; i++) {
        printf("%d:  %d\n",i, machine.memory[i]);
    }



    while(1) {
        
    }
}