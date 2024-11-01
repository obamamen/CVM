#include "vm.h"

void setupVM(vm* machine) {
    machine->programCounter = 0;
    machine->running = 1;

    int i;
    for (i = 0; i < registerCount; i++) {
        machine->registers[i] = 0;
    }
    for (i = 0; i < ramSize; i++) {
        machine->memory[i] = 0;
    }
    for (i = 0; i < instructionSize; i++) {
        instruction instr = emptyInstruction;
        machine->instructions[i] = instr;
    }
}