#include <stdio.h>
#include <stdlib.h>
#include "vm/vm.h"
#include "instruction/instruction.h"

void putString(const char* string, void* place) {
    int index = 0;
    char* charPlace = (char*)place;

    while (string[index] != '\0') {
        charPlace[index] = string[index];
        index++;
    }
}


void printInt(void* p) {
    int* val = (int*)p;
    printf("%d\n", *val);
}

int main(int argc, char **argv) {
    vm machine;
    setupVM(&machine);
    int i = 0;
    //machine.instructions[i++] = (instruction){LOAD,0, 104};
    //machine.instructions[i++] = (instruction){LOAD,1, 101};
    //machine.instructions[i++] = (instruction){LOAD,2, 108};
    //machine.instructions[i++] = (instruction){LOAD,3, 108};
    //machine.instructions[i++] = (instruction){LOAD,4, 111};
    //machine.instructions[i++] = (instruction){LOAD,5,  32};
    //machine.instructions[i++] = (instruction){LOAD,6, 119};
    //machine.instructions[i++] = (instruction){LOAD,7, 111};
    //machine.instructions[i++] = (instruction){LOAD,8, 114};
    //machine.instructions[i++] = (instruction){LOAD,9, 108};
    //machine.instructions[i++] = (instruction){LOAD,10,100};
    //machine.instructions[i++] = (instruction){LOAD,11, 33};
    //machine.instructions[i++] = (instruction){LOAD,12, 0 };
    machine.instructions[i++] = (instruction){IOP,0,   Int };
    machine.instructions[i++] = (instruction){HALT,0 , 0 };
    
    //machine.instructions[i++] = (instruction){LOAD,1,8};
    //machine.instructions[i++] = (instruction){MOVEM,1,0};
    //machine.instructions[i++] = (instruction){MOVEM,2,1};
    //machine.instructions[i++] = (instruction){CMP,1,2};

    machine.instructions[instructionSize-1] = (instruction){HALT,0,0};

    printf("\n\nMachine started!\n\n");
    printf("\nPress enter\n");
    while(1) {

        int number = 2000;
        *(int *)&machine.memory[0] = number;

        getchar(); // wait for user input to continue

        if (machine.running == 1) { 
            system("cls");
            printf("\nPC: %d\n", machine.programCounter);
            executeInstruction(&machine.instructions[machine.programCounter], &machine);
        } else {
            continue;
        }


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