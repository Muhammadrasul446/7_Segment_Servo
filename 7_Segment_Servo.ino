#define INTERVAL 1000  // Delay before showing next symbol

#define SERVO_DOWN 0  // minimal 
#define SERVO_UP 90  // and maximal positions of servo motor

#define TEXT "Muhammadrasuls Github is great!"  // Any kinda text

uint8_t servo_pins[] = {2, 3, 4, 5, 6, 7, 8};

#include <Servo.h>
Servo motors[7];

// Here is a "Hash table" data structure
// Please follow the order, for each symbol to be displayed correctly. So hash_values[n] must be a number for hash_keys[n]
char hash_keys[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', ' ', '=', '_'};
uint8_t hash_values[] = {119, 124, 57, 94, 121, 113, 116, 6, 30, 118, 56, 21, 55, 92, 115, 103, 80, 109, 120, 28, 62, 42, 118, 110, 91, 61, 6, 91, 79, 102, 109, 125, 7, 127, 111, 64, 0, 65, 8};

uint16_t length_of_arrays = sizeof(hash_keys) / sizeof(hash_keys[0]);

String text = String(TEXT);

void setup()
{
	
	for (uint8_t i = 0; i < 7; ++i)
	{
		motors[i].attach(servo_pins[i]);
	}
	
	
	text.trim();
	text.toLowerCase();
	
	update('0');
	delay(2000
}

void loop()
{
	for (uint8_t i = 0; i < text.length(); ++i)
	{
		update(text[i]);
		delay(INTERVAL);

		// If there are repeating symbols like 'Running', uncomment this:
		// update('0');
		// delay(300);
	}

	// If you want to use BT or Serial port, then uncomment this, and comment the above code:
	//serial();
}


int bin_search(char arr[], int low, int high, char val) {  // binary search implementation

	if (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == val)
			return mid;
		else if (arr[mid] > val)
			return bin_search(arr, low, mid - 1, val);
		else if (arr[mid] < val)
			return bin_search(arr, mid + 1, high, val);
	}
	return -1;
}

void update(char val) {
	uint8_t index = bin_search(hash_keys, 0, n - 1, val); // search for the value
	for (uint8_t i = 0; i < 7; i++) {
		
		byte state = bitRead(hash_values[index], i); // read i'th bit in a number
		
		if (state == 0)
			state = SERVO_DOWN;
		else
			state = SERVO_UP;
		
		motors[i].write(state);  // turn servo up or down appropriately
	}
}

void serial() {
	if (Serial.available())
	{
		char val = Serial.read();
		update(val);
	}
}
