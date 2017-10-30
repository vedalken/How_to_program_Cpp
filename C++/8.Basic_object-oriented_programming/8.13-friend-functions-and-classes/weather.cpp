#include <iostream>

class Humidity;

class Temperature
{
private:
	int m_temp;
public:
	Temperature(int temp = 0) : m_temp(temp) {}
	void setTemperature(int temp) { m_temp = temp; }
	//friend void printWeather(const Temperature &, const Humidity &);
	friend class Humidity;
};

class Humidity
{
private:
	int m_humidity;
public:
	Humidity(int humidity = 0) : m_humidity(humidity) {}
	void setHumidity(int humidity) { m_humidity = humidity; }
	void printWeather(const Temperature &, const Humidity &);
};

void Humidity::printWeather(const Temperature &temperature, const Humidity &humidity)
{
	std::cout << "The temperature is " << temperature.m_temp 
		<< " and the humidity is " << humidity.m_humidity << std::endl;
}

int main()
{
	Humidity hum(50);
	Temperature temp(25);

	hum.printWeather(temp, hum);
	return 0;
}
