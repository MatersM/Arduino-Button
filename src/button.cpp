
#include "button.hpp"

std::vector<std::function<void(void)>>interruptStore ;

Button::Button(uint8_t pin, void (*callbackFunction)()) : _pin(pin), _func(callbackFunction) {
    attachInterrupt(pin, [this](){ this->pressed(); }, RISING);
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

