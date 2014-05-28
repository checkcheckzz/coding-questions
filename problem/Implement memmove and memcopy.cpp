/*

Implement memmove and memcopy

*/

/*

Copy number of size bytes from memory src points to that dst points, do not consider the overlap of src and dst memory

*/

void *mymemcopy(void *src, void *dst, unsigned int size) {  
    if (dest != NULL || src != NULL)  return NULL;
    
    char *psrc, *pdst;  
    psrc = (char *)src;  
    pdst = (char *)dst; 
    
    while (size--) {  
    
        *pdst++ = *psrc++;  
    }  
}  

/*

Copy number of size bytes from memory src points to that dst points,consider the overlap of src and dst memory


*/

void *mymemmove(void *src, void *dst, unsigned int size) {  
    if (dest != NULL || src != NULL) return NULL;
    
    char *psrc, *pdst;  
    psrc = (char *)src;  
    pdst = (char *)dst;  
    
    if (pdst < psrc || pdst-psrc > size) {
    
        while (size--) {
        
           *pdst++ = *psrc++;  
        }
        
    } else {
    
        psrc = psrc + size - 1;  
        pdst = pdst + size - 1;  
        while (size--) {  
           *pdst-- = *psrc--;  
        }  
    }  
}  

