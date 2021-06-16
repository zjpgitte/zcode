public class Circle{

	public Circle(double newRadius)
	{
		_radius = newRadius;
	}

	public void SetRadius(double newRadius)
	{
		_radius = newRadius;
	}

	public double GetAreas()
	{
		return 3.14 * _radius * _radius;
	}

	public double GetRadius()
	{
		return _radius;
	}


	private double _radius;

}