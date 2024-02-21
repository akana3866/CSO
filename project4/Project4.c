/*
This code was coded solely by Aditi Kanaujia
this file represents how to find the PPN from 
the TLB to find the byte in cache
*/


#include <stdio.h>
#include <string.h>

#define MAX_SIZE 16

// Structure definitions
typedef struct {
    int setIndex;
    int tag;
    int ppn;
} TLBEntry;

typedef struct {
    int vpn;
    int ppn;
} PageTableEntry;

typedef struct {
    int cacheIndex;
    int tag;
    char bytes[4];
} CacheEntry;

// Global arrays to store data
TLBEntry tlb[MAX_SIZE];
PageTableEntry pageTable[MAX_SIZE];
CacheEntry cache[MAX_SIZE];

// Global counters for each array
int tlbCount = 0, pageTableCount = 0, cacheCount = 0;

// Function to read input data
void readData() {
    char line[50];
    while(fgets(line, sizeof(line), stdin)) {
        if(strncmp(line, "TLB", 3) == 0) {
            sscanf(line, "TLB,%d,%x,%x", &tlb[tlbCount].setIndex, &tlb[tlbCount].tag, &tlb[tlbCount].ppn);
            tlbCount++;
        } else if(strncmp(line, "Page", 4) == 0) {
            sscanf(line, "Page,%d,%d", &pageTable[pageTableCount].vpn, &pageTable[pageTableCount].ppn);
            pageTableCount++;
        } else if(strncmp(line, "Cache", 5) == 0) {
            sscanf(line, "Cache,%d,%x,%2hhx,%2hhx,%2hhx,%2hhx", &cache[cacheCount].cacheIndex, &cache[cacheCount].tag, 
                   &cache[cacheCount].bytes[0], &cache[cacheCount].bytes[1], &cache[cacheCount].bytes[2], &cache[cacheCount].bytes[3]);
            cacheCount++;
        }
    }
}

// Function to convert hex string to int
int hexToInt(char hex[]) {
    int result = 0;
    sscanf(hex, "%x", &result);
    return result;
}

// Function to find PPN in TLB
int findInTLB(int vpn) {
    for(int i = 0; i < tlbCount; i++) {
        if(tlb[i].tag == vpn) return tlb[i].ppn;
    }
    return -1;
}

// Function to find PPN in Page Table
int findInPageTable(int vpn) {
    for(int i = 0; i < pageTableCount; i++) {
        if(pageTable[i].vpn == vpn) return pageTable[i].ppn;
    }
    return -1;
}

// Function to find Byte in Cache
char findInCache(int ppn, int offset) {
    for(int i = 0; i < cacheCount; i++) {
        if(cache[i].tag == ppn) return cache[i].bytes[offset];
    }
    return -1;
}

int main() {
    readData();

    for(int i = 0; i < 3; i++) {
        char vAddress[5];
        printf("Enter Virtual Address: ");
        scanf("%s", vAddress);

        int vpn = hexToInt(vAddress) >> 2;
        int offset = hexToInt(vAddress) & 0x3;

        int ppn = findInTLB(vpn);
        if(ppn == -1) ppn = findInPageTable(vpn);

        if(ppn != -1) {
            char byte = findInCache(ppn, offset);
            if(byte != -1) printf("Byte found: %02X\n", byte);
            else printf("Cannot be determined\n");
        } else {
            printf("Cannot be determined\n");
        }
    }

    return 0;
}