#include <stdio.h>
#include <malloc.h>

typedef struct stream
{
	unsigned char *p;
	unsigned char *data;
    unsigned int size;
}
*STREAM;

#define out_uint16_be(s,v)	{ *((s)->p++) = ((v) >> 8) & 0xff; *((s)->p++) = (v) & 0xff; }
#define out_uint8(s,v)		*((s)->p++) = v;

void
sec_out_mcs_data(STREAM s)
{
	out_uint8(s, 5);
	out_uint16_be(s, 16);
}

void 
show(STREAM s)
{   
	int i = 1;
	while(s->data != s->p)
	{
		printf("i = %d, s->data = 0x%X\n", i, *(s->data));
		i++;
		s->data++;
	};
}

int main()
{
	struct stream s;
	s.size = 512;	
	s.p = s.data = (char *) malloc(s.size);
	sec_out_mcs_data( &s );
	show(&s);
	printf("s.p = %p\n", *(--s.p));
	return 1;
}
