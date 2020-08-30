#include "timer.h"
#include "heater.h"

ISR(TIMER1_COMPA_vect) {
	Timer::Instance().Interrupt();
}

Timer::Timer() {
	pinMode(LED_BUILTIN, OUTPUT);
	
	// Инициализация Timer1

	// Запрещаем прерывания
	cli();

	// установить регистры в 0
	TCCR1A = 0;   

	TCCR1B = 0;
	// Включить CTC режим 
	TCCR1B |= (1 << WGM12);  
	// Установить биты на коэффициент деления 8
	TCCR1B |= (0 << CS12) | (1 << CS11) | (0 << CS10);

	// Установка регистра совпадения для частоты 50Гц
	OCR1A = 20000; 
	// Включить прерывание по совпадению таймера 
	TIMSK1 |= (1 << OCIE1A);  

	// Разрешаем прерывания
	sei();
}

void Timer::Interrupt() {
	digitalWrite(LED_BUILTIN, Heater::Instance()() * 255 >= ++mCounter);
}