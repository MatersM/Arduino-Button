
#ifndef BUTTON_H
#define BUTTON_H
#include <vector>
#include <functional>
/* Helper routines to simulate Arduino "attachInterrupt" */
extern std::vector<std::function<void(void)>>interruptStore ;
#define RISING 1
// Same function definition as the Arduino definition, but on the Arduino this doesn't seem to work :-(
inline void attachInterrupt(uint8_t pin, std::function<void(void)> intRoutine, int mode) { interruptStore.push_back(intRoutine) ; }
inline void detachInterrupt(uint8_t pin) { ; }
/**************************************************/

class Button {
public:
	Button(uint8_t pin, void (*callbackFunction)()) ;
  ~Button() ;
private:
  inline void pressed() ;
  uint32_t _pin ;
  void    (*_func)() ;
  uint32_t _debounce ;
  static std::vector<std::function<void(void)>>_lambdas ;
} ;
#endif

