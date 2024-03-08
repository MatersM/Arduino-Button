
#include "button.hpp"

void pushedA() { printf("Pushed A\n") ; }
void pushedB() { printf("Pushed B\n") ; }
void pushedC() { printf("Pushed C\n") ; }

int main() {
	printf("Start\n") ;
	Button a(27,pushedA) ;
	Button b(25,pushedB) ;
	Button c(23,pushedC) ;

	printf("Execute\n") ;
	// So in the interruptStore we have functionpointers to class members. Now execute!
	for (auto interruptRoutine : interruptStore) {
		interruptRoutine() ;
	}
	return 0 ;
}
