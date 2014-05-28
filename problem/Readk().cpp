/*

There is an encapsulated function, int block_reader(char *buf). A statis pointer is in this function and it
can only move to the end of a file but rewind. It read k bytes block into buf and return the bytes it read (always K unless reach the end of a file).
Please implement int anysize_reader(char *buf, int size), this function can read any size data you want into buf, and return the real data size it read.
Note: int anysize_reader(char *buf, int size) may be called several times to read a whole block of data.
     
*/

const int k = 1024; //suppose k=1024

char buffer[k];
int preSize = 0; //valid data size in buffer, this value will be set within funciton block_reader(char *buf)
int BlockReader(char *buf);

void MoveToBuf(char*& pW, int n) {
    if (n <= 0 || pW == NULL || preSize < n) return;     
    memcpy(pW, buffer, n);
    preSize -= n;
    memcpy(buffer, buffer+n, preSize);
    pW += n;
}

int AnysizeReader(char *buf, int size) {
    if (buf == NULL || size <= 0) return 0;

    char* pw = buf;
    int Lft = size;  //the size you want to read 
    int Mov = Lft > preSize ? preSize : Lft ;
    MoveToBuf(pW, Mov); //get the valid data from buffer last time left  
    Lft -= Mov;
     
    while (Lft > 0) {
    
        int Read = BlockReader(buffer); //read k bytes into buffer and set preSize
        Mov = Lft < Read ? Lft : Read;
        MoveToBuf(pW, Mov);
        Lft -= Mov;
         
        if (Read < k) break; //reach end of a file
    }
     
    return pW - buf;
}
