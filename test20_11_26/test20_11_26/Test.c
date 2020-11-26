#include<stdio.h>
#include<string.h>

int main()
{
	union
	{
		short k;
		char i[2];
	}*s, a;
	s = &a;
	s->i[0] = 0x39;
	s->i[1] = 0x38;
	printf("%x\n", a.k);
	return 0;
}

/*
struct S
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
}S;

int main()
{

	struct S s = { 0 };
	s.a = 10;
	s.b = 12; 
	s.c = 3; 
	s.d = 4; 

	printf("a = %d b = %d c = %d d = %d\n", s.a, s.b, s.c, s.d);

	return 0;
}
*/

/*
struct Test
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
}*PTest;

int main()
{
	unsigned char ch[4];
	PTest = (struct Test*)ch;
	memset(ch,0,4);
	PTest->a = 10;	
	PTest->b = 12;
	PTest->c = 3;
	PTest->d = 4;

	printf("a = %x b = %x c = %x d = %x\n",ch[0], ch[1], ch[2], ch[3]);

	return 0;
}
*/

/*
struct Test
{
	char a : 1;
	char b : 6;
	int c : 1;
}Test;

int main()
{
	printf("size = %d\n", sizeof(struct Test));
	return 0;
}
*/