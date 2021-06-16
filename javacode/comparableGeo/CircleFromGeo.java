public class CircleFromGeo extends ComparableGeo
{

	private double _radius;

	public CircleFromGeo()
	{
		_radius = 0;
	}
	
	public CircleFromGeo(double newRadius)
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

	public String toString()
	{
		return "Circle : " + "radius: " + _radius + "areas: " + GetAreas();
	}
	

}