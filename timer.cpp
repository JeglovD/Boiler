#include "timer.h"
#include "heater.h"

ISR(TIMER1_COMPA_vect) {
	Timer::Instance().Interrupt();
}

Timer::Timer() {
	pinMode(LED_BUILTIN, OUTPUT);
	
	// ������������� Timer1

	// ��������� ����������
	cli();

	// ���������� �������� � 0
	TCCR1A = 0;   

	TCCR1B = 0;
	// �������� CTC ����� 
	TCCR1B |= (1 << WGM12);  
	// ���������� ���� �� ����������� ������� 8
	TCCR1B |= (0 << CS12) | (1 << CS11) | (0 << CS10);

	// ��������� �������� ���������� ��� ������� 50��
	OCR1A = 20000; 
	// �������� ���������� �� ���������� ������� 
	TIMSK1 |= (1 << OCIE1A);  

	// ��������� ����������
	sei();
}

void Timer::Interrupt() {
	digitalWrite(LED_BUILTIN, Heater::Instance()() * 255 >= ++mCounter);
}