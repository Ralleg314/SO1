#include<assert.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

typedef struct m_block *p_block;

struct m_block {
	size_t size;
	p_block next;
	int free;
};

#define META_SIZE sizeof(struct m_block)

p_block first_element = NULL;
p_block last_element  = NULL;

p_block demanar_espai(size_t);
p_block crear_bloc_lliure(size_t);

void *malloc(size_t size) 
{
    void *p;
    p_block block;

    if (size <= 0) {
        return NULL;
    }

    if (first_element){
        block = cercar_bloc_lliure(size);
        if (block) { // block found
            block->free = 0;
        } else {     // no block found
            block = demanar_espai(size);
            if (!block)
                return (NULL);
        }
    } 
    else  // This is done the first time malloc is called
    {
        block = demanar_espai(size);
        if (!block)
            return(NULL);
        first_element = block;
    }

    p = (void *) block;
    return (p + META_SIZE); 
}

p_block demanar_espai(size_t size){
	p_block block;
	block = sbrk(0);

	if (sbrk(META_SIZE + size) == (void *) -1)
		return (NULL);

	block->size = size;
	block->next = NULL;
	block->free = 0;

	if (last_element)
		last_element->next = block;

	last_element = block;
	return block;
}

p_block cercar_bloc_lliure(size_t size) {
	p_block current = first_element;

	while (current && !(current->free && current->size >= size))
		current = current->next;
	
	return current;
}

void free(void *p){
	block->free=1;
}
