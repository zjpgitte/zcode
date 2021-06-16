public class convert
{
	private double _fahrenheit;
	private double _celsius;

	public void SetCelsius(double newCelsius)
	{
		_celsius = newCelsius;

	}

	public double ConvertToFah()
	{
		_fahrenheit = (9.0 / 5) * _celsius + 32;

		return _fahrenheit; 
	}
}