/*

Implement malloc and free in C

*/

/*
Background: for each process, OS already allocated a small memory space. When the program calls malloc, 
it will search this space at first. 
If the space is not enough, malloc will call  function sbrk to extend the end of the allocated memory space.
*/

//memory control block

struct mcb { 

int available; //1 if this memory space is free, 0 if not.
int size; //size of this memory space

} 

void *memStart; //the memory address which malloc searches from. 
void *lastAddr; //last effective memory address
int hasInit;

void init() {
    lastAddr = sbrk(0); //initialize the last effective memory address as the stack end

    memStart = lastAddr; 
    hasInit = 1;
}

void *malloc_mem(int num) {

    if (!hasInit) {
	
        init();
    }
        
    void *current = memStart; 
	
    void *ret = NULL; // the final return address
 
    num += sizeof(mcb); //need to add the size of mcb
	

    while (current != lastAddr) { 
	
        mcb *pcurrent = current; 
       if (pcurrent->available && pcurrent->size >= num) { // if size is enough
		
            pcurrent->available = 0; 
            ret = current; 
            break; 
        } 
		
        current += pcurrent->size; //check next memory block
    }
	
    if (!ret) { //if there is no available memory block，or allocated first time
	
        sbrk(num); //adjust the size of stack end 
        ret = lastAddr; 
        lastAddr += num; 
        mcb *pcb = ret; 
        pcb->size = num; 
        pcb->available = 0; 
		
    } 
	
    ret += sizeof(mcb); // return ret, skip the size of mcb 
    return ret;
}

/*
free memory function
*/

void free_mem(void *start) {
    mcb *pmcb = (mcb *)(start - sizeof(mcb));
    pmcb->available = 1;
}

