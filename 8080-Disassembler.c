#include <stdio.h>
#include <stdlib.h>

int Disassemble8080Op(unsigned char *codebuffer, int pc){
    unsigned char *codeSeg = &codebuffer[pc];
    int opBytes = 1;
    printf("%04x:   ",pc);
    switch (*codeSeg) // ML = Memory location NOT value, VAL = Value at memory location
    {
    case 0x00: printf("NOP"); break; // No operation
    case 0x01: printf("LXI      B,#$%02x%02x",codeSeg[2],codeSeg[1]); opBytes=3; break; // Moves byte 3 to register B (ML), moves byte 2 to register C (ML)
    case 0x02: printf("STAX     B"); break; // The value of register A (ML) is copied to memory at the address of register pair BC (VAL)
    case 0x03: printf("INX      B"); break; // Register pair (BC) is incremented as a 16-bit number (ML) (by 1)
    case 0x04: printf("INR      B"); break; // Register B is incremented by 1 (ML)
    case 0x05: printf("DCR      B"); break; // Register B is decremented (ML)
    case 0x06: printf("MVI      B,#$%02x", codeSeg[1]); opBytes=2; break; // Moves the value of byte 2 to the memory at register B (ML)
    case 0x07: printf("RLC"); break; // Content of register A is shifted left one bit (ML). The lowest order bit of register A's content is set to whatever bit was shifted out and flag CY is set to this bit (ML).
    case 0x08: printf("NOP"); break; // No operation
    case 0x09: printf("DAD      B"); break; // The register pair BC (ML) is added to the HL register pair (ML)
    case 0x0a: printf("LDAX     B"); break; // The content found at register pair BC (VAL) is copied into register A (ML)
    case 0x0b: printf("DCX      B"); break; // Decrements the register pair BC (ML)
    case 0x0c: printf("INR      C"); break; // Register C is incremented by 1 (ML)
    case 0x0d: printf("DCR      C"); break; // Register C is decremented by 1 (ML)
    case 0x0e: printf("MVI      C,#$%02x", codeSeg[1]); opBytes=2; break; // Moves the value of byte 2 to the memory at register C (ML)
    case 0x0f: printf("RRC"); opBytes=2; break; // Content of register A is shifted right one bit (ML). The highest order bit of register A is set to whatever bit was shifted out and flag CY is set to this bit (ML).
    case 0x10: printf("NOP"); break; // No operation
    case 0x11: printf("LXI      D,#$%02x%02x",codeSeg[2],codeSeg[1]); opBytes=3; break; // Moves byte 3 to register D (ML), moves byte 2 to register E (ML)
    case 0x12: printf("STAX     D"); break; // The value of register A (ML) is copied to memory at the address of register pair DE (VAL)
    case 0x13: printf("INX      D"); break; // Register pair (DE) is incremented as a 16-bit number (ML) (by 1)
    case 0x14: printf("INR      D"); break; // Register D is incremented by 1 (ML)
    case 0x15: printf("DCR      D"); break; // Register D is decremented (ML)
    case 0x16: printf("MVI      D,#$%02x", codeSeg[1]); opBytes=2; break; // Moves the value of byte 2 to the memory at register D (ML)
    case 0x17: printf("RAL"); break; // Content of register A is shifted left 1 bit (ML). The lowest order bit of register A's content is set to the previous flag CY (ML). The flag CY is set to the bit shifted out (ML).
    case 0x18: printf("NOP"); break; // No operation
    case 0x19: printf("DAD      D"); break; // The register pair DE is added to the HL register pair (ML)
    case 0x1a: printf("LDAX     D"); break; // The content found at register pair DE (VAL) is copied into register A (ML)
    case 0x1b: printf("DCX      D"); break; // Decrements the register pair DE (ML)
    case 0x1c: printf("INR      E"); break; // Register E is incremented by 1 (ML)
    case 0x1d: printf("DCR      E"); break; // Register E is decremented (ML)
    case 0x1e: printf("MVI      E,#$%02x", codeSeg[1]); opBytes=2; break; // Moves the value of byte 2 to the memory at register E (ML)
    case 0x1f: printf("RAR"); break; // Content of register A is shifted right one bit (ML). The highest order bit of register A is set to what it was before being shifted (IE value of bit 6) and flag CY is set to the bit shifted out(ML).
    case 0x20: printf("NOP"); break; // No operation
    case 0x21: printf("LXI      H,#$%02x%02x",codeSeg[2],codeSeg[1]); opBytes=3; break; // Moves byte 3 to register H (ML), moves byte 2 to register L (ML)
    case 0x22: printf("SHLD     #$%02x%02x",codeSeg[2],codeSeg[1]); opBytes=3; break; // Content of register L (ML) is copied into the memory pointed to by adr (VAL), content of register H (ML) is copied into the memory pointed to by adr+1 (VAL) 
    case 0x23: printf("INX      H"); break; // Register pair (HL) is incremented as a 16-bit number (ML) (by 1)
    case 0x24: printf("INR      H"); break; // Register H is incremented by 1 (ML)
    case 0x25: printf("DCR      H"); break; // Register H is decremented (ML)
    case 0x26: printf("MVI      H,#$%02x", codeSeg[1]); opBytes=2; break; // Moves the value of byte 2 to the memory at register H (ML)
    case 0x27: printf("DAA"); break; // Special opcode
    case 0x28: printf("NOP"); break; // No operation
    case 0x29: printf("DAD      H"); break; // The register pair HL is added to the HL register pair (ML)
    case 0x2a: printf("LHLD     #$%02x%02x",codeSeg[2],codeSeg[1]); opBytes=3; break; // Copies the value found at adr (VAL) into register L (ML), Copies the value found at adr+1 (VAL) into register H (ML)
    case 0x2b: printf("DCX      H"); break; // Decrements the register pair HL (ML)
    case 0x2c: printf("INR      L"); break; // Register L is incremented by 1 (ML)
    case 0x2d: printf("DCR      L"); break; // Register L is decremented (ML)
    case 0x2e: printf("MVI      L,#$%02x", codeSeg[1]); opBytes=2; break; // Moves the value of byte 2 to the memory at register L (ML)
    case 0x2f: printf("CMA"); break; // The register A (ML) is given the value of !A (Not a) (ML)
    case 0x30: printf("NOP"); break; // No operation
    case 0x31: printf("LXI      SP,#$%02x%02x",codeSeg[2],codeSeg[1]); opBytes=3; break; // Moves byte 3 to the high order of register pair SP (Stack pointer) (ML), moves byte 2 to the low order of register pair SP (Stack pointer) (ML)
    case 0x32: printf("STA      #$%02x%02x",codeSeg[2],codeSeg[1]); opBytes=3; break; // Copies register A (ML) to the value of the given adress (Byte 2 and 3) (VAL)
    case 0x33: printf("INX      SP"); break; // Register pair (SP - Stack pointer) is incremented as a 16-bit number (ML) (by 1)
    case 0x34: printf("INR      M"); break; // Register pair HL (Val) is incremented by 1
    case 0x35: printf("DCR      M"); break; // Register pair HL (Val) is decremented by 1
    case 0x36: printf("MVI      M,#$%02x", codeSeg[1]); opBytes=2; break; // Moves the value of byte 2 to the value at register HL (VAL)
    case 0x37: printf("STC"); break; // CY flag is set to 1
    case 0x38: printf("NOP"); break; // No operation
    case 0x39: printf("DAD      SP"); break; // The register pair SP is added to the HL register pair (ML)
    case 0x3a: printf("LDA      #$%02x%02x",codeSeg[2],codeSeg[1]); opBytes=3; break; // Copies the value found at adr (VAL) into register A (ML)
    case 0x3b: printf("DCX      SP"); break; // Decrements the register pair SP by 1 (ML)
    case 0x3c: printf("INR      A"); break; // Register A (ML) is incremented by 1
    case 0x3d: printf("DCR      A"); break; // Register A (ML) is decremented by 1
    case 0x3e: printf("MVI      A,#$%02x", codeSeg[1]); opBytes=2; break; // Moves the value of byte 2 to the memory at register A (ML)
    case 0x3f: printf("CMC"); // The register flag CY (ML) is given the value of !CY (Not CY) (ML)
    }
    printf("\n");
    return opBytes;
}
  

int main(int argc, char *argv[])
{
    FILE *fp;
    unsigned char *buffer=0;
    long length;
    int pc=0;
    if(argc==2){
        fp = fopen(argv[1],"r");
        fseek(fp,0,SEEK_END);
        length = ftell(fp);
        fseek(fp,0,SEEK_SET);
        buffer = (unsigned char*)malloc(length*sizeof(unsigned char));
        if(buffer!=0){
            fread(buffer,1,length,fp);
            while(pc<length){
                pc = pc + Disassemble8080Op(buffer,pc);
            }
            free(buffer);
        }
        fclose(fp);
    }
    else{
        printf("Invalid Number of Arguments");
        return 0;
    }
  
    return 0;
}