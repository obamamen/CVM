#pragma once
#include "../types/types.h"

void printInstruction(const instruction *inst);
void executeInstruction(const instruction *inst, vm *machine);

typedef enum instructionSet{
    NOP = 0,        // no instruction
    ADD,            // addition (ra = 1 + 2) {1,2}
    SUB,            // subtract (ra = 1 - 2) {1,2}
    MULT,           // multiply (ra = 1 * 2) {1,2}
    JUMPI,          // jump if (jump if ra == 1) {poitoin}
    CMP,            // compare a and b (-1 less, 0 equal, 1 greater)  puts the answer into C
    MOVER,          // move register to mem {register, memoryPos}
    MOVEM,          // move memory to reg {register, memoryPos}
    LOAD,           // load number into memory {memoryPos,number}

    
    // end of instruction set
    HALT
}instructionSet;