#include <stdio.h>
#include <stdlib.h>

#define TURKCE
#define INGILIZCE

	


int main(void){
	#undef INGILIZCE
	
	#if defined(TURKCE)
		printf("Turkce tanimlanmistir.\n");
	#elif defined(INGILIZCE)
		printf("Ingilizce tanimlanmistir.\n");
	#else
		printf("Turkce-ingilizce tanimlanmamistir.\n");
	#endif
	
	
	
	
	
	return 0;
}
