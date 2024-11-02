#pragma once
#include "../types/types.h"

void printInstruction(const instruction *inst);
void executeInstruction(const instruction *inst, vm *machine);

typedef enum instructionSet{
    NOP = 0,        // no instruction
    ADD,            // addition (ra = 1 + 2) {1,2}
    SUB,            // subtract (ra = 1 - 2) {1,2}
    MULT,           // multiply (ra = 1 * 2) {1,2}
    JUMPI,          // jump if (jump if ra != 0) {poitoin}
    CMP,            // compare a and b (-1 less, 0 equal, 1 greater)  puts the answer into C
    MOVER,          // move register to mem {register, memoryPos}
    MOVEM,          // move memory to reg {register, memoryPos}
    LOAD,           // load number into memory {memoryPos,number}
    IOP,            // instruction for output , {memoryPos, type} (0:char,1:string,2:short,3:int,4:charNumber)
    SHL,            // bitshift left        {register,amount}
    SHR,            // bitshift left right  {register,amount}
    
    // end of instruction set
    HALT
}instructionSet;