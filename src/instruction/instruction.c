#include "instruction.h"
#include  <stdio.h>

void executeInstruction(const instruction *inst, vm *machine) {
    switch (inst->op) {
        case NOP:
            break;
        case ADD: {
            int a = machine->registers[inst->operands[0]];
            int b = machine->registers[inst->operands[1]]; 
            machine->registers[registerA] = a + b; 
            break;
        }
        case SUB: {
            int a = machine->registers[inst->operands[0]];
            int b = machine->registers[inst->operands[1]];
            machine->registers[registerA] = a - b;
            break;
        }
        case MULT: {
            int a = machine->registers[inst->operands[0]];
            int b = machine->registers[inst->operands[1]];
            machine->registers[registerA] = a * b;
            break;
        }
        case JUMPI: {
            if (machine->registers[registerA] != 0) {
                machine->programCounter = inst->operands[0]; 
            }
            break;
        }
        case CMP: {
            int a = machine->registers[inst->operands[0]];
            int b = machine->registers[inst->operands[1]];
            machine->registers[registerA] = (a == b) ? 1 : 0; 
            break;
        }
        case MOVER: {
            machine->memory[inst->operands[1]] = machine->registers[inst->operands[0]]; 
            break;
        }
        case MOVEM: {
            machine->registers[inst->operands[0]] = machine->memory[inst->operands[1]]; 
            break;
        }
        case LOAD: {
            machine->memory[inst->operands[0]] = inst->operands[1]; 
            break;
        }
        case HALT:
            machine->running = 0;
            break;
    }
}
void printInstruction(const instruction *inst) {
    printf("Opcode: ");
    switch (inst->op) {
        case NOP:
            printf("none");
            break;
        case ADD:
            printf("adition (%d, %d)",  
                inst->operands[0], inst->operands[1]);
            break;    
        case SUB:
            printf("subtraction (%d, %d)",  
                inst->operands[0], inst->operands[1]);
            break;    
        case MULT:
            printf("multiply (%d, %d)",  
                inst->operands[0], inst->operands[1]);
            break;   
        case JUMPI:
            printf("jump if (%d)",inst->operands[0]);
            break;
        case CMP:
            printf("compare (%d, %d)",  
                inst->operands[0], inst->operands[1]);
            break;
        case MOVER:
            printf("move into register (%d, %d)",  
                inst->operands[0], inst->operands[1]);
            break; 
        case MOVEM:
            printf("move into memory (%d, %d)",  
                inst->operands[0], inst->operands[1]);
            break; 
        case LOAD:
            printf("load into memory (%d,%d)", inst->operands[0], inst->operands[1]);
            break; 
        case HALT:
            printf("exit program");
            break; 
    }
    printf("\n");
}