#include <stdio.h>
#include <stdlib.h>
#include "vm/vm.h"
#include "instruction/instruction.h"

int main(int argc, char **argv) {
    vm machine;
    setupVM(&machine);
    int i = 0;
    machine.instructions[i++] = (instruction){LOAD,0,2};
    machine.instructions[i++] = (instruction){LOAD,1,8};
    machine.instructions[i++] = (instruction){MOVEM,1,0};
    machine.instructions[i++] = (instruction){MOVEM,2,1};
    machine.instructions[i++] = (instruction){CMP,1,2};

    machine.instructions[instructionSize-1] = (instruction){HALT,0,0};

    printf("\n\nMachine started!\n\n");
    printf("\nPress enter\n");
    while(1) {

        getchar();

        if (machine.running == 0) {
            continue;
        }

        system("cls");
        

        executeInstruction(&machine.instructions[machine.programCounter], &machine);
        if (machine.running == 0) {
            printf("\n\nMachine stopped or got closed!!!\n\n");
            continue;
        }

        printf("\nPC: %d\n", machine.programCounter);

        printf("\nInstructions: \n");
        for (int i = 0; i < instructionSize; i++) {
            if (machine.instructions[i].op != NOP) {
                printf("    %d: ",i);
                printInstruction(&machine.instructions[i]);
                printf("\n");
            }
        }

        printf("\nRegisters: \n");
        for (int i = 0; i < registerCount; i++) {
            printf("    ");printf("%d:  %d\n",i, machine.registers[i]);
        }

        printf("\nMemory: \n");
        for (int i = 0; i < ramSize; i++) {
            printf("    ");printf("%d:  %d\n",i, machine.memory[i]);
        }

    }
}