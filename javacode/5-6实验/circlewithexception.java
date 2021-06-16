public class circlewithexception{

	public circlewithexception(double newRadius)
	{
		SetRadius(newRadius);
		_numberOfObject++;
	}

	public void SetRadius(double newRadius) throws IllegalArgumentException
	{
		if(newRadius <= 0)
		{
			throw new IllegalArgumentException("Raidus can not be negative!");
		}
		else 
		{
			_radius = newRadius;
		}
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
	public static int _numberOfObject;

}