class Circle
{
	protected double _r;

	public Circle(double r)
	{
		_r = r;
	}

	public Circle()
	{
		_r = 1;
	}

	public double GetArea()
	{
		return 3.14 * _r * _r;
	}
}