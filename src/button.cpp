
#include "button.hpp"

std::vector<std::function<void(void)>>interruptStore ;

Button::Button(uint8_t pin, void (*callbackFunction)()) {
	_func = callbackFunction ;
	auto pressedFunction =  [this]() {this->pressed() ;} ;
	_lambdas.push_back(pressedFunction) ;
	attachInterrupt(pin,_lambdas.back(),RISING) ;
	_pin = pin ;
}

Button::~Button() {
	detachInterrupt(_pin) ;
}

inline void Button::pressed() {
//	if (millis()-_debounce>60) { // Here we would normally handle the debounce
		printf("Button on pin %d pressed\n",(int)_pin) ; 
    	_func() ;
//		_debounce = millis() ;
//	}
}

std::vector<std::function<void(void)>>Button::_lambdas ; // We need to define a static here, declaration is done in button.hpp

