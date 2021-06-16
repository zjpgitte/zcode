public class octogan extends Geometric implements Cloneable 
{ 
	private double _x; //边长
	octogan()
	{
		_x = 0;
	}
	octogan(double x)
	{
		_x = x;
	}

	public double getPerimeter()
	{
		return 8 * _x;
	}

	public double getArea()
	{
		return (2 + 4 / Math.sqrt(2)) * _x * _x;
	}
	public int compareTo(octogan o)
	{
		if(getArea() > o.getArea())
		{
			return 1;
		}
		else if(getArea() < o.getArea())
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}

	public Object clone() throws CloneNotSupportedException
	{
		return super.clone();
	}
}