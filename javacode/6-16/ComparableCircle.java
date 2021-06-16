class ComparableCircle extends Circle implements Comparable<ComparableCircle>
{

	public ComparableCircle()
	{

	}

	public ComparableCircle(double r)
	{
		super(r);
	}

	public int compareTo(ComparableCircle o)
	{
		if(GetArea() > o.GetArea())
		{
			return 1;
		}
		else if(GetArea() < o.GetArea())
		{
			return -1;
		}
		else 
		{
			return 0;
		}
	}
}