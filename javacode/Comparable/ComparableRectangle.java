public class ComparableRectangle extends RectangleFromGeo implements Comparable<ComparableRectangle>
{
	public ComparableRectangle(double width,double height)
	{
		super(width, height);
	}

	public int compareTo(ComparableRectangle o)
	{
		if(GetAreas() > o.GetAreas())
		{
			return 1;
		}
		else if(GetAreas() < o.GetAreas())
		{
			return -1;
		}
		else 
		{
			return 0;
		}
	}

	public String toString()
	{
		return (super.toString() + "areas:" + GetAreas());
	}
}